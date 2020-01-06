#pragma once

#include "AstNode.h"
#include "AstCodeBlock.h"
#include "../grammar/parser/zsharp_parserParser.h"

class AstFunction : public AstNode, public AstCodeBlockSite
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

    bool AddCodeBlock(std::shared_ptr<AstCodeBlock> codeBlock) { 
        _codeblocks.push_back(codeBlock);
        return true;
    }
    const std::vector<std::shared_ptr<AstCodeBlock>>& getCodeBlocks() const { return _codeblocks; }

private:
    bool _isExternal;
    std::string _name;
    std::vector<std::shared_ptr<AstCodeBlock>> _codeblocks;
    zsharp_parserParser::Function_defContext* _function;
};

