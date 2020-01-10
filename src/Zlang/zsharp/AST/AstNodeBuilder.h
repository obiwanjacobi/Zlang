#pragma once

#include "AstNode.h"
#include "AstError.h"
#include "../grammar/parser/zsharp_parserBaseVisitor.h"
#include <antlr4-runtime.h>

class AstNodeBuilder : public zsharp_parserBaseVisitor
{
    typedef zsharp_parserBaseVisitor base;

public:
    AstNodeBuilder(std::string namespace_)
        : _namespace(namespace_)
    {}

    antlrcpp::Any aggregateResult(antlrcpp::Any aggregate, const antlrcpp::Any& nextResult) override;

    antlrcpp::Any visitFile(zsharp_parserParser::FileContext* ctx) override;
    antlrcpp::Any visitStatement_import(zsharp_parserParser::Statement_importContext* ctx) override;
    antlrcpp::Any visitStatement_export(zsharp_parserParser::Statement_exportContext* ctx) override;
    antlrcpp::Any visitFunction_def(zsharp_parserParser::Function_defContext* ctx) override;

    antlrcpp::Any visitCodeblock(zsharp_parserParser::CodeblockContext* ctx) override;

    antlrcpp::Any visitStatement_if(zsharp_parserParser::Statement_ifContext* ctx) override;
    antlrcpp::Any visitStatement_else(zsharp_parserParser::Statement_elseContext* ctx) override;
    antlrcpp::Any visitStatement_elseif(zsharp_parserParser::Statement_elseifContext* ctx) override;
    antlrcpp::Any visitStatement_return(zsharp_parserParser::Statement_returnContext* ctx) override;
    antlrcpp::Any visitStatement_break(zsharp_parserParser::Statement_breakContext* ctx) override;
    antlrcpp::Any visitStatement_continue(zsharp_parserParser::Statement_continueContext* ctx) override;

    antlrcpp::Any visitVariable_assign(zsharp_parserParser::Variable_assignContext* ctx) override;
    antlrcpp::Any visitExpression_value(zsharp_parserParser::Expression_valueContext* ctx) override;

    antlrcpp::Any visitIndent(zsharp_parserParser::IndentContext* ctx) override;

    bool hasErrors() const { return _errors.size() == 0; }
    const std::vector<std::shared_ptr<AstError>>& getErrors() const { return _errors; }

protected:
    antlrcpp::Any visitChildrenExcept(antlr4::ParserRuleContext* node, antlr4::ParserRuleContext* except);

private:
    template <class T> 
    T getCurrent();
    template <class T> 
    void setCurrent(std::shared_ptr<T> current) { setCurrent(current.get()); }
    void setCurrent(AstNode* current) { _current.push_front(current); }
    void revertCurrent() { _current.pop_front(); }
    std::deque<AstNode*> _current;

    std::string ToQualifiedName(const std::string& name);
    std::string _namespace;

    void addIndentation();
    void revertIndentation() { _indentation.pop(); }
    std::stack<int> _indentation;
    int _indent;

    std::vector<std::shared_ptr<AstError>> _errors;
};

