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
    //guard(!hasCurrent());

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
    guard(success && "AddFunction() failed");

    setCurrent(function);

    // process identifier first (needed for symbol)
    auto identifier = ctx->identifier_func();
    auto dummy = visitIdentifier_func(identifier);

    auto symbolTable = GetCurrent<AstSymbolTableSite>();
    auto entry = symbolTable->AddSymbol(function->getIdentifier()->getName(), AstSymbolKind::Function, function);

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
    guard(success && "SetCodeBlock() failed");

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
    guard(success && "AddCodeBlockItem() failed");

    setCurrent(branch);

    auto any = visitChildren(ctx);

    revertCurrent();
    return any;
}

antlrcpp::Any AstNodeBuilder::visitStatement_else(zsharp_parserParser::Statement_elseContext* ctx)
{
    auto indent = CheckIndent(ctx);
    auto branch = GetCurrent<AstBranchConditional>();
    guard(indent == branch->getIndent() && "Indentation mismatch CodeBlock <=> Branch");

    auto subBr = std::make_shared<AstBranchConditional>(ctx);
    bool success = branch->AddSubBranch(subBr);
    guard(success && "AddSubBranch() failed");

    setCurrent(subBr);

    auto any = visitChildren(ctx);
    
    revertCurrent();
    return any;
}

antlrcpp::Any AstNodeBuilder::visitStatement_elseif(zsharp_parserParser::Statement_elseifContext* ctx)
{
    auto indent = CheckIndent(ctx);
    auto branch = GetCurrent<AstBranchConditional>();
    guard(indent == branch->getIndent() && "Indentation mismatch CodeBlock <=> Branch");

    auto subBr = std::make_shared<AstBranchConditional>(ctx);
    bool success = branch->AddSubBranch(subBr);
    guard(success && "AddSubBranch() failed");

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
    guard(success && "AddCodeBlockItem() failed");

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
    guard(success && "AddCodeBlockItem() failed");

    return visitChildren(ctx);
}

antlrcpp::Any AstNodeBuilder::visitStatement_continue(zsharp_parserParser::Statement_continueContext* ctx)
{
    auto indent = CheckIndent(ctx);
    auto codeBlock = GetCodeBlock(indent);

    auto branch = std::make_shared<AstBranch>(ctx);
    bool success = codeBlock->AddItem(branch);
    guard(success && "AddCodeBlockItem() failed");

    return visitChildren(ctx);
}


antlrcpp::Any AstNodeBuilder::visitIdentifier_type(zsharp_parserParser::Identifier_typeContext* ctx)
{
    bool success = AddIdentifier(ctx);
    guard(success && "AddIdentifier(Type) failed");

    return nullptr;
}

antlrcpp::Any AstNodeBuilder::visitIdentifier_var(zsharp_parserParser::Identifier_varContext* ctx)
{
    bool success = AddIdentifier(ctx);
    guard(success && "AddIdentifier(Variable) failed");

    return nullptr;
}

antlrcpp::Any AstNodeBuilder::visitIdentifier_param(zsharp_parserParser::Identifier_paramContext* ctx)
{
    bool success = AddIdentifier(ctx);
    guard(success && "AddIdentifier(Parameter) failed");

    return nullptr;
}

antlrcpp::Any AstNodeBuilder::visitIdentifier_func(zsharp_parserParser::Identifier_funcContext* ctx)
{
    bool success = AddIdentifier(ctx);
    guard(success && "AddIdentifier(Function) failed");

    return nullptr;
}

antlrcpp::Any AstNodeBuilder::visitIdentifier_field(zsharp_parserParser::Identifier_fieldContext* ctx)
{
    bool success = AddIdentifier(ctx);
    guard(success && "AddIdentifier(Field) failed");

    return nullptr;
}

antlrcpp::Any AstNodeBuilder::visitIdentifier_enumoption(zsharp_parserParser::Identifier_enumoptionContext* ctx)
{
    bool success = AddIdentifier(ctx);
    guard(success && "AddIdentifier(EnumOption) failed");

    return nullptr;
}



antlrcpp::Any AstNodeBuilder::visitFunction_parameter(zsharp_parserParser::Function_parameterContext* ctx) {
    auto funcParam = std::make_shared<AstFunctionParameter>(ctx);
    auto function = GetCurrent<AstFunction>();
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

antlrcpp::Any AstNodeBuilder::visitVariable_def(zsharp_parserParser::Variable_defContext* ctx) {
    auto indent = CheckIndent(ctx);
    auto codeBlock = GetCodeBlock(indent);
    setCurrent(codeBlock);

    auto any = visitChildren(ctx);

    revertCurrent();
    return any;
}

antlrcpp::Any AstNodeBuilder::visitVariable_def_typed(zsharp_parserParser::Variable_def_typedContext* ctx) {
    auto variable = std::make_shared<AstVariableDefinition>(ctx);
    auto codeBlock = GetCodeBlock();
    bool success = codeBlock->AddItem(variable);
    guard(success && "AddCodeBlockItem() failed");
    setCurrent(variable);

    auto any = visitChildren(ctx);

    revertCurrent();

    auto symbols = GetCurrent<AstSymbolTableSite>();
    auto entry = symbols->AddSymbol(variable, AstSymbolKind::Variable, variable);

    return any;
}

antlrcpp::Any AstNodeBuilder::visitVariable_def_typed_init(zsharp_parserParser::Variable_def_typed_initContext* ctx) {
    auto assign = std::make_shared<AstAssignment>(ctx);
    auto codeBlock = GetCodeBlock();
    bool success = codeBlock->AddItem(assign);
    guard(success && "AddCodeBlockItem() failed");
    setCurrent(assign);

    auto variable = std::make_shared<AstVariableDefinition>(ctx);
    success = assign->SetVariable(variable);
    guard(success && "SetVariable() failed");
    setCurrent(variable);

    auto any = visitChildren(ctx);

    revertCurrent();
    revertCurrent();

    auto symbols = GetCurrent<AstSymbolTableSite>();
    auto entry = symbols->AddSymbol(variable, AstSymbolKind::Variable, variable);

    return any;
}

antlrcpp::Any AstNodeBuilder::visitVariable_assign_auto(zsharp_parserParser::Variable_assign_autoContext* ctx)
{
    auto assign = std::make_shared<AstAssignment>(ctx);
    auto codeBlock = GetCodeBlock();
    bool success = codeBlock->AddItem(assign);
    guard(success && "AddCodeBlockItem() failed");
    setCurrent(assign);

    std::shared_ptr<AstVariable> variable;
    if (dynamic_cast<zsharp_parserParser::Variable_assignContext*>(ctx->parent)) {
        variable = std::make_shared<AstVariableReference>(ctx);
    }
    else {
        variable = std::make_shared<AstVariableDefinition>(ctx);
    }

    success = assign->SetVariable(variable);
    guard(success && "SetVariable() failed");
    setCurrent(variable);

    auto any = visitChildren(ctx);

    revertCurrent();
    revertCurrent();

    auto symbols = GetCurrent<AstSymbolTableSite>();
    auto entry = symbols->AddSymbol(variable, AstSymbolKind::Variable, variable);

    return any;
}

antlrcpp::Any AstNodeBuilder::visitVariable_assign(zsharp_parserParser::Variable_assignContext* ctx)
{
    auto indent = CheckIndent(ctx);
    auto codeBlock = GetCodeBlock(indent);
    setCurrent(codeBlock);

    auto any = visitChildren(ctx);

    revertCurrent();
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
        guard(success && "SetExpression() failed");
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
        guard(success && "SetExpression() failed");
    }
    return nullptr;
}

antlrcpp::Any AstNodeBuilder::visitType_ref(zsharp_parserParser::Type_refContext* ctx)
{
    auto type = AstTypeReference::Create(ctx);
    auto trSite = GetCurrent<AstTypeReferenceSite>();
    trSite->SetTypeReference(type);
    return nullptr;
}