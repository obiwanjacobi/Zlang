#include "AstExpressionOperand.h"
#include "AstExpression.h"

antlr4::ParserRuleContext* AstExpressionOperand::getContext() const
{
    if (_litBoolCtx) return _litBoolCtx;
    if (_boolCtx) return _boolCtx;
    if (_callCtx) return _callCtx;
    return nullptr;
}

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
