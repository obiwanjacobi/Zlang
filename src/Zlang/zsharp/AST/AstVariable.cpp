#include "AstVariable.h"
#include "AstVisitor.h"

void AstVariableDefinition::Accept(AstVisitor* visitor) {
    visitor->VisitVariableDefinition(this);
}

void AstVariableReference::Accept(AstVisitor* visitor) {
    visitor->VisitVariableReference(this);
}
