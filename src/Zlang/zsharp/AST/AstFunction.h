#pragma once

#include "AstNode.h"
#include "../grammar/parser/zsharp_parserParser.h"

class AstFunction : public AstNode
{
    friend class AstNodeBuilder;

public:
    AstFunction(zsharp_parserParser::Function_defContext* function)
        : AstNode(AstNodeType::Function), _function(function), _isExternal(false)
    {}

    zsharp_parserParser::Function_defContext* getContext() const { return _function; }

    const std::string& getName() const { return _name; }
    void setName(const std::string name) { _name = name; }

    bool isExternal() const { return _isExternal; }
    void setIsExternal() { _isExternal = true; }

private:
    bool _isExternal;
    std::string _name;
    zsharp_parserParser::Function_defContext* _function;
};

