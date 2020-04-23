#include "AstType.h"
#include "AstVisitor.h"

void AstTypeReference::Accept(AstVisitor* visitor) {
    visitor->VisitTypeReference(this);
}
void AstTypeReference::VisitChildren(AstVisitor* visitor) {
    getIdentifier()->Accept(visitor);
}

static const std::shared_ptr<AstIdentifierIntrinsic> U8 = std::make_shared<AstIdentifierIntrinsic>("U8", AstIdentifierType::Type);
static const std::shared_ptr<AstIdentifierIntrinsic> U16 = std::make_shared<AstIdentifierIntrinsic>("U16", AstIdentifierType::Type);
static const std::shared_ptr<AstIdentifierIntrinsic> U24 = std::make_shared<AstIdentifierIntrinsic>("U24", AstIdentifierType::Type);
static const std::shared_ptr<AstIdentifierIntrinsic> U32 = std::make_shared<AstIdentifierIntrinsic>("U32", AstIdentifierType::Type);
static const std::shared_ptr<AstIdentifierIntrinsic> I8 = std::make_shared<AstIdentifierIntrinsic>("I8", AstIdentifierType::Type);
static const std::shared_ptr<AstIdentifierIntrinsic> I16 = std::make_shared<AstIdentifierIntrinsic>("I16", AstIdentifierType::Type);
static const std::shared_ptr<AstIdentifierIntrinsic> I24 = std::make_shared<AstIdentifierIntrinsic>("I24", AstIdentifierType::Type);
static const std::shared_ptr<AstIdentifierIntrinsic> I32 = std::make_shared<AstIdentifierIntrinsic>("I32", AstIdentifierType::Type);
static const std::shared_ptr<AstIdentifierIntrinsic> F16 = std::make_shared<AstIdentifierIntrinsic>("F16", AstIdentifierType::Type);
static const std::shared_ptr<AstIdentifierIntrinsic> F32 = std::make_shared<AstIdentifierIntrinsic>("F32", AstIdentifierType::Type);
static const std::shared_ptr<AstIdentifierIntrinsic> Str = std::make_shared<AstIdentifierIntrinsic>("Str", AstIdentifierType::Type);
static const std::shared_ptr<AstIdentifierIntrinsic> Bool = std::make_shared<AstIdentifierIntrinsic>("Bool", AstIdentifierType::Type);

std::shared_ptr<AstIdentifier> SelectKnownIdentifier(zsharp_parserParser::Known_typesContext* ctx)
{
    if (!ctx) return nullptr;
    //if (ctx->type_Bit()) return Bit;
    //if (ctx->type_Ptr()) return Ptr;

    if (ctx->type_Bool()) return Bool;
    if (ctx->type_Str()) return Str;
    if (ctx->type_F16()) return F16;
    if (ctx->type_F32()) return F32;
    if (ctx->type_I8()) return I8;
    if (ctx->type_I16()) return I16;
    if (ctx->type_I24()) return I24;
    if (ctx->type_I32()) return I32;
    if (ctx->type_U8()) return U8;
    if (ctx->type_U16()) return U16;
    if (ctx->type_U24()) return U24;
    if (ctx->type_U32()) return U32;

    return nullptr;
}

void AstType::Construct(std::shared_ptr<AstType> instance, zsharp_parserParser::Type_anyContext* ctx)
{
    auto nameCtx = ctx->type_name();
    guard(nameCtx);

    std::shared_ptr<AstIdentifier> identifier;

    auto idCtx = nameCtx->identifier_type();
    if (idCtx) {
        identifier = std::make_shared<AstIdentifier>(idCtx);
    }
    else {
        auto knownCtx = nameCtx->known_types();
        identifier = SelectKnownIdentifier(knownCtx);
    }

    guard(identifier && "Identifier failed.");
    bool success = instance->SetIdentifier(identifier);
    guard(success && "SetIdentifier() failed");
}


std::shared_ptr<AstTypeReference> AstTypeReference::Create(zsharp_parserParser::Type_refContext* ctx)
{
    auto typeRef = std::make_shared<AstTypeReference>(ctx);
    AstType::Construct(typeRef, ctx->type_any());
    return typeRef;
}
