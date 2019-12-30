#include "AstModule.h"

void AstModule::AddModule(zsharp_parserParser::Statement_moduleContext* moduleCtx)
{
    if (moduleCtx != nullptr) {
        _fileModules.push_back(moduleCtx);
    }
}

void AstModule::AddFile(std::unique_ptr<AstFile> file)
{
    if (file != nullptr) {
        _files.push_back(std::move(file));
    }
}