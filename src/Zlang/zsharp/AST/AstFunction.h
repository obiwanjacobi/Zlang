#pragma once

#include "AstNode.h"
#include "AstCodeBlock.h"
#include "AstIdentifier.h"
#include "../grammar/parser/zsharp_parserParser.h"

class AstFunction : public AstNode, public AstCodeBlockSite, public AstIdentifierSite
{
    friend class AstNodeBuilder;

public:
    AstFunction(zsharp_parserParser::Function_defContext* function)
        : AstNode(AstNodeType::Function), _function(function)
    {}

    zsharp_parserParser::Function_defContext* getContext() const { return _function; }

    bool AddCodeBlock(std::shared_ptr<AstCodeBlock> codeBlock) { 
        _codeblocks.push_back(codeBlock);
        return true;
    }
    const std::vector<std::shared_ptr<AstCodeBlock>>& getCodeBlocks() const { return _codeblocks; }

    const std::shared_ptr<AstIdentifier> getIdentifier() const { return _identifier; }
    bool AddIdentifier(std::shared_ptr<AstIdentifier> identifier) override;

private:
    std::vector<std::shared_ptr<AstCodeBlock>> _codeblocks;
    std::shared_ptr<AstIdentifier> _identifier;

    zsharp_parserParser::Function_defContext* _function;
};

