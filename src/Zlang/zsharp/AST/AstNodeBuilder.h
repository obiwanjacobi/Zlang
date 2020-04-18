#pragma once

#include "AstNode.h"
#include "AstError.h"
#include "AstCodeBlock.h"
#include "AstBuilderContext.h"
#include "../grammar/parser/zsharp_parserBaseVisitor.h"
#include <antlr4-runtime.h>

class AstNodeBuilder : public zsharp_parserBaseVisitor, private AstBuilderContext
{
    typedef zsharp_parserBaseVisitor base;

public:
    AstNodeBuilder(std::string ns, int defaultIndentation = 0)
        : AstBuilderContext(defaultIndentation), _namespace(ns)
    {}

    antlrcpp::Any aggregateResult(antlrcpp::Any aggregate, const antlrcpp::Any& nextResult) override;

    antlrcpp::Any visitFile(zsharp_parserParser::FileContext* ctx) override;
    antlrcpp::Any visitStatement_import(zsharp_parserParser::Statement_importContext* ctx) override;
    antlrcpp::Any visitStatement_export(zsharp_parserParser::Statement_exportContext* ctx) override;

    antlrcpp::Any visitFunction_def(zsharp_parserParser::Function_defContext* ctx) override;
    antlrcpp::Any visitCodeblock(zsharp_parserParser::CodeblockContext* ctx) override;

    antlrcpp::Any visitStatement_if(zsharp_parserParser::Statement_ifContext* ctx) override;
    antlrcpp::Any visitStatement_else(zsharp_parserParser::Statement_elseContext* ctx) override;
    antlrcpp::Any visitStatement_elseif(zsharp_parserParser::Statement_elseifContext* ctx) override;
    antlrcpp::Any visitStatement_return(zsharp_parserParser::Statement_returnContext* ctx) override;
    antlrcpp::Any visitStatement_break(zsharp_parserParser::Statement_breakContext* ctx) override;
    antlrcpp::Any visitStatement_continue(zsharp_parserParser::Statement_continueContext* ctx) override;

    antlrcpp::Any visitIdentifier_type(zsharp_parserParser::Identifier_typeContext* ctx) override;
    antlrcpp::Any visitIdentifier_var(zsharp_parserParser::Identifier_varContext* ctx) override;
    antlrcpp::Any visitIdentifier_param(zsharp_parserParser::Identifier_paramContext* ctx) override;
    antlrcpp::Any visitIdentifier_func(zsharp_parserParser::Identifier_funcContext* ctx) override;
    antlrcpp::Any visitIdentifier_field(zsharp_parserParser::Identifier_fieldContext* ctx) override;
    antlrcpp::Any visitIdentifier_enumoption(zsharp_parserParser::Identifier_enumoptionContext* ctx) override;

    antlrcpp::Any visitFunction_parameter(zsharp_parserParser::Function_parameterContext* ctx) override;
    antlrcpp::Any visitFunction_parameter_self(zsharp_parserParser::Function_parameter_selfContext* ctx) override;

    antlrcpp::Any visitVariable_assign(zsharp_parserParser::Variable_assignContext* ctx) override;
    antlrcpp::Any visitVariable_assign_auto(zsharp_parserParser::Variable_assign_autoContext* ctx) override;
    antlrcpp::Any visitVariable_def(zsharp_parserParser::Variable_defContext* ctx) override;
    antlrcpp::Any visitVariable_def_typed(zsharp_parserParser::Variable_def_typedContext* ctx) override;
    antlrcpp::Any visitVariable_def_typed_init(zsharp_parserParser::Variable_def_typed_initContext* ctx) override;

    antlrcpp::Any visitExpression_value(zsharp_parserParser::Expression_valueContext* ctx) override;
    antlrcpp::Any visitExpression_logic(zsharp_parserParser::Expression_logicContext* ctx) override;

    antlrcpp::Any visitType_ref(zsharp_parserParser::Type_refContext* ctx) override;


    bool hasErrors() const { return AstBuilderContext::hasErrors(); }
    const std::vector<std::shared_ptr<AstError>>& getErrors() const { return AstBuilderContext::getErrors(); }

protected:
    antlrcpp::Any visitChildrenExcept(antlr4::ParserRuleContext* node, const antlr4::ParserRuleContext* except);

private:
    std::string _namespace;
};
