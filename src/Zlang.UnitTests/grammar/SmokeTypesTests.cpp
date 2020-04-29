#include "pch.h"
#include "../Utils.h"
#include <gtest/gtest.h>


TEST(SmokeTypesTests, Bit) {
    const char* src =
        "b: Bit<4>\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(SmokeTypesTests, BitInit) {
    const char* src =
        "b: Bit<4> = 12\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(SmokeTypesTests, BitBig) {
    const char* src =
        "b: Bit<1024>\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}


TEST(SmokeTypesTests, Ptr) {
    const char* src =
        "p: Ptr<U8>\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}


TEST(SmokeTypesTests, TypeDef) {
    const char* src =
        "MyType: Map<Str, U8> _\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(SmokeTypesTests, TypeAlias) {
    const char* src =
        "MyType = Map<Str, U8>\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}
