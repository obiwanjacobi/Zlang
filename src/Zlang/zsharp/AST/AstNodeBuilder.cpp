#include "AstNodeBuilder.h"
#include "AstFile.h"
#include "AstAssignment.h"
#include "AstBranch.h"
#include "AstFunction.h"
#include "AstIdentifier.h"
#include "AstExpressionBuilder.h"
#include "../grammar/parser/zsharp_parserParser.h"
#include "../../Utils.h"

bool isEmpty(const antlr4::ParserRuleContext* ctx) {
    return ctx->children.size() == 0;
}

AstCodeBlock* AstNodeBuilder::findCodeBlock(uint32_t indent) const
{
    AstCodeBlock* p = nullptr;

    for (auto c : _current) {
        p = dynamic_cast<AstCodeBlock*>(c);
        if (p && p->getIndent() == indent) {
            break;
        }
    }

    guard(p != nullptr);
    return p;
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

std::shared_ptr<AstError> AstNodeBuilder::AddError(antlr4::ParserRuleContext* ctx, const char* text)
{
    auto error = std::make_shared<AstError>(ctx);
    error->setText(text);
    _errors.push_back(error);
    return error;
}

antlrcpp::Any AstNodeBuilder::visitChildrenExcept(antlr4::ParserRuleContext* node, const antlr4::ParserRuleContext* except)
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

    auto entry = file->SetSymbol(ctx->module_name()->getText(), "", AstSymbolType::NotSet, nullptr);
    entry->setSymbolLocality(AstSymbolLocality::Imported);

    return nullptr;
}

antlrcpp::Any AstNodeBuilder::visitStatement_export(zsharp_parserParser::Statement_exportContext* ctx)
{
    auto file = findCurrent<AstFile>();
    file->AddExport(ctx);

    auto entry = file->SetSymbol(_namespace, ctx->identifier_func()->getText(), AstSymbolType::Function, nullptr);
    entry->setSymbolLocality(AstSymbolLocality::Exported);

    return nullptr;
}

antlrcpp::Any AstNodeBuilder::visitFunction_def(zsharp_parserParser::Function_defContext* ctx)
{
    auto file = findCurrent<AstFile>();
    auto function = std::make_shared<AstFunction>(ctx);
    
    file->AddFunction(function);
    setCurrent(function);

    // process identifier first (needed for symbol)
    auto identifier = ctx->identifier_func();
    auto dummy = visitIdentifier_func(identifier);

    auto entry = file->SetSymbol(_namespace, function->getIdentifier()->getName(), AstSymbolType::Function, function);

    if (dynamic_cast<zsharp_parserParser::Function_def_exportContext*>(ctx->parent)) {
        entry->setSymbolLocality(AstSymbolLocality::Exported);
    }

    auto any = visitChildrenExcept(ctx, identifier);

    revertCurrent();
    return any;
}

antlrcpp::Any AstNodeBuilder::visitCodeblock(zsharp_parserParser::CodeblockContext* ctx)
{
    if (isEmpty(ctx)) {
        AddError(ctx, AstError::EmptyCodeBlock);
        return nullptr;
    }

    auto stSite = findCurrent<AstSymbolTableSite>();
    auto codeBlock = std::make_shared<AstCodeBlock>(stSite->getSymbols(), ctx);
    
    auto cbSite = findCurrent<AstCodeBlockSite>();
    bool success = cbSite->AddCodeBlock(codeBlock);
    guard(success);

    setCurrent(codeBlock);
    
    auto any = base::visitChildren(ctx);

    revertCurrent();
    return any;
}

antlrcpp::Any AstNodeBuilder::visitStatement_if(zsharp_parserParser::Statement_ifContext* ctx)
{
    auto indent = getIndent(ctx);
    auto codeBlock = findCodeBlock(indent);
    auto branch = std::make_shared<AstBranch>(ctx);
    bool success = codeBlock->AddItem(branch);
    guard(success);
    guard(indent == branch->getIndent());

    setCurrent(branch);

    auto any = visitChildren(ctx);

    revertCurrent();
    return any;
}

antlrcpp::Any AstNodeBuilder::visitStatement_else(zsharp_parserParser::Statement_elseContext* ctx)
{
    auto branch = findCurrent<AstBranch>();
    auto last = branch->Last();

    setCurrent(last);

    auto any = visitChildren(ctx);
    
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

    auto any = visitChildrenExcept(ctx, indent);
    
    return any;
}

antlrcpp::Any AstNodeBuilder::visitStatement_return(zsharp_parserParser::Statement_returnContext* ctx)
{
    auto indent = getIndent(ctx);
    auto codeBlock = findCodeBlock(indent);
    auto branch = std::make_shared<AstBranch>(ctx);
    bool success = codeBlock->AddItem(branch);
    guard(success);
    guard(indent == branch->getIndent());

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


template<class T>
bool AstNodeBuilder::AddIdentifier(T ctx)
{
    auto namedObj = findCurrent<AstIdentifierSite>();
    if (namedObj) {
        auto identifier = std::make_shared<AstIdentifier>(ctx);
        return namedObj->AddIdentifier(identifier);
    }
    return false;
}

antlrcpp::Any AstNodeBuilder::visitIdentifier_bool(zsharp_parserParser::Identifier_boolContext* ctx)
{
    bool success = AddIdentifier(ctx);
    guard(success);

    return visitChildren(ctx);
}

antlrcpp::Any AstNodeBuilder::visitIdentifier_type(zsharp_parserParser::Identifier_typeContext* ctx)
{
    bool success = AddIdentifier(ctx);
    guard(success);

    return visitChildren(ctx);
}

antlrcpp::Any AstNodeBuilder::visitIdentifier_var(zsharp_parserParser::Identifier_varContext* ctx)
{
    bool success = AddIdentifier(ctx);
    guard(success);

    return visitChildren(ctx);
}

antlrcpp::Any AstNodeBuilder::visitIdentifier_param(zsharp_parserParser::Identifier_paramContext* ctx)
{
    bool success = AddIdentifier(ctx);
    guard(success);

    return visitChildren(ctx);
}

antlrcpp::Any AstNodeBuilder::visitIdentifier_func(zsharp_parserParser::Identifier_funcContext* ctx)
{
    bool success = AddIdentifier(ctx);
    guard(success);

    return visitChildren(ctx);
}

antlrcpp::Any AstNodeBuilder::visitIdentifier_field(zsharp_parserParser::Identifier_fieldContext* ctx)
{
    bool success = AddIdentifier(ctx);
    guard(success);

    return visitChildren(ctx);
}

antlrcpp::Any AstNodeBuilder::visitIdentifier_enumoption(zsharp_parserParser::Identifier_enumoptionContext* ctx)
{
    bool success = AddIdentifier(ctx);
    guard(success);

    return visitChildren(ctx);
}

antlrcpp::Any AstNodeBuilder::visitFunction_parameter(zsharp_parserParser::Function_parameterContext* ctx) {
    auto function = findCurrent<AstFunction>();
    auto funcParam = std::make_shared<AstFunctionParameter>(ctx);
    function->AddParameter(funcParam);

    setCurrent(funcParam);
    
    auto any = visitChildren(ctx);
    
    revertCurrent();
    return any;
}

antlrcpp::Any AstNodeBuilder::visitFunction_parameter_self(zsharp_parserParser::Function_parameter_selfContext* ctx) {
    auto function = findCurrent<AstFunction>();
    auto funcParam = std::make_shared<AstFunctionParameter>(ctx);
    function->AddParameter(funcParam);

    setCurrent(funcParam);

    auto any = visitChildren(ctx);

    revertCurrent();
    return any;
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

    auto symbols = findCurrent<AstSymbolTableSite>();
    auto entry = symbols->SetSymbol(_namespace, assign->getIdentifier()->getName(), AstSymbolType::Variable, assign);

    return any;
}

antlrcpp::Any AstNodeBuilder::visitExpression_value(zsharp_parserParser::Expression_valueContext* ctx)
{
    AstExpressionBuilder builder;
    auto expr = builder.Build(ctx);
    if (expr != nullptr)
    {
        auto site = findCurrent<AstExpressionSite>();
        bool success = site->AddExpression(expr);
        guard(success);
    }
    return nullptr;
}

antlrcpp::Any AstNodeBuilder::visitExpression_logic(zsharp_parserParser::Expression_logicContext* ctx) {
    AstExpressionBuilder builder;
    auto expr = builder.Build(ctx);
    if (expr != nullptr)
    {
        auto site = findCurrent<AstExpressionSite>();
        bool success = site->AddExpression(expr);
        guard(success);
    }
    return nullptr;
}

antlrcpp::Any AstNodeBuilder::visitIndent(zsharp_parserParser::IndentContext* ctx)
{
    auto indent = ctx->getText().length();
    assert(std::numeric_limits<int>::max() > indent);

    if (_indent == 0) {
        _indent = indent;
    }

    if (indent % _indent)
    {
        AddError(ctx, AstError::IndentationMismatch);
    }
    return indent / _indent;
}
