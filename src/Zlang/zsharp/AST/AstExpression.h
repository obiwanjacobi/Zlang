#pragma once

#include "AstNode.h"
#include "AstNumeric.h"
#include "AstExpressionOperand.h"
#include "AstExpressionOperator.h"
#include "../grammar/parser/zsharp_parserParser.h"
#include <memory>

class AstExpressionSite
{
public:
    virtual bool AddExpression(std::shared_ptr<AstExpression> expr) = 0;
};

class AstExpression : public AstNode
{
    friend class AstExpressionBuilder;

public:
    AstExpression(zsharp_parserParser::Expression_arithmeticContext* ctx)
        : AstNode(AstNodeType::Expression),
        _arithmeticCtx(ctx), _logicCtx(nullptr), _comparisonCtx(nullptr), 
        _valueCtx(nullptr), _operator(AstExpressionOperator::NotSet)
    {}
    AstExpression(zsharp_parserParser::Expression_logicContext* ctx)
        : AstNode(AstNodeType::Expression),
        _arithmeticCtx(nullptr), _logicCtx(ctx), _comparisonCtx(nullptr), 
        _valueCtx(nullptr), _operator(AstExpressionOperator::NotSet)
    {}
    AstExpression(zsharp_parserParser::Expression_comparisonContext* ctx)
        : AstNode(AstNodeType::Expression),
        _arithmeticCtx(nullptr), _logicCtx(nullptr), _comparisonCtx(ctx), 
        _valueCtx(nullptr), _operator(AstExpressionOperator::NotSet)
    {}
    AstExpression(zsharp_parserParser::Expression_valueContext* ctx)
        : AstNode(AstNodeType::Expression),
        _arithmeticCtx(nullptr), _logicCtx(nullptr), _comparisonCtx(nullptr),
        _valueCtx(ctx), _operator(AstExpressionOperator::Number)
    {}

    AstExpressionOperator getOperator() const { return _operator; }
    bool isOperator(AstExpressionOperator op) const { return ((int)_operator & (int)op) > 0; }
    uint32_t getPrecedence() const { return ((int)_operator & (int)AstExpressionOperator::MaskPrecedence) >> 4; }

    std::shared_ptr<AstExpressionOperand> getLHS() const { return _lhs; }
    std::shared_ptr<AstExpressionOperand> getRHS() const { return _rhs; }

protected:
    bool Add(std::shared_ptr<AstExpressionOperand> child);
    bool Add(std::shared_ptr<AstExpression> child) { return Add(std::make_shared<AstExpressionOperand>(child)); }
    bool Add(std::shared_ptr<AstNumeric> child) { return Add(std::make_shared<AstExpressionOperand>(child)); }
    void setOperator(AstExpressionOperator op) { _operator = op; }

private:
    std::shared_ptr<AstExpressionOperand> _lhs;
    std::shared_ptr<AstExpressionOperand> _rhs;
    AstExpressionOperator _operator;
    zsharp_parserParser::Expression_arithmeticContext* _arithmeticCtx;
    zsharp_parserParser::Expression_logicContext* _logicCtx;
    zsharp_parserParser::Expression_comparisonContext* _comparisonCtx;
    zsharp_parserParser::Expression_valueContext* _valueCtx;
};
