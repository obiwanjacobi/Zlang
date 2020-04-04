#pragma once

#include "AstNode.h"
#include "AstCodeBlock.h"
#include "AstExpression.h"
#include "AstIdentifier.h"

class AstAssignment : public AstCodeBlockItem, public AstExpressionSite, public AstIdentifierSite
{
public:
    AstAssignment(zsharp_parserParser::Variable_assignContext* ctx)
        : AstCodeBlockItem(AstNodeType::Assignment), _ctx(ctx)
    {}

    bool AddExpression(std::shared_ptr<AstExpression> expr) override;
    const std::shared_ptr<AstExpression>& getExpression() const { return _expression; }

    bool AddIdentifier(std::shared_ptr<AstIdentifier> identifier) override;
    const std::shared_ptr<AstIdentifier>& getIdentifier() const { return _identifier; }

private:
    std::shared_ptr<AstExpression> _expression;
    std::shared_ptr<AstIdentifier> _identifier;

    zsharp_parserParser::Variable_assignContext* _ctx;
};

