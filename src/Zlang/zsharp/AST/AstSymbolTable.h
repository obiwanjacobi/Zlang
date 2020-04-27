#pragma once

#include "AstNode.h"
#include "AstIdentifier.h"
#include <map>
#include <memory>
#include <string>
#include <vector>

enum class AstSymbolKind
{
    NotSet,
    Function,
    Struct,
    Enum,
    Type,
    Parameter,
    Variable,
    Field,
};

enum class AstSymbolLocality
{
    Private,
    Exported,
    Imported,
};


class AstSymbolEntry
{
    friend class AstSymbolTable;

public:
    AstSymbolEntry(std::string symbolName, AstSymbolKind kind)
        : _kind(kind), _name(symbolName), _locality(AstSymbolLocality::Private)
    {}

    AstSymbolKind getSymbolKind() const { return _kind; }

    AstSymbolLocality getSymbolLocality() const { return _locality; }
    void setSymbolLocality(AstSymbolLocality loc) { _locality = loc; }

    const std::string& getSymbolName() const { return _name; }
    const std::string getKey() const { return makeKey(_name, _kind); }

    void AddNode(std::shared_ptr<AstNode> node);
    template<class T> std::shared_ptr<T> getDefinition() const {
        return std::dynamic_pointer_cast<T>(_definition);
    }
    const std::vector<std::shared_ptr<AstNode>>& getReferences() const {
        return _references;
    }

private:
    AstSymbolKind _kind;
    std::string _name;
    AstSymbolLocality _locality;
    std::shared_ptr<AstNode> _definition;
    std::vector<std::shared_ptr<AstNode>> _references;

    static std::string makeKey(const std::string& name, AstSymbolKind kind) {
        return name + std::to_string((int)kind);
    }
};


class AstSymbolTable
{
public:
    AstSymbolTable()
    {}
    AstSymbolTable(const std::string& name)
        : _name(name)
    {}
    AstSymbolTable(std::shared_ptr<AstSymbolTable> parentTable)
        : _parent(parentTable)
    {}
    AstSymbolTable(const std::string& name, std::shared_ptr<AstSymbolTable> parentTable)
        : _parent(parentTable), _name(name)
    {}

    std::shared_ptr<AstSymbolEntry> AddSymbol(
        const std::string& symbolName, AstSymbolKind kind, std::shared_ptr<AstNode> node);
    std::shared_ptr<AstSymbolEntry> getEntry(const std::string& name, AstSymbolKind kind);
    std::shared_ptr<AstSymbolTable> getParentTable() const { return _parent; }
    const std::vector<std::shared_ptr<AstSymbolEntry>> getSymbolEntries() const;

    std::string getName() const { return _name; }
    std::string getNamespace() const;

private:
    std::string _name;
    std::shared_ptr<AstSymbolTable> _parent;
    std::map<const std::string, std::shared_ptr<AstSymbolEntry>> _table;
};

class AstSymbolTableSite
{
public:
    virtual std::shared_ptr<AstSymbolTable> getSymbols() const = 0;
    virtual std::shared_ptr<AstSymbolEntry> AddSymbol(const std::string& symbolName,
        AstSymbolKind kind, std::shared_ptr<AstNode> node) = 0;
    
    std::shared_ptr<AstSymbolEntry> AddSymbol(std::shared_ptr<AstIdentifier> identifier,
        AstSymbolKind kind, std::shared_ptr<AstNode> node) {
        return AddSymbol(identifier->getName(), kind, node);
    }
    
    std::shared_ptr<AstSymbolEntry> AddSymbol(std::shared_ptr<AstIdentifierSite> identifierSite,
        AstSymbolKind kind, std::shared_ptr<AstNode> node) {
        return AddSymbol(identifierSite->getIdentifier()->getName(), kind, node);
    }
};

class AstSymbolTableSiteImpl : public AstSymbolTableSite
{
public:
    std::shared_ptr<AstSymbolTable> getSymbols() const override { return _symbols; }
    std::shared_ptr<AstSymbolEntry> AddSymbol(const std::string& symbolName,
        AstSymbolKind kind, std::shared_ptr<AstNode> node) override
    {
        return _symbols->AddSymbol(symbolName, kind, node);
    }

protected:
    AstSymbolTableSiteImpl(std::shared_ptr<AstSymbolTable> parent) {
        _symbols = std::make_shared<AstSymbolTable>(parent);
    }
    AstSymbolTableSiteImpl(std::string ns) {
        _symbols = std::make_shared<AstSymbolTable>(ns);
    }
    AstSymbolTableSiteImpl(std::string ns, std::shared_ptr<AstSymbolTable> parent) {
        _symbols = std::make_shared<AstSymbolTable>(ns, parent);
    }

private:
    std::shared_ptr<AstSymbolTable> _symbols;
};
