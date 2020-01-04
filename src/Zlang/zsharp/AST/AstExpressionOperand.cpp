#include "AstExpressionOperand.h"
#include "AstExpression.h"

const AstNode* AstExpressionOperand::getParent() const
{
    if (_expression != nullptr) {
        return _expression->getParent();
    }
    if (_numeric != nullptr) {
        return _numeric->getParent();
    }
    return nullptr;
}

void AstExpressionOperand::setParent(AstNode* parent)
{
    if (_expression != nullptr) {
        _expression->setParent(parent);
    }
    if (_numeric != nullptr) {
        _numeric->setParent(parent);
    }
}
