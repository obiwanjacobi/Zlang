
// Generated from c:\Users\marc\Documents\MyProjects\Zalt\Zlang\src\zsharp\grammar\zsharp_parser.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  zsharp_parserParser : public antlr4::Parser {
public:
  enum {
    U8 = 1, U16 = 2, U24 = 3, U32 = 4, I8 = 5, I16 = 6, I24 = 7, I32 = 8, 
    F16 = 9, F32 = 10, STR = 11, BOOL = 12, BIT = 13, MODULE = 14, IMPORT = 15, 
    EXPORT = 16, LOOP = 17, BREAK = 18, CONTINUE = 19, IF = 20, ELSE = 21, 
    RETURN = 22, IN = 23, SELF = 24, TRUE = 25, FALSE = 26, COMMENT = 27, 
    NUMBERbin = 28, NUMBERoct = 29, NUMBERdec = 30, NUMBERdec_prefix = 31, 
    NUMBERhex = 32, CHARACTER = 33, STRING = 34, UNUSED = 35, PLUS = 36, 
    MINUS_NEG = 37, MULT = 38, DIV = 39, MOD = 40, POW = 41, EQ_ASSIGN = 42, 
    NEQ = 43, GREAT_ANGLEclose = 44, SMALL_ANGLEopen = 45, GREQ = 46, SMEQ = 47, 
    AND = 48, OR = 49, NOT = 50, BIT_AND = 51, BIT_OR = 52, BIT_XOR = 53, 
    BIT_NOT = 54, BIT_SHL = 55, BIT_SHR = 56, BIT_ROLL = 57, BIT_ROLR = 58, 
    CONCAT = 59, SUBopen = 60, SUBclose = 61, PARENopen = 62, PARENclose = 63, 
    QUESTION = 64, COLON = 65, DOT = 66, RANGE = 67, SPREAD = 68, COMMA = 69, 
    META = 70, COMPTIME = 71, ERROR = 72, STR_QUOTE = 73, CHAR_QUOTE = 74, 
    COMMENTstart = 75, IDENTIFIERupper = 76, IDENTIFIERlower = 77, IDENTIFIERmixed = 78, 
    SP = 79, TAB = 80, INDENT = 81, EOL = 82
  };

  enum {
    RuleFile = 0, RuleCodeblock = 1, RuleModule_statement = 2, RuleModule_name = 3, 
    RuleStatement_module = 4, RuleStatement_import = 5, RuleStatement_export = 6, 
    RuleFlow_statement = 7, RuleStatement_return = 8, RuleStatement_if = 9, 
    RuleStatement_else = 10, RuleStatement_elseif = 11, RuleStatement_break = 12, 
    RuleStatement_continue = 13, RuleStatement_loop = 14, RuleStatement_loop_infinite = 15, 
    RuleStatement_loop_while = 16, RuleDefinition_top = 17, RuleDefinition = 18, 
    RuleExpression_value = 19, RuleComptime_expression_value = 20, RuleExpression_arithmetic = 21, 
    RuleArithmetic_operand = 22, RuleExpression_logic = 23, RuleLogic_operand = 24, 
    RuleExpression_comparison = 25, RuleComparison_operand = 26, RuleExpression_bitwise = 27, 
    RuleBitwise_operand = 28, RuleExpression_bool = 29, RuleIdentifier_bool = 30, 
    RuleFunction_call = 31, RuleFunction_def = 32, RuleFunction_parameter_list = 33, 
    RuleFunction_parameter = 34, RuleFunction_type = 35, RuleFunction_parameter_uselist = 36, 
    RuleFunction_param_use = 37, RuleVariable_ref = 38, RuleParameter_ref = 39, 
    RuleVariable_def_top = 40, RuleVariable_def = 41, RuleVariable_def_typed = 42, 
    RuleVariable_def_typed_init = 43, RuleVariable_auto_assign = 44, RuleVariable_assign = 45, 
    RuleStruct_def = 46, RuleStruct_field_def_list = 47, RuleStruct_field_def = 48, 
    RuleEnum_def = 49, RuleEnum_option_def_list = 50, RuleEnum_option_def = 51, 
    RuleEnum_base_types = 52, RuleType_any = 53, RuleOptional_type = 54, 
    RuleError_type = 55, RuleOptional_error_type = 56, RuleType_name = 57, 
    RuleKnown_types = 58, RuleType_U8 = 59, RuleType_U16 = 60, RuleType_U24 = 61, 
    RuleType_U32 = 62, RuleType_I8 = 63, RuleType_I16 = 64, RuleType_I24 = 65, 
    RuleType_I32 = 66, RuleType_F16 = 67, RuleType_F32 = 68, RuleType_Str = 69, 
    RuleType_Bool = 70, RuleType_Bit = 71, RuleIdentifier_type = 72, RuleIdentifier_var = 73, 
    RuleIdentifier_param = 74, RuleIdentifier_func = 75, RuleIdentifier_field = 76, 
    RuleIdentifier_enumoption = 77, RuleIdentifier_module = 78, RuleIdentifier_unused = 79, 
    RuleLiteral_bool = 80, RuleLiteral = 81, RuleNumber = 82, RuleNumber_unsigned = 83, 
    RuleNumber_bin = 84, RuleNumber_oct = 85, RuleNumber_dec = 86, RuleNumber_hex = 87, 
    RuleNumber_char = 88, RuleOperator_arithmetic = 89, RuleOperator_arithmetic_unary = 90, 
    RuleOperator_logic = 91, RuleOperator_logic_unary = 92, RuleOperator_comparison = 93, 
    RuleOperator_bits = 94, RuleOperator_bits_unary = 95, RuleOperator_assignment = 96, 
    RuleOp_plus = 97, RuleOp_minus_neg = 98, RuleOp_mult = 99, RuleOp_div = 100, 
    RuleOp_mod = 101, RuleOp_pow = 102, RuleOp_eq_assign = 103, RuleOp_neq = 104, 
    RuleOp_great = 105, RuleOp_small = 106, RuleOp_greq = 107, RuleOp_smeq = 108, 
    RuleOp_and = 109, RuleOp_or = 110, RuleOp_not = 111, RuleOp_bit_and = 112, 
    RuleOp_bit_or = 113, RuleOp_bit_xor = 114, RuleOp_bit_not = 115, RuleOp_bit_shl = 116, 
    RuleOp_bit_shr = 117, RuleOp_bit_roll = 118, RuleOp_bit_rolr = 119, 
    RuleOp_concat = 120, RuleEmpty_line = 121, RuleNewline = 122, RuleComment = 123, 
    RuleString = 124, RuleCharacter = 125, RuleIndent = 126
  };

  zsharp_parserParser(antlr4::TokenStream *input);
  ~zsharp_parserParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class FileContext;
  class CodeblockContext;
  class Module_statementContext;
  class Module_nameContext;
  class Statement_moduleContext;
  class Statement_importContext;
  class Statement_exportContext;
  class Flow_statementContext;
  class Statement_returnContext;
  class Statement_ifContext;
  class Statement_elseContext;
  class Statement_elseifContext;
  class Statement_breakContext;
  class Statement_continueContext;
  class Statement_loopContext;
  class Statement_loop_infiniteContext;
  class Statement_loop_whileContext;
  class Definition_topContext;
  class DefinitionContext;
  class Expression_valueContext;
  class Comptime_expression_valueContext;
  class Expression_arithmeticContext;
  class Arithmetic_operandContext;
  class Expression_logicContext;
  class Logic_operandContext;
  class Expression_comparisonContext;
  class Comparison_operandContext;
  class Expression_bitwiseContext;
  class Bitwise_operandContext;
  class Expression_boolContext;
  class Identifier_boolContext;
  class Function_callContext;
  class Function_defContext;
  class Function_parameter_listContext;
  class Function_parameterContext;
  class Function_typeContext;
  class Function_parameter_uselistContext;
  class Function_param_useContext;
  class Variable_refContext;
  class Parameter_refContext;
  class Variable_def_topContext;
  class Variable_defContext;
  class Variable_def_typedContext;
  class Variable_def_typed_initContext;
  class Variable_auto_assignContext;
  class Variable_assignContext;
  class Struct_defContext;
  class Struct_field_def_listContext;
  class Struct_field_defContext;
  class Enum_defContext;
  class Enum_option_def_listContext;
  class Enum_option_defContext;
  class Enum_base_typesContext;
  class Type_anyContext;
  class Optional_typeContext;
  class Error_typeContext;
  class Optional_error_typeContext;
  class Type_nameContext;
  class Known_typesContext;
  class Type_U8Context;
  class Type_U16Context;
  class Type_U24Context;
  class Type_U32Context;
  class Type_I8Context;
  class Type_I16Context;
  class Type_I24Context;
  class Type_I32Context;
  class Type_F16Context;
  class Type_F32Context;
  class Type_StrContext;
  class Type_BoolContext;
  class Type_BitContext;
  class Identifier_typeContext;
  class Identifier_varContext;
  class Identifier_paramContext;
  class Identifier_funcContext;
  class Identifier_fieldContext;
  class Identifier_enumoptionContext;
  class Identifier_moduleContext;
  class Identifier_unusedContext;
  class Literal_boolContext;
  class LiteralContext;
  class NumberContext;
  class Number_unsignedContext;
  class Number_binContext;
  class Number_octContext;
  class Number_decContext;
  class Number_hexContext;
  class Number_charContext;
  class Operator_arithmeticContext;
  class Operator_arithmetic_unaryContext;
  class Operator_logicContext;
  class Operator_logic_unaryContext;
  class Operator_comparisonContext;
  class Operator_bitsContext;
  class Operator_bits_unaryContext;
  class Operator_assignmentContext;
  class Op_plusContext;
  class Op_minus_negContext;
  class Op_multContext;
  class Op_divContext;
  class Op_modContext;
  class Op_powContext;
  class Op_eq_assignContext;
  class Op_neqContext;
  class Op_greatContext;
  class Op_smallContext;
  class Op_greqContext;
  class Op_smeqContext;
  class Op_andContext;
  class Op_orContext;
  class Op_notContext;
  class Op_bit_andContext;
  class Op_bit_orContext;
  class Op_bit_xorContext;
  class Op_bit_notContext;
  class Op_bit_shlContext;
  class Op_bit_shrContext;
  class Op_bit_rollContext;
  class Op_bit_rolrContext;
  class Op_concatContext;
  class Empty_lineContext;
  class NewlineContext;
  class CommentContext;
  class StringContext;
  class CharacterContext;
  class IndentContext; 

  class  FileContext : public antlr4::ParserRuleContext {
  public:
    FileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<Module_statementContext *> module_statement();
    Module_statementContext* module_statement(size_t i);
    std::vector<Definition_topContext *> definition_top();
    Definition_topContext* definition_top(size_t i);
    std::vector<CommentContext *> comment();
    CommentContext* comment(size_t i);
    std::vector<Empty_lineContext *> empty_line();
    Empty_lineContext* empty_line(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FileContext* file();

  class  CodeblockContext : public antlr4::ParserRuleContext {
  public:
    CodeblockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Flow_statementContext *> flow_statement();
    Flow_statementContext* flow_statement(size_t i);
    std::vector<Variable_assignContext *> variable_assign();
    Variable_assignContext* variable_assign(size_t i);
    std::vector<DefinitionContext *> definition();
    DefinitionContext* definition(size_t i);
    std::vector<CommentContext *> comment();
    CommentContext* comment(size_t i);
    std::vector<Empty_lineContext *> empty_line();
    Empty_lineContext* empty_line(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CodeblockContext* codeblock();

  class  Module_statementContext : public antlr4::ParserRuleContext {
  public:
    Module_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Statement_moduleContext *statement_module();
    Statement_importContext *statement_import();
    Statement_exportContext *statement_export();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Module_statementContext* module_statement();

  class  Module_nameContext : public antlr4::ParserRuleContext {
  public:
    Module_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Identifier_moduleContext *identifier_module();
    Module_nameContext *module_name();
    antlr4::tree::TerminalNode *DOT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Module_nameContext* module_name();
  Module_nameContext* module_name(int precedence);
  class  Statement_moduleContext : public antlr4::ParserRuleContext {
  public:
    Statement_moduleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MODULE();
    antlr4::tree::TerminalNode *SP();
    Module_nameContext *module_name();
    NewlineContext *newline();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Statement_moduleContext* statement_module();

  class  Statement_importContext : public antlr4::ParserRuleContext {
  public:
    Statement_importContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IMPORT();
    antlr4::tree::TerminalNode *SP();
    Module_nameContext *module_name();
    NewlineContext *newline();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Statement_importContext* statement_import();

  class  Statement_exportContext : public antlr4::ParserRuleContext {
  public:
    Statement_exportContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EXPORT();
    antlr4::tree::TerminalNode *SP();
    NewlineContext *newline();
    Identifier_funcContext *identifier_func();
    Identifier_typeContext *identifier_type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Statement_exportContext* statement_export();

  class  Flow_statementContext : public antlr4::ParserRuleContext {
  public:
    Flow_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Statement_ifContext *statement_if();
    Statement_elseContext *statement_else();
    Statement_elseifContext *statement_elseif();
    Statement_loopContext *statement_loop();
    Statement_returnContext *statement_return();
    Statement_breakContext *statement_break();
    Statement_continueContext *statement_continue();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Flow_statementContext* flow_statement();

  class  Statement_returnContext : public antlr4::ParserRuleContext {
  public:
    Statement_returnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IndentContext *indent();
    antlr4::tree::TerminalNode *RETURN();
    NewlineContext *newline();
    antlr4::tree::TerminalNode *SP();
    Expression_valueContext *expression_value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Statement_returnContext* statement_return();

  class  Statement_ifContext : public antlr4::ParserRuleContext {
  public:
    Statement_ifContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IndentContext *indent();
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *SP();
    Expression_logicContext *expression_logic();
    NewlineContext *newline();
    CodeblockContext *codeblock();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Statement_ifContext* statement_if();

  class  Statement_elseContext : public antlr4::ParserRuleContext {
  public:
    Statement_elseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IndentContext *indent();
    antlr4::tree::TerminalNode *ELSE();
    NewlineContext *newline();
    CodeblockContext *codeblock();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Statement_elseContext* statement_else();

  class  Statement_elseifContext : public antlr4::ParserRuleContext {
  public:
    Statement_elseifContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IndentContext *indent();
    antlr4::tree::TerminalNode *ELSE();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    antlr4::tree::TerminalNode *IF();
    Expression_logicContext *expression_logic();
    NewlineContext *newline();
    CodeblockContext *codeblock();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Statement_elseifContext* statement_elseif();

  class  Statement_breakContext : public antlr4::ParserRuleContext {
  public:
    Statement_breakContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IndentContext *indent();
    antlr4::tree::TerminalNode *BREAK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Statement_breakContext* statement_break();

  class  Statement_continueContext : public antlr4::ParserRuleContext {
  public:
    Statement_continueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IndentContext *indent();
    antlr4::tree::TerminalNode *CONTINUE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Statement_continueContext* statement_continue();

  class  Statement_loopContext : public antlr4::ParserRuleContext {
  public:
    Statement_loopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IndentContext *indent();
    NewlineContext *newline();
    CodeblockContext *codeblock();
    Statement_loop_infiniteContext *statement_loop_infinite();
    Statement_loop_whileContext *statement_loop_while();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Statement_loopContext* statement_loop();

  class  Statement_loop_infiniteContext : public antlr4::ParserRuleContext {
  public:
    Statement_loop_infiniteContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LOOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Statement_loop_infiniteContext* statement_loop_infinite();

  class  Statement_loop_whileContext : public antlr4::ParserRuleContext {
  public:
    Statement_loop_whileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LOOP();
    antlr4::tree::TerminalNode *SP();
    Expression_logicContext *expression_logic();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Statement_loop_whileContext* statement_loop_while();

  class  Definition_topContext : public antlr4::ParserRuleContext {
  public:
    Definition_topContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Function_defContext *function_def();
    Enum_defContext *enum_def();
    Struct_defContext *struct_def();
    Variable_def_topContext *variable_def_top();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Definition_topContext* definition_top();

  class  DefinitionContext : public antlr4::ParserRuleContext {
  public:
    DefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Variable_defContext *variable_def();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DefinitionContext* definition();

  class  Expression_valueContext : public antlr4::ParserRuleContext {
  public:
    Expression_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NumberContext *number();
    StringContext *string();
    Expression_boolContext *expression_bool();
    Expression_arithmeticContext *expression_arithmetic();
    Expression_logicContext *expression_logic();
    Expression_bitwiseContext *expression_bitwise();
    Function_callContext *function_call();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expression_valueContext* expression_value();

  class  Comptime_expression_valueContext : public antlr4::ParserRuleContext {
  public:
    Comptime_expression_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NumberContext *number();
    StringContext *string();
    Expression_boolContext *expression_bool();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Comptime_expression_valueContext* comptime_expression_value();

  class  Expression_arithmeticContext : public antlr4::ParserRuleContext {
  public:
    Expression_arithmeticContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PARENopen();
    std::vector<Expression_arithmeticContext *> expression_arithmetic();
    Expression_arithmeticContext* expression_arithmetic(size_t i);
    antlr4::tree::TerminalNode *PARENclose();
    Operator_arithmetic_unaryContext *operator_arithmetic_unary();
    Arithmetic_operandContext *arithmetic_operand();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    Operator_arithmeticContext *operator_arithmetic();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expression_arithmeticContext* expression_arithmetic();
  Expression_arithmeticContext* expression_arithmetic(int precedence);
  class  Arithmetic_operandContext : public antlr4::ParserRuleContext {
  public:
    Arithmetic_operandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expression_bitwiseContext *expression_bitwise();
    NumberContext *number();
    Variable_refContext *variable_ref();
    Parameter_refContext *parameter_ref();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Arithmetic_operandContext* arithmetic_operand();

  class  Expression_logicContext : public antlr4::ParserRuleContext {
  public:
    Expression_logicContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Operator_logic_unaryContext *operator_logic_unary();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    std::vector<Expression_logicContext *> expression_logic();
    Expression_logicContext* expression_logic(size_t i);
    Logic_operandContext *logic_operand();
    Operator_logicContext *operator_logic();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expression_logicContext* expression_logic();
  Expression_logicContext* expression_logic(int precedence);
  class  Logic_operandContext : public antlr4::ParserRuleContext {
  public:
    Logic_operandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expression_comparisonContext *expression_comparison();
    Expression_boolContext *expression_bool();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Logic_operandContext* logic_operand();

  class  Expression_comparisonContext : public antlr4::ParserRuleContext {
  public:
    Expression_comparisonContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Comparison_operandContext *> comparison_operand();
    Comparison_operandContext* comparison_operand(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    Operator_comparisonContext *operator_comparison();
    antlr4::tree::TerminalNode *PARENopen();
    Expression_comparisonContext *expression_comparison();
    antlr4::tree::TerminalNode *PARENclose();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expression_comparisonContext* expression_comparison();

  class  Comparison_operandContext : public antlr4::ParserRuleContext {
  public:
    Comparison_operandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expression_arithmeticContext *expression_arithmetic();
    Expression_bitwiseContext *expression_bitwise();
    Function_callContext *function_call();
    Variable_refContext *variable_ref();
    LiteralContext *literal();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Comparison_operandContext* comparison_operand();

  class  Expression_bitwiseContext : public antlr4::ParserRuleContext {
  public:
    Expression_bitwiseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Bitwise_operandContext *> bitwise_operand();
    Bitwise_operandContext* bitwise_operand(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    Operator_bitsContext *operator_bits();
    Operator_bits_unaryContext *operator_bits_unary();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expression_bitwiseContext* expression_bitwise();

  class  Bitwise_operandContext : public antlr4::ParserRuleContext {
  public:
    Bitwise_operandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Function_callContext *function_call();
    Variable_refContext *variable_ref();
    NumberContext *number();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Bitwise_operandContext* bitwise_operand();

  class  Expression_boolContext : public antlr4::ParserRuleContext {
  public:
    Expression_boolContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Literal_boolContext *literal_bool();
    Identifier_boolContext *identifier_bool();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expression_boolContext* expression_bool();

  class  Identifier_boolContext : public antlr4::ParserRuleContext {
  public:
    Identifier_boolContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Variable_refContext *variable_ref();
    Parameter_refContext *parameter_ref();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Identifier_boolContext* identifier_bool();

  class  Function_callContext : public antlr4::ParserRuleContext {
  public:
    Function_callContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Identifier_funcContext *identifier_func();
    antlr4::tree::TerminalNode *PARENopen();
    antlr4::tree::TerminalNode *PARENclose();
    Function_parameter_uselistContext *function_parameter_uselist();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_callContext* function_call();

  class  Function_defContext : public antlr4::ParserRuleContext {
  public:
    Function_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Identifier_funcContext *identifier_func();
    antlr4::tree::TerminalNode *PARENopen();
    antlr4::tree::TerminalNode *PARENclose();
    NewlineContext *newline();
    CodeblockContext *codeblock();
    Function_parameter_listContext *function_parameter_list();
    Function_typeContext *function_type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_defContext* function_def();

  class  Function_parameter_listContext : public antlr4::ParserRuleContext {
  public:
    Function_parameter_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Function_parameterContext *> function_parameter();
    Function_parameterContext* function_parameter(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_parameter_listContext* function_parameter_list();

  class  Function_parameterContext : public antlr4::ParserRuleContext {
  public:
    Function_parameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Identifier_paramContext *identifier_param();
    Function_typeContext *function_type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_parameterContext* function_parameter();

  class  Function_typeContext : public antlr4::ParserRuleContext {
  public:
    Function_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *SP();
    Type_anyContext *type_any();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_typeContext* function_type();

  class  Function_parameter_uselistContext : public antlr4::ParserRuleContext {
  public:
    Function_parameter_uselistContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Function_param_useContext *> function_param_use();
    Function_param_useContext* function_param_use(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_parameter_uselistContext* function_parameter_uselist();

  class  Function_param_useContext : public antlr4::ParserRuleContext {
  public:
    Function_param_useContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Expression_valueContext *> expression_value();
    Expression_valueContext* expression_value(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_param_useContext* function_param_use();

  class  Variable_refContext : public antlr4::ParserRuleContext {
  public:
    Variable_refContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Identifier_varContext *identifier_var();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Variable_refContext* variable_ref();

  class  Parameter_refContext : public antlr4::ParserRuleContext {
  public:
    Parameter_refContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Identifier_paramContext *identifier_param();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Parameter_refContext* parameter_ref();

  class  Variable_def_topContext : public antlr4::ParserRuleContext {
  public:
    Variable_def_topContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NewlineContext *newline();
    Variable_def_typedContext *variable_def_typed();
    Variable_def_typed_initContext *variable_def_typed_init();
    Variable_auto_assignContext *variable_auto_assign();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Variable_def_topContext* variable_def_top();

  class  Variable_defContext : public antlr4::ParserRuleContext {
  public:
    Variable_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IndentContext *indent();
    NewlineContext *newline();
    Variable_def_typedContext *variable_def_typed();
    Variable_def_typed_initContext *variable_def_typed_init();
    Variable_auto_assignContext *variable_auto_assign();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Variable_defContext* variable_def();

  class  Variable_def_typedContext : public antlr4::ParserRuleContext {
  public:
    Variable_def_typedContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Identifier_varContext *identifier_var();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *SP();
    Type_anyContext *type_any();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Variable_def_typedContext* variable_def_typed();

  class  Variable_def_typed_initContext : public antlr4::ParserRuleContext {
  public:
    Variable_def_typed_initContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Identifier_varContext *identifier_var();
    antlr4::tree::TerminalNode *COLON();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    Type_anyContext *type_any();
    antlr4::tree::TerminalNode *EQ_ASSIGN();
    Expression_valueContext *expression_value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Variable_def_typed_initContext* variable_def_typed_init();

  class  Variable_auto_assignContext : public antlr4::ParserRuleContext {
  public:
    Variable_auto_assignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Identifier_varContext *identifier_var();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    antlr4::tree::TerminalNode *EQ_ASSIGN();
    Expression_valueContext *expression_value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Variable_auto_assignContext* variable_auto_assign();

  class  Variable_assignContext : public antlr4::ParserRuleContext {
  public:
    Variable_assignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IndentContext *indent();
    Identifier_varContext *identifier_var();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    antlr4::tree::TerminalNode *EQ_ASSIGN();
    Expression_valueContext *expression_value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Variable_assignContext* variable_assign();

  class  Struct_defContext : public antlr4::ParserRuleContext {
  public:
    Struct_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Identifier_typeContext *identifier_type();
    NewlineContext *newline();
    Struct_field_def_listContext *struct_field_def_list();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *SP();
    Type_anyContext *type_any();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Struct_defContext* struct_def();

  class  Struct_field_def_listContext : public antlr4::ParserRuleContext {
  public:
    Struct_field_def_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Struct_field_defContext *> struct_field_def();
    Struct_field_defContext* struct_field_def(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Struct_field_def_listContext* struct_field_def_list();

  class  Struct_field_defContext : public antlr4::ParserRuleContext {
  public:
    Struct_field_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IndentContext *indent();
    Identifier_fieldContext *identifier_field();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *SP();
    Type_anyContext *type_any();
    NewlineContext *newline();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Struct_field_defContext* struct_field_def();

  class  Enum_defContext : public antlr4::ParserRuleContext {
  public:
    Enum_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Identifier_typeContext *identifier_type();
    NewlineContext *newline();
    Enum_option_def_listContext *enum_option_def_list();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *SP();
    Enum_base_typesContext *enum_base_types();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Enum_defContext* enum_def();

  class  Enum_option_def_listContext : public antlr4::ParserRuleContext {
  public:
    Enum_option_def_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Enum_option_defContext *> enum_option_def();
    Enum_option_defContext* enum_option_def(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Enum_option_def_listContext* enum_option_def_list();

  class  Enum_option_defContext : public antlr4::ParserRuleContext {
  public:
    Enum_option_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IndentContext *indent();
    Identifier_enumoptionContext *identifier_enumoption();
    NewlineContext *newline();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    antlr4::tree::TerminalNode *EQ_ASSIGN();
    Comptime_expression_valueContext *comptime_expression_value();
    antlr4::tree::TerminalNode *COMMA();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Enum_option_defContext* enum_option_def();

  class  Enum_base_typesContext : public antlr4::ParserRuleContext {
  public:
    Enum_base_typesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_BitContext *type_Bit();
    Type_StrContext *type_Str();
    Type_F16Context *type_F16();
    Type_F32Context *type_F32();
    Type_I16Context *type_I16();
    Type_I24Context *type_I24();
    Type_I32Context *type_I32();
    Type_I8Context *type_I8();
    Type_U16Context *type_U16();
    Type_U24Context *type_U24();
    Type_U32Context *type_U32();
    Type_U8Context *type_U8();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Enum_base_typesContext* enum_base_types();

  class  Type_anyContext : public antlr4::ParserRuleContext {
  public:
    Type_anyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_nameContext *type_name();
    Optional_typeContext *optional_type();
    Error_typeContext *error_type();
    Optional_error_typeContext *optional_error_type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_anyContext* type_any();

  class  Optional_typeContext : public antlr4::ParserRuleContext {
  public:
    Optional_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_nameContext *type_name();
    antlr4::tree::TerminalNode *QUESTION();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Optional_typeContext* optional_type();

  class  Error_typeContext : public antlr4::ParserRuleContext {
  public:
    Error_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_nameContext *type_name();
    antlr4::tree::TerminalNode *ERROR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Error_typeContext* error_type();

  class  Optional_error_typeContext : public antlr4::ParserRuleContext {
  public:
    Optional_error_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_nameContext *type_name();
    antlr4::tree::TerminalNode *ERROR();
    antlr4::tree::TerminalNode *QUESTION();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Optional_error_typeContext* optional_error_type();

  class  Type_nameContext : public antlr4::ParserRuleContext {
  public:
    Type_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Known_typesContext *known_types();
    Identifier_typeContext *identifier_type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_nameContext* type_name();

  class  Known_typesContext : public antlr4::ParserRuleContext {
  public:
    Known_typesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_BitContext *type_Bit();
    Type_BoolContext *type_Bool();
    Type_StrContext *type_Str();
    Type_F16Context *type_F16();
    Type_F32Context *type_F32();
    Type_I16Context *type_I16();
    Type_I24Context *type_I24();
    Type_I32Context *type_I32();
    Type_I8Context *type_I8();
    Type_U16Context *type_U16();
    Type_U24Context *type_U24();
    Type_U32Context *type_U32();
    Type_U8Context *type_U8();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Known_typesContext* known_types();

  class  Type_U8Context : public antlr4::ParserRuleContext {
  public:
    Type_U8Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *U8();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_U8Context* type_U8();

  class  Type_U16Context : public antlr4::ParserRuleContext {
  public:
    Type_U16Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *U16();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_U16Context* type_U16();

  class  Type_U24Context : public antlr4::ParserRuleContext {
  public:
    Type_U24Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *U24();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_U24Context* type_U24();

  class  Type_U32Context : public antlr4::ParserRuleContext {
  public:
    Type_U32Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *U32();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_U32Context* type_U32();

  class  Type_I8Context : public antlr4::ParserRuleContext {
  public:
    Type_I8Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *I8();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_I8Context* type_I8();

  class  Type_I16Context : public antlr4::ParserRuleContext {
  public:
    Type_I16Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *I16();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_I16Context* type_I16();

  class  Type_I24Context : public antlr4::ParserRuleContext {
  public:
    Type_I24Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *I24();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_I24Context* type_I24();

  class  Type_I32Context : public antlr4::ParserRuleContext {
  public:
    Type_I32Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *I32();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_I32Context* type_I32();

  class  Type_F16Context : public antlr4::ParserRuleContext {
  public:
    Type_F16Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *F16();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_F16Context* type_F16();

  class  Type_F32Context : public antlr4::ParserRuleContext {
  public:
    Type_F32Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *F32();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_F32Context* type_F32();

  class  Type_StrContext : public antlr4::ParserRuleContext {
  public:
    Type_StrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_StrContext* type_Str();

  class  Type_BoolContext : public antlr4::ParserRuleContext {
  public:
    Type_BoolContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BOOL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_BoolContext* type_Bool();

  class  Type_BitContext : public antlr4::ParserRuleContext {
  public:
    Type_BitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BIT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_BitContext* type_Bit();

  class  Identifier_typeContext : public antlr4::ParserRuleContext {
  public:
    Identifier_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIERupper();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Identifier_typeContext* identifier_type();

  class  Identifier_varContext : public antlr4::ParserRuleContext {
  public:
    Identifier_varContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIERlower();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Identifier_varContext* identifier_var();

  class  Identifier_paramContext : public antlr4::ParserRuleContext {
  public:
    Identifier_paramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIERlower();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Identifier_paramContext* identifier_param();

  class  Identifier_funcContext : public antlr4::ParserRuleContext {
  public:
    Identifier_funcContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIERmixed();
    antlr4::tree::TerminalNode *IDENTIFIERupper();
    antlr4::tree::TerminalNode *IDENTIFIERlower();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Identifier_funcContext* identifier_func();

  class  Identifier_fieldContext : public antlr4::ParserRuleContext {
  public:
    Identifier_fieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIERmixed();
    antlr4::tree::TerminalNode *IDENTIFIERupper();
    antlr4::tree::TerminalNode *IDENTIFIERlower();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Identifier_fieldContext* identifier_field();

  class  Identifier_enumoptionContext : public antlr4::ParserRuleContext {
  public:
    Identifier_enumoptionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIERmixed();
    antlr4::tree::TerminalNode *IDENTIFIERupper();
    antlr4::tree::TerminalNode *IDENTIFIERlower();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Identifier_enumoptionContext* identifier_enumoption();

  class  Identifier_moduleContext : public antlr4::ParserRuleContext {
  public:
    Identifier_moduleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIERmixed();
    antlr4::tree::TerminalNode *IDENTIFIERupper();
    antlr4::tree::TerminalNode *IDENTIFIERlower();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Identifier_moduleContext* identifier_module();

  class  Identifier_unusedContext : public antlr4::ParserRuleContext {
  public:
    Identifier_unusedContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UNUSED();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Identifier_unusedContext* identifier_unused();

  class  Literal_boolContext : public antlr4::ParserRuleContext {
  public:
    Literal_boolContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TRUE();
    antlr4::tree::TerminalNode *FALSE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Literal_boolContext* literal_bool();

  class  LiteralContext : public antlr4::ParserRuleContext {
  public:
    LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NumberContext *number();
    StringContext *string();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LiteralContext* literal();

  class  NumberContext : public antlr4::ParserRuleContext {
  public:
    NumberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Number_unsignedContext *number_unsigned();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NumberContext* number();

  class  Number_unsignedContext : public antlr4::ParserRuleContext {
  public:
    Number_unsignedContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Number_binContext *number_bin();
    Number_octContext *number_oct();
    Number_decContext *number_dec();
    Number_hexContext *number_hex();
    Number_charContext *number_char();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Number_unsignedContext* number_unsigned();

  class  Number_binContext : public antlr4::ParserRuleContext {
  public:
    Number_binContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBERbin();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Number_binContext* number_bin();

  class  Number_octContext : public antlr4::ParserRuleContext {
  public:
    Number_octContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBERoct();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Number_octContext* number_oct();

  class  Number_decContext : public antlr4::ParserRuleContext {
  public:
    Number_decContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBERdec();
    antlr4::tree::TerminalNode *NUMBERdec_prefix();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Number_decContext* number_dec();

  class  Number_hexContext : public antlr4::ParserRuleContext {
  public:
    Number_hexContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBERhex();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Number_hexContext* number_hex();

  class  Number_charContext : public antlr4::ParserRuleContext {
  public:
    Number_charContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CharacterContext *character();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Number_charContext* number_char();

  class  Operator_arithmeticContext : public antlr4::ParserRuleContext {
  public:
    Operator_arithmeticContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Op_plusContext *op_plus();
    Op_minus_negContext *op_minus_neg();
    Op_divContext *op_div();
    Op_modContext *op_mod();
    Op_multContext *op_mult();
    Op_powContext *op_pow();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Operator_arithmeticContext* operator_arithmetic();

  class  Operator_arithmetic_unaryContext : public antlr4::ParserRuleContext {
  public:
    Operator_arithmetic_unaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Op_minus_negContext *op_minus_neg();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Operator_arithmetic_unaryContext* operator_arithmetic_unary();

  class  Operator_logicContext : public antlr4::ParserRuleContext {
  public:
    Operator_logicContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Op_andContext *op_and();
    Op_orContext *op_or();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Operator_logicContext* operator_logic();

  class  Operator_logic_unaryContext : public antlr4::ParserRuleContext {
  public:
    Operator_logic_unaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Op_notContext *op_not();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Operator_logic_unaryContext* operator_logic_unary();

  class  Operator_comparisonContext : public antlr4::ParserRuleContext {
  public:
    Operator_comparisonContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Op_eq_assignContext *op_eq_assign();
    Op_neqContext *op_neq();
    Op_greatContext *op_great();
    Op_smallContext *op_small();
    Op_greqContext *op_greq();
    Op_smeqContext *op_smeq();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Operator_comparisonContext* operator_comparison();

  class  Operator_bitsContext : public antlr4::ParserRuleContext {
  public:
    Operator_bitsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Op_bit_andContext *op_bit_and();
    Op_bit_orContext *op_bit_or();
    Op_bit_xorContext *op_bit_xor();
    Op_bit_shlContext *op_bit_shl();
    Op_bit_shrContext *op_bit_shr();
    Op_bit_rollContext *op_bit_roll();
    Op_bit_rolrContext *op_bit_rolr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Operator_bitsContext* operator_bits();

  class  Operator_bits_unaryContext : public antlr4::ParserRuleContext {
  public:
    Operator_bits_unaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Op_bit_notContext *op_bit_not();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Operator_bits_unaryContext* operator_bits_unary();

  class  Operator_assignmentContext : public antlr4::ParserRuleContext {
  public:
    Operator_assignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Op_eq_assignContext *op_eq_assign();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Operator_assignmentContext* operator_assignment();

  class  Op_plusContext : public antlr4::ParserRuleContext {
  public:
    Op_plusContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PLUS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_plusContext* op_plus();

  class  Op_minus_negContext : public antlr4::ParserRuleContext {
  public:
    Op_minus_negContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MINUS_NEG();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_minus_negContext* op_minus_neg();

  class  Op_multContext : public antlr4::ParserRuleContext {
  public:
    Op_multContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MULT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_multContext* op_mult();

  class  Op_divContext : public antlr4::ParserRuleContext {
  public:
    Op_divContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DIV();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_divContext* op_div();

  class  Op_modContext : public antlr4::ParserRuleContext {
  public:
    Op_modContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MOD();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_modContext* op_mod();

  class  Op_powContext : public antlr4::ParserRuleContext {
  public:
    Op_powContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *POW();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_powContext* op_pow();

  class  Op_eq_assignContext : public antlr4::ParserRuleContext {
  public:
    Op_eq_assignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EQ_ASSIGN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_eq_assignContext* op_eq_assign();

  class  Op_neqContext : public antlr4::ParserRuleContext {
  public:
    Op_neqContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NEQ();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_neqContext* op_neq();

  class  Op_greatContext : public antlr4::ParserRuleContext {
  public:
    Op_greatContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GREAT_ANGLEclose();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_greatContext* op_great();

  class  Op_smallContext : public antlr4::ParserRuleContext {
  public:
    Op_smallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SMALL_ANGLEopen();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_smallContext* op_small();

  class  Op_greqContext : public antlr4::ParserRuleContext {
  public:
    Op_greqContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GREQ();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_greqContext* op_greq();

  class  Op_smeqContext : public antlr4::ParserRuleContext {
  public:
    Op_smeqContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SMEQ();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_smeqContext* op_smeq();

  class  Op_andContext : public antlr4::ParserRuleContext {
  public:
    Op_andContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AND();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_andContext* op_and();

  class  Op_orContext : public antlr4::ParserRuleContext {
  public:
    Op_orContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_orContext* op_or();

  class  Op_notContext : public antlr4::ParserRuleContext {
  public:
    Op_notContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_notContext* op_not();

  class  Op_bit_andContext : public antlr4::ParserRuleContext {
  public:
    Op_bit_andContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BIT_AND();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_bit_andContext* op_bit_and();

  class  Op_bit_orContext : public antlr4::ParserRuleContext {
  public:
    Op_bit_orContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BIT_OR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_bit_orContext* op_bit_or();

  class  Op_bit_xorContext : public antlr4::ParserRuleContext {
  public:
    Op_bit_xorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BIT_XOR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_bit_xorContext* op_bit_xor();

  class  Op_bit_notContext : public antlr4::ParserRuleContext {
  public:
    Op_bit_notContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BIT_NOT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_bit_notContext* op_bit_not();

  class  Op_bit_shlContext : public antlr4::ParserRuleContext {
  public:
    Op_bit_shlContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BIT_SHL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_bit_shlContext* op_bit_shl();

  class  Op_bit_shrContext : public antlr4::ParserRuleContext {
  public:
    Op_bit_shrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BIT_SHR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_bit_shrContext* op_bit_shr();

  class  Op_bit_rollContext : public antlr4::ParserRuleContext {
  public:
    Op_bit_rollContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BIT_ROLL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_bit_rollContext* op_bit_roll();

  class  Op_bit_rolrContext : public antlr4::ParserRuleContext {
  public:
    Op_bit_rolrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BIT_ROLR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_bit_rolrContext* op_bit_rolr();

  class  Op_concatContext : public antlr4::ParserRuleContext {
  public:
    Op_concatContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONCAT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Op_concatContext* op_concat();

  class  Empty_lineContext : public antlr4::ParserRuleContext {
  public:
    Empty_lineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INDENT();
    std::vector<antlr4::tree::TerminalNode *> EOL();
    antlr4::tree::TerminalNode* EOL(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Empty_lineContext* empty_line();

  class  NewlineContext : public antlr4::ParserRuleContext {
  public:
    NewlineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOL();
    antlr4::tree::TerminalNode *INDENT();
    antlr4::tree::TerminalNode *COMMENT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NewlineContext* newline();

  class  CommentContext : public antlr4::ParserRuleContext {
  public:
    CommentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMENT();
    antlr4::tree::TerminalNode *EOL();
    antlr4::tree::TerminalNode *INDENT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CommentContext* comment();

  class  StringContext : public antlr4::ParserRuleContext {
  public:
    StringContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRING();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StringContext* string();

  class  CharacterContext : public antlr4::ParserRuleContext {
  public:
    CharacterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CHARACTER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CharacterContext* character();

  class  IndentContext : public antlr4::ParserRuleContext {
  public:
    IndentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INDENT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IndentContext* indent();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool module_nameSempred(Module_nameContext *_localctx, size_t predicateIndex);
  bool expression_arithmeticSempred(Expression_arithmeticContext *_localctx, size_t predicateIndex);
  bool expression_logicSempred(Expression_logicContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

