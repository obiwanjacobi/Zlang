#include "AstExpressionOperand.h"
#include "AstExpression.h"
#include "AstVariable.h"
#include "AstVisitor.h"

AstExpressionOperand::AstExpressionOperand(std::shared_ptr<AstExpression> expr)
    : AstNode(AstNodeType::Operand),
    _expression(expr)
{
    bool success = expr->setParent(this);
    guard(success && "setParent failed.");
}
AstExpressionOperand::AstExpressionOperand(std::shared_ptr<AstNumeric> num)
    : AstNode(AstNodeType::Operand),
    _numeric(num)
{
    bool success = num->setParent(this);
    guard(success && "setParent failed.");
}
AstExpressionOperand::AstExpressionOperand(std::shared_ptr<AstVariableReference> variable)
    : AstNode(AstNodeType::Operand),
    _variable(variable)
{
    bool success = variable->setParent(this);
    guard(success && "setParent failed.");
}

void AstExpressionOperand::Accept(AstVisitor* visitor) {
    visitor->VisitExpressionOperand(this);
}
void AstExpressionOperand::VisitChildren(AstVisitor* visitor) {
    if (_expression) {
        _expression->Accept(visitor);
    }
    if (_numeric) {
        _numeric->Accept(visitor);
    }
    if (_variable) {
        _variable->Accept(visitor);
    }
}

antlr4::ParserRuleContext* AstExpressionOperand::getContext() const
{
    if (_litBoolCtx) return _litBoolCtx;
    if (_callCtx) return _callCtx;
    return nullptr;
}
