#include "AstAssignment.h"
#include "AstVisitor.h"

void AstAssignment::Accept(AstVisitor* visitor) {
    visitor->VisitAssignment(this);
}

bool AstAssignment::SetExpression(std::shared_ptr<AstExpression> expr)
{
    if (AstExpressionSite::SetExpression(expr)) {
        expr->setParent(this);
        return true;
    }
    return false;
}
