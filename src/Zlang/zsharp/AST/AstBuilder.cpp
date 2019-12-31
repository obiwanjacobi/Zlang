#include "AstBuilder.h"
#include "AstNodeBuilder.h"
#include "ParseTreeNavigator.h"

std::shared_ptr<AstModule> AstBuilder::AddModule(zsharp_parserParser::Statement_moduleContext* moduleCtx)
{
    assert(moduleCtx != nullptr);
    auto mod = std::make_shared<AstModule>();
    mod->AddModule(moduleCtx);

    _modules.push_back(mod);
    return mod;
}

void AstBuilder::Build(zsharp_parserParser::FileContext* fileCtx)
{
    ParseTreeNavigator nav;

    auto module = AddModule(nav.ToStatementModule(fileCtx));
    auto file = BuildFile(module->getName(), fileCtx);
    module->AddFile(file);
}

std::shared_ptr<AstFile> AstBuilder::BuildFile(std::string moduleName, zsharp_parserParser::FileContext* fileCtx)
{
    AstNodeBuilder builder(moduleName);
    auto file = builder.visitFile(fileCtx);
    
    return file.as<std::shared_ptr<AstFile>>();
}
