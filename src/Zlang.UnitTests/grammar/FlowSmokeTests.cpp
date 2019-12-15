#include "pch.h"
#include "../Utils.h"


TEST(FlowSmokeTests, If) {
    const char* src = "fn()\n"
        "    if true\n"
        "       return\n"
        ;

    EXPECT_TRUE(ParserSmokeTest(src));
}

TEST(FlowSmokeTests, IfElse) {
    const char* src = "fn()\n"
        "    if true\n"
        "       return\n"
        "    else\n"
        "       return\n"
        ;

    EXPECT_TRUE(ParserSmokeTest(src));
}
