#pragma once

#include "AstNode.h"
#include "AstNumeric.h"
#include <memory>

class AstExpression;

class AstExpressionOperand
{
public:
    AstExpressionOperand(std::shared_ptr<AstExpression> expr)
        : _expression(expr)
    {}
    AstExpressionOperand(std::shared_ptr<AstNumeric> num)
        : _numeric(num)
    {}

    std::shared_ptr<AstExpression> getExpression() const { return _expression; }
    std::shared_ptr<AstNumeric> getNumeric() const { return _numeric; }

    const AstNode* getParent() const;
    void setParent(AstNode* parent);

private:
    std::shared_ptr<AstExpression> _expression;
    std::shared_ptr<AstNumeric> _numeric;
};
