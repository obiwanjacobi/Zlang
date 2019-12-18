#include "pch.h"
#include "../Utils.h"

TEST(EnumSmokeTests, DefaultOptions) {
    const char* src = 
        "MyEnum\n"
        "    opt1\n"
        "    opt2\n"
        "    opt3\n"
        ;

    EXPECT_TRUE(ParserSmokeTest(src));
}

TEST(EnumSmokeTests, ExplicitOptions) {
    const char* src = 
        "MyEnum\n"
        "    opt1 = 0\n"
        "    opt2 = 1\n"
        "    opt3 = 2\n"
        ;

    EXPECT_TRUE(ParserSmokeTest(src));
}

TEST(EnumSmokeTests, StrOptions) {
    const char* src = 
        "MyEnum: Str\n"
        "    opt1 = \"1\"\n"
        "    opt2 = \"1\"\n"
        "    opt3 = \"1\"\n"
        ;

    EXPECT_TRUE(ParserSmokeTest(src));
}

TEST(EnumSmokeTests, E_NoOptions) {
    const char* src = 
        "MyEnum\n"
        ;

    EXPECT_FALSE(ParserSmokeTest(src));
}
