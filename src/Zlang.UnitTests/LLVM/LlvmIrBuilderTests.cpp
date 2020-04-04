#include "pch.h"

#include "../../Zlang/zsharp/AST/AstBuilder.h"
#include "../../Zlang/zsharp/grammar/ZsharpParser.h"
#include "../../Zlang/zsharp/grammar/parser/zsharp_parserParser.h"
#include "../../Zlang/zsharp/LLVM/LlvmIrBuilder.h"
#include <gtest/gtest.h>

TEST(LlvmIrBuilderTests, BuildFile) 
{
    const char* src =
        "module mod1\n"
        "fn()\n"
        "    return\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    ASSERT_FALSE(parser.hasErrors());

    AstBuilder uut;
    uut.Build(fileCtx);
    ASSERT_FALSE(uut.hasErrors());

    auto modules = uut.getModules();

    LlvmIrBuilder builder;
    auto llvmModule = builder.Build(modules.at(0));

    llvmModule->dump();
}
