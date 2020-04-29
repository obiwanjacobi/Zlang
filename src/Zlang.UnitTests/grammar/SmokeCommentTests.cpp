#include "pch.h"
#include "../Utils.h"
#include <gtest/gtest.h>

TEST(SmokeCommentTests, StartOfLine) {
    const char* src =
        "// comment\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(SmokeCommentTests, AfterInstruction) {
    const char* src =
        "g: U8 = 42       // comment\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(SmokeCommentTests, ThreeSlashes) {
    const char* src =
        "/// comment\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(SmokeCommentTests, WhitespaceAfter) {
    const char* src =
        "// comment      \t    \n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

