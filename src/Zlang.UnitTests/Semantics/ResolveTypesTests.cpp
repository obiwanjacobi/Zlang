#include "pch.h"

#include "../../Zlang/zsharp/AST/AstBuilder.h"
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
    auto typeEntry = symbols->getEntry(typeRef->getIdentifier()->getName(), AstSymbolKind::Type);
    auto typeDef = typeRef->getTypeDefinition();
    ASSERT_NE(typeDef, nullptr);
}
