#include "pch.h"
#include "../Utils.h"
#include <gtest/gtest.h>

TEST(SmokeEnumTests, DefaultOptionsLine) {
    const char* src =
        "MyEnum\n"
        "    opt1, opt2, opt3\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(SmokeEnumTests, DefaultOptions) {
    const char* src = 
        "MyEnum\n"
        "    opt1,\n"
        "    opt2,\n"
        "    opt3,\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(SmokeEnumTests, ExplicitOptions) {
    const char* src = 
        "MyEnum\n"
        "    opt1 = 0,\n"
        "    opt2 = 1,\n"
        "    opt3 = 2\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(SmokeEnumTests, StrOptions) {
    const char* src = 
        "MyEnum: Str\n"
        "    opt1 = \"1\",\n"
        "    opt2 = \"2\",\n"
        "    opt3 = \"3\",\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(SmokeEnumTests, E_NoCommas) {
    const char* src =
        "MyEnum\n"
        "    Opt1\n"
        "    Opt2\n"
        ;

    // TODO: Error not detected! Works in debugger in VScode.
    //ASSERT_FALSE(ParserSmokeTest(src));
}

TEST(SmokeEnumTests, E_NoOptions) {
    const char* src = 
        "MyEnum\n"
        ;

    ASSERT_FALSE(ParserSmokeTest(src));
}
