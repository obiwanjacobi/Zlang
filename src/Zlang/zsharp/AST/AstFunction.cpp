#include "AstFunction.h"

bool AstFunctionParameter::SetIdentifier(std::shared_ptr<AstIdentifier> identifier)
{
    if (AssignIdentifier(identifier)) {
        identifier->setParent(this);
        return true;
    }
    return false;
}

bool AstFunction::SetIdentifier(std::shared_ptr<AstIdentifier> identifier)
{
    if (AssignIdentifier(identifier)) {
        identifier->setParent(this);
        return true;
    }
    return false;
}

bool AstFunction::SetCodeBlock(std::shared_ptr<AstCodeBlock> codeBlock) {
    if (!_codeblock && codeBlock) {
        codeBlock->setIndent(1);
        _codeblock = codeBlock;

        AddFunctionSymbols();
        return true;
    }
    return false;
}

std::shared_ptr<AstSymbolTable> AstFunction::getSymbols()
{
    if (_codeblock) {
        return _codeblock->getSymbols();
    }
    
    return getParent<AstSymbolTableSite>()->getSymbols();
}

std::shared_ptr<AstSymbolEntry> AstFunction::AddSymbol(const std::string& symbolName,
    AstSymbolType type, std::shared_ptr<AstNode> node)
{
    auto symbols = getSymbols();
    if (symbols) {
        return symbols->AddSymbol(symbolName, type, node);
    }
    return nullptr;
}

void AstFunction::AddFunctionSymbols()
{
    // deferred registration of function parameter symbols in the codeblock's symbol table
    for (const auto param : _parameters)
    {
        AstIdentifierSite::AddSymbol(param->getIdentifier());
    }
}