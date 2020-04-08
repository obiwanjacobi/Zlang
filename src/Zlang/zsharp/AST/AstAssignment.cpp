#include "AstAssignment.h"

bool AstAssignment::SetExpression(std::shared_ptr<AstExpression> expr)
{
    if (AstExpressionSite::SetExpression(expr)) {
        expr->setParent(this);
        return true;
    }
    return false;
}

bool AstAssignment::SetIdentifier(std::shared_ptr<AstIdentifier> identifier)
{
    if (AstIdentifierSite::SetIdentifier(identifier)) {
        identifier->setParent(this);
        return true;
    }
    return false;
}