#include "pch.h"

#include "../../Zlang/zsharp/AST/AstBuilder.h"
#include "../../Zlang/zsharp/grammar/ZsharpParser.h"
#include "../../Zlang/zsharp/grammar/parser/zsharp_parserParser.h"
#include "../../Zlang/zsharp/Dgml/DgmlBuilder.h"

TEST(DgmlBuilderTests, File)
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
    builder.SaveAs("DgmlBuilderTest_File.dgml");
}