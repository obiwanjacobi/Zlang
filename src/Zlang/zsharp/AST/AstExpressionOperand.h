#pragma once

#include "AstNode.h"
#include "../grammar/parser/zsharp_parserParser.h"
#include <memory>

class AstExpression;
class AstNumeric;
class AstVariableReference;

class AstExpressionOperand
{
public:
    AstExpressionOperand(std::shared_ptr<AstExpression> expr)
        : _expression(expr),
        _litBoolCtx(nullptr), _boolCtx(nullptr), _callCtx(nullptr)
    {}
    AstExpressionOperand(std::shared_ptr<AstNumeric> num)
        : _numeric(num),
        _litBoolCtx(nullptr), _boolCtx(nullptr), _callCtx(nullptr)
    {}
    AstExpressionOperand(std::shared_ptr<AstVariableReference> variable)
        : _variable(variable),
        _litBoolCtx(nullptr), _boolCtx(nullptr), _callCtx(nullptr)
    {}

    AstExpressionOperand(zsharp_parserParser::Literal_boolContext* ctx)
        : _litBoolCtx(ctx), _boolCtx(nullptr), _callCtx(nullptr)
    {}
    AstExpressionOperand(zsharp_parserParser::Identifier_boolContext* ctx)
        : _litBoolCtx(nullptr), _boolCtx(ctx), _callCtx(nullptr)
    {}
    AstExpressionOperand(zsharp_parserParser::Function_callContext* ctx)
        : _litBoolCtx(nullptr), _boolCtx(nullptr), _callCtx(ctx)
    {}

    std::shared_ptr<AstExpression> getExpression() const { return _expression; }
    std::shared_ptr<AstNumeric> getNumeric() const { return _numeric; }
    std::shared_ptr<AstVariableReference> getVariableReference() const { return _variable; }

    antlr4::ParserRuleContext* getContext() const;
    zsharp_parserParser::Literal_boolContext* getLiteralBoolContext() const { return _litBoolCtx; }
    zsharp_parserParser::Identifier_boolContext* getIdentifierBoolContext() const { return _boolCtx; }
    zsharp_parserParser::Function_callContext* getFunctionCallContext() const { return _callCtx; }
    
    const AstNode* getParent() const;
    void setParent(AstNode* parent);

private:
    std::shared_ptr<AstExpression> _expression;
    std::shared_ptr<AstNumeric> _numeric;
    std::shared_ptr<AstVariableReference> _variable;

    zsharp_parserParser::Literal_boolContext* _litBoolCtx;
    zsharp_parserParser::Identifier_boolContext* _boolCtx;
    zsharp_parserParser::Function_callContext* _callCtx;
};
