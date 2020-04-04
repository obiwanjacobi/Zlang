#include "pch.h"
#include "../Utils.h"
#include <gtest/gtest.h>

// --- Arithmetic ---

TEST(ExpressionSmokeTests, ArithemeticLiterals) {
    const char* src =
        "x = 2 + 3\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(ExpressionSmokeTests, ArithemeticLiteralVariable) {
    const char* src =
        "x = 2 + a\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(ExpressionSmokeTests, ArithemeticVariables) {
    const char* src =
        "x = a + b\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(ExpressionSmokeTests, ArithemeticLiteralVariable2) {
    const char* src =
        "x = 2 + a / 2\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

// --- Comparison ---

TEST(ExpressionSmokeTests, ComparisonLiteralVariable) {
    const char* src =
        "b = 2 < a\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(ExpressionSmokeTests, ComparisonLogicalLiteralVariable) {
    const char* src =
        "b = 2 < a and 10 > b\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(ExpressionSmokeTests, ArithmeticComparisonLogicalLiteralVariable) {
    const char* src =
        "b = not ((2 + 7) / 8) > 4\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(ExpressionSmokeTests, ArithmeticBitwiseLiteralVariable) {
    const char* src =
        "b = 42 * (x + 7) >> 4\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(ExpressionSmokeTests, BitwiseArithmetic) {
    const char* src =
        "b = 42 * (x >> 7) / 4\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

