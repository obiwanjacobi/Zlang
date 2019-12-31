#include "AstModule.h"

void AstModule::AddModule(zsharp_parserParser::Statement_moduleContext* moduleCtx)
{
    if (moduleCtx != nullptr) {
        if (_fileModules.size() == 0) {
            _name = moduleCtx->module_name()->getText();
        }
        else {
            // TODO: check they all represent the same module
        }

        _fileModules.push_back(moduleCtx);
    }
}

void AstModule::AddFile(std::shared_ptr<AstFile> file)
{
    if (file != nullptr) {
        _files.push_back(std::move(file));
    }
}