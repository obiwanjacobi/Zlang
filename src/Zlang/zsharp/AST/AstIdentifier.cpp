#include "AstIdentifier.h"

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
}