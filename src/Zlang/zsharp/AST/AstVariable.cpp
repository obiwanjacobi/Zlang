#include "AstVariable.h"
#include "AstVisitor.h"

void AstVariableDefinition::Accept(AstVisitor* visitor) {
    if (dynamic_cast<AstCodeBlock*>(getParent()))
        AstCodeBlockItem::Accept(visitor);
    visitor->VisitVariableDefinition(this);
}
void AstVariableDefinition::VisitChildren(AstVisitor* visitor) {
    getIdentifier()->Accept(visitor);

    auto typeRef = getTypeReference();
    if (typeRef) {
        typeRef->Accept(visitor);
    }
}

void AstVariableReference::Accept(AstVisitor* visitor) {
    visitor->VisitVariableReference(this);
}
void AstVariableReference::VisitChildren(AstVisitor* visitor) {
    getIdentifier()->Accept(visitor);
}
