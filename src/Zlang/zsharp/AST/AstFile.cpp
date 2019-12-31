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

bool AstFile::functionIsExport(std::shared_ptr<AstFunction> function)
{
    auto ctx = function->getContext();
    auto identifier = ctx->identifier_func();
    auto functionName = identifier->getText();
    return functionIsExport(functionName);
}

bool AstFile::functionIsExport(const std::string& functionName) const
{
    for (auto exprt : _exports) {
        auto identifier = exprt->identifier_func();
        if (identifier) {
            auto fnName = identifier->getText();
            return fnName == functionName;
        }
    }

    return false;
}

void AstFile::AddFunction(std::shared_ptr<AstFunction> function)
{
    if (function != nullptr) {
        function->setParent(this);

        if (functionIsExport(function)) {
            function->setIsExternal();
        }
        _functions.push_back(function);
    }
}
