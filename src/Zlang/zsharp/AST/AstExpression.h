#pragma once

#include "AstNode.h"
#include "AstNumeric.h"
#include "AstExpressionOperand.h"
#include "AstExpressionOperator.h"
#include "AstType.h"
#include "../grammar/parser/zsharp_parserParser.h"
#include <memory>

class AstExpression : public AstNode, public AstTypeReferenceSite
{
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

    antlr4::ParserRuleContext* getContext() const;

    AstExpressionOperator getOperator() const { return _operator; }
    bool isOperator(AstExpressionOperator op) const { return ((int)_operator & (int)op) > 0; }
    uint32_t getPrecedence() const { return ((int)_operator & (int)AstExpressionOperator::MaskPrecedence) >> 4; }

    std::shared_ptr<AstExpressionOperand> getLHS() const { return _lhs; }
    std::shared_ptr<AstExpressionOperand> getRHS() const { return _rhs; }

    bool Add(std::shared_ptr<AstExpressionOperand> child);
    bool Add(std::shared_ptr<AstExpression> child) { return Add(std::make_shared<AstExpressionOperand>(child)); }
    bool Add(std::shared_ptr<AstNumeric> child) { return Add(std::make_shared<AstExpressionOperand>(child)); }
    void setOperator(AstExpressionOperator op) { _operator = op; }

    bool SetTypeReference(std::shared_ptr<AstTypeReference> type) override {
        if (AstTypeReferenceSite::SetTypeReference(type)) {
            bool success = type->setParent(this);
            guard(success && "setParent failed.");
            return true;
        }
        return false;
    }

    void Accept(AstVisitor* visitor) override;
    void VisitChildren(AstVisitor* visitor) override;

private:
    std::shared_ptr<AstExpressionOperand> _lhs;
    std::shared_ptr<AstExpressionOperand> _rhs;
    AstExpressionOperator _operator;
    zsharp_parserParser::Expression_arithmeticContext* _arithmeticCtx;
    zsharp_parserParser::Expression_logicContext* _logicCtx;
    zsharp_parserParser::Expression_comparisonContext* _comparisonCtx;
    zsharp_parserParser::Expression_valueContext* _valueCtx;
};


class AstExpressionSite
{
public:
    std::shared_ptr<AstExpression> getExpression() const { return _expression; }
    virtual bool SetExpression(std::shared_ptr<AstExpression> expr) {
        if (!_expression && expr) {
            _expression = expr;
            return true;
        }
        return false;
    }

private:
    std::shared_ptr<AstExpression> _expression;
};
