#pragma once

#include "AstNode.h"
#include "AstNumeric.h"
#include "../grammar/parser/zsharp_parserParser.h"
#include <memory>

enum class AstExpressionOperator {
    NotSet          = 0x0000,

    // precedence
    Open            = 0x00C1,
    Close           = 0x00C2,

    // arithmetic
    Plus            = 0x1091,
    Minus           = 0x1092,
    Divide          = 0x10A3,
    Multiply        = 0x10A4,
    Modulo          = 0x10A5,
    Power           = 0x10A6,
    Negate          = 0x11B0,
    
    // comparison
    Equal           = 0x2051,
    NotEqual        = 0x2052,
    Greater         = 0x2063,
    Smaller         = 0x2064,
    GreaterEqual    = 0x2065,
    SmallerEqual    = 0x2066,
    
    // bitwise
    BitAnd          = 0x4041,
    BitOr           = 0x4022,
    BitXor          = 0x4033,
    BitShiftLeft    = 0x4074,
    BitShiftRight   = 0x4075,
    BitRollLeft     = 0x4076,
    BitRollRight    = 0x4077,
    BitNegate       = 0x41B0,
    
    // logic
    And             = 0x8011,
    Or              = 0x8002,
    Not             = 0x81B0,

    // masks
    MaskArithmetic  = 0x1000,
    MaskComparison  = 0x2000,
    MaskBitwise     = 0x4000,
    MaskLogic       = 0x8000,
    MaskUnary       = 0x0100,
    MaskPrecedence  = 0x00F0,
};

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

private:
    std::shared_ptr<AstExpression> _expression;
    std::shared_ptr<AstNumeric> _numeric;
};

class AstExpression : public AstNode
{
    friend class AstExpressionBuilder;

public:
    AstExpression(zsharp_parserParser::Expression_arithmeticContext* ctx)
        : AstNode(AstNodeType::Expression), 
        _arithmeticCtx(ctx), _operator(AstExpressionOperator::NotSet)
    {}

    AstExpressionOperator getOperator() const { return _operator; }
    bool isOperator(AstExpressionOperator op) const { return ((int)_operator & (int)op) > 0; }
    uint32_t getPrecedence() const { return ((int)_operator & (int)AstExpressionOperator::MaskPrecedence) >> 4; }

    std::shared_ptr<AstExpressionOperand> getLHS() const { return _lhs; }
    std::shared_ptr<AstExpressionOperand> getRHS() const { return _rhs; }

protected:
    bool Add(std::shared_ptr<AstExpressionOperand> child);
    bool Add(std::shared_ptr<AstExpression> child) { return Add(std::make_shared<AstExpressionOperand > (child)); }
    bool Add(std::shared_ptr<AstNumeric> child) { return Add(std::make_shared<AstExpressionOperand >(child)); }
    void setOperator(AstExpressionOperator op) { _operator = op; }

private:
    std::shared_ptr<AstExpressionOperand> _lhs;
    std::shared_ptr<AstExpressionOperand> _rhs;
    AstExpressionOperator _operator;
    zsharp_parserParser::Expression_arithmeticContext* _arithmeticCtx;
};

