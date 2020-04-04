#include "AstExtensions.h"

const char* EmptyString = "";

std::string ToString(AstExpressionOperator op)
{
    switch (op)
    {
    case AstExpressionOperator::Open:
        return "(";
    case AstExpressionOperator::Close:
        return ")(";

            // arithmetic
    case AstExpressionOperator::Plus:
        return "+";
    case AstExpressionOperator::Minus:
        return "-";
    case AstExpressionOperator::Divide:
        return "/";
    case AstExpressionOperator::Multiply:
        return "*";
    case AstExpressionOperator::Modulo:
        return "%";
    case AstExpressionOperator::Power:
        return "**";
    case AstExpressionOperator::Negate:
        return "-";

            // comparison
    case AstExpressionOperator::Equal:
        return "=";
    case AstExpressionOperator::NotEqual:
        return "<>";
    case AstExpressionOperator::Greater:
        return ">";
    case AstExpressionOperator::Smaller:
        return "<";
    case AstExpressionOperator::GreaterEqual:
        return ">=";
    case AstExpressionOperator::SmallerEqual:
        return "<=";

            // bitwise
    case AstExpressionOperator::BitAnd:
        return "&";
    case AstExpressionOperator::BitOr:
        return "|";
    case AstExpressionOperator::BitXor:
        return "^";
    case AstExpressionOperator::BitShiftLeft:
        return "<<";
    case AstExpressionOperator::BitShiftRight:
        return ">>";
    case AstExpressionOperator::BitRollLeft:
        return "|<";
    case AstExpressionOperator::BitRollRight:
        return ">|";
    case AstExpressionOperator::BitNegate:
        return "~";

            // logic
    case AstExpressionOperator::And:
        return "and";
    case AstExpressionOperator::Or:
        return "or";
    case AstExpressionOperator::Not:
        return "not";

    default:
        return EmptyString;
    }
}

std::string ToString(std::shared_ptr<AstNumeric> numeric)
{
    return numeric->getContext()->getText();
}

std::string ToString(std::shared_ptr<AstExpression> expression)
{
    if (!expression) { return EmptyString; }

    auto lhs = expression->getLHS();
    auto rhs = expression->getRHS();

    return ToString(lhs) + ToString(expression->getOperator()) + ToString(rhs);
}

std::string ToString(std::shared_ptr<AstExpressionOperand> operand)
{
    if (!operand) { return EmptyString; }

    auto expr = operand->getExpression();
    if (expr) { return ToString(expr); }

    auto num = operand->getNumeric();
    if (num) { return ToString(num); }

    auto ctx = operand->getContext();
    if (ctx) { return ctx->getText(); }

    return EmptyString;
}