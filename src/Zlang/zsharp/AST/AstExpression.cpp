#include "AstExpression.h"
#include "AstVisitor.h"

void AstExpression::Accept(AstVisitor* visitor) {
    visitor->VisitExpression(this);
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
    if (_rhs == nullptr) {
        _rhs = op;
        return true;
    }

    if (_lhs == nullptr &&
        !isOperator(AstExpressionOperator::MaskUnary)) {
        _lhs = op;
        return true;
    }

    return false;
}
