#include "pch.h"
#include "../Utils.h"
#include <gtest/gtest.h>


TEST(SmokeModuleTests, Module) {
    const char* src = 
        "module test1\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(SmokeModuleTests, Import) {
    const char* src = 
        "import somemodule.v2\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}

TEST(SmokeModuleTests, Export) {
    const char* src = 
        "export somefunction\n"
        ;

    ASSERT_TRUE(ParserSmokeTest(src));
}
