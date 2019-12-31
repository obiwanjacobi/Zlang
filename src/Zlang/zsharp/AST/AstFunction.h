#pragma once

#include "AstNode.h"
#include "../grammar/parser/zsharp_parserParser.h"

class AstFunction : public AstNode
{
    friend class AstNodeBuilder;

public:
    AstFunction(zsharp_parserParser::Function_defContext* function)
        : AstNode(AstNodeType::Function), _function(function)
    {}

    zsharp_parserParser::Function_defContext* getContext() const { return _function; }

private:
    zsharp_parserParser::Function_defContext* _function;
};

