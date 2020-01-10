#pragma once

#include "AstNode.h"
#include "AstCodeBlock.h"
#include "AstExpression.h"

class AstAssignment : public AstCodeBlockItem, public AstExpressionSite
{
public:
    AstAssignment(zsharp_parserParser::Variable_assignContext* ctx)
        : AstCodeBlockItem(AstNodeType::Assignment), _ctx(ctx)
    {}

    bool AddExpression(std::shared_ptr<AstExpression> expr);

private:
    std::shared_ptr<AstExpression> _expression;

    zsharp_parserParser::Variable_assignContext* _ctx;
};

