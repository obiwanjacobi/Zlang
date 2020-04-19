#include "AstCodeBlock.h"
#include "AstVisitor.h"

void AstCodeBlockItem::Accept(AstVisitor* visitor) {
    visitor->VisitCodeBlockItem(this);
}

void AstCodeBlock::Accept(AstVisitor* visitor) {
    visitor->VisitCodeBlock(this);
}
void AstCodeBlock::VisitChildren(AstVisitor* visitor) {
    for (auto item : _items) {
        item->Accept(visitor);
    }
}
