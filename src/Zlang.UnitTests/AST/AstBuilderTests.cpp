#include "pch.h"

#include "../../Zlang/zsharp/AST/AstBuilder.h"
#include "../../Zlang/zsharp/grammar/ZsharpParser.h"
#include "../../Zlang/zsharp/grammar/parser/zsharp_parserParser.h"

TEST(AstBuilderTests, BuildFile_empty) {
    
    const char* src = 
        "// comment"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);

    AstBuilder uut;
    auto file = uut.BuildFile(fileCtx);

    EXPECT_NE(file, nullptr);
    EXPECT_EQ(file->getNodeType(), AstNodeType::File);
}

TEST(AstBuilderTests, BuildFile_ImportsOne) {

    const char* src =
        "import importmodule"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);

    AstBuilder uut;
    auto file = uut.BuildFile(fileCtx);

    auto imports = file->getImports();
    EXPECT_EQ(imports.size(), 1);

    auto import = imports.at(0);
    auto modName = import->module_name();
    auto text = modName->getText();
    EXPECT_STREQ(text.c_str(), "importmodule");
}

TEST(AstBuilderTests, BuildFile_ExportsOne) {

    const char* src =
        "export myFunction"
        ;

    ZsharpParser parser;
    auto fileCtx = parser.parseFileText(src);

    AstBuilder uut;
    auto file = uut.BuildFile(fileCtx);

    auto exports = file->getExports();
    EXPECT_EQ(exports.size(), 1);

    auto exprt = exports.at(0);
    auto funName = exprt->identifier_func();
    auto text = funName->getText();
    EXPECT_STREQ(text.c_str(), "myFunction");
}
