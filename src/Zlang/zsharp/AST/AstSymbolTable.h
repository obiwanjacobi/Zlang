#pragma once

#include "AstNode.h"
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

class AstSymbolName
{
public:
    AstSymbolName(const std::string& ns, const std::string& name)
        : _namespace(ns), _name(name)
    {}

    const std::string getQualifiedName() const;

private:
    std::string _namespace;
    std::string _name;
    std::vector<std::string> _aliases;
};

class AstSymbolEntry
{
public:
    AstSymbolEntry(std::string ns, std::string symbolName, AstSymbolKind kind)
        : _kind(kind), _name(ns, symbolName), _locality(AstSymbolLocality::Private)
    {}

    AstSymbolKind getSymbolKind() const { return _kind; }

    AstSymbolLocality getSymbolLocality() const { return _locality; }
    void setSymbolLocality(AstSymbolLocality loc) { _locality = loc; }

    const AstSymbolName& getSymbolName() const { return _name; }
    const std::string getKey() const { return _name.getQualifiedName() + std::to_string((int)_kind); }

    void AddNode(std::shared_ptr<AstNode> node);

private:
    AstSymbolKind _kind;
    AstSymbolName _name;
    AstSymbolLocality _locality;
    std::shared_ptr<AstNode> _definition;
    std::vector<std::shared_ptr<AstNode>> _references;
};

class AstSymbolTable
{
public:
    AstSymbolTable(std::string basename)
        : _namespace(basename)
    {}
    AstSymbolTable(std::shared_ptr<AstSymbolTable> parentTable)
        : _parent(parentTable)
    {}
    AstSymbolTable(std::string basename, std::shared_ptr<AstSymbolTable> parentTable)
        : _parent(parentTable), _namespace(basename)
    {}

    std::shared_ptr<AstSymbolEntry> AddSymbol(
        const std::string& symbolName, AstSymbolKind type, std::shared_ptr<AstNode> node);
    std::shared_ptr<AstSymbolEntry> getEntry(const std::string qualifiedNameOrAlias, AstSymbolKind kind);

    std::shared_ptr<AstSymbolTable> getParentTable() const { return _parent; }
    const std::vector<std::shared_ptr<AstSymbolEntry>> getSymbolEntries() const;

    std::string getQualifiedName() const;
    std::string getNamespace() const { return _namespace; }

private:
    std::string _namespace;
    std::shared_ptr<AstSymbolTable> _parent;
    std::map<const std::string, std::shared_ptr<AstSymbolEntry>> _table;
};

class AstSymbolTableSite
{
public:
    virtual std::shared_ptr<AstSymbolTable> getSymbols() const = 0;
    virtual std::shared_ptr<AstSymbolEntry> AddSymbol(const std::string& symbolName,
        AstSymbolKind type, std::shared_ptr<AstNode> node) = 0;
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
