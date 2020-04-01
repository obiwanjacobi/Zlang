#include "pch.h"
#include "../Utils.h"
#include <gtest/gtest.h>


TEST(FlowSmokeTests, If) {
    const char* src = 
        "fn()\n"
        "    if true\n"
        "       return\n"
        ;

    EXPECT_TRUE(ParserSmokeTest(src));
}

TEST(FlowSmokeTests, IfElse) {
    const char* src = 
        "fn()\n"
        "    if true\n"
        "       return\n"
        "    else\n"
        "       return\n"
        ;

    EXPECT_TRUE(ParserSmokeTest(src));
}

TEST(FlowSmokeTests, IfElseIfElse) {
    const char* src =
        "fn()\n"
        "    if true\n"
        "       return\n"
        "    else if false\n"
        "       return\n"
        "    else\n"
        "       return\n"
        ;

    EXPECT_TRUE(ParserSmokeTest(src));
}

TEST(FlowSmokeTests, Loop) {
    const char* src =
        "fn()\n"
        "    loop\n"
        "       x = x + 1\n"
        ;

    EXPECT_TRUE(ParserSmokeTest(src));
}

TEST(FlowSmokeTests, While) {
    const char* src =
        "fn()\n"
        "    loop x < 65535\n"
        "       x = x + 1\n"
        ;

    EXPECT_TRUE(ParserSmokeTest(src));
}

TEST(FlowSmokeTests, While2) {
    const char* src =
        "fn()\n"
        "    x: U8 = 42\n"
        "    loop x < 65535\n"
        "       x = x + 1\n"
        ;

    EXPECT_TRUE(ParserSmokeTest(src));
}
