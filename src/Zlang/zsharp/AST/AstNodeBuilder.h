#pragma once

#include "AstNode.h"
#include "AstError.h"
#include "AstCodeBlock.h"
#include "../grammar/parser/zsharp_parserBaseVisitor.h"
#include <antlr4-runtime.h>

class AstNodeBuilder : public zsharp_parserBaseVisitor
{
    typedef zsharp_parserBaseVisitor base;

public:
    AstNodeBuilder(std::string namespace_, int defaultIndentation = 0)
        : _namespace(namespace_), _indent(defaultIndentation)
    {}

    antlrcpp::Any aggregateResult(antlrcpp::Any aggregate, const antlrcpp::Any& nextResult) override;

    antlrcpp::Any visitFile(zsharp_parserParser::FileContext* ctx) override;
    antlrcpp::Any visitStatement_import(zsharp_parserParser::Statement_importContext* ctx) override;
    antlrcpp::Any visitStatement_export(zsharp_parserParser::Statement_exportContext* ctx) override;

    // WIP: block iteration for now - not implemented yet
    antlrcpp::Any visitVariable_def_top(zsharp_parserParser::Variable_def_topContext* ctx) override { return nullptr; }

    antlrcpp::Any visitFunction_def(zsharp_parserParser::Function_defContext* ctx) override;
    antlrcpp::Any visitCodeblock(zsharp_parserParser::CodeblockContext* ctx) override;

    antlrcpp::Any visitStatement_if(zsharp_parserParser::Statement_ifContext* ctx) override;
    antlrcpp::Any visitStatement_else(zsharp_parserParser::Statement_elseContext* ctx) override;
    antlrcpp::Any visitStatement_elseif(zsharp_parserParser::Statement_elseifContext* ctx) override;
    antlrcpp::Any visitStatement_return(zsharp_parserParser::Statement_returnContext* ctx) override;
    antlrcpp::Any visitStatement_break(zsharp_parserParser::Statement_breakContext* ctx) override;
    antlrcpp::Any visitStatement_continue(zsharp_parserParser::Statement_continueContext* ctx) override;

    antlrcpp::Any visitIdentifier_bool(zsharp_parserParser::Identifier_boolContext* ctx) override;
    antlrcpp::Any visitIdentifier_type(zsharp_parserParser::Identifier_typeContext* ctx) override;
    antlrcpp::Any visitIdentifier_var(zsharp_parserParser::Identifier_varContext* ctx) override;
    antlrcpp::Any visitIdentifier_param(zsharp_parserParser::Identifier_paramContext* ctx) override;
    antlrcpp::Any visitIdentifier_func(zsharp_parserParser::Identifier_funcContext* ctx) override;
    antlrcpp::Any visitIdentifier_field(zsharp_parserParser::Identifier_fieldContext* ctx) override;
    antlrcpp::Any visitIdentifier_enumoption(zsharp_parserParser::Identifier_enumoptionContext* ctx) override;

    antlrcpp::Any visitFunction_parameter(zsharp_parserParser::Function_parameterContext* ctx) override;
    antlrcpp::Any visitFunction_parameter_self(zsharp_parserParser::Function_parameter_selfContext* ctx) override;

    antlrcpp::Any visitVariable_assign(zsharp_parserParser::Variable_assignContext* ctx) override;
    antlrcpp::Any visitExpression_value(zsharp_parserParser::Expression_valueContext* ctx) override;
    antlrcpp::Any visitExpression_logic(zsharp_parserParser::Expression_logicContext* ctx) override;

    antlrcpp::Any visitIndent(zsharp_parserParser::IndentContext* ctx) override;

    bool hasErrors() const { return _errors.size() == 0; }
    const std::vector<std::shared_ptr<AstError>>& getErrors() const { return _errors; }

protected:
    antlrcpp::Any visitChildrenExcept(antlr4::ParserRuleContext* node, const antlr4::ParserRuleContext* except);

    template<class T>
    bool AddIdentifier(T ctx);

private:
    AstCodeBlock* findCodeBlock(uint32_t indent) const;
    template <class T> 
    T* findCurrent() const;
    template <class T>
    T* getCurrent() const { return dynamic_cast<T*>(_current.front()); }
    template <class T> 
    void setCurrent(std::shared_ptr<T> current) { setCurrent(current.get()); }
    void setCurrent(AstNode* current) { _current.push_front(current); }
    void revertCurrent() { _current.pop_front(); }
    std::deque<AstNode*> _current;

    std::string _namespace;

    int _indent;
    template <class T>
    uint32_t getIndent(T ctx) {
        return visitIndent(ctx->indent()).as<uint64_t>();
    }

    std::shared_ptr<AstError> AddError(antlr4::ParserRuleContext* ctx, const char* text);
    std::vector<std::shared_ptr<AstError>> _errors;
};

