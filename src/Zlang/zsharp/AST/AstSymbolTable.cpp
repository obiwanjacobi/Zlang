#include "AstSymbolTable.h"
#include "AstFunction.h"
#include "AstVariable.h"

void AstSymbolEntry::AddNode(std::shared_ptr<AstNode> node)
{
    guard(node);

    if (_kind == AstSymbolKind::Function &&
        dynamic_cast<AstFunction*>(node.get()))
    {
        guard(!_definition);
        _definition = node;
    }
    else if (_kind == AstSymbolKind::Parameter &&
        dynamic_cast<AstFunctionParameter*>(node.get()))
    {
        guard(!_definition);
        _definition = node;
    }
    else if (_kind == AstSymbolKind::Variable &&
        dynamic_cast<AstVariableDefinition*>(node.get()))
    {
        guard(!_definition);
        _definition = node;
    }
    else if(_kind == AstSymbolKind::Type && 
        dynamic_cast<AstTypeDefinition*>(node.get()))
    {
        guard(!_definition);
        _definition = node;
    }
    //else if (_kind == AstSymbolKind::Struct &&
    //    dynamic_cast<AstStruct*>(node.get()))
    //{
    //     guard(!_definition);
    //    _definition = node;
    //}
    //else if (_kind == AstSymbolKind::Enum &&
    //    dynamic_cast<AstEnum*>(node.get()))
    //{
    //     guard(!_definition);
    //    _definition = node;
    //}
    //else if (_kind == AstSymbolKind::Field &&
    //    dynamic_cast<AstField*>(node.get()))
    //{
    //     guard(!_definition);
    //    _definition = node;
    //}
    else
    {
        _references.push_back(node);
    }
}

std::shared_ptr<AstSymbolEntry> AstSymbolTable::AddSymbol(
    const std::string& symbolName, AstSymbolKind kind, std::shared_ptr<AstNode> node)
{
    auto entry = getEntry(symbolName, kind);
    if (!entry) {
        entry = std::make_shared<AstSymbolEntry>(symbolName, kind);
        _table[entry->getKey()] = entry;
    }
    
    if (node) {
        entry->AddNode(node);
    }
    return entry;
}

std::shared_ptr<AstSymbolEntry> AstSymbolTable::getEntry(const std::string& name, AstSymbolKind kind)
{
    if (name.find_first_of('.') != std::string::npos) {
        guard(false && "Parsing dot-names is not implemented yet.");
    }

    auto key = AstSymbolEntry::makeKey(name, kind);
    auto keyEntry = _table.find(key);
    if (keyEntry == _table.end() && _parent) {
        return _parent->getEntry(name, kind);
    }
    if (keyEntry != _table.end()) {
        return keyEntry->second;
    }
    return nullptr;
}

const std::vector<std::shared_ptr<AstSymbolEntry>> AstSymbolTable::getSymbolEntries() const
{
    std::vector<std::shared_ptr<AstSymbolEntry>> entries;
    for (auto it = _table.begin(); it != _table.end(); ++it) {
        entries.push_back(it->second);
    }
    return entries;
}

std::string AstSymbolTable::getNamespace() const
{
    if (_parent) {
        return _parent->getNamespace() + "." + _name;
    }
    return _name;
}
