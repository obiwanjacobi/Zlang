#pragma once

#include "AstExpression.h"

#include "../grammar/parser/zsharp_parserBaseVisitor.h"
#include "../grammar/parser/zsharp_parserParser.h"
#include <antlr4-runtime.h>

// implements shunting-yard algorithm
class AstExpressionBuilder : protected zsharp_parserBaseVisitor
{
    typedef zsharp_parserBaseVisitor base;

public:
    std::shared_ptr<AstExpression> Build(zsharp_parserParser::Expression_valueContext* expressionCtx) {
        auto val = visitExpression_value(expressionCtx);
        assert(val.isNull());

        return BuildExpression(0);
    }

    std::shared_ptr<AstExpression> Test(antlr4::ParserRuleContext* ctx) {
        auto val = visit(ctx);
        assert(val.isNull());

        return BuildExpression(0);
    }

protected:
    antlrcpp::Any aggregateResult(antlrcpp::Any aggregate, const antlrcpp::Any& nextResult) override;

    // expressions
    antlrcpp::Any visitExpression_value(zsharp_parserParser::Expression_valueContext* ctx) override;
    antlrcpp::Any visitExpression_arithmetic(zsharp_parserParser::Expression_arithmeticContext* ctx) override;
    antlrcpp::Any visitExpression_logic(zsharp_parserParser::Expression_logicContext* ctx) override;
    antlrcpp::Any visitExpression_comparison(zsharp_parserParser::Expression_comparisonContext* ctx) override;
    
    // operands
    antlrcpp::Any visitLiteral_bool(zsharp_parserParser::Literal_boolContext* ctx) override;
    antlrcpp::Any visitIdentifier_bool(zsharp_parserParser::Identifier_boolContext* ctx) override;
    antlrcpp::Any visitFunction_call(zsharp_parserParser::Function_callContext* ctx) override;
    antlrcpp::Any visitVariable_ref(zsharp_parserParser::Variable_refContext* ctx) override;
    antlrcpp::Any visitNumber(zsharp_parserParser::NumberContext* ctx) override;

    // operators
    antlrcpp::Any visitOperator_arithmetic(zsharp_parserParser::Operator_arithmeticContext* ctx) override;
    antlrcpp::Any visitOperator_arithmetic_unary(zsharp_parserParser::Operator_arithmetic_unaryContext* ctx) override;
    antlrcpp::Any visitOperator_logic(zsharp_parserParser::Operator_logicContext* ctx) override;
    antlrcpp::Any visitOperator_logic_unary(zsharp_parserParser::Operator_logic_unaryContext* ctx) override;
    antlrcpp::Any visitOperator_comparison(zsharp_parserParser::Operator_comparisonContext* ctx) override;
    antlrcpp::Any visitOperator_bits(zsharp_parserParser::Operator_bitsContext* ctx) override;
    antlrcpp::Any visitOperator_bits_unary(zsharp_parserParser::Operator_bits_unaryContext* ctx) override;

private:
    template<class T> antlrcpp::Any ProcessExpression(T ctx);
    std::shared_ptr<AstExpression> BuildExpression(size_t stopAtCount);
    std::shared_ptr<AstExpression> PopExpression();
    void AddOperand(std::shared_ptr<AstExpression> expr) {
        auto operand = std::make_shared<AstExpressionOperand>(expr);
        _values.push(operand);
    }

    std::stack<std::shared_ptr<AstExpressionOperand>> _values;
    std::stack<std::shared_ptr<AstExpression>> _operators;
};

