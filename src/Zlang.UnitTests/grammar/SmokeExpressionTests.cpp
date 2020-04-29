#include "pch.h"
#include "../Utils.h"
#include <gtest/gtest.h>

// --- Arithmetic ---

TEST(SmokeExpressionTests, ArithemeticLiterals) {
    const char* src =
        "x = 2 + 3\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(SmokeExpressionTests, ArithemeticLiteralVariable) {
    const char* src =
        "x = 2 + a\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(SmokeExpressionTests, ArithemeticVariables) {
    const char* src =
        "x = a + b\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(SmokeExpressionTests, ArithemeticLiteralVariable2) {
    const char* src =
        "x = 2 + a / 2\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

// --- Comparison ---

TEST(SmokeExpressionTests, ComparisonLiteralVariable) {
    const char* src =
        "b = 2 < a\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(SmokeExpressionTests, ComparisonLogicalLiteralVariable) {
    const char* src =
        "b = 2 < a and 10 > b\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(SmokeExpressionTests, ArithmeticComparisonLogicalLiteralVariable) {
    const char* src =
        "b = not ((2 + 7) / 8) > 4\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(SmokeExpressionTests, ArithmeticBitwiseLiteralVariable) {
    const char* src =
        "b = 42 * (x + 7) >> 4\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(SmokeExpressionTests, BitwiseArithmetic) {
    const char* src =
        "b = 42 * (x >> 7) / 4\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

