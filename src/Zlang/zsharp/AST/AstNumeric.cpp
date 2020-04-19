#include "AstNumeric.h"
#include "AstVisitor.h"

void AstNumeric::Accept(AstVisitor* visitor) {
    visitor->VisitNumeric(this);
}
