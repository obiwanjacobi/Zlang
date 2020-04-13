#pragma once

#include "AstNode.h"
#include "AstCodeBlock.h"
#include "AstExpression.h"
#include "AstVariable.h"

class AstAssignment : public AstCodeBlockItem, public AstExpressionSite
{
public:
    AstAssignment(zsharp_parserParser::Variable_assign_autoContext* ctx)
        : AstCodeBlockItem(AstNodeType::Assignment), _ctx(ctx)
    {}

    bool SetExpression(std::shared_ptr<AstExpression> expr) override;

    std::shared_ptr<AstVariable> getVariable() const { return _variable; }
    bool SetVariable(std::shared_ptr<AstVariable> variable) {
        if (!_variable && variable) {
            _variable = variable;
            return true;
        }
        return false;
    }

private:
    zsharp_parserParser::Variable_assign_autoContext* _ctx;
    std::shared_ptr<AstVariable> _variable;
};

