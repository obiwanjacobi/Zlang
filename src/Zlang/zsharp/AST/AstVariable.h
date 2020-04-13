#pragma once

#include "AstNode.h"
#include "AstIdentifier.h"

class AstVariable : public AstNode, public AstIdentifierSite
{
public:
    AstVariable()
        : AstNode(AstNodeType::Variable)
    {}
};


class AstVariableReference : public AstVariable
{
public:
    AstVariableReference(zsharp_parserParser::Variable_refContext* ctx)
        : _context(ctx)
    {}

private:
    zsharp_parserParser::Variable_refContext* _context;
};
