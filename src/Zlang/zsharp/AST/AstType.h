#pragma once

#include "AstNode.h"
#include "AstIdentifier.h"
#include "../grammar/parser/zsharp_parserParser.h"
#include <memory>


class AstType : public AstNode, public AstIdentifierSite
{
public:
    zsharp_parserParser::Type_anyContext* getContext() const { return _context; }

    bool getIsOptional() const { return _isOptional; }
    bool getIsError() const { return _isError; }

protected:
    AstType(zsharp_parserParser::Type_anyContext* ctx)
        : AstNode(AstNodeType::Type), _context(ctx),
        _isOptional(ctx->QUESTION() != nullptr),
        _isError(ctx->ERROR() != nullptr)
    {}

    static void Construct(std::shared_ptr<AstType> instance, zsharp_parserParser::Type_anyContext* ctx);

private:
    zsharp_parserParser::Type_anyContext* _context;

    bool _isOptional;
    bool _isError;
};


class AstTypeReference : public AstType
{
public:
    static std::shared_ptr<AstTypeReference> Create(zsharp_parserParser::Type_refContext* ctx);

    // Do not use (needed for std::make_shared)
    AstTypeReference(zsharp_parserParser::Type_refContext* ctx)
        : AstType(ctx->type_any())
    {}
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
