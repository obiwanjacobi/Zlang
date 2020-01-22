#pragma once

#include "AstNode.h"
#include "AstSymbolTable.h"
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

class AstCodeBlock : public AstNode, public AstSymbolTableSite
{
public:
    AstCodeBlock(std::shared_ptr<AstSymbolTable> parentSymbolTable, zsharp_parserParser::CodeblockContext* ctx)
        : AstNode(AstNodeType::CodeBlock), _ctx(ctx)
    {
        _symbols = std::make_shared<AstSymbolTable>(parentSymbolTable);
    }

    zsharp_parserParser::CodeblockContext* getContext() const { return _ctx; }
    const std::vector<std::shared_ptr<AstCodeBlockItem>>& getItems() const { return _items; }
    
    bool AddItem(std::shared_ptr<AstCodeBlockItem> item) { 
        _items.push_back(item);
        return true;
    }

    std::shared_ptr<AstSymbolTable> getSymbols() override { return _symbols; }
    std::shared_ptr<AstSymbolEntry> SetSymbol(const std::string& ns, const std::string& symbolName,
        AstSymbolType type, std::shared_ptr<AstNode> node) override
    {
        return _symbols->AddSymbol(ns, symbolName, type, node);
    }

private:
    zsharp_parserParser::CodeblockContext* _ctx;

    std::shared_ptr<AstSymbolTable> _symbols;
    std::vector<std::shared_ptr<AstCodeBlockItem>> _items;
};

