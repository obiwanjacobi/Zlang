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

    bool SetExpression(std::shared_ptr<AstExpression> expr) override;
    bool SetIdentifier(std::shared_ptr<AstIdentifier> identifier) override;

private:
    zsharp_parserParser::Variable_assignContext* _ctx;
};

