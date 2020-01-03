#include "AstExpression.h"

bool AstExpression::Add(std::shared_ptr<AstExpressionOperand> op)
{
    if (_lhs == nullptr) {
        _lhs = op;
        return true;
    }
    
    if (_rhs == nullptr && 
        !isOperator(AstExpressionOperator::MaskUnary)) {
        _rhs = op;
        return true;
    }
    
    return false;
}
