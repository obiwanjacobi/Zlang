#include "AstAssignment.h"

bool AstAssignment::AddExpression(std::shared_ptr<AstExpression> expr)
{
    if (_expression == nullptr) {
        _expression = expr;
        return true;
    }

    return false;
}