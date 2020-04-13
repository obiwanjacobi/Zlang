#include "AstIdentifier.h"
#include "AstSymbolTable.h"


AstSymbolKind toSymbolKind(AstIdentifierType idType)
{
    switch (idType) {
    case AstIdentifierType::Variable:
        return AstSymbolKind::Variable;
    case AstIdentifierType::EnumOption:
    case AstIdentifierType::Field:
        return AstSymbolKind::Field;
    case AstIdentifierType::Function:
        return AstSymbolKind::Function;
    case AstIdentifierType::Parameter:
        return AstSymbolKind::Parameter;
    case AstIdentifierType::Type:
        return AstSymbolKind::Type;
    default:
        return AstSymbolKind::NotSet;
    }
}

std::shared_ptr<AstSymbolEntry> AstIdentifierSite::AddSymbol(std::shared_ptr<AstIdentifier> identifier)
{
    auto symbols = identifier->getParentRecursive<AstSymbolTableSite>();
    return symbols->AddSymbol(identifier->getName(),
        toSymbolKind(identifier->getType()), identifier);
}

const std::string AstIdentifier::getName() const
{
    if (_typeCtx) {
        return _typeCtx->getText();
    }
    if (_varCtx) {
        return _varCtx->getText();
    }
    if (_paramCtx) {
        return _paramCtx->getText();
    }
    if (_funcCtx) {
        return _funcCtx->getText();
    }
    if (_fieldCtx) {
        return _fieldCtx->getText();
    }
    if (_enumOptCtx) {
        return _enumOptCtx->getText();
    }

    return "";
}

const AstIdentifierType AstIdentifier::getType() const
{
    if (_typeCtx) {
        return AstIdentifierType::Type;
    }
    if (_varCtx) {
        return AstIdentifierType::Variable;
    }
    if (_paramCtx) {
        return AstIdentifierType::Parameter;
    }
    if (_funcCtx) {
        return AstIdentifierType::Function;
    }
    if (_fieldCtx) {
        return AstIdentifierType::Field;
    }
    if (_enumOptCtx) {
        return AstIdentifierType::EnumOption;
    }

    return AstIdentifierType::Unknown;
}
