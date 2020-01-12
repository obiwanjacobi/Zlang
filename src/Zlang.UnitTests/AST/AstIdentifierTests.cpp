#include "pch.h"

#include "../../Zlang/zsharp/AST/AstAssignment.h"
#include "../../Zlang/zsharp/AST/AstBuilder.h"
#include "../../Zlang/zsharp/grammar/ZsharpParser.h"
#include "../../Zlang/zsharp/grammar/parser/zsharp_parserParser.h"
#include <memory>

TEST(AstIndentifierTests, FunctionName)
{
    const char* src =
        "MyFunction()\n"
        "    c = 0\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    EXPECT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);
    EXPECT_FALSE(uut.hasErrors());

    auto fn = file->getFunctions().at(0);
    auto identifier = fn->getIdentifier();
    EXPECT_NE(identifier, nullptr);
    EXPECT_STREQ(identifier->getName().c_str(), "MyFunction");
}

TEST(AstIndentifierTests, VarAssignment)
{
    const char* src =
        "MyFunction()\n"
        "    c = 0\n"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);
    EXPECT_FALSE(parser.hasErrors());

    AstBuilder uut;
    auto file = uut.BuildFile("", fileCtx);
    EXPECT_FALSE(uut.hasErrors());

    auto fn = file->getFunctions().at(0);
    auto codeblocks = fn->getCodeBlocks();
    auto cb = codeblocks.at(0);
    auto codeItems = cb->getItems();
    auto ci = std::static_pointer_cast<AstAssignment>(codeItems.at(0));
    auto identifier = ci->getIdentifier();
    EXPECT_NE(identifier, nullptr);
    EXPECT_STREQ(identifier->getName().c_str(), "c");
}

