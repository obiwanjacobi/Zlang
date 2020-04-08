#pragma once

#include "AstNode.h"
#include "AstIdentifier.h"
#include "../grammar/parser/zsharp_parserParser.h"
#include <memory>


class AstType : public AstNode, public AstIdentifierSite
{
public:
    AstType(zsharp_parserParser::Type_anyContext* ctx)
        : AstNode(AstNodeType::Type), _context(ctx)
    {
        _isOptional = (ctx->QUESTION() != nullptr);
        _isError = (ctx->ERROR() != nullptr);

        guard(ctx->type_name());
        if (ctx->type_name()->identifier_type())
        {
            auto idCtx = ctx->type_name()->identifier_type();
            auto identifier = std::make_shared<AstIdentifier>(idCtx);
            SetIdentifier(identifier);
        }
        // TODO: known_types
    }

    zsharp_parserParser::Type_anyContext* getContext() const { return _context; }

    bool getIsOptional() const { return _isOptional; }
    bool getIsError() const { return _isError; }

private:
    zsharp_parserParser::Type_anyContext* _context;

    bool _isOptional;
    bool _isError;
};


class AstTypeReference : public AstType
{
public:
    AstTypeReference(zsharp_parserParser::Type_refContext* ctx)
        : AstType(ctx->type_any()), _context(ctx)
    {}

    zsharp_parserParser::Type_refContext* getRefContext() const { return _context; }

private:
    zsharp_parserParser::Type_refContext* _context;
};


class AstTypeReferenceSite
{
public:
    std::shared_ptr<AstTypeReference> getTypeReference() const { return _type; }
    virtual bool SetTypeReference(std::shared_ptr<AstTypeReference> type) {
        if (!_type && type) {
            _type = type;
            return true;
        }
        return false;
    }

private:
    std::shared_ptr<AstTypeReference> _type;
};
