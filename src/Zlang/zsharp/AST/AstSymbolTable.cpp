#include "AstSymbolTable.h"
#include "AstFunction.h"

const std::string AstSymbolName::getQualifiedName() const
{
    bool hasName = _name.size() > 0;
    bool hasNamespace = _namespace.size() > 0;

    if (hasNamespace) {
        if (!hasName) {
            return _namespace;
        }
        return _namespace + "." + _name;
    }
    return _name;
}

void AstSymbolEntry::AddNode(std::shared_ptr<AstNode> node)
{
    if (_type == AstSymbolType::Function &&
        dynamic_cast<AstFunction*>(node.get()))
    {
        _definition = node;
    } 
    else if (_type == AstSymbolType::Parameter &&
        dynamic_cast<AstFunctionParameter*>(node.get()))
    {
        _definition = node;
    }
    //else if (_type == AstSymbolType::Struct &&
    //    dynamic_cast<AstStruct*>(node.get()))
    //{
    //    _definition = node;
    //}
    //else if(_type == AstSymbolType::Type &&
    //    dynamic_cast<AstType*>(node.get()))
    //{
    //    _definition = node;
    //}
    //else if (_type == AstSymbolType::Enum &&
    //    dynamic_cast<AstEnum*>(node.get()))
    //{
    //    _definition = node;
    //}
    //else if (_type == AstSymbolType::Field &&
    //    dynamic_cast<AstField*>(node.get()))
    //{
    //    _definition = node;
    //}
    //else if (_type == AstSymbolType::Variable &&
    //    dynamic_cast<AstVariable*>(node.get()))
    //{
    //    _definition = node;
    //}
    else
    {
        _references.push_back(node);
    }
}

std::shared_ptr<AstSymbolEntry> AstSymbolTable::AddSymbol(const std::string& ns, 
    const std::string& symbolName, AstSymbolType type, std::shared_ptr<AstNode> node)
{
    auto entry = std::make_shared<AstSymbolEntry>(ns, symbolName, type);
    entry->AddNode(node);

    _table[entry->getKey()] = entry;
    return entry;
}
