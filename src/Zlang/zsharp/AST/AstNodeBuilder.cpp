#include "AstNodeBuilder.h"
#include "AstFile.h"
#include "AstAssignment.h"
#include "AstBranch.h"
#include "AstFunction.h"
#include "AstIdentifier.h"
#include "AstExpressionBuilder.h"
#include "../grammar/parser/zsharp_parserParser.h"
#include "../../Utils.h"
#include "AstType.h"

bool isEmpty(const antlr4::ParserRuleContext* ctx) {
    return ctx->children.size() == 0;
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
    auto file = std::make_shared<AstFile>(_namespace, ctx);
    setCurrent(file);

    auto any = base::visitChildren(ctx);

    revertCurrent();
    //guard(_current.size() == 0);

    return file;
}

antlrcpp::Any AstNodeBuilder::visitStatement_import(zsharp_parserParser::Statement_importContext* ctx)
{
    auto file = GetCurrent<AstFile>();
    file->AddImport(ctx);

    auto entry = file->AddSymbol(ctx->module_name()->getText(), AstSymbolKind::NotSet, nullptr);
    entry->setSymbolLocality(AstSymbolLocality::Imported);

    return nullptr;
}

antlrcpp::Any AstNodeBuilder::visitStatement_export(zsharp_parserParser::Statement_exportContext* ctx)
{
    auto file = GetCurrent<AstFile>();
    file->AddExport(ctx);

    auto entry = file->AddSymbol(ctx->identifier_func()->getText(), AstSymbolKind::Function, nullptr);
    entry->setSymbolLocality(AstSymbolLocality::Exported);

    return nullptr;
}

antlrcpp::Any AstNodeBuilder::visitFunction_def(zsharp_parserParser::Function_defContext* ctx)
{
    auto file = GetCurrent<AstFile>();
    auto function = std::make_shared<AstFunction>(ctx);
    
    bool success = file->AddFunction(function);
    guard(success);

    setCurrent(function);

    // process identifier first (needed for symbol)
    auto identifier = ctx->identifier_func();
    auto dummy = visitIdentifier_func(identifier);

    auto entry = file->AddSymbol(function->getIdentifier()->getName(), AstSymbolKind::Function, function);

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
    
    auto stSite = GetCurrent<AstSymbolTableSite>();
    auto symbols = stSite->getSymbols();
    std::string scopeName = symbols->getNamespace();

    auto cbSite = GetCurrent<AstCodeBlockSite>();
    auto parent = dynamic_cast<AstFunction*>(cbSite);
    if (parent) { 
        scopeName = parent->getIdentifier()->getName();
    }

    auto codeBlock = std::make_shared<AstCodeBlock>(scopeName, symbols, ctx);
    bool success = cbSite->SetCodeBlock(codeBlock);
    guard(success);

    setCurrent(codeBlock);
    
    auto any = base::visitChildren(ctx);

    revertCurrent();
    return any;
}

antlrcpp::Any AstNodeBuilder::visitStatement_if(zsharp_parserParser::Statement_ifContext* ctx)
{
    auto indent = CheckIndent(ctx);
    auto codeBlock = GetCodeBlock(indent);

    auto branch = std::make_shared<AstBranchConditional>(ctx);
    bool success = codeBlock->AddItem(branch);
    guard(success);

    setCurrent(branch);

    auto any = visitChildren(ctx);

    revertCurrent();
    return any;
}

antlrcpp::Any AstNodeBuilder::visitStatement_else(zsharp_parserParser::Statement_elseContext* ctx)
{
    auto indent = CheckIndent(ctx);
    auto branch = GetCurrent<AstBranchConditional>();
    guard(indent == branch->getIndent());

    auto subBr = std::make_shared<AstBranchConditional>(ctx);
    bool success = branch->AddSubBranch(subBr);
    guard(success);

    setCurrent(subBr);

    auto any = visitChildren(ctx);
    
    revertCurrent();
    return any;
}

antlrcpp::Any AstNodeBuilder::visitStatement_elseif(zsharp_parserParser::Statement_elseifContext* ctx)
{
    auto indent = CheckIndent(ctx);
    auto branch = GetCurrent<AstBranchConditional>();
    guard(indent == branch->getIndent());

    auto subBr = std::make_shared<AstBranchConditional>(ctx);
    bool success = branch->AddSubBranch(subBr);
    guard(success);

    setCurrent(subBr);

    auto any = visitChildren(ctx);
    
    revertCurrent();
    return any;
}

antlrcpp::Any AstNodeBuilder::visitStatement_return(zsharp_parserParser::Statement_returnContext* ctx)
{
    auto indent = CheckIndent(ctx);
    auto codeBlock = GetCodeBlock(indent);

    auto branch = std::make_shared<AstBranchExpression>(ctx);
    bool success = codeBlock->AddItem(branch);
    guard(success);

    setCurrent(branch);

    auto any = base::visitChildren(ctx);

    revertCurrent();
    return any;
}

antlrcpp::Any AstNodeBuilder::visitStatement_break(zsharp_parserParser::Statement_breakContext* ctx)
{
    auto indent = CheckIndent(ctx);
    auto codeBlock = GetCodeBlock(indent);

    auto branch = std::make_shared<AstBranch>(ctx);
    bool success = codeBlock->AddItem(branch);
    guard(success);

    return visitChildren(ctx);
}

antlrcpp::Any AstNodeBuilder::visitStatement_continue(zsharp_parserParser::Statement_continueContext* ctx)
{
    auto indent = CheckIndent(ctx);
    auto codeBlock = GetCodeBlock(indent);

    auto branch = std::make_shared<AstBranch>(ctx);
    bool success = codeBlock->AddItem(branch);
    guard(success);

    return visitChildren(ctx);
}


template<class T>
bool AstNodeBuilder::AddIdentifier(T ctx)
{
    auto namedObj = GetCurrent<AstIdentifierSite>();
    if (namedObj) {
        auto identifier = std::make_shared<AstIdentifier>(ctx);
        return namedObj->SetIdentifier(identifier);
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
    auto function = GetCurrent<AstFunction>();
    auto funcParam = std::make_shared<AstFunctionParameter>(ctx);
    function->AddParameter(funcParam);

    setCurrent(funcParam);
    
    auto any = visitChildren(ctx);
    
    revertCurrent();
    return any;
}

antlrcpp::Any AstNodeBuilder::visitFunction_parameter_self(zsharp_parserParser::Function_parameter_selfContext* ctx) {
    auto function = GetCurrent<AstFunction>();
    auto funcParam = std::make_shared<AstFunctionParameter>(ctx);
    funcParam->SetIdentifier(std::make_shared<AstIdentifierIntrinsic>("self", AstIdentifierType::Parameter));
    function->AddParameter(funcParam);

    setCurrent(funcParam);

    auto any = visitChildren(ctx);

    revertCurrent();
    return any;
}



antlrcpp::Any AstNodeBuilder::visitVariable_assign(zsharp_parserParser::Variable_assignContext* ctx)
{
    auto indent = CheckIndent(ctx);
    auto codeBlock = GetCodeBlock(indent);

    auto assign = std::make_shared<AstAssignment>(ctx);
    bool success = codeBlock->AddItem(assign);
    guard(success);

    setCurrent(assign);

    auto any = visitChildren(ctx);

    revertCurrent();

    auto symbols = GetCurrent<AstSymbolTableSite>();
    auto entry = symbols->AddSymbol(assign->getIdentifier()->getName(), AstSymbolKind::Variable, assign);

    return any;
}

antlrcpp::Any AstNodeBuilder::visitExpression_value(zsharp_parserParser::Expression_valueContext* ctx)
{
    AstExpressionBuilder builder(this);
    auto expr = builder.Build(ctx);
    if (expr != nullptr)
    {
        auto site = GetCurrent<AstExpressionSite>();
        bool success = site->SetExpression(expr);
        guard(success);
    }
    return nullptr;
}

antlrcpp::Any AstNodeBuilder::visitExpression_logic(zsharp_parserParser::Expression_logicContext* ctx) {
    AstExpressionBuilder builder(this);
    auto expr = builder.Build(ctx);
    if (expr != nullptr)
    {
        auto site = GetCurrent<AstExpressionSite>();
        bool success = site->SetExpression(expr);
        guard(success);
    }
    return nullptr;
}

antlrcpp::Any AstNodeBuilder::visitType_ref(zsharp_parserParser::Type_refContext* ctx)
{
    auto trSite = GetCurrent<AstTypeReferenceSite>();
    guard(trSite);

    auto type = AstTypeReference::Create(ctx);
    trSite->SetTypeReference(type);
    
    return nullptr;
}