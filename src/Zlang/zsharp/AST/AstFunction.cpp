#include "AstFunction.h"

bool AstFunctionParameter::AddIdentifier(std::shared_ptr<AstIdentifier> identifier)
{
    if (_identifier == nullptr) {
        _identifier = identifier;
        identifier->setParent(this);
        auto entry = AddSymbol(identifier);
        guard(entry);
        return true;
    }

    return false;
}

bool AstFunction::AddIdentifier(std::shared_ptr<AstIdentifier> identifier)
{
    if (_identifier == nullptr) {
        _identifier = identifier;
        identifier->setParent(this);
        return true;
    }

    return false;
}