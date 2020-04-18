#include "AstFile.h"

bool AstFile::AddImport(zsharp_parserParser::Statement_importContext* importCtx)
{
    if (importCtx != nullptr) {
        _imports.push_back(importCtx);
        return true;
    }
    return false;
}

bool AstFile::AddExport(zsharp_parserParser::Statement_exportContext* exportCtx)
{
    if (exportCtx != nullptr) {
        _exports.push_back(exportCtx);
        return true;
    }
    return false;
}

bool AstFile::AddFunction(std::shared_ptr<AstFunction> function)
{
    auto codeBlock = getCodeBlock();

    if (codeBlock->AddItem(function)) {
        _functions.push_back(function);
        return true;
    }
    return false;
}
