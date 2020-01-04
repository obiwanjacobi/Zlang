#pragma once

#include "AstNode.h"
#include "AstNumeric.h"
#include <memory>

class AstExpression;

class AstExpressionOperand
{
public:
    AstExpressionOperand(std::shared_ptr<AstExpression> expr)
        : _expression(expr),
        _litBoolCtx(nullptr), _boolCtx(nullptr), _callCtx(nullptr), _varCtx(nullptr), _paramCtx(nullptr)
    {}
    AstExpressionOperand(std::shared_ptr<AstNumeric> num)
        : _numeric(num),
        _litBoolCtx(nullptr), _boolCtx(nullptr), _callCtx(nullptr), _varCtx(nullptr), _paramCtx(nullptr)
    {}

    AstExpressionOperand(zsharp_parserParser::Literal_boolContext* ctx)
        : _litBoolCtx(ctx), _boolCtx(nullptr), _callCtx(nullptr), _varCtx(nullptr), _paramCtx(nullptr)
    {}
    AstExpressionOperand(zsharp_parserParser::Identifier_boolContext* ctx)
        : _litBoolCtx(nullptr), _boolCtx(ctx), _callCtx(nullptr), _varCtx(nullptr), _paramCtx(nullptr)
    {}
    AstExpressionOperand(zsharp_parserParser::Function_callContext* ctx)
        : _litBoolCtx(nullptr), _boolCtx(nullptr), _callCtx(ctx), _varCtx(nullptr), _paramCtx(nullptr)
    {}
    AstExpressionOperand(zsharp_parserParser::Variable_refContext* ctx)
        : _litBoolCtx(nullptr), _boolCtx(nullptr), _callCtx(nullptr), _varCtx(ctx), _paramCtx(nullptr)
    {}
    AstExpressionOperand(zsharp_parserParser::Parameter_refContext* ctx)
        : _litBoolCtx(nullptr), _boolCtx(nullptr), _callCtx(nullptr), _varCtx(nullptr), _paramCtx(ctx)
    {}

    std::shared_ptr<AstExpression> getExpression() const { return _expression; }
    std::shared_ptr<AstNumeric> getNumeric() const { return _numeric; }

    zsharp_parserParser::Literal_boolContext* getLiteralBool() const { return _litBoolCtx; }
    zsharp_parserParser::Identifier_boolContext* getBool() const { return _boolCtx; }
    zsharp_parserParser::Function_callContext* getCall() const { return _callCtx; }
    zsharp_parserParser::Variable_refContext* getVariable() const { return _varCtx; }
    zsharp_parserParser::Parameter_refContext* getParameter() const { return _paramCtx; }

    const AstNode* getParent() const;
    void setParent(AstNode* parent);

private:
    std::shared_ptr<AstExpression> _expression;
    std::shared_ptr<AstNumeric> _numeric;

    zsharp_parserParser::Literal_boolContext* _litBoolCtx;
    zsharp_parserParser::Identifier_boolContext* _boolCtx;
    zsharp_parserParser::Function_callContext* _callCtx;
    zsharp_parserParser::Variable_refContext* _varCtx;
    zsharp_parserParser::Parameter_refContext* _paramCtx;
};
