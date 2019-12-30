#include "AstFile.h"

void AstFile::AddImport(zsharp_parserParser::Statement_importContext* importCtx)
{
    if (importCtx != nullptr) {
        _imports.push_back(importCtx);
    }
}

void AstFile::AddExport(zsharp_parserParser::Statement_exportContext* exportCtx)
{
    if (exportCtx != nullptr) {
        _exports.push_back(exportCtx);
    }
}