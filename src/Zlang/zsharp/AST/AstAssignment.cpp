#include "AstAssignment.h"

bool AstAssignment::SetExpression(std::shared_ptr<AstExpression> expr)
{
    if (AstExpressionSite::SetExpression(expr)) {
        expr->setParent(this);
        return true;
    }
    return false;
}
