#include "pch.h"
#include "../Utils.h"
#include <gtest/gtest.h>

TEST(SmokeVariablesTests, GlobalAutoVariable) {
    const char* src =
        "g = 42\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(SmokeVariablesTests, GlobalTypedVariable) {
    const char* src =
        "g: U8\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(SmokeVariablesTests, GlobalTypedVariableInit) {
    const char* src =
        "g: U8 = 42\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(SmokeVariablesTests, LocalAutoVariable) {
    const char* src =
        "fn()\n"
        "   l = 42\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(SmokeVariablesTests, LocalTypedVariable) {
    const char* src =
        "fn()\n"
        "   l: U8\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(SmokeVariablesTests, LocalTypedVariableInit) {
    const char* src =
        "fn()\n"
        "   l: U8 = 42\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

