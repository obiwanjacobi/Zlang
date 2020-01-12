#include "pch.h"

#include "../../Zlang/zsharp/AST/AstNumericBuilder.h"
#include "../../Zlang/zsharp/grammar/ZsharpParser.h"
#include "../../Zlang/zsharp/grammar/parser/zsharp_parserParser.h"

TEST(AstNumericBuilderTests, Binary)
{
    const char* src =
        "a = 0b0000_0000_1111_0000\n"
        ;

    ZsharpParser parser;
    auto sourceCtx = parser.parseText(src);
    EXPECT_FALSE(parser.hasErrors());

    AstNumericBuilder uut;
    auto numeric = uut.Test(sourceCtx);

    EXPECT_NE(numeric, nullptr);
    EXPECT_EQ(numeric->getUnsignedInt(), (uint64_t)0x00F0);
}

TEST(AstNumericBuilderTests, Octal)
{
    const char* src =
        "a = 0c10\n"
        ;

    ZsharpParser parser;
    auto sourceCtx = parser.parseText(src);
    EXPECT_FALSE(parser.hasErrors());

    AstNumericBuilder uut;
    auto numeric = uut.Test(sourceCtx);

    EXPECT_NE(numeric, nullptr);
    EXPECT_EQ(numeric->getUnsignedInt(), (uint64_t)8);
}

TEST(AstNumericBuilderTests, Decimal)
{
    const char* src =
        "a = 42\n"
        ;

    ZsharpParser parser;
    auto sourceCtx = parser.parseText(src);
    EXPECT_FALSE(parser.hasErrors());

    AstNumericBuilder uut;
    auto numeric = uut.Test(sourceCtx);

    EXPECT_NE(numeric, nullptr);
    EXPECT_EQ(numeric->getUnsignedInt(), (uint64_t)42);
}

TEST(AstNumericBuilderTests, DecimalPrefix)
{
    const char* src =
        "a = 0d42_42\n"
        ;

    ZsharpParser parser;
    auto sourceCtx = parser.parseText(src);
    EXPECT_FALSE(parser.hasErrors());

    AstNumericBuilder uut;
    auto numeric = uut.Test(sourceCtx);

    EXPECT_NE(numeric, nullptr);
    EXPECT_EQ(numeric->getUnsignedInt(), (uint64_t)4242);
}

TEST(AstNumericBuilderTests, Hexadecimal)
{
    const char* src =
        "a = 0x42\n"
        ;

    ZsharpParser parser;
    auto sourceCtx = parser.parseText(src);
    EXPECT_FALSE(parser.hasErrors());

    AstNumericBuilder uut;
    auto numeric = uut.Test(sourceCtx);

    EXPECT_NE(numeric, nullptr);
    EXPECT_EQ(numeric->getUnsignedInt(), (uint64_t)0x42);
}
