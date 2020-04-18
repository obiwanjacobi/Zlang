#include "pch.h"

#include "../../Zlang/zsharp/AST/AstBuilder.h"
#include "../../Zlang/zsharp/grammar/ZsharpParser.h"
#include "../../Zlang/zsharp/grammar/parser/zsharp_parserParser.h"
#include <gtest/gtest.h>
#include "../../Zlang/zsharp/AST/AstVariable.h"

TEST(AstSymbolTableTests, FunctionName)
{
    const char* src =
        "MyFunction()\n"
        "    c = 0\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("UnitTest", fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    auto symbols = file->getSymbols();
    auto entry = symbols->getEntry("UnitTest.MyFunction", AstSymbolKind::Function);
    ASSERT_NE(entry, nullptr);
    ASSERT_EQ(entry->getSymbolKind(), AstSymbolKind::Function);
}

TEST(AstSymbolTableTests, FunctionParameterName)
{
    const char* src =
        "MyFunction(c: U8)\n"
        "    return\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("UnitTest", fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    auto fn = file->getFunctions().at(0);
    auto cb = fn->getCodeBlock();
    auto symbols = cb->getSymbols();
    auto entry = symbols->getEntry("UnitTest.MyFunction.c", AstSymbolKind::Parameter);

    ASSERT_NE(entry, nullptr);
    ASSERT_EQ(entry->getSymbolKind(), AstSymbolKind::Parameter);
}

TEST(AstSymbolTableTests, LocalVariableName)
{
    const char* src =
        "MyFunction()\n"
        "    c = 0\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("UnitTest", fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    auto fn = file->getFunctions().at(0);
    auto cb = fn->getCodeBlock();
    auto symbols = cb->getSymbols();
    auto entry = symbols->getEntry("UnitTest.MyFunction.c", AstSymbolKind::Variable);

    ASSERT_NE(entry, nullptr);
    ASSERT_EQ(entry->getSymbolKind(), AstSymbolKind::Variable);
}

TEST(AstSymbolTableTests, LocalVariableDefAndUse)
{
    const char* src =
        "MyFunction()\n"
        "    c: U8\n"
        "    c = 42\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("UnitTest", fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    auto fn = file->getFunctions().at(0);
    auto cb = fn->getCodeBlock();
    auto symbols = cb->getSymbols();
    auto entry = symbols->getEntry("UnitTest.MyFunction.c", AstSymbolKind::Variable);
    ASSERT_NE(entry, nullptr);
    ASSERT_EQ(entry->getSymbolKind(), AstSymbolKind::Variable);

    auto def = entry->getDefinition<AstVariable>();
    ASSERT_NE(def, nullptr);
    ASSERT_EQ(def->getIdentifier()->getType(), AstIdentifierType::Variable);

    auto ref = std::static_pointer_cast<AstVariableReference>(entry->getReferences().at(0));
    ASSERT_NE(ref, nullptr);
    ASSERT_EQ(ref->getIdentifier()->getType(), AstIdentifierType::Variable);
}
