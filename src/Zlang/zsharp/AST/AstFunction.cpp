#include "AstFunction.h"
#include "AstVisitor.h"

void AstFunction::Accept(AstVisitor* visitor) {
    visitor->VisitFunction(this);
}
void AstFunctionParameter::Accept(AstVisitor* visitor) {
    visitor->VisitFunctionParameter(this);
}

bool AstFunctionParameter::SetIdentifier(std::shared_ptr<AstIdentifier> identifier)
{
    if (AstIdentifierSite::SetIdentifier(identifier)) {
        identifier->setParent(this);
        return true;
    }
    return false;
}

bool AstFunction::SetIdentifier(std::shared_ptr<AstIdentifier> identifier)
{
    if (AstIdentifierSite::SetIdentifier(identifier)) {
        identifier->setParent(this);
        return true;
    }
    return false;
}

bool AstFunction::SetCodeBlock(std::shared_ptr<AstCodeBlock> codeBlock) {
    if (AstCodeBlockSite::SetCodeBlock(codeBlock)) {
        codeBlock->setIndent(1);
        AddFunctionSymbols();
        return true;
    }
    return false;
}

std::shared_ptr<AstSymbolTable> AstFunction::getSymbols() const
{
    auto codeBlock = getCodeBlock();
    if (codeBlock) {
        return codeBlock->getSymbols();
    }
    
    return getParent<AstSymbolTableSite>()->getSymbols();
}

std::shared_ptr<AstSymbolEntry> AstFunction::AddSymbol(const std::string& symbolName,
    AstSymbolKind type, std::shared_ptr<AstNode> node)
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
        auto identifier = param->getIdentifier();
        if (identifier) {
            AstIdentifierSite::AddSymbol(identifier);
        }
    }
}