#include "pch.h"

#include "../../Zlang/zsharp/AST/AstBuilder.h"
#include "../../Zlang/zsharp/AST/AstAssignment.h"
#include "../../Zlang/zsharp/AST/AstVariable.h"
#include "../../Zlang/zsharp/Semantics/ResolveTypes.h"
#include "../../Zlang/zsharp/grammar/ZsharpParser.h"
#include "../../Zlang/zsharp/grammar/parser/zsharp_parserParser.h"
#include <gtest/gtest.h>


TEST(ResolveTypesTests, TopVariableTypeDef)
{
    const char* src =
        "a: U8\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    ResolveTypes resolver;
    resolver.Apply(file.get());

    auto cb = file->getCodeBlock();
    auto symbols = cb->getSymbols();
    auto var = cb->getItemAt<AstVariableDefinition>(0);
    auto typeRef = var->getTypeReference();
    ASSERT_NE(typeRef, nullptr);
    auto typeDef = typeRef->getTypeDefinition();
    ASSERT_NE(typeDef, nullptr);
}


TEST(ResolveTypesTests, TopVariableInferType)
{
    const char* src =
        "a = 42\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    ResolveTypes resolver;
    resolver.Apply(file.get());

    auto cb = file->getCodeBlock();
    auto symbols = cb->getSymbols();
    auto assign = cb->getItemAt<AstAssignment>(0);
    auto var = std::static_pointer_cast<AstVariableDefinition>(assign->getVariable());
    auto typeRef = var->getTypeReference();
    ASSERT_NE(typeRef, nullptr);
    ASSERT_EQ(typeRef->getParent(), var.get());
    auto identifier = typeRef->getIdentifier();
    ASSERT_EQ(identifier->getParent(), typeRef.get());
    ASSERT_STREQ(identifier->getName().c_str(), "U8");
    auto typeEntry = symbols->getEntry(typeRef->getIdentifier()->getName(), AstSymbolKind::Type);
    auto typeDef = typeRef->getTypeDefinition();
    ASSERT_NE(typeDef, nullptr);
    identifier = typeDef->getIdentifier();
    ASSERT_EQ(identifier->getParent(), typeDef.get());
    ASSERT_STREQ(identifier->getName().c_str(), "U8");
}
