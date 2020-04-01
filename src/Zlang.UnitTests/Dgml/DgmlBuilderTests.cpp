#include "pch.h"

#include "../../Zlang/zsharp/AST/AstBuilder.h"
#include "../../Zlang/zsharp/grammar/ZsharpParser.h"
#include "../../Zlang/zsharp/grammar/parser/zsharp_parserParser.h"
#include "../../Zlang/zsharp/Dgml/DgmlBuilder.h"
#include <gtest/gtest.h>

TEST(DgmlBuilderTests, File_If)
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
    EXPECT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("UnitTest", fileCtx);
    EXPECT_FALSE(uut.hasErrors());

    DgmlBuilder builder;
    builder.WriteFile(file);
    builder.SaveAs("DgmlBuilderTest_File_If.dgml");
}


TEST(DgmlBuilderTests, File_IfElse)
{
    const char* src =
        "// comment\n"
        "export MyFunction\n"
        "\n"
        "MyFunction(a: U8): Bool\n"
        "    if a = 42\n"
        "        return true\n"
        "    else\n"
        "        return false\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    EXPECT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("UnitTest", fileCtx);
    EXPECT_FALSE(uut.hasErrors());

    DgmlBuilder builder;
    builder.WriteFile(file);
    builder.SaveAs("DgmlBuilderTest_File_IfElse.dgml");
}

TEST(DgmlBuilderTests, File_IfElseIfElse)
{
    const char* src =
        "// comment\n"
        "export MyFunction\n"
        "\n"
        "MyFunction(a: U8): Bool\n"
        "    if a = 42\n"
        "        return true\n"
        "    else if a > 99\n"
        "        return true\n"
        "    else\n"
        "        return false\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    EXPECT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("UnitTest", fileCtx);
    EXPECT_FALSE(uut.hasErrors());

    DgmlBuilder builder;
    builder.WriteFile(file);
    builder.SaveAs("DgmlBuilderTest_File_IfElseIfElse.dgml");
}