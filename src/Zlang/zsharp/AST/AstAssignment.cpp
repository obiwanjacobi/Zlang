#include "AstAssignment.h"
#include "AstVisitor.h"

void AstAssignment::Accept(AstVisitor* visitor) {
    AstCodeBlockItem::Accept(visitor);
    visitor->VisitAssignment(this);
}
void AstAssignment::VisitChildren(AstVisitor* visitor) {
    getVariable()->Accept(visitor);
    getExpression()->Accept(visitor);
}

bool AstAssignment::SetExpression(std::shared_ptr<AstExpression> expr)
{
    if (AstExpressionSite::SetExpression(expr)) {
        bool success = expr->setParent(this);
        guard(success && "setParent failed.");
        return true;
    }
    return false;
}
