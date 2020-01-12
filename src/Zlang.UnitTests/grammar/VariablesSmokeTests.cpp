#include "pch.h"
#include "../Utils.h"

TEST(VariablesSmokeTests, GlobalAutoVariable) {
    const char* src =
        "g = 42\n"
        ;

    EXPECT_TRUE(ParserSmokeTest(src));
}

TEST(VariablesSmokeTests, GlobalTypedVariable) {
    const char* src =
        "g: U8\n"
        ;

    EXPECT_TRUE(ParserSmokeTest(src));
}

TEST(VariablesSmokeTests, GlobalTypedVariableInit) {
    const char* src =
        "g: U8 = 42\n"
        ;

    EXPECT_TRUE(ParserSmokeTest(src));
}

TEST(VariablesSmokeTests, LocalAutoVariable) {
    const char* src =
        "fn()\n"
        "   l = 42\n"
        ;

    EXPECT_TRUE(ParserSmokeTest(src));
}

TEST(VariablesSmokeTests, LocalTypedVariable) {
    const char* src =
        "fn()\n"
        "   l: U8\n"
        ;

    EXPECT_TRUE(ParserSmokeTest(src));
}

TEST(VariablesSmokeTests, LocalTypedVariableInit) {
    const char* src =
        "fn()\n"
        "   l: U8 = 42\n"
        ;

    EXPECT_TRUE(ParserSmokeTest(src));
}

