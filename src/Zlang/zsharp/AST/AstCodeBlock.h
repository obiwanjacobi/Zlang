#pragma once

#include "AstNode.h"
#include "AstSymbolTable.h"
#include "../grammar/parser/zsharp_parserParser.h"
#include <memory>

class AstCodeBlockItem : public AstNode
{
public:
    uint32_t getIndent() const { return _indent; }
    void setIndent(uint32_t indent) { _indent = indent; }

    void Accept(AstVisitor* visitor) override;

protected:
    AstCodeBlockItem(AstNodeType nodeType)
        : AstNode(nodeType), _indent(0)
    {}

private:
    uint32_t _indent;
};


class AstCodeBlock : public AstNode, public AstSymbolTableSiteImpl
{
public:
    AstCodeBlock(std::string scopeName, std::shared_ptr<AstSymbolTable> parentSymbolTable, zsharp_parserParser::CodeblockContext* ctx)
        : AstNode(AstNodeType::CodeBlock), AstSymbolTableSiteImpl(scopeName, parentSymbolTable),
        _ctx(ctx), _indent(0)
    {}

    zsharp_parserParser::CodeblockContext* getContext() const { return _ctx; }

    const std::vector<std::shared_ptr<AstCodeBlockItem>>& getItems() const { return _items; }
    template<class T>
    std::shared_ptr<T> getItemAt(size_t index) {
        return std::dynamic_pointer_cast<T>(_items.at(index));
    }
    bool AddItem(std::shared_ptr<AstCodeBlockItem> item) { 
        if (!item) return false;
        _items.push_back(item);
        item->setIndent(_indent);
        bool success = item->setParent(this);
        guard(success && "setParent failed.");
        return true;
    }

    uint32_t getIndent() const { return _indent;  }
    void setIndent(uint32_t indent) { _indent = indent; }

    void Accept(AstVisitor* visitor) override;
    void VisitChildren(AstVisitor* visitor) override;

private:
    uint32_t _indent;
    zsharp_parserParser::CodeblockContext* _ctx;

    std::vector<std::shared_ptr<AstCodeBlockItem>> _items;
};


class AstCodeBlockSite
{
public:
    virtual bool SetCodeBlock(std::shared_ptr<AstCodeBlock> codeBlock) {
        if (!_codeBlock && codeBlock) {
            _codeBlock = codeBlock;
            return true;
        }
        return false;
    }

    std::shared_ptr<AstCodeBlock> getCodeBlock() const { return _codeBlock; }

private:
    std::shared_ptr<AstCodeBlock> _codeBlock;
};
