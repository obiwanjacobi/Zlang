
// Generated from c:\Users\marc\Documents\MyProjects\Zalt\Zlang\src\Zlang\zsharp\grammar\zsharp_parser.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "zsharp_parserParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by zsharp_parserParser.
 */
class  zsharp_parserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterFile(zsharp_parserParser::FileContext *ctx) = 0;
  virtual void exitFile(zsharp_parserParser::FileContext *ctx) = 0;

  virtual void enterSource(zsharp_parserParser::SourceContext *ctx) = 0;
  virtual void exitSource(zsharp_parserParser::SourceContext *ctx) = 0;

  virtual void enterCodeblock(zsharp_parserParser::CodeblockContext *ctx) = 0;
  virtual void exitCodeblock(zsharp_parserParser::CodeblockContext *ctx) = 0;

  virtual void enterModule_statement(zsharp_parserParser::Module_statementContext *ctx) = 0;
  virtual void exitModule_statement(zsharp_parserParser::Module_statementContext *ctx) = 0;

  virtual void enterModule_name(zsharp_parserParser::Module_nameContext *ctx) = 0;
  virtual void exitModule_name(zsharp_parserParser::Module_nameContext *ctx) = 0;

  virtual void enterStatement_module(zsharp_parserParser::Statement_moduleContext *ctx) = 0;
  virtual void exitStatement_module(zsharp_parserParser::Statement_moduleContext *ctx) = 0;

  virtual void enterStatement_import(zsharp_parserParser::Statement_importContext *ctx) = 0;
  virtual void exitStatement_import(zsharp_parserParser::Statement_importContext *ctx) = 0;

  virtual void enterStatement_export(zsharp_parserParser::Statement_exportContext *ctx) = 0;
  virtual void exitStatement_export(zsharp_parserParser::Statement_exportContext *ctx) = 0;

  virtual void enterFlow_statement(zsharp_parserParser::Flow_statementContext *ctx) = 0;
  virtual void exitFlow_statement(zsharp_parserParser::Flow_statementContext *ctx) = 0;

  virtual void enterStatement_return(zsharp_parserParser::Statement_returnContext *ctx) = 0;
  virtual void exitStatement_return(zsharp_parserParser::Statement_returnContext *ctx) = 0;

  virtual void enterStatement_if(zsharp_parserParser::Statement_ifContext *ctx) = 0;
  virtual void exitStatement_if(zsharp_parserParser::Statement_ifContext *ctx) = 0;

  virtual void enterStatement_else(zsharp_parserParser::Statement_elseContext *ctx) = 0;
  virtual void exitStatement_else(zsharp_parserParser::Statement_elseContext *ctx) = 0;

  virtual void enterStatement_elseif(zsharp_parserParser::Statement_elseifContext *ctx) = 0;
  virtual void exitStatement_elseif(zsharp_parserParser::Statement_elseifContext *ctx) = 0;

  virtual void enterStatement_break(zsharp_parserParser::Statement_breakContext *ctx) = 0;
  virtual void exitStatement_break(zsharp_parserParser::Statement_breakContext *ctx) = 0;

  virtual void enterStatement_continue(zsharp_parserParser::Statement_continueContext *ctx) = 0;
  virtual void exitStatement_continue(zsharp_parserParser::Statement_continueContext *ctx) = 0;

  virtual void enterStatement_loop(zsharp_parserParser::Statement_loopContext *ctx) = 0;
  virtual void exitStatement_loop(zsharp_parserParser::Statement_loopContext *ctx) = 0;

  virtual void enterStatement_loop_infinite(zsharp_parserParser::Statement_loop_infiniteContext *ctx) = 0;
  virtual void exitStatement_loop_infinite(zsharp_parserParser::Statement_loop_infiniteContext *ctx) = 0;

  virtual void enterStatement_loop_while(zsharp_parserParser::Statement_loop_whileContext *ctx) = 0;
  virtual void exitStatement_loop_while(zsharp_parserParser::Statement_loop_whileContext *ctx) = 0;

  virtual void enterDefinition_top(zsharp_parserParser::Definition_topContext *ctx) = 0;
  virtual void exitDefinition_top(zsharp_parserParser::Definition_topContext *ctx) = 0;

  virtual void enterDefinition(zsharp_parserParser::DefinitionContext *ctx) = 0;
  virtual void exitDefinition(zsharp_parserParser::DefinitionContext *ctx) = 0;

  virtual void enterExpression_value(zsharp_parserParser::Expression_valueContext *ctx) = 0;
  virtual void exitExpression_value(zsharp_parserParser::Expression_valueContext *ctx) = 0;

  virtual void enterComptime_expression_value(zsharp_parserParser::Comptime_expression_valueContext *ctx) = 0;
  virtual void exitComptime_expression_value(zsharp_parserParser::Comptime_expression_valueContext *ctx) = 0;

  virtual void enterExpression_arithmetic(zsharp_parserParser::Expression_arithmeticContext *ctx) = 0;
  virtual void exitExpression_arithmetic(zsharp_parserParser::Expression_arithmeticContext *ctx) = 0;

  virtual void enterArithmetic_operand(zsharp_parserParser::Arithmetic_operandContext *ctx) = 0;
  virtual void exitArithmetic_operand(zsharp_parserParser::Arithmetic_operandContext *ctx) = 0;

  virtual void enterExpression_logic(zsharp_parserParser::Expression_logicContext *ctx) = 0;
  virtual void exitExpression_logic(zsharp_parserParser::Expression_logicContext *ctx) = 0;

  virtual void enterLogic_operand(zsharp_parserParser::Logic_operandContext *ctx) = 0;
  virtual void exitLogic_operand(zsharp_parserParser::Logic_operandContext *ctx) = 0;

  virtual void enterExpression_comparison(zsharp_parserParser::Expression_comparisonContext *ctx) = 0;
  virtual void exitExpression_comparison(zsharp_parserParser::Expression_comparisonContext *ctx) = 0;

  virtual void enterComparison_operand(zsharp_parserParser::Comparison_operandContext *ctx) = 0;
  virtual void exitComparison_operand(zsharp_parserParser::Comparison_operandContext *ctx) = 0;

  virtual void enterExpression_bool(zsharp_parserParser::Expression_boolContext *ctx) = 0;
  virtual void exitExpression_bool(zsharp_parserParser::Expression_boolContext *ctx) = 0;

  virtual void enterFunction_call(zsharp_parserParser::Function_callContext *ctx) = 0;
  virtual void exitFunction_call(zsharp_parserParser::Function_callContext *ctx) = 0;

  virtual void enterFunction_def(zsharp_parserParser::Function_defContext *ctx) = 0;
  virtual void exitFunction_def(zsharp_parserParser::Function_defContext *ctx) = 0;

  virtual void enterFunction_def_export(zsharp_parserParser::Function_def_exportContext *ctx) = 0;
  virtual void exitFunction_def_export(zsharp_parserParser::Function_def_exportContext *ctx) = 0;

  virtual void enterFunction_parameter_list(zsharp_parserParser::Function_parameter_listContext *ctx) = 0;
  virtual void exitFunction_parameter_list(zsharp_parserParser::Function_parameter_listContext *ctx) = 0;

  virtual void enterFunction_parameter(zsharp_parserParser::Function_parameterContext *ctx) = 0;
  virtual void exitFunction_parameter(zsharp_parserParser::Function_parameterContext *ctx) = 0;

  virtual void enterFunction_parameter_self(zsharp_parserParser::Function_parameter_selfContext *ctx) = 0;
  virtual void exitFunction_parameter_self(zsharp_parserParser::Function_parameter_selfContext *ctx) = 0;

  virtual void enterFunction_parameter_uselist(zsharp_parserParser::Function_parameter_uselistContext *ctx) = 0;
  virtual void exitFunction_parameter_uselist(zsharp_parserParser::Function_parameter_uselistContext *ctx) = 0;

  virtual void enterFunction_param_use(zsharp_parserParser::Function_param_useContext *ctx) = 0;
  virtual void exitFunction_param_use(zsharp_parserParser::Function_param_useContext *ctx) = 0;

  virtual void enterVariable_ref(zsharp_parserParser::Variable_refContext *ctx) = 0;
  virtual void exitVariable_ref(zsharp_parserParser::Variable_refContext *ctx) = 0;

  virtual void enterVariable_def_top(zsharp_parserParser::Variable_def_topContext *ctx) = 0;
  virtual void exitVariable_def_top(zsharp_parserParser::Variable_def_topContext *ctx) = 0;

  virtual void enterVariable_def(zsharp_parserParser::Variable_defContext *ctx) = 0;
  virtual void exitVariable_def(zsharp_parserParser::Variable_defContext *ctx) = 0;

  virtual void enterVariable_def_typed(zsharp_parserParser::Variable_def_typedContext *ctx) = 0;
  virtual void exitVariable_def_typed(zsharp_parserParser::Variable_def_typedContext *ctx) = 0;

  virtual void enterVariable_def_typed_init(zsharp_parserParser::Variable_def_typed_initContext *ctx) = 0;
  virtual void exitVariable_def_typed_init(zsharp_parserParser::Variable_def_typed_initContext *ctx) = 0;

  virtual void enterVariable_assign_auto(zsharp_parserParser::Variable_assign_autoContext *ctx) = 0;
  virtual void exitVariable_assign_auto(zsharp_parserParser::Variable_assign_autoContext *ctx) = 0;

  virtual void enterVariable_assign(zsharp_parserParser::Variable_assignContext *ctx) = 0;
  virtual void exitVariable_assign(zsharp_parserParser::Variable_assignContext *ctx) = 0;

  virtual void enterStruct_def(zsharp_parserParser::Struct_defContext *ctx) = 0;
  virtual void exitStruct_def(zsharp_parserParser::Struct_defContext *ctx) = 0;

  virtual void enterStruct_field_def_list(zsharp_parserParser::Struct_field_def_listContext *ctx) = 0;
  virtual void exitStruct_field_def_list(zsharp_parserParser::Struct_field_def_listContext *ctx) = 0;

  virtual void enterStruct_field_def(zsharp_parserParser::Struct_field_defContext *ctx) = 0;
  virtual void exitStruct_field_def(zsharp_parserParser::Struct_field_defContext *ctx) = 0;

  virtual void enterEnum_def(zsharp_parserParser::Enum_defContext *ctx) = 0;
  virtual void exitEnum_def(zsharp_parserParser::Enum_defContext *ctx) = 0;

  virtual void enterEnum_option_def_listline(zsharp_parserParser::Enum_option_def_listlineContext *ctx) = 0;
  virtual void exitEnum_option_def_listline(zsharp_parserParser::Enum_option_def_listlineContext *ctx) = 0;

  virtual void enterEnum_option_def_list(zsharp_parserParser::Enum_option_def_listContext *ctx) = 0;
  virtual void exitEnum_option_def_list(zsharp_parserParser::Enum_option_def_listContext *ctx) = 0;

  virtual void enterEnum_option_def(zsharp_parserParser::Enum_option_defContext *ctx) = 0;
  virtual void exitEnum_option_def(zsharp_parserParser::Enum_option_defContext *ctx) = 0;

  virtual void enterEnum_option_value(zsharp_parserParser::Enum_option_valueContext *ctx) = 0;
  virtual void exitEnum_option_value(zsharp_parserParser::Enum_option_valueContext *ctx) = 0;

  virtual void enterEnum_base_type(zsharp_parserParser::Enum_base_typeContext *ctx) = 0;
  virtual void exitEnum_base_type(zsharp_parserParser::Enum_base_typeContext *ctx) = 0;

  virtual void enterType_def(zsharp_parserParser::Type_defContext *ctx) = 0;
  virtual void exitType_def(zsharp_parserParser::Type_defContext *ctx) = 0;

  virtual void enterType_alias(zsharp_parserParser::Type_aliasContext *ctx) = 0;
  virtual void exitType_alias(zsharp_parserParser::Type_aliasContext *ctx) = 0;

  virtual void enterType_ref_use(zsharp_parserParser::Type_ref_useContext *ctx) = 0;
  virtual void exitType_ref_use(zsharp_parserParser::Type_ref_useContext *ctx) = 0;

  virtual void enterType_ref(zsharp_parserParser::Type_refContext *ctx) = 0;
  virtual void exitType_ref(zsharp_parserParser::Type_refContext *ctx) = 0;

  virtual void enterType_name(zsharp_parserParser::Type_nameContext *ctx) = 0;
  virtual void exitType_name(zsharp_parserParser::Type_nameContext *ctx) = 0;

  virtual void enterKnown_types(zsharp_parserParser::Known_typesContext *ctx) = 0;
  virtual void exitKnown_types(zsharp_parserParser::Known_typesContext *ctx) = 0;

  virtual void enterType_Bit(zsharp_parserParser::Type_BitContext *ctx) = 0;
  virtual void exitType_Bit(zsharp_parserParser::Type_BitContext *ctx) = 0;

  virtual void enterType_Ptr(zsharp_parserParser::Type_PtrContext *ctx) = 0;
  virtual void exitType_Ptr(zsharp_parserParser::Type_PtrContext *ctx) = 0;

  virtual void enterType_param_number(zsharp_parserParser::Type_param_numberContext *ctx) = 0;
  virtual void exitType_param_number(zsharp_parserParser::Type_param_numberContext *ctx) = 0;

  virtual void enterType_param_list(zsharp_parserParser::Type_param_listContext *ctx) = 0;
  virtual void exitType_param_list(zsharp_parserParser::Type_param_listContext *ctx) = 0;

  virtual void enterType_param_name_list(zsharp_parserParser::Type_param_name_listContext *ctx) = 0;
  virtual void exitType_param_name_list(zsharp_parserParser::Type_param_name_listContext *ctx) = 0;

  virtual void enterType_param_type_use(zsharp_parserParser::Type_param_type_useContext *ctx) = 0;
  virtual void exitType_param_type_use(zsharp_parserParser::Type_param_type_useContext *ctx) = 0;

  virtual void enterType_param_type(zsharp_parserParser::Type_param_typeContext *ctx) = 0;
  virtual void exitType_param_type(zsharp_parserParser::Type_param_typeContext *ctx) = 0;

  virtual void enterIdentifier_type(zsharp_parserParser::Identifier_typeContext *ctx) = 0;
  virtual void exitIdentifier_type(zsharp_parserParser::Identifier_typeContext *ctx) = 0;

  virtual void enterIdentifier_var(zsharp_parserParser::Identifier_varContext *ctx) = 0;
  virtual void exitIdentifier_var(zsharp_parserParser::Identifier_varContext *ctx) = 0;

  virtual void enterIdentifier_param(zsharp_parserParser::Identifier_paramContext *ctx) = 0;
  virtual void exitIdentifier_param(zsharp_parserParser::Identifier_paramContext *ctx) = 0;

  virtual void enterIdentifier_func(zsharp_parserParser::Identifier_funcContext *ctx) = 0;
  virtual void exitIdentifier_func(zsharp_parserParser::Identifier_funcContext *ctx) = 0;

  virtual void enterIdentifier_field(zsharp_parserParser::Identifier_fieldContext *ctx) = 0;
  virtual void exitIdentifier_field(zsharp_parserParser::Identifier_fieldContext *ctx) = 0;

  virtual void enterIdentifier_enumoption(zsharp_parserParser::Identifier_enumoptionContext *ctx) = 0;
  virtual void exitIdentifier_enumoption(zsharp_parserParser::Identifier_enumoptionContext *ctx) = 0;

  virtual void enterIdentifier_module(zsharp_parserParser::Identifier_moduleContext *ctx) = 0;
  virtual void exitIdentifier_module(zsharp_parserParser::Identifier_moduleContext *ctx) = 0;

  virtual void enterIdentifier_unused(zsharp_parserParser::Identifier_unusedContext *ctx) = 0;
  virtual void exitIdentifier_unused(zsharp_parserParser::Identifier_unusedContext *ctx) = 0;

  virtual void enterLiteral_bool(zsharp_parserParser::Literal_boolContext *ctx) = 0;
  virtual void exitLiteral_bool(zsharp_parserParser::Literal_boolContext *ctx) = 0;

  virtual void enterLiteral(zsharp_parserParser::LiteralContext *ctx) = 0;
  virtual void exitLiteral(zsharp_parserParser::LiteralContext *ctx) = 0;

  virtual void enterNumber(zsharp_parserParser::NumberContext *ctx) = 0;
  virtual void exitNumber(zsharp_parserParser::NumberContext *ctx) = 0;

  virtual void enterNumber_bin(zsharp_parserParser::Number_binContext *ctx) = 0;
  virtual void exitNumber_bin(zsharp_parserParser::Number_binContext *ctx) = 0;

  virtual void enterNumber_oct(zsharp_parserParser::Number_octContext *ctx) = 0;
  virtual void exitNumber_oct(zsharp_parserParser::Number_octContext *ctx) = 0;

  virtual void enterNumber_dec(zsharp_parserParser::Number_decContext *ctx) = 0;
  virtual void exitNumber_dec(zsharp_parserParser::Number_decContext *ctx) = 0;

  virtual void enterNumber_hex(zsharp_parserParser::Number_hexContext *ctx) = 0;
  virtual void exitNumber_hex(zsharp_parserParser::Number_hexContext *ctx) = 0;

  virtual void enterNumber_char(zsharp_parserParser::Number_charContext *ctx) = 0;
  virtual void exitNumber_char(zsharp_parserParser::Number_charContext *ctx) = 0;

  virtual void enterOperator_arithmetic(zsharp_parserParser::Operator_arithmeticContext *ctx) = 0;
  virtual void exitOperator_arithmetic(zsharp_parserParser::Operator_arithmeticContext *ctx) = 0;

  virtual void enterOperator_arithmetic_unary(zsharp_parserParser::Operator_arithmetic_unaryContext *ctx) = 0;
  virtual void exitOperator_arithmetic_unary(zsharp_parserParser::Operator_arithmetic_unaryContext *ctx) = 0;

  virtual void enterOperator_logic(zsharp_parserParser::Operator_logicContext *ctx) = 0;
  virtual void exitOperator_logic(zsharp_parserParser::Operator_logicContext *ctx) = 0;

  virtual void enterOperator_logic_unary(zsharp_parserParser::Operator_logic_unaryContext *ctx) = 0;
  virtual void exitOperator_logic_unary(zsharp_parserParser::Operator_logic_unaryContext *ctx) = 0;

  virtual void enterOperator_comparison(zsharp_parserParser::Operator_comparisonContext *ctx) = 0;
  virtual void exitOperator_comparison(zsharp_parserParser::Operator_comparisonContext *ctx) = 0;

  virtual void enterOperator_bits(zsharp_parserParser::Operator_bitsContext *ctx) = 0;
  virtual void exitOperator_bits(zsharp_parserParser::Operator_bitsContext *ctx) = 0;

  virtual void enterOperator_bits_unary(zsharp_parserParser::Operator_bits_unaryContext *ctx) = 0;
  virtual void exitOperator_bits_unary(zsharp_parserParser::Operator_bits_unaryContext *ctx) = 0;

  virtual void enterOperator_assignment(zsharp_parserParser::Operator_assignmentContext *ctx) = 0;
  virtual void exitOperator_assignment(zsharp_parserParser::Operator_assignmentContext *ctx) = 0;

  virtual void enterEmpty_line(zsharp_parserParser::Empty_lineContext *ctx) = 0;
  virtual void exitEmpty_line(zsharp_parserParser::Empty_lineContext *ctx) = 0;

  virtual void enterNewline(zsharp_parserParser::NewlineContext *ctx) = 0;
  virtual void exitNewline(zsharp_parserParser::NewlineContext *ctx) = 0;

  virtual void enterComment(zsharp_parserParser::CommentContext *ctx) = 0;
  virtual void exitComment(zsharp_parserParser::CommentContext *ctx) = 0;

  virtual void enterString(zsharp_parserParser::StringContext *ctx) = 0;
  virtual void exitString(zsharp_parserParser::StringContext *ctx) = 0;

  virtual void enterCharacter(zsharp_parserParser::CharacterContext *ctx) = 0;
  virtual void exitCharacter(zsharp_parserParser::CharacterContext *ctx) = 0;

  virtual void enterIndent(zsharp_parserParser::IndentContext *ctx) = 0;
  virtual void exitIndent(zsharp_parserParser::IndentContext *ctx) = 0;


};

