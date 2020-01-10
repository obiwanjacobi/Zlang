#include "pch.h"

#include "../../Zlang/zsharp/AST/AstBuilder.h"
#include "../../Zlang/zsharp/grammar/ZsharpParser.h"
#include "../../Zlang/zsharp/grammar/parser/zsharp_parserParser.h"
#include "../../Zlang/zsharp/AST/AstBranch.h"

TEST(AstIndentationTests, Function)
{
    const char* src =
        "MyFunction()\n"
        "    c = 0\n"
        "    return\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);
    EXPECT_FALSE(uut.hasErrors());

    EXPECT_NE(file, nullptr);
    auto fn = file->getFunctions().at(0);
    auto cb = fn->getCodeBlocks().at(0);
    auto assign = cb->getItems().at(0);
    
}
