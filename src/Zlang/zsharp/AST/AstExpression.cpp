#include "AstExpression.h"

bool AstExpression::Add(std::shared_ptr<AstExpressionOperand> op)
{
    if (_rhs == nullptr) {
        _rhs = op;
        return true;
    }

    if (_lhs == nullptr &&
        !isOperator(AstExpressionOperator::MaskUnary)) {
        _lhs = op;
        return true;
    }

    return false;
}
