#include "AstBuilderContext.h"

AstCodeBlock* AstBuilderContext::GetCodeBlock(uint32_t indent) const
{
    AstCodeBlock* p = nullptr;

    for (auto c : _current) {
        p = dynamic_cast<AstCodeBlock*>(c);
        if (p && p->getIndent() == indent) {
            break;
        }
    }

    guard(p != nullptr);
    return p;
}

std::shared_ptr<AstError> AstBuilderContext::AddError(antlr4::ParserRuleContext* ctx, const char* text)
{
    auto error = std::make_shared<AstError>(ctx);
    error->setText(text);
    _errors.push_back(error);
    return error;
}
