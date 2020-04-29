#include "pch.h"
#include "../Utils.h"
#include <gtest/gtest.h>


TEST(SmokeFlowTests, If) {
    const char* src = 
        "fn()\n"
        "    if true\n"
        "       return\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(SmokeFlowTests, IfElse) {
    const char* src = 
        "fn()\n"
        "    if true\n"
        "       return\n"
        "    else\n"
        "       return\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(SmokeFlowTests, IfElseIfElse) {
    const char* src =
        "fn()\n"
        "    if true\n"
        "       return\n"
        "    else if false\n"
        "       return\n"
        "    else\n"
        "       return\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(SmokeFlowTests, Loop) {
    const char* src =
        "fn()\n"
        "    loop\n"
        "       x = x + 1\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(SmokeFlowTests, While) {
    const char* src =
        "fn()\n"
        "    loop x < 65535\n"
        "       x = x + 1\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(SmokeFlowTests, While2) {
    const char* src =
        "fn()\n"
        "    x: U8 = 42\n"
        "    loop x < 65535\n"
        "       x = x + 1\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}
