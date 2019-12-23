#include "pch.h"
#include "../Utils.h"


TEST(TypesSmokeTests, Bit) {
    const char* src =
        "b: Bit<4>\n"
        ;

    EXPECT_TRUE(ParserSmokeTest(src));
}

TEST(TypesSmokeTests, BitInit) {
    const char* src =
        "b: Bit<4> = 12\n"
        ;

    EXPECT_TRUE(ParserSmokeTest(src));
}

TEST(TypesSmokeTests, BitBig) {
    const char* src =
        "b: Bit<1024>\n"
        ;

    EXPECT_TRUE(ParserSmokeTest(src));
}


TEST(TypesSmokeTests, Ptr) {
    const char* src =
        "p: Ptr<U8>\n"
        ;

    EXPECT_TRUE(ParserSmokeTest(src));
}
