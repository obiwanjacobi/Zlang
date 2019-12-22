#include "pch.h"
#include "../Utils.h"


TEST(VariablesSmokeTests, GlobalVariable) {
    const char* src =
        "g: U8 = 42\n"
        ;

    EXPECT_TRUE(ParserSmokeTest(src));
}
