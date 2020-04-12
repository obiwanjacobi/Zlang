#pragma once

#include "AstNode.h"
#include "AstCodeBlock.h"
#include "AstError.h"
#include "../../Utils.h"
#include <antlr4-runtime.h>
#include <memory>

class AstBuilderContext
{
public:
    AstBuilderContext(int indent)
        : _indent(indent)
    {}

    template <class T>
    void setCurrent(std::shared_ptr<T> current) { setCurrent(current.get()); }
    void setCurrent(AstNode* current) { _current.push_front(current); }
    void revertCurrent() { _current.pop_front(); }
    AstCodeBlock* GetCodeBlock(uint32_t indent) const;

    template <class T>
    T* GetCurrent() const
    {
        T* p = nullptr;

        for (auto c : _current) {
            p = dynamic_cast<T*>(c);
            if (p) {
                break;
            }
        }

        guard(p != nullptr);
        return p;
    }

    template<class T>
    uint32_t CheckIndent(T ctx)
    {
        auto indentCtx = ctx->indent();
        auto indent = indentCtx->getText().length();
        assert(std::numeric_limits<int32_t>::max() > indent);

        if (_indent == 0) {
            _indent = indent;
        }

        if (indent % _indent) {
            AddError(ctx, AstError::IndentationInvalid);
            // guess where it should go
            return std::lroundf(indent / _indent);
        }

        return indent / _indent;
    }


    std::shared_ptr<AstError> AddError(antlr4::ParserRuleContext* ctx, const char* text);
    bool hasErrors() const { return _errors.size() == 0; }
    const std::vector<std::shared_ptr<AstError>>& getErrors() const { return _errors; }

private:
    int _indent;
    std::deque<AstNode*> _current;
    std::vector<std::shared_ptr<AstError>> _errors;
};
