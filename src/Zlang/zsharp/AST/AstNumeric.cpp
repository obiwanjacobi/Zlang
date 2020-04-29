#include "AstNumeric.h"
#include "AstVisitor.h"

void AstNumeric::Accept(AstVisitor* visitor) {
    visitor->VisitNumeric(this);
}

uint32_t AstNumeric::getBitCount() const
{
    uint64_t n = _intValue;
    uint32_t count = 0;
    while (n)
    {
        count++;
        n >>= 1;
    }
    return count;
}
