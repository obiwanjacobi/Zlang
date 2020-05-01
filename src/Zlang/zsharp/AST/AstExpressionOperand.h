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
    AstExpressionOperand(std::shared_ptr<AstExpression> expr);
    AstExpressionOperand(std::shared_ptr<AstNumeric> num);
    AstExpressionOperand(std::shared_ptr<AstVariableReference> variable);
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
    std::shared_ptr<AstExpression> _expression;
    std::shared_ptr<AstNumeric> _numeric;
    std::shared_ptr<AstVariableReference> _variable;

    zsharp_parserParser::Literal_boolContext* _litBoolCtx = nullptr;
    zsharp_parserParser::Function_callContext* _callCtx = nullptr;
};
