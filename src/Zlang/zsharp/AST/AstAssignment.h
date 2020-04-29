#pragma once

#include "AstNode.h"
#include "AstCodeBlock.h"
#include "AstExpression.h"
#include "AstVariable.h"
#include <memory>

class AstAssignment : public AstCodeBlockItem, public AstExpressionSite
{
public:
    AstAssignment(zsharp_parserParser::Variable_assign_autoContext* ctx)
        : AstCodeBlockItem(AstNodeType::Assignment), 
        _ctx(ctx), _typedCtx(nullptr)
    {}
    AstAssignment(zsharp_parserParser::Variable_def_typed_initContext* ctx)
        : AstCodeBlockItem(AstNodeType::Assignment),
        _ctx(nullptr), _typedCtx(ctx)
    {}

    bool SetExpression(std::shared_ptr<AstExpression> expr) override;

    std::shared_ptr<AstVariable> getVariable() const { return _variable; }
    template<class T>
    std::shared_ptr<T> getVariable() const { return std::dynamic_pointer_cast<T>(_variable); }
    bool SetVariable(std::shared_ptr<AstVariable> variable) {
        if (!_variable && variable) {
            _variable = variable;
            _variable->setParent(this);
            return true;
        }
        return false;
    }

    void Accept(AstVisitor* visitor) override;
    void VisitChildren(AstVisitor* visitor) override;

private:
    zsharp_parserParser::Variable_assign_autoContext* _ctx;
    zsharp_parserParser::Variable_def_typed_initContext* _typedCtx;
    std::shared_ptr<AstVariable> _variable;
};

