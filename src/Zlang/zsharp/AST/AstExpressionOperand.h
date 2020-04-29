#pragma once

#include "AstNode.h"
#include "AstType.h"
#include "../grammar/parser/zsharp_parserParser.h"
#include <memory>

class AstExpression;
class AstNumeric;
class AstVariableReference;

class AstExpressionOperand : public AstNode, public AstTypeReferenceSite
{
public:
    AstExpressionOperand(std::shared_ptr<AstExpression> expr)
        : AstNode(AstNodeType::Operand),
        _expression(expr),
        _litBoolCtx(nullptr), _callCtx(nullptr)
    {}
    AstExpressionOperand(std::shared_ptr<AstNumeric> num)
        : AstNode(AstNodeType::Operand),
        _numeric(num),
        _litBoolCtx(nullptr), _callCtx(nullptr)
    {}
    AstExpressionOperand(std::shared_ptr<AstVariableReference> variable)
        : AstNode(AstNodeType::Operand),
        _variable(variable),
        _litBoolCtx(nullptr), _callCtx(nullptr)
    {}
    AstExpressionOperand(zsharp_parserParser::Literal_boolContext* ctx)
        : AstNode(AstNodeType::Operand),
        _litBoolCtx(ctx), _callCtx(nullptr)
    {}
    AstExpressionOperand(zsharp_parserParser::Function_callContext* ctx)
        : AstNode(AstNodeType::Operand),
        _litBoolCtx(nullptr), _callCtx(ctx)
    {}

    std::shared_ptr<AstExpression> getExpression() const { return _expression; }
    std::shared_ptr<AstNumeric> getNumeric() const { return _numeric; }
    std::shared_ptr<AstVariableReference> getVariableReference() const { return _variable; }

    antlr4::ParserRuleContext* getContext() const;
    zsharp_parserParser::Literal_boolContext* getLiteralBoolContext() const { return _litBoolCtx; }
    zsharp_parserParser::Function_callContext* getFunctionCallContext() const { return _callCtx; }
    
    const AstNode* getParent() const;
    void setParent(AstNode* parent);

    bool SetTypeReference(std::shared_ptr<AstTypeReference> type) override {
        if (AstTypeReferenceSite::SetTypeReference(type)) {
            type->setParent(this);
            return true;
        }
        return false;
    }

    void Accept(AstVisitor* visitor) override;
    void VisitChildren(AstVisitor* visitor) override;

private:
    std::shared_ptr<AstExpression> _expression;
    std::shared_ptr<AstNumeric> _numeric;
    std::shared_ptr<AstVariableReference> _variable;

    zsharp_parserParser::Literal_boolContext* _litBoolCtx;
    zsharp_parserParser::Function_callContext* _callCtx;
};
