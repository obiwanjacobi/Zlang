#include "AstExpression.h"
#include "AstVisitor.h"

void AstExpression::Accept(AstVisitor* visitor) {
    visitor->VisitExpression(this);
}
void AstExpression::VisitChildren(AstVisitor* visitor) {
    if (_rhs) {
        _rhs->Accept(visitor);
    }
    if (_lhs) {
        _lhs->Accept(visitor);
    }
}

antlr4::ParserRuleContext* AstExpression::getContext() const
{
    if (_arithmeticCtx) { return _arithmeticCtx; }
    if (_logicCtx) { return _logicCtx; }
    if (_comparisonCtx) { return _comparisonCtx; }
    if (_valueCtx) { return _valueCtx; }
    return nullptr;
}

bool AstExpression::Add(std::shared_ptr<AstExpressionOperand> op)
{
    if (!_rhs) {
        bool success = op->setParent(this);
        guard(success && "setParent failed.");
        _rhs = op;
        return true;
    }

    if (!_lhs &&
        !isOperator(AstExpressionOperator::MaskUnary)) {
        bool success = op->setParent(this);
        guard(success && "setParent failed.");
        _lhs = op;
        return true;
    }

    return false;
}
