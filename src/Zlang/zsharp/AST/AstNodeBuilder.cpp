#include "AstNodeBuilder.h"
#include "AstFile.h"
#include "AstBranch.h"
#include "AstFunction.h"
#include "AstExpressionBuilder.h"
#include "../grammar/parser/zsharp_parserParser.h"
#include "../../Utils.h"

bool isEmpty(antlr4::ParserRuleContext* ctx) {
    return ctx->children.size() == 0;
}

template <class T> 
T AstNodeBuilder::getCurrent()
{
    T p = nullptr;

    for (auto c : _current) {
        p = dynamic_cast<T>(c);
        if (p) {
            break;
        }
    }

    guard(p != nullptr);
    return p;
}

std::string AstNodeBuilder::ToQualifiedName(const std::string& name)
{
    if (_namespace.size() > 0) {
        return _namespace + "." + name;
    }
    return name;
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

    auto any = base::visitFile(ctx);

    revertCurrent();
    guard(_current.size() == 0);

    return file;
}

antlrcpp::Any AstNodeBuilder::visitStatement_import(zsharp_parserParser::Statement_importContext* ctx)
{
    auto file = getCurrent<AstFile*>();
    file->AddImport(ctx);

    return nullptr;
}

antlrcpp::Any AstNodeBuilder::visitStatement_export(zsharp_parserParser::Statement_exportContext* ctx)
{
    auto file = getCurrent<AstFile*>();
    file->AddExport(ctx);

    return nullptr;
}

antlrcpp::Any AstNodeBuilder::visitFunction_def(zsharp_parserParser::Function_defContext* ctx)
{
    auto file = getCurrent<AstFile*>();
    auto function = std::make_shared<AstFunction>(ctx);        
    function->setName(ToQualifiedName(ctx->identifier_func()->getText()));

    file->AddFunction(function);
    setCurrent(function);

    auto any = base::visitChildren(ctx);

    revertCurrent();
    return any;
}

antlrcpp::Any AstNodeBuilder::visitCodeblock(zsharp_parserParser::CodeblockContext* ctx)
{
    if (isEmpty(ctx)) {
        auto err = std::make_shared<AstError>(ctx);
        err->setText("Empty Code Block");
        _errors.push_back(err);
        return nullptr;
    }

    auto site = getCurrent<AstCodeBlockSite*>();
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
    auto codeBlock = getCurrent<AstCodeBlock*>();
    auto branch = std::make_shared<AstBranch>(ctx);
    bool success = codeBlock->AddItem(branch);
    guard(success);

    setCurrent(branch);

    auto any = base::visitChildren(ctx);

    revertCurrent();
    return any;
}

antlrcpp::Any AstNodeBuilder::visitStatement_else(zsharp_parserParser::Statement_elseContext* ctx)
{
    auto branch = getCurrent<AstBranch*>();
    auto last = branch->Last();
    setCurrent(last);

    auto any = base::visitChildren(ctx);
    
    revertCurrent();
    return any;
}

antlrcpp::Any AstNodeBuilder::visitStatement_elseif(zsharp_parserParser::Statement_elseifContext* ctx)
{
    auto branch = getCurrent<AstBranch*>();
    auto subBr = std::make_shared<AstBranch>(ctx);
    branch->AddSubBranch(subBr);

    auto any = base::visitChildren(ctx);
    
    return any;
}

antlrcpp::Any AstNodeBuilder::visitStatement_return(zsharp_parserParser::Statement_returnContext* ctx)
{
    auto codeBlock = getCurrent<AstCodeBlock*>();
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
    auto codeBlock = getCurrent<AstCodeBlock*>();
    auto branch = std::make_shared<AstBranch>(ctx);
    bool success = codeBlock->AddItem(branch);
    guard(success);
    return visitChildren(ctx);
}

antlrcpp::Any AstNodeBuilder::visitStatement_continue(zsharp_parserParser::Statement_continueContext* ctx)
{
    auto codeBlock = getCurrent<AstCodeBlock*>();
    auto branch = std::make_shared<AstBranch>(ctx);
    bool success = codeBlock->AddItem(branch);
    guard(success);
    return visitChildren(ctx);
}

antlrcpp::Any AstNodeBuilder::visitExpression_value(zsharp_parserParser::Expression_valueContext* ctx)
{
    AstExpressionBuilder builder;
    auto expr = builder.Build(ctx);
    
    auto site = getCurrent<AstExpressionSite*>();
    bool success = site->AddExpression(expr);
    guard(success);

    return nullptr;
}
