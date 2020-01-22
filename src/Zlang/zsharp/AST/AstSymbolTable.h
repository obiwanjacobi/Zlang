#pragma once

#include "AstNode.h"
#include <map>
#include <memory>
#include <string>
#include <vector>

enum class AstSymbolType
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
    AstSymbolEntry(std::string ns, std::string symbolName, AstSymbolType type)
        : _type(type), _name(ns, symbolName), _locality(AstSymbolLocality::Private)
    {}

    AstSymbolType getSymbolType() const { return _type; }
    void setSymbolType(AstSymbolType type) { _type = type; }

    AstSymbolLocality getSymbolLocality() const { return _locality; }
    void setSymbolLocality(AstSymbolLocality loc) { _locality = loc; }

    const AstSymbolName& getSymbolName() const { return _name; }
    const std::string getKey() const { return _name.getQualifiedName(); }

    void AddNode(std::shared_ptr<AstNode> node);

private:
    AstSymbolType _type;
    AstSymbolName _name;
    AstSymbolLocality _locality;
    std::shared_ptr<AstNode> _definition;
    std::vector<std::shared_ptr<AstNode>> _references;
};

class AstSymbolTable
{
public:
    AstSymbolTable()
    {}
    AstSymbolTable(std::shared_ptr<AstSymbolTable> parentTable)
        : _parent(parentTable)
    {}

    std::shared_ptr<AstSymbolEntry> AddSymbol(const std::string& ns, const std::string& symbolName, 
        AstSymbolType type, std::shared_ptr<AstNode> node);

    std::shared_ptr<AstSymbolEntry> getEntry(const std::string qualifiedNameOrAlias) { return _table[qualifiedNameOrAlias]; }

    std::shared_ptr<AstSymbolTable> getParentTable() const { return _parent; }

private:
    std::shared_ptr<AstSymbolTable> _parent;
    std::map<const std::string, std::shared_ptr<AstSymbolEntry>> _table;
};

class AstSymbolTableSite
{
public:
    virtual std::shared_ptr<AstSymbolTable> getSymbols() = 0;
    virtual std::shared_ptr<AstSymbolEntry> SetSymbol(const std::string& ns, const std::string& symbolName,
        AstSymbolType type, std::shared_ptr<AstNode> node) = 0;
};
