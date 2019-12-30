#include "AstBuilder.h"
#include "AstNodeBuilder.h"
#include "ParseTreeNavigator.h"

AstModule* AstBuilder::AddModule(zsharp_parserParser::Statement_moduleContext* moduleCtx)
{
    assert(moduleCtx != nullptr);
    auto mod = std::make_unique<AstModule>();
    mod->AddModule(moduleCtx);

    _modules.push_back(std::move(mod));
    return mod.get();
}

void AstBuilder::Build(zsharp_parserParser::FileContext* fileCtx)
{
    ParseTreeNavigator nav;

    auto module = AddModule(nav.ToStatementModule(fileCtx));
    auto file = BuildFile(fileCtx);
    module->AddFile(std::move(file));
}

std::unique_ptr<AstFile> AstBuilder::BuildFile(zsharp_parserParser::FileContext* fileCtx)
{
    AstNodeBuilder builder;
    auto file = builder.visitFile(fileCtx);
    
    return std::move(file.as<std::unique_ptr<AstFile>>());
}
