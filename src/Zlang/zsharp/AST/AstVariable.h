#pragma once

#include "AstIdentifier.h"

class AstVariable : public AstIdentifierSite
{
public:
    AstVariable()
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
