#include "pch.h"

#include "../../Zlang/zsharp/grammar/ZsharpParser.h"

bool SmokeTest(const char* src)
{
    ZsharpParser parser;
    auto parseTree = parser.parseText(src);
    return !parser.hasErrors();
}

TEST(EnumSmokeTests, DefaultOptions) {
    const char* src = "MyEnum\n"
        "    opt1\n"
        "    opt2\n"
        "    opt3\n"
        ;

    EXPECT_TRUE(SmokeTest(src));
}

TEST(EnumSmokeTests, ExplicitOptions) {
    const char* src = "MyEnum\n"
        "    opt1 = 0\n"
        "    opt2 = 1\n"
        "    opt3 = 2\n"
        ;

    EXPECT_TRUE(SmokeTest(src));
}

TEST(EnumSmokeTests, StrOptions) {
    const char* src = "MyEnum: Str\n"
        "    opt1 = \"1\"\n"
        "    opt2 = \"1\"\n"
        "    opt3 = \"1\"\n"
        ;

    EXPECT_TRUE(SmokeTest(src));
}

TEST(EnumSmokeTests, E_NoOptions) {
    const char* src = "MyEnum\n"
        ;

    EXPECT_FALSE(SmokeTest(src));
}
