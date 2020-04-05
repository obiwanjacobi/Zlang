#include "AstAssignment.h"

bool AstAssignment::AddExpression(std::shared_ptr<AstExpression> expr)
{
    if (_expression == nullptr) {
        _expression = expr;
        expr->setParent(this);
        return true;
    }

    return false;
}

bool AstAssignment::SetIdentifier(std::shared_ptr<AstIdentifier> identifier)
{
    if (AssignIdentifier(identifier)) {
        identifier->setParent(this);
        return true;
    }
    return false;
}