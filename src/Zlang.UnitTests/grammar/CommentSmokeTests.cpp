#include "pch.h"
#include "../Utils.h"
#include <gtest/gtest.h>

TEST(CommentSmokeTests, StartOfLine) {
    const char* src =
        "// comment\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(CommentSmokeTests, AfterInstruction) {
    const char* src =
        "g: U8 = 42       // comment\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(CommentSmokeTests, ThreeSlashes) {
    const char* src =
        "/// comment\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(CommentSmokeTests, WhitespaceAfter) {
    const char* src =
        "// comment      \t    \n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

