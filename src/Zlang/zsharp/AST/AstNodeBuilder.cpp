#include "AstNodeBuilder.h"
#include "AstFile.h"
#include "AstAssignment.h"
#include "AstBranch.h"
#include "AstFunction.h"
#include "AstExpressionBuilder.h"
#include "../grammar/parser/zsharp_parserParser.h"
#include "../../Utils.h"

bool isEmpty(antlr4::ParserRuleContext* ctx) {
    return ctx->children.size() == 0;
}

template <class T> 
T* AstNodeBuilder::findCurrent() const
{
    T* p = nullptr;

    for (auto c : _current) {
        p = dynamic_cast<T*>(c);
        if (p) {
            break;
        }
    }

    guard(p != nullptr);
    return p;
}

antlrcpp::Any AstNodeBuilder::visitChildrenExcept(antlr4::ParserRuleContext* node, antlr4::ParserRuleContext* except)
{
    antlrcpp::Any result = defaultResult();
    size_t n = node->children.size();
    for (size_t i = 0; i < n; i++) {
        antlr4::tree::ParseTree* child = node->children[i];
        if (child == except) continue;

        if (!shouldVisitNextChild(node, result)) {
            break;
        }

        antlrcpp::Any childResult = child->accept(this);
        result = aggregateResult(result, childResult);
    }

    return result;
}

antlrcpp::Any AstNodeBuilder::aggregateResult(antlrcpp::Any aggregate, const antlrcpp::Any& nextResult)
{
    if (nextResult.isNull()) {
        return aggregate;
    }
    return nextResult;
}

antlrcpp::Any AstNodeBuilder::visitFile(zsharp_parserParser::FileContext* ctx) {
    auto file = std::make_shared<AstFile>(ctx);
    setCurrent(file);

    auto any = base::visitChildren(ctx);

    revertCurrent();
    guard(_current.size() == 0);

    return file;
}

antlrcpp::Any AstNodeBuilder::visitStatement_import(zsharp_parserParser::Statement_importContext* ctx)
{
    auto file = findCurrent<AstFile>();
    file->AddImport(ctx);

    auto symbols = file->getSymbols();
    auto entry = symbols.AddSymbol(ctx->module_name()->getText(), "", AstSymbolType::NotSet, nullptr);
    entry->setSymbolLocality(AstSymbolLocality::Imported);

    return nullptr;
}

antlrcpp::Any AstNodeBuilder::visitStatement_export(zsharp_parserParser::Statement_exportContext* ctx)
{
    auto file = findCurrent<AstFile>();
    file->AddExport(ctx);

    auto symbols = file->getSymbols();
    auto entry = symbols.AddSymbol(_namespace, ctx->identifier_func()->getText(), AstSymbolType::Function, nullptr);
    entry->setSymbolLocality(AstSymbolLocality::Exported);

    return nullptr;
}

antlrcpp::Any AstNodeBuilder::visitFunction_def(zsharp_parserParser::Function_defContext* ctx)
{
    auto file = findCurrent<AstFile>();
    auto function = std::make_shared<AstFunction>(ctx);

    auto symbols = file->getSymbols();
    auto entry = symbols.AddSymbol(_namespace, ctx->identifier_func()->getText(), AstSymbolType::Function, function);
    function->setName(entry->getSymbolName().getQualifiedName());

    if (dynamic_cast<zsharp_parserParser::Function_def_exportContext*>(ctx->parent)) {
        entry->setSymbolLocality(AstSymbolLocality::Exported);
    }

    file->AddFunction(function);
    setCurrent(function);
    addIndentation();

    auto any = base::visitChildren(ctx);

    revertIndentation();
    revertCurrent();
    return any;
}

antlrcpp::Any AstNodeBuilder::visitCodeblock(zsharp_parserParser::CodeblockContext* ctx)
{
    if (isEmpty(ctx)) {
        auto err = std::make_shared<AstError>(ctx);
        err->setText(AstError::EmptyCodeBlock);
        _errors.push_back(err);
        return nullptr;
    }

    auto site = findCurrent<AstCodeBlockSite>();
    auto codeBlock = std::make_shared<AstCodeBlock>(ctx);
    bool success = site->AddCodeBlock(codeBlock);
    guard(success);

    setCurrent(codeBlock);
    
    auto any = base::visitChildren(ctx);

    revertCurrent();
    return any;
}

antlrcpp::Any AstNodeBuilder::visitStatement_if(zsharp_parserParser::Statement_ifContext* ctx)
{
    auto codeBlock = findCurrent<AstCodeBlock>();
    auto branch = std::make_shared<AstBranch>(ctx);
    bool success = codeBlock->AddItem(branch);
    guard(success);

    auto indent = ctx->indent();
    auto retVal = visitIndent(indent);

    setCurrent(branch);
    addIndentation();

    auto any = visitChildrenExcept(ctx, indent);

    revertIndentation();
    revertCurrent();
    return any;
}

antlrcpp::Any AstNodeBuilder::visitStatement_else(zsharp_parserParser::Statement_elseContext* ctx)
{
    auto branch = findCurrent<AstBranch>();
    auto last = branch->Last();

    auto indent = ctx->indent();
    auto retVal = visitIndent(indent);

    setCurrent(last);
    addIndentation();

    auto any = visitChildrenExcept(ctx, indent);
    
    revertIndentation();
    revertCurrent();
    return any;
}

antlrcpp::Any AstNodeBuilder::visitStatement_elseif(zsharp_parserParser::Statement_elseifContext* ctx)
{
    auto branch = findCurrent<AstBranch>();
    auto subBr = std::make_shared<AstBranch>(ctx);
    branch->AddSubBranch(subBr);

    auto indent = ctx->indent();
    auto retVal = visitIndent(indent);

    addIndentation();

    auto any = visitChildrenExcept(ctx, indent);
    
    revertIndentation();
    return any;
}

antlrcpp::Any AstNodeBuilder::visitStatement_return(zsharp_parserParser::Statement_returnContext* ctx)
{
    auto codeBlock = findCurrent<AstCodeBlock>();
    auto branch = std::make_shared<AstBranch>(ctx);
    bool success = codeBlock->AddItem(branch);
    guard(success);

    setCurrent(branch);

    auto any = base::visitChildren(ctx);

    revertCurrent();
    return any;
}

antlrcpp::Any AstNodeBuilder::visitStatement_break(zsharp_parserParser::Statement_breakContext* ctx)
{
    auto codeBlock = findCurrent<AstCodeBlock>();
    auto branch = std::make_shared<AstBranch>(ctx);
    bool success = codeBlock->AddItem(branch);
    guard(success);

    return visitChildren(ctx);
}

antlrcpp::Any AstNodeBuilder::visitStatement_continue(zsharp_parserParser::Statement_continueContext* ctx)
{
    auto codeBlock = findCurrent<AstCodeBlock>();
    auto branch = std::make_shared<AstBranch>(ctx);
    bool success = codeBlock->AddItem(branch);
    guard(success);

    return visitChildren(ctx);
}

antlrcpp::Any AstNodeBuilder::visitVariable_assign(zsharp_parserParser::Variable_assignContext* ctx)
{
    auto codeBlock = findCurrent<AstCodeBlock>();
    auto assign = std::make_shared<AstAssignment>(ctx);
    bool success = codeBlock->AddItem(assign);
    guard(success);

    setCurrent(assign);

    auto any = visitChildren(ctx);

    revertCurrent();
    return any;
}

antlrcpp::Any AstNodeBuilder::visitExpression_value(zsharp_parserParser::Expression_valueContext* ctx)
{
    AstExpressionBuilder builder;
    auto expr = builder.Build(ctx);
    
    auto site = findCurrent<AstExpressionSite>();
    bool success = site->AddExpression(expr);
    guard(success);

    return nullptr;
}

antlrcpp::Any AstNodeBuilder::visitIndent(zsharp_parserParser::IndentContext* ctx)
{
    // ignore indents that appear at the end of a line
    if (dynamic_cast<zsharp_parserParser::NewlineContext*>(ctx->parent) ||
        dynamic_cast<zsharp_parserParser::Empty_lineContext*>(ctx->parent) ||
        dynamic_cast<zsharp_parserParser::CommentContext*>(ctx->parent) ) {
        return 0;
    }

    auto indent = ctx->getText().length();
    assert(std::numeric_limits<int>::max() > indent);

    if (_indent == 0) {
        _indent = (int)indent;

        if (_indentation.size() == 1) {
            _indentation.pop(); // remove placeholder
            _indentation.push(_indent);
        }

        assert(_indentation.size() <= 1);
    }

    if (indent != _indentation.top()) {
        auto err = std::make_shared<AstError>(ctx);
        err->setText(AstError::IndentationMismatch);
        _errors.push_back(err);
    }

    return nullptr;
}

void AstNodeBuilder::addIndentation()
{
    if (_indentation.size() > 0) {
        _indentation.push(_indentation.top() + _indent);
    }
    else {
        _indentation.push(_indent);
    }
}