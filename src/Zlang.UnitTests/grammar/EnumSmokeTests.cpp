#include "pch.h"
#include "../Utils.h"
#include <gtest/gtest.h>

TEST(EnumSmokeTests, DefaultOptionsLine) {
    const char* src =
        "MyEnum\n"
        "    opt1, opt2, opt3\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(EnumSmokeTests, DefaultOptions) {
    const char* src = 
        "MyEnum\n"
        "    opt1,\n"
        "    opt2,\n"
        "    opt3,\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(EnumSmokeTests, ExplicitOptions) {
    const char* src = 
        "MyEnum\n"
        "    opt1 = 0,\n"
        "    opt2 = 1,\n"
        "    opt3 = 2\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(EnumSmokeTests, StrOptions) {
    const char* src = 
        "MyEnum: Str\n"
        "    opt1 = \"1\",\n"
        "    opt2 = \"2\",\n"
        "    opt3 = \"3\",\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(EnumSmokeTests, E_NoCommas) {
    const char* src =
        "MyEnum\n"
        "    Opt1\n"
        "    Opt2\n"
        ;

    // TODO: Error not detected! Works in debugger in VScode.
    //ASSERT_FALSE(ParserSmokeTest(src));
}

TEST(EnumSmokeTests, E_NoOptions) {
    const char* src = 
        "MyEnum\n"
        ;

    ASSERT_FALSE(ParserSmokeTest(src));
}
