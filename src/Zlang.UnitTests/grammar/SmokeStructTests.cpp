#include "pch.h"
#include "../Utils.h"
#include <gtest/gtest.h>


TEST(SmokeStructTests, DefaultWithFields) {
    const char* src = 
        "MyStruct\n"
        "    fld1: U8\n"
        "    fld2: U16\n"
        "    fld3: Str\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(SmokeStructTests, DerivedWithFields) {
    const char* src = 
        "MyStruct: OtherStruct\n"
        "    fld1: U8\n"
        "    fld2: U16\n"
        "    fld3: Str\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(SmokeStructTests, DefaultWithTypeParam1) {
    const char* src =
        "MyStruct<T>\n"
        "    fld1: T\n"
        "    fld2: U16\n"
        "    fld3: Str\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}
