#include "AstCodeBlock.h"
#include "AstVisitor.h"

void AstCodeBlockItem::Accept(AstVisitor* visitor) {
    visitor->VisitCodeBlockItem(this);
}

void AstCodeBlock::Accept(AstVisitor* visitor) {
    visitor->VisitCodeBlock(this);
}
