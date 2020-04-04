#include "pch.h"

#include "../../Zlang/zsharp/AST/AstBuilder.h"
#include "../../Zlang/zsharp/grammar/ZsharpParser.h"
#include "../../Zlang/zsharp/grammar/parser/zsharp_parserParser.h"
#include <gtest/gtest.h>

TEST(AstCodeTests, Code1)
{
    const char* src =
        "// comment\n"
        "export MyFunction\n"
        "\n"
        "MyFunction(a: U8): Bool\n"
        "    if a = 42\n"
        "        return true\n"
        "    return false\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);
    ASSERT_FALSE(uut.hasErrors());
}