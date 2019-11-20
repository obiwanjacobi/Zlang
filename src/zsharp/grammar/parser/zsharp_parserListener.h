
// Generated from c:\Users\marc\Documents\MyProjects\Zalt\Zlang\src\zsharp\grammar\zsharp_parser.g4 by ANTLR 4.7.1

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

  virtual void enterExpression_bitwise(zsharp_parserParser::Expression_bitwiseContext *ctx) = 0;
  virtual void exitExpression_bitwise(zsharp_parserParser::Expression_bitwiseContext *ctx) = 0;

  virtual void enterBitwise_operand(zsharp_parserParser::Bitwise_operandContext *ctx) = 0;
  virtual void exitBitwise_operand(zsharp_parserParser::Bitwise_operandContext *ctx) = 0;

  virtual void enterExpression_bool(zsharp_parserParser::Expression_boolContext *ctx) = 0;
  virtual void exitExpression_bool(zsharp_parserParser::Expression_boolContext *ctx) = 0;

  virtual void enterIdentifier_bool(zsharp_parserParser::Identifier_boolContext *ctx) = 0;
  virtual void exitIdentifier_bool(zsharp_parserParser::Identifier_boolContext *ctx) = 0;

  virtual void enterFunction_call(zsharp_parserParser::Function_callContext *ctx) = 0;
  virtual void exitFunction_call(zsharp_parserParser::Function_callContext *ctx) = 0;

  virtual void enterFunction_def(zsharp_parserParser::Function_defContext *ctx) = 0;
  virtual void exitFunction_def(zsharp_parserParser::Function_defContext *ctx) = 0;

  virtual void enterFunction_parameter_list(zsharp_parserParser::Function_parameter_listContext *ctx) = 0;
  virtual void exitFunction_parameter_list(zsharp_parserParser::Function_parameter_listContext *ctx) = 0;

  virtual void enterFunction_parameter(zsharp_parserParser::Function_parameterContext *ctx) = 0;
  virtual void exitFunction_parameter(zsharp_parserParser::Function_parameterContext *ctx) = 0;

  virtual void enterFunction_type(zsharp_parserParser::Function_typeContext *ctx) = 0;
  virtual void exitFunction_type(zsharp_parserParser::Function_typeContext *ctx) = 0;

  virtual void enterFunction_parameter_uselist(zsharp_parserParser::Function_parameter_uselistContext *ctx) = 0;
  virtual void exitFunction_parameter_uselist(zsharp_parserParser::Function_parameter_uselistContext *ctx) = 0;

  virtual void enterFunction_param_use(zsharp_parserParser::Function_param_useContext *ctx) = 0;
  virtual void exitFunction_param_use(zsharp_parserParser::Function_param_useContext *ctx) = 0;

  virtual void enterVariable_ref(zsharp_parserParser::Variable_refContext *ctx) = 0;
  virtual void exitVariable_ref(zsharp_parserParser::Variable_refContext *ctx) = 0;

  virtual void enterParameter_ref(zsharp_parserParser::Parameter_refContext *ctx) = 0;
  virtual void exitParameter_ref(zsharp_parserParser::Parameter_refContext *ctx) = 0;

  virtual void enterVariable_def(zsharp_parserParser::Variable_defContext *ctx) = 0;
  virtual void exitVariable_def(zsharp_parserParser::Variable_defContext *ctx) = 0;

  virtual void enterVariable_def_typed(zsharp_parserParser::Variable_def_typedContext *ctx) = 0;
  virtual void exitVariable_def_typed(zsharp_parserParser::Variable_def_typedContext *ctx) = 0;

  virtual void enterVariable_def_auto(zsharp_parserParser::Variable_def_autoContext *ctx) = 0;
  virtual void exitVariable_def_auto(zsharp_parserParser::Variable_def_autoContext *ctx) = 0;

  virtual void enterVariable_init(zsharp_parserParser::Variable_initContext *ctx) = 0;
  virtual void exitVariable_init(zsharp_parserParser::Variable_initContext *ctx) = 0;

  virtual void enterStruct_def(zsharp_parserParser::Struct_defContext *ctx) = 0;
  virtual void exitStruct_def(zsharp_parserParser::Struct_defContext *ctx) = 0;

  virtual void enterStruct_field_def_list(zsharp_parserParser::Struct_field_def_listContext *ctx) = 0;
  virtual void exitStruct_field_def_list(zsharp_parserParser::Struct_field_def_listContext *ctx) = 0;

  virtual void enterStruct_field_def(zsharp_parserParser::Struct_field_defContext *ctx) = 0;
  virtual void exitStruct_field_def(zsharp_parserParser::Struct_field_defContext *ctx) = 0;

  virtual void enterEnum_def(zsharp_parserParser::Enum_defContext *ctx) = 0;
  virtual void exitEnum_def(zsharp_parserParser::Enum_defContext *ctx) = 0;

  virtual void enterEnum_option_def_list(zsharp_parserParser::Enum_option_def_listContext *ctx) = 0;
  virtual void exitEnum_option_def_list(zsharp_parserParser::Enum_option_def_listContext *ctx) = 0;

  virtual void enterEnum_option_def(zsharp_parserParser::Enum_option_defContext *ctx) = 0;
  virtual void exitEnum_option_def(zsharp_parserParser::Enum_option_defContext *ctx) = 0;

  virtual void enterEnum_base_types(zsharp_parserParser::Enum_base_typesContext *ctx) = 0;
  virtual void exitEnum_base_types(zsharp_parserParser::Enum_base_typesContext *ctx) = 0;

  virtual void enterType_any(zsharp_parserParser::Type_anyContext *ctx) = 0;
  virtual void exitType_any(zsharp_parserParser::Type_anyContext *ctx) = 0;

  virtual void enterOptional_type(zsharp_parserParser::Optional_typeContext *ctx) = 0;
  virtual void exitOptional_type(zsharp_parserParser::Optional_typeContext *ctx) = 0;

  virtual void enterError_type(zsharp_parserParser::Error_typeContext *ctx) = 0;
  virtual void exitError_type(zsharp_parserParser::Error_typeContext *ctx) = 0;

  virtual void enterOptional_error_type(zsharp_parserParser::Optional_error_typeContext *ctx) = 0;
  virtual void exitOptional_error_type(zsharp_parserParser::Optional_error_typeContext *ctx) = 0;

  virtual void enterType_name(zsharp_parserParser::Type_nameContext *ctx) = 0;
  virtual void exitType_name(zsharp_parserParser::Type_nameContext *ctx) = 0;

  virtual void enterKnown_types(zsharp_parserParser::Known_typesContext *ctx) = 0;
  virtual void exitKnown_types(zsharp_parserParser::Known_typesContext *ctx) = 0;

  virtual void enterType_U8(zsharp_parserParser::Type_U8Context *ctx) = 0;
  virtual void exitType_U8(zsharp_parserParser::Type_U8Context *ctx) = 0;

  virtual void enterType_U16(zsharp_parserParser::Type_U16Context *ctx) = 0;
  virtual void exitType_U16(zsharp_parserParser::Type_U16Context *ctx) = 0;

  virtual void enterType_U24(zsharp_parserParser::Type_U24Context *ctx) = 0;
  virtual void exitType_U24(zsharp_parserParser::Type_U24Context *ctx) = 0;

  virtual void enterType_U32(zsharp_parserParser::Type_U32Context *ctx) = 0;
  virtual void exitType_U32(zsharp_parserParser::Type_U32Context *ctx) = 0;

  virtual void enterType_I8(zsharp_parserParser::Type_I8Context *ctx) = 0;
  virtual void exitType_I8(zsharp_parserParser::Type_I8Context *ctx) = 0;

  virtual void enterType_I16(zsharp_parserParser::Type_I16Context *ctx) = 0;
  virtual void exitType_I16(zsharp_parserParser::Type_I16Context *ctx) = 0;

  virtual void enterType_I24(zsharp_parserParser::Type_I24Context *ctx) = 0;
  virtual void exitType_I24(zsharp_parserParser::Type_I24Context *ctx) = 0;

  virtual void enterType_I32(zsharp_parserParser::Type_I32Context *ctx) = 0;
  virtual void exitType_I32(zsharp_parserParser::Type_I32Context *ctx) = 0;

  virtual void enterType_F16(zsharp_parserParser::Type_F16Context *ctx) = 0;
  virtual void exitType_F16(zsharp_parserParser::Type_F16Context *ctx) = 0;

  virtual void enterType_F32(zsharp_parserParser::Type_F32Context *ctx) = 0;
  virtual void exitType_F32(zsharp_parserParser::Type_F32Context *ctx) = 0;

  virtual void enterType_Str(zsharp_parserParser::Type_StrContext *ctx) = 0;
  virtual void exitType_Str(zsharp_parserParser::Type_StrContext *ctx) = 0;

  virtual void enterType_Bool(zsharp_parserParser::Type_BoolContext *ctx) = 0;
  virtual void exitType_Bool(zsharp_parserParser::Type_BoolContext *ctx) = 0;

  virtual void enterType_Bit(zsharp_parserParser::Type_BitContext *ctx) = 0;
  virtual void exitType_Bit(zsharp_parserParser::Type_BitContext *ctx) = 0;

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

  virtual void enterKeyword_module(zsharp_parserParser::Keyword_moduleContext *ctx) = 0;
  virtual void exitKeyword_module(zsharp_parserParser::Keyword_moduleContext *ctx) = 0;

  virtual void enterKeyword_import(zsharp_parserParser::Keyword_importContext *ctx) = 0;
  virtual void exitKeyword_import(zsharp_parserParser::Keyword_importContext *ctx) = 0;

  virtual void enterKeyword_export(zsharp_parserParser::Keyword_exportContext *ctx) = 0;
  virtual void exitKeyword_export(zsharp_parserParser::Keyword_exportContext *ctx) = 0;

  virtual void enterKeyword_loop(zsharp_parserParser::Keyword_loopContext *ctx) = 0;
  virtual void exitKeyword_loop(zsharp_parserParser::Keyword_loopContext *ctx) = 0;

  virtual void enterKeyword_break(zsharp_parserParser::Keyword_breakContext *ctx) = 0;
  virtual void exitKeyword_break(zsharp_parserParser::Keyword_breakContext *ctx) = 0;

  virtual void enterKeyword_continue(zsharp_parserParser::Keyword_continueContext *ctx) = 0;
  virtual void exitKeyword_continue(zsharp_parserParser::Keyword_continueContext *ctx) = 0;

  virtual void enterKeyword_if(zsharp_parserParser::Keyword_ifContext *ctx) = 0;
  virtual void exitKeyword_if(zsharp_parserParser::Keyword_ifContext *ctx) = 0;

  virtual void enterKeyword_else(zsharp_parserParser::Keyword_elseContext *ctx) = 0;
  virtual void exitKeyword_else(zsharp_parserParser::Keyword_elseContext *ctx) = 0;

  virtual void enterKeyword_return(zsharp_parserParser::Keyword_returnContext *ctx) = 0;
  virtual void exitKeyword_return(zsharp_parserParser::Keyword_returnContext *ctx) = 0;

  virtual void enterKeyword_in(zsharp_parserParser::Keyword_inContext *ctx) = 0;
  virtual void exitKeyword_in(zsharp_parserParser::Keyword_inContext *ctx) = 0;

  virtual void enterKeyword_self(zsharp_parserParser::Keyword_selfContext *ctx) = 0;
  virtual void exitKeyword_self(zsharp_parserParser::Keyword_selfContext *ctx) = 0;

  virtual void enterLiteral_bool(zsharp_parserParser::Literal_boolContext *ctx) = 0;
  virtual void exitLiteral_bool(zsharp_parserParser::Literal_boolContext *ctx) = 0;

  virtual void enterLiteral(zsharp_parserParser::LiteralContext *ctx) = 0;
  virtual void exitLiteral(zsharp_parserParser::LiteralContext *ctx) = 0;

  virtual void enterNumber(zsharp_parserParser::NumberContext *ctx) = 0;
  virtual void exitNumber(zsharp_parserParser::NumberContext *ctx) = 0;

  virtual void enterNumber_unsigned(zsharp_parserParser::Number_unsignedContext *ctx) = 0;
  virtual void exitNumber_unsigned(zsharp_parserParser::Number_unsignedContext *ctx) = 0;

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

  virtual void enterOp_plus(zsharp_parserParser::Op_plusContext *ctx) = 0;
  virtual void exitOp_plus(zsharp_parserParser::Op_plusContext *ctx) = 0;

  virtual void enterOp_minus_neg(zsharp_parserParser::Op_minus_negContext *ctx) = 0;
  virtual void exitOp_minus_neg(zsharp_parserParser::Op_minus_negContext *ctx) = 0;

  virtual void enterOp_mult(zsharp_parserParser::Op_multContext *ctx) = 0;
  virtual void exitOp_mult(zsharp_parserParser::Op_multContext *ctx) = 0;

  virtual void enterOp_div(zsharp_parserParser::Op_divContext *ctx) = 0;
  virtual void exitOp_div(zsharp_parserParser::Op_divContext *ctx) = 0;

  virtual void enterOp_mod(zsharp_parserParser::Op_modContext *ctx) = 0;
  virtual void exitOp_mod(zsharp_parserParser::Op_modContext *ctx) = 0;

  virtual void enterOp_pow(zsharp_parserParser::Op_powContext *ctx) = 0;
  virtual void exitOp_pow(zsharp_parserParser::Op_powContext *ctx) = 0;

  virtual void enterOp_eq_assign(zsharp_parserParser::Op_eq_assignContext *ctx) = 0;
  virtual void exitOp_eq_assign(zsharp_parserParser::Op_eq_assignContext *ctx) = 0;

  virtual void enterOp_neq(zsharp_parserParser::Op_neqContext *ctx) = 0;
  virtual void exitOp_neq(zsharp_parserParser::Op_neqContext *ctx) = 0;

  virtual void enterOp_great(zsharp_parserParser::Op_greatContext *ctx) = 0;
  virtual void exitOp_great(zsharp_parserParser::Op_greatContext *ctx) = 0;

  virtual void enterOp_small(zsharp_parserParser::Op_smallContext *ctx) = 0;
  virtual void exitOp_small(zsharp_parserParser::Op_smallContext *ctx) = 0;

  virtual void enterOp_greq(zsharp_parserParser::Op_greqContext *ctx) = 0;
  virtual void exitOp_greq(zsharp_parserParser::Op_greqContext *ctx) = 0;

  virtual void enterOp_smeq(zsharp_parserParser::Op_smeqContext *ctx) = 0;
  virtual void exitOp_smeq(zsharp_parserParser::Op_smeqContext *ctx) = 0;

  virtual void enterOp_and(zsharp_parserParser::Op_andContext *ctx) = 0;
  virtual void exitOp_and(zsharp_parserParser::Op_andContext *ctx) = 0;

  virtual void enterOp_or(zsharp_parserParser::Op_orContext *ctx) = 0;
  virtual void exitOp_or(zsharp_parserParser::Op_orContext *ctx) = 0;

  virtual void enterOp_not(zsharp_parserParser::Op_notContext *ctx) = 0;
  virtual void exitOp_not(zsharp_parserParser::Op_notContext *ctx) = 0;

  virtual void enterOp_bit_and(zsharp_parserParser::Op_bit_andContext *ctx) = 0;
  virtual void exitOp_bit_and(zsharp_parserParser::Op_bit_andContext *ctx) = 0;

  virtual void enterOp_bit_or(zsharp_parserParser::Op_bit_orContext *ctx) = 0;
  virtual void exitOp_bit_or(zsharp_parserParser::Op_bit_orContext *ctx) = 0;

  virtual void enterOp_bit_xor(zsharp_parserParser::Op_bit_xorContext *ctx) = 0;
  virtual void exitOp_bit_xor(zsharp_parserParser::Op_bit_xorContext *ctx) = 0;

  virtual void enterOp_bit_not(zsharp_parserParser::Op_bit_notContext *ctx) = 0;
  virtual void exitOp_bit_not(zsharp_parserParser::Op_bit_notContext *ctx) = 0;

  virtual void enterOp_bit_shl(zsharp_parserParser::Op_bit_shlContext *ctx) = 0;
  virtual void exitOp_bit_shl(zsharp_parserParser::Op_bit_shlContext *ctx) = 0;

  virtual void enterOp_bit_shr(zsharp_parserParser::Op_bit_shrContext *ctx) = 0;
  virtual void exitOp_bit_shr(zsharp_parserParser::Op_bit_shrContext *ctx) = 0;

  virtual void enterOp_bit_roll(zsharp_parserParser::Op_bit_rollContext *ctx) = 0;
  virtual void exitOp_bit_roll(zsharp_parserParser::Op_bit_rollContext *ctx) = 0;

  virtual void enterOp_bit_rolr(zsharp_parserParser::Op_bit_rolrContext *ctx) = 0;
  virtual void exitOp_bit_rolr(zsharp_parserParser::Op_bit_rolrContext *ctx) = 0;

  virtual void enterOp_concat(zsharp_parserParser::Op_concatContext *ctx) = 0;
  virtual void exitOp_concat(zsharp_parserParser::Op_concatContext *ctx) = 0;

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

