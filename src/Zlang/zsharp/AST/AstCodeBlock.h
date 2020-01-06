#pragma once

#include "AstNode.h"
#include "../grammar/parser/zsharp_parserParser.h"
#include <memory>

class AstCodeBlock;

class AstCodeBlockSite
{
public:
    virtual bool AddCodeBlock(std::shared_ptr<AstCodeBlock> codeBlock) = 0;
};

class AstCodeBlockItem : public AstNode
{
protected:
    AstCodeBlockItem(AstNodeType nodeType)
        : AstNode(nodeType)
    {}

private:
};

class AstCodeBlock : public AstNode
{
public:
    AstCodeBlock(zsharp_parserParser::CodeblockContext* ctx)
        : AstNode(AstNodeType::CodeBlock), _ctx(ctx)
    {}

    zsharp_parserParser::CodeblockContext* getContext() const { return _ctx; }
    const std::vector<std::shared_ptr<AstCodeBlockItem>>& getItems() const { return _items; }
    
    bool AddItem(std::shared_ptr<AstCodeBlockItem> item) { 
        _items.push_back(item);
        return true;
    }

private:
    zsharp_parserParser::CodeblockContext* _ctx;

    std::vector<std::shared_ptr<AstCodeBlockItem>> _items;
};

