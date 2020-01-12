#include "pch.h"

#include "../../Zlang/zsharp/AST/AstBuilder.h"
#include "../../Zlang/zsharp/grammar/ZsharpParser.h"
#include "../../Zlang/zsharp/grammar/parser/zsharp_parserParser.h"

TEST(AstSymbolTableTests, FunctionName)
{
    const char* src =
        "MyFunction()\n"
        "    c = 0\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    EXPECT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);
    EXPECT_FALSE(uut.hasErrors());

    auto symbols = file->getSymbols();
    auto entry = symbols->getEntry("MyFunction");
    EXPECT_NE(entry, nullptr);
    EXPECT_EQ(entry->getSymbolType(), AstSymbolType::Function);
}

TEST(AstSymbolTableTests, LocalVariableName)
{
    const char* src =
        "MyFunction()\n"
        "    c = 0\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    EXPECT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);
    EXPECT_FALSE(uut.hasErrors());

    auto symbols = file->getSymbols();
    auto entry = symbols->getEntry("c");

    EXPECT_NE(entry, nullptr);
    EXPECT_EQ(entry->getSymbolType(), AstSymbolType::Variable);
}
