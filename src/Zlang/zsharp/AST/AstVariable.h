#pragma once

#include "AstNode.h"
#include "AstCodeBlock.h"
#include "AstIdentifier.h"
#include "AstType.h"
#include "../grammar/parser/zsharp_parserParser.h"

class AstVariable : public AstCodeBlockItem, public AstIdentifierSite
{
public:
    bool SetIdentifier(std::shared_ptr<AstIdentifier> identifier) override {
        if (AstIdentifierSite::SetIdentifier(identifier)) {
            bool success = identifier->setParent(this);
            guard(success && "setParent failed.");
            return true;
        }
        return false;
    }

protected:
    AstVariable()
        : AstCodeBlockItem(AstNodeType::Variable)
    {}
};


class AstVariableDefinition : public AstVariable, public AstTypeReferenceSite
{
public:
    AstVariableDefinition(zsharp_parserParser::Variable_def_typedContext* ctx)
        : _typedCtx(ctx), _typedInitCtx(nullptr), _assignCtx(nullptr)
    {}

    AstVariableDefinition(zsharp_parserParser::Variable_def_typed_initContext* ctx)
        : _typedCtx(nullptr), _typedInitCtx(ctx), _assignCtx(nullptr)
    {}

    AstVariableDefinition(zsharp_parserParser::Variable_assign_autoContext* ctx)
        : _typedCtx(nullptr), _typedInitCtx(nullptr), _assignCtx(ctx)
    {}

    bool SetTypeReference(std::shared_ptr<AstTypeReference> type) override {
        if (AstTypeReferenceSite::SetTypeReference(type)) {
            bool success = type->setParent(this);
            guard(success && "setParent failed.");
            return true;
        }
        return false;
    }

    void Accept(AstVisitor* visitor) override;
    void VisitChildren(AstVisitor* visitor) override;

private:
    zsharp_parserParser::Variable_def_typedContext* _typedCtx;
    zsharp_parserParser::Variable_def_typed_initContext* _typedInitCtx;
    zsharp_parserParser::Variable_assign_autoContext* _assignCtx;
};


class AstVariableReference : public AstVariable
{
public:
    AstVariableReference(zsharp_parserParser::Variable_refContext* ctx)
        : _refContext(ctx), _assignCtx(nullptr)
    {}

    AstVariableReference(zsharp_parserParser::Variable_assign_autoContext* ctx)
        : _refContext(nullptr), _assignCtx(ctx)
    {}

    void Accept(AstVisitor* visitor) override;
    void VisitChildren(AstVisitor* visitor) override;

private:
    zsharp_parserParser::Variable_assign_autoContext* _assignCtx;
    zsharp_parserParser::Variable_refContext* _refContext;
};
