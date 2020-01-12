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

bool AstAssignment::AddIdentifier(std::shared_ptr<AstIdentifier> identifier)
{
    if (_identifier == nullptr) {
        _identifier = identifier;
        identifier->setParent(this);
        return true;
    }

    return false;
}