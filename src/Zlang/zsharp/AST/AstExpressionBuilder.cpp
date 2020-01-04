#include "AstExpressionBuilder.h"
#include "AstNumericBuilder.h"

std::shared_ptr<AstExpression> AstExpressionBuilder::PopExpression() {
    std::shared_ptr<AstExpression> expr = _operators.top();
    _operators.pop();

    if (expr->Add(_values.top())) {
        _values.top()->setParent(expr.get());
        _values.pop();
    }
    if (expr->Add(_values.top())) {
        _values.top()->setParent(expr.get());
        _values.pop();
    }

    return expr;
}

std::shared_ptr<AstExpression> AstExpressionBuilder::BuildExpression(size_t stopAtCount)
{
    std::shared_ptr<AstExpression> expr;

    while (_operators.size() > stopAtCount) {
        expr = PopExpression();

        if (_operators.size() > stopAtCount) {
            AddOperand(expr);
        }
    }

    return expr;
}

antlrcpp::Any AstExpressionBuilder::aggregateResult(antlrcpp::Any aggregate, const antlrcpp::Any& nextResult)
{
    if (nextResult.isNull()) {
        return aggregate;
    }
    return nextResult;
}

antlrcpp::Any AstExpressionBuilder::visitExpression_arithmetic(zsharp_parserParser::Expression_arithmeticContext* ctx) {
    
    auto operatorPosition = _operators.size();
    
    for (auto child : ctx->children) {
        auto retVal = child->accept(this);

        if (retVal.is<AstExpressionOperator>()) {
            // there is an extra expression node with just the operand.
            // return its value and be done.
            if (ctx->arithmetic_operand() != nullptr) {
                return retVal;
            }

            auto op = retVal.as<AstExpressionOperator>();
            if (op != AstExpressionOperator::NotSet) {
                
                auto expr = std::make_shared<AstExpression>(ctx);
                expr->setOperator(op);

                if (_operators.size() > 0) {
                    auto lowerOp = _operators.top();

                    if (lowerOp->getPrecedence() > expr->getPrecedence()) {
                        auto popExpr = PopExpression();
                        assert(lowerOp == popExpr);

                        AddOperand(popExpr);
                    }
                }
                _operators.push(expr);
            }
        }
        else if (retVal.is<std::shared_ptr<AstExpressionOperand>>()){
            _values.push(retVal.as<std::shared_ptr<AstExpressionOperand>>());
        }
    }

    if (ctx->PARENclose() != nullptr) {
        auto expr = BuildExpression(operatorPosition);
        AddOperand(expr);
    }

    return nullptr;
}

antlrcpp::Any AstExpressionBuilder::visitNumber(zsharp_parserParser::NumberContext* ctx) {
    AstNumericBuilder builder;
    auto numeric = builder.Build(ctx);
    auto operand = std::make_shared<AstExpressionOperand>(numeric);   
    return operand;
}

antlrcpp::Any AstExpressionBuilder::visitOperator_arithmetic(zsharp_parserParser::Operator_arithmeticContext* ctx) {
    if (ctx->DIV() != nullptr) return AstExpressionOperator::Divide;
    if (ctx->MINUS_NEG() != nullptr) return AstExpressionOperator::Minus;
    if (ctx->MOD() != nullptr) return AstExpressionOperator::Modulo;
    if (ctx->MULT() != nullptr) return AstExpressionOperator::Multiply;
    if (ctx->PLUS() != nullptr) return AstExpressionOperator::Plus;
    if (ctx->POW() != nullptr) return AstExpressionOperator::Power;
    return AstExpressionOperator::NotSet;
}

antlrcpp::Any AstExpressionBuilder::visitOperator_arithmetic_unary(zsharp_parserParser::Operator_arithmetic_unaryContext* ctx) {
    if (ctx->MINUS_NEG() != nullptr) return AstExpressionOperator::Negate;
    return AstExpressionOperator::NotSet;
}

antlrcpp::Any AstExpressionBuilder::visitOperator_logic(zsharp_parserParser::Operator_logicContext* ctx) {
    if (ctx->AND() != nullptr) return AstExpressionOperator::And;
    if (ctx->OR() != nullptr) return AstExpressionOperator::Or;
    return AstExpressionOperator::NotSet;
}

antlrcpp::Any AstExpressionBuilder::visitOperator_logic_unary(zsharp_parserParser::Operator_logic_unaryContext* ctx) {
    if (ctx->NOT() != nullptr) return AstExpressionOperator::Not;
    return AstExpressionOperator::NotSet;
}

antlrcpp::Any AstExpressionBuilder::visitOperator_comparison(zsharp_parserParser::Operator_comparisonContext* ctx) {
    if (ctx->EQ_ASSIGN() != nullptr) return AstExpressionOperator::Equal;
    if (ctx->GREAT_ANGLEclose() != nullptr) return AstExpressionOperator::Greater;
    if (ctx->GREQ() != nullptr) return AstExpressionOperator::GreaterEqual;
    if (ctx->NEQ() != nullptr) return AstExpressionOperator::NotEqual;
    if (ctx->SMALL_ANGLEopen() != nullptr) return AstExpressionOperator::Smaller;
    if (ctx->SMEQ() != nullptr) return AstExpressionOperator::SmallerEqual;
    return AstExpressionOperator::NotSet;
}

antlrcpp::Any AstExpressionBuilder::visitOperator_bits(zsharp_parserParser::Operator_bitsContext* ctx) {
    if (ctx->BIT_AND() != nullptr) return AstExpressionOperator::BitAnd;
    if (ctx->BIT_OR() != nullptr) return AstExpressionOperator::BitOr;
    if (ctx->BIT_ROLL() != nullptr) return AstExpressionOperator::BitRollLeft;
    if (ctx->BIT_ROLR() != nullptr) return AstExpressionOperator::BitRollRight;
    if (ctx->BIT_SHL() != nullptr) return AstExpressionOperator::BitShiftLeft;
    if (ctx->BIT_SHR() != nullptr) return AstExpressionOperator::BitShiftRight;
    if (ctx->BIT_XOR() != nullptr) return AstExpressionOperator::BitXor;
    return AstExpressionOperator::NotSet;
}

antlrcpp::Any AstExpressionBuilder::visitOperator_bits_unary(zsharp_parserParser::Operator_bits_unaryContext* ctx) {
    if (ctx->BIT_NOT() != nullptr) return AstExpressionOperator::BitNegate;
    return AstExpressionOperator::NotSet;
}
