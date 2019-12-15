#include "pch.h"
#include "../Utils.h"


TEST(ModuleSmokeTests, Module) {
    const char* src = "module test1\n"
        ;

    EXPECT_TRUE(ParserSmokeTest(src));
}

TEST(ModuleSmokeTests, Import) {
    const char* src = "import somemodule.v2\n"
        ;

    EXPECT_TRUE(ParserSmokeTest(src));
}

TEST(ModuleSmokeTests, Export) {
    const char* src = "export somefunction\n"
        ;

    EXPECT_TRUE(ParserSmokeTest(src));
}
