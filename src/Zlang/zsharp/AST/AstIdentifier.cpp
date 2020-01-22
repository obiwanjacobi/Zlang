#include "AstIdentifier.h"
#include "AstSymbolTable.h"


AstSymbolType toSymbolType(AstIdentifierType idType)
{
    switch (idType) {
    case AstIdentifierType::Bool:
    case AstIdentifierType::Variable:
        return AstSymbolType::Variable;
    case AstIdentifierType::EnumOption:
    case AstIdentifierType::Field:
        return AstSymbolType::Field;
    case AstIdentifierType::Function:
        return AstSymbolType::Function;
    case AstIdentifierType::Parameter:
        return AstSymbolType::Parameter;
    case AstIdentifierType::Type:
        return AstSymbolType::Type;
    default:
        return AstSymbolType::NotSet;
    }
}

std::shared_ptr<AstSymbolEntry> AstIdentifierSite::AddSymbol(std::shared_ptr<AstIdentifier> identifier)
{
    auto symbols = identifier->getParentRecursive<AstSymbolTableSite>();
    return symbols->SetSymbol("", identifier->getName(),
        toSymbolType(identifier->getType()), identifier);
}

const std::string AstIdentifier::getName() const
{
    if (_boolCtx) {
        return _boolCtx->variable_ref()->identifier_var()->getText();
    }
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
    if (_boolCtx) {
        return AstIdentifierType::Bool;
    }
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