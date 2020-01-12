#include "AstSymbolTable.h"

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

void AstSymbolName::Parse(const std::string& symbol)
{

}

std::shared_ptr<AstSymbolEntry> AstSymbolTable::AddSymbol(const std::string& ns, const std::string& symbolName, AstSymbolType type, std::shared_ptr<AstNode> node)
{
    auto entry = std::make_shared<AstSymbolEntry>(ns, symbolName, type);
    entry->setNode(node);

    //_table.insert(std::pair<const std::string, std::shared_ptr<AstSymbolEntry>>(entry->getKey(), entry));
    _table[entry->getKey()] = entry;
    return entry;
}