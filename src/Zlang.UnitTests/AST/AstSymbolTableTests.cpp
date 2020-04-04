#include "pch.h"

#include "../../Zlang/zsharp/AST/AstBuilder.h"
#include "../../Zlang/zsharp/grammar/ZsharpParser.h"
#include "../../Zlang/zsharp/grammar/parser/zsharp_parserParser.h"
#include <gtest/gtest.h>

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
    auto file = uut.BuildFile("", fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    auto symbols = file->getSymbols();
    auto entry = symbols->getEntry("MyFunction");
    ASSERT_NE(entry, nullptr);
    ASSERT_EQ(entry->getSymbolType(), AstSymbolType::Function);
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
    auto file = uut.BuildFile("", fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    auto fn = file->getFunctions().at(0);
    auto cb = fn->getCodeBlocks().at(0);
    auto symbols = cb->getSymbols();
    auto entry = symbols->getEntry("c");

    ASSERT_NE(entry, nullptr);
    ASSERT_EQ(entry->getSymbolType(), AstSymbolType::Variable);
}
