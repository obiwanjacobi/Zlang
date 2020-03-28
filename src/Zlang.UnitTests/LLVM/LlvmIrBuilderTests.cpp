#include "pch.h"

#include "../../Zlang/zsharp/AST/AstBuilder.h"
#include "../../Zlang/zsharp/grammar/ZsharpParser.h"
#include "../../Zlang/zsharp/grammar/parser/zsharp_parserParser.h"
#include "../../Zlang/zsharp/LLVM/LlvmIrBuilder.h"

TEST(LlvmIrBuilderTests, BuildFile) 
{
    const char* src =
        "module mod1\n"
        "fn()\n"
        "    return\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    EXPECT_FALSE(parser.hasErrors());

    AstBuilder uut;
    uut.Build(fileCtx);
    auto modules = uut.getModules();

    LlvmIrBuilder builder;
    auto llvmModule = builder.Build(modules.at(0));

    llvmModule->dump();
}
