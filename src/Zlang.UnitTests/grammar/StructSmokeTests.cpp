#include "pch.h"
#include "../Utils.h"


TEST(StructSmokeTests, DefaultWithFields) {
    const char* src = "MyStruct\n"
        "    fld1: U8\n"
        "    fld2: U16\n"
        "    fld3: Str\n"
        ;

    EXPECT_TRUE(ParserSmokeTest(src));
}

TEST(StructSmokeTests, DerivedWithFields) {
    const char* src = "MyStruct: OtherStruct\n"
        "    fld1: U8\n"
        "    fld2: U16\n"
        "    fld3: Str\n"
        ;

    EXPECT_TRUE(ParserSmokeTest(src));
}
