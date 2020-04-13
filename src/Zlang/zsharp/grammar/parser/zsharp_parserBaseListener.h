
// Generated from c:\Users\marc\Documents\MyProjects\Zalt\Zlang\src\Zlang\zsharp\grammar\zsharp_parser.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "zsharp_parserListener.h"


/**
 * This class provides an empty implementation of zsharp_parserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  zsharp_parserBaseListener : public zsharp_parserListener {
public:

  virtual void enterFile(zsharp_parserParser::FileContext * /*ctx*/) override { }
  virtual void exitFile(zsharp_parserParser::FileContext * /*ctx*/) override { }

  virtual void enterSource(zsharp_parserParser::SourceContext * /*ctx*/) override { }
  virtual void exitSource(zsharp_parserParser::SourceContext * /*ctx*/) override { }

  virtual void enterCodeblock(zsharp_parserParser::CodeblockContext * /*ctx*/) override { }
  virtual void exitCodeblock(zsharp_parserParser::CodeblockContext * /*ctx*/) override { }

  virtual void enterModule_statement(zsharp_parserParser::Module_statementContext * /*ctx*/) override { }
  virtual void exitModule_statement(zsharp_parserParser::Module_statementContext * /*ctx*/) override { }

  virtual void enterModule_name(zsharp_parserParser::Module_nameContext * /*ctx*/) override { }
  virtual void exitModule_name(zsharp_parserParser::Module_nameContext * /*ctx*/) override { }

  virtual void enterStatement_module(zsharp_parserParser::Statement_moduleContext * /*ctx*/) override { }
  virtual void exitStatement_module(zsharp_parserParser::Statement_moduleContext * /*ctx*/) override { }

  virtual void enterStatement_import(zsharp_parserParser::Statement_importContext * /*ctx*/) override { }
  virtual void exitStatement_import(zsharp_parserParser::Statement_importContext * /*ctx*/) override { }

  virtual void enterStatement_export(zsharp_parserParser::Statement_exportContext * /*ctx*/) override { }
  virtual void exitStatement_export(zsharp_parserParser::Statement_exportContext * /*ctx*/) override { }

  virtual void enterFlow_statement(zsharp_parserParser::Flow_statementContext * /*ctx*/) override { }
  virtual void exitFlow_statement(zsharp_parserParser::Flow_statementContext * /*ctx*/) override { }

  virtual void enterStatement_return(zsharp_parserParser::Statement_returnContext * /*ctx*/) override { }
  virtual void exitStatement_return(zsharp_parserParser::Statement_returnContext * /*ctx*/) override { }

  virtual void enterStatement_if(zsharp_parserParser::Statement_ifContext * /*ctx*/) override { }
  virtual void exitStatement_if(zsharp_parserParser::Statement_ifContext * /*ctx*/) override { }

  virtual void enterStatement_else(zsharp_parserParser::Statement_elseContext * /*ctx*/) override { }
  virtual void exitStatement_else(zsharp_parserParser::Statement_elseContext * /*ctx*/) override { }

  virtual void enterStatement_elseif(zsharp_parserParser::Statement_elseifContext * /*ctx*/) override { }
  virtual void exitStatement_elseif(zsharp_parserParser::Statement_elseifContext * /*ctx*/) override { }

  virtual void enterStatement_break(zsharp_parserParser::Statement_breakContext * /*ctx*/) override { }
  virtual void exitStatement_break(zsharp_parserParser::Statement_breakContext * /*ctx*/) override { }

  virtual void enterStatement_continue(zsharp_parserParser::Statement_continueContext * /*ctx*/) override { }
  virtual void exitStatement_continue(zsharp_parserParser::Statement_continueContext * /*ctx*/) override { }

  virtual void enterStatement_loop(zsharp_parserParser::Statement_loopContext * /*ctx*/) override { }
  virtual void exitStatement_loop(zsharp_parserParser::Statement_loopContext * /*ctx*/) override { }

  virtual void enterStatement_loop_infinite(zsharp_parserParser::Statement_loop_infiniteContext * /*ctx*/) override { }
  virtual void exitStatement_loop_infinite(zsharp_parserParser::Statement_loop_infiniteContext * /*ctx*/) override { }

  virtual void enterStatement_loop_while(zsharp_parserParser::Statement_loop_whileContext * /*ctx*/) override { }
  virtual void exitStatement_loop_while(zsharp_parserParser::Statement_loop_whileContext * /*ctx*/) override { }

  virtual void enterDefinition_top(zsharp_parserParser::Definition_topContext * /*ctx*/) override { }
  virtual void exitDefinition_top(zsharp_parserParser::Definition_topContext * /*ctx*/) override { }

  virtual void enterDefinition(zsharp_parserParser::DefinitionContext * /*ctx*/) override { }
  virtual void exitDefinition(zsharp_parserParser::DefinitionContext * /*ctx*/) override { }

  virtual void enterExpression_value(zsharp_parserParser::Expression_valueContext * /*ctx*/) override { }
  virtual void exitExpression_value(zsharp_parserParser::Expression_valueContext * /*ctx*/) override { }

  virtual void enterComptime_expression_value(zsharp_parserParser::Comptime_expression_valueContext * /*ctx*/) override { }
  virtual void exitComptime_expression_value(zsharp_parserParser::Comptime_expression_valueContext * /*ctx*/) override { }

  virtual void enterExpression_arithmetic(zsharp_parserParser::Expression_arithmeticContext * /*ctx*/) override { }
  virtual void exitExpression_arithmetic(zsharp_parserParser::Expression_arithmeticContext * /*ctx*/) override { }

  virtual void enterArithmetic_operand(zsharp_parserParser::Arithmetic_operandContext * /*ctx*/) override { }
  virtual void exitArithmetic_operand(zsharp_parserParser::Arithmetic_operandContext * /*ctx*/) override { }

  virtual void enterExpression_logic(zsharp_parserParser::Expression_logicContext * /*ctx*/) override { }
  virtual void exitExpression_logic(zsharp_parserParser::Expression_logicContext * /*ctx*/) override { }

  virtual void enterLogic_operand(zsharp_parserParser::Logic_operandContext * /*ctx*/) override { }
  virtual void exitLogic_operand(zsharp_parserParser::Logic_operandContext * /*ctx*/) override { }

  virtual void enterExpression_comparison(zsharp_parserParser::Expression_comparisonContext * /*ctx*/) override { }
  virtual void exitExpression_comparison(zsharp_parserParser::Expression_comparisonContext * /*ctx*/) override { }

  virtual void enterComparison_operand(zsharp_parserParser::Comparison_operandContext * /*ctx*/) override { }
  virtual void exitComparison_operand(zsharp_parserParser::Comparison_operandContext * /*ctx*/) override { }

  virtual void enterExpression_bool(zsharp_parserParser::Expression_boolContext * /*ctx*/) override { }
  virtual void exitExpression_bool(zsharp_parserParser::Expression_boolContext * /*ctx*/) override { }

  virtual void enterFunction_call(zsharp_parserParser::Function_callContext * /*ctx*/) override { }
  virtual void exitFunction_call(zsharp_parserParser::Function_callContext * /*ctx*/) override { }

  virtual void enterFunction_def(zsharp_parserParser::Function_defContext * /*ctx*/) override { }
  virtual void exitFunction_def(zsharp_parserParser::Function_defContext * /*ctx*/) override { }

  virtual void enterFunction_def_export(zsharp_parserParser::Function_def_exportContext * /*ctx*/) override { }
  virtual void exitFunction_def_export(zsharp_parserParser::Function_def_exportContext * /*ctx*/) override { }

  virtual void enterFunction_parameter_list(zsharp_parserParser::Function_parameter_listContext * /*ctx*/) override { }
  virtual void exitFunction_parameter_list(zsharp_parserParser::Function_parameter_listContext * /*ctx*/) override { }

  virtual void enterFunction_parameter(zsharp_parserParser::Function_parameterContext * /*ctx*/) override { }
  virtual void exitFunction_parameter(zsharp_parserParser::Function_parameterContext * /*ctx*/) override { }

  virtual void enterFunction_parameter_self(zsharp_parserParser::Function_parameter_selfContext * /*ctx*/) override { }
  virtual void exitFunction_parameter_self(zsharp_parserParser::Function_parameter_selfContext * /*ctx*/) override { }

  virtual void enterFunction_parameter_uselist(zsharp_parserParser::Function_parameter_uselistContext * /*ctx*/) override { }
  virtual void exitFunction_parameter_uselist(zsharp_parserParser::Function_parameter_uselistContext * /*ctx*/) override { }

  virtual void enterFunction_param_use(zsharp_parserParser::Function_param_useContext * /*ctx*/) override { }
  virtual void exitFunction_param_use(zsharp_parserParser::Function_param_useContext * /*ctx*/) override { }

  virtual void enterVariable_ref(zsharp_parserParser::Variable_refContext * /*ctx*/) override { }
  virtual void exitVariable_ref(zsharp_parserParser::Variable_refContext * /*ctx*/) override { }

  virtual void enterVariable_def_top(zsharp_parserParser::Variable_def_topContext * /*ctx*/) override { }
  virtual void exitVariable_def_top(zsharp_parserParser::Variable_def_topContext * /*ctx*/) override { }

  virtual void enterVariable_def(zsharp_parserParser::Variable_defContext * /*ctx*/) override { }
  virtual void exitVariable_def(zsharp_parserParser::Variable_defContext * /*ctx*/) override { }

  virtual void enterVariable_def_typed(zsharp_parserParser::Variable_def_typedContext * /*ctx*/) override { }
  virtual void exitVariable_def_typed(zsharp_parserParser::Variable_def_typedContext * /*ctx*/) override { }

  virtual void enterVariable_def_typed_init(zsharp_parserParser::Variable_def_typed_initContext * /*ctx*/) override { }
  virtual void exitVariable_def_typed_init(zsharp_parserParser::Variable_def_typed_initContext * /*ctx*/) override { }

  virtual void enterVariable_assign_auto(zsharp_parserParser::Variable_assign_autoContext * /*ctx*/) override { }
  virtual void exitVariable_assign_auto(zsharp_parserParser::Variable_assign_autoContext * /*ctx*/) override { }

  virtual void enterVariable_assign(zsharp_parserParser::Variable_assignContext * /*ctx*/) override { }
  virtual void exitVariable_assign(zsharp_parserParser::Variable_assignContext * /*ctx*/) override { }

  virtual void enterStruct_def(zsharp_parserParser::Struct_defContext * /*ctx*/) override { }
  virtual void exitStruct_def(zsharp_parserParser::Struct_defContext * /*ctx*/) override { }

  virtual void enterStruct_field_def_list(zsharp_parserParser::Struct_field_def_listContext * /*ctx*/) override { }
  virtual void exitStruct_field_def_list(zsharp_parserParser::Struct_field_def_listContext * /*ctx*/) override { }

  virtual void enterStruct_field_def(zsharp_parserParser::Struct_field_defContext * /*ctx*/) override { }
  virtual void exitStruct_field_def(zsharp_parserParser::Struct_field_defContext * /*ctx*/) override { }

  virtual void enterEnum_def(zsharp_parserParser::Enum_defContext * /*ctx*/) override { }
  virtual void exitEnum_def(zsharp_parserParser::Enum_defContext * /*ctx*/) override { }

  virtual void enterEnum_option_def_listline(zsharp_parserParser::Enum_option_def_listlineContext * /*ctx*/) override { }
  virtual void exitEnum_option_def_listline(zsharp_parserParser::Enum_option_def_listlineContext * /*ctx*/) override { }

  virtual void enterEnum_option_def_list(zsharp_parserParser::Enum_option_def_listContext * /*ctx*/) override { }
  virtual void exitEnum_option_def_list(zsharp_parserParser::Enum_option_def_listContext * /*ctx*/) override { }

  virtual void enterEnum_option_def(zsharp_parserParser::Enum_option_defContext * /*ctx*/) override { }
  virtual void exitEnum_option_def(zsharp_parserParser::Enum_option_defContext * /*ctx*/) override { }

  virtual void enterEnum_option_value(zsharp_parserParser::Enum_option_valueContext * /*ctx*/) override { }
  virtual void exitEnum_option_value(zsharp_parserParser::Enum_option_valueContext * /*ctx*/) override { }

  virtual void enterEnum_base_type(zsharp_parserParser::Enum_base_typeContext * /*ctx*/) override { }
  virtual void exitEnum_base_type(zsharp_parserParser::Enum_base_typeContext * /*ctx*/) override { }

  virtual void enterType_def(zsharp_parserParser::Type_defContext * /*ctx*/) override { }
  virtual void exitType_def(zsharp_parserParser::Type_defContext * /*ctx*/) override { }

  virtual void enterType_alias(zsharp_parserParser::Type_aliasContext * /*ctx*/) override { }
  virtual void exitType_alias(zsharp_parserParser::Type_aliasContext * /*ctx*/) override { }

  virtual void enterType_ref(zsharp_parserParser::Type_refContext * /*ctx*/) override { }
  virtual void exitType_ref(zsharp_parserParser::Type_refContext * /*ctx*/) override { }

  virtual void enterType_any(zsharp_parserParser::Type_anyContext * /*ctx*/) override { }
  virtual void exitType_any(zsharp_parserParser::Type_anyContext * /*ctx*/) override { }

  virtual void enterType_name(zsharp_parserParser::Type_nameContext * /*ctx*/) override { }
  virtual void exitType_name(zsharp_parserParser::Type_nameContext * /*ctx*/) override { }

  virtual void enterKnown_types(zsharp_parserParser::Known_typesContext * /*ctx*/) override { }
  virtual void exitKnown_types(zsharp_parserParser::Known_typesContext * /*ctx*/) override { }

  virtual void enterType_U8(zsharp_parserParser::Type_U8Context * /*ctx*/) override { }
  virtual void exitType_U8(zsharp_parserParser::Type_U8Context * /*ctx*/) override { }

  virtual void enterType_U16(zsharp_parserParser::Type_U16Context * /*ctx*/) override { }
  virtual void exitType_U16(zsharp_parserParser::Type_U16Context * /*ctx*/) override { }

  virtual void enterType_U24(zsharp_parserParser::Type_U24Context * /*ctx*/) override { }
  virtual void exitType_U24(zsharp_parserParser::Type_U24Context * /*ctx*/) override { }

  virtual void enterType_U32(zsharp_parserParser::Type_U32Context * /*ctx*/) override { }
  virtual void exitType_U32(zsharp_parserParser::Type_U32Context * /*ctx*/) override { }

  virtual void enterType_I8(zsharp_parserParser::Type_I8Context * /*ctx*/) override { }
  virtual void exitType_I8(zsharp_parserParser::Type_I8Context * /*ctx*/) override { }

  virtual void enterType_I16(zsharp_parserParser::Type_I16Context * /*ctx*/) override { }
  virtual void exitType_I16(zsharp_parserParser::Type_I16Context * /*ctx*/) override { }

  virtual void enterType_I24(zsharp_parserParser::Type_I24Context * /*ctx*/) override { }
  virtual void exitType_I24(zsharp_parserParser::Type_I24Context * /*ctx*/) override { }

  virtual void enterType_I32(zsharp_parserParser::Type_I32Context * /*ctx*/) override { }
  virtual void exitType_I32(zsharp_parserParser::Type_I32Context * /*ctx*/) override { }

  virtual void enterType_F16(zsharp_parserParser::Type_F16Context * /*ctx*/) override { }
  virtual void exitType_F16(zsharp_parserParser::Type_F16Context * /*ctx*/) override { }

  virtual void enterType_F32(zsharp_parserParser::Type_F32Context * /*ctx*/) override { }
  virtual void exitType_F32(zsharp_parserParser::Type_F32Context * /*ctx*/) override { }

  virtual void enterType_Str(zsharp_parserParser::Type_StrContext * /*ctx*/) override { }
  virtual void exitType_Str(zsharp_parserParser::Type_StrContext * /*ctx*/) override { }

  virtual void enterType_Bool(zsharp_parserParser::Type_BoolContext * /*ctx*/) override { }
  virtual void exitType_Bool(zsharp_parserParser::Type_BoolContext * /*ctx*/) override { }

  virtual void enterType_Bit(zsharp_parserParser::Type_BitContext * /*ctx*/) override { }
  virtual void exitType_Bit(zsharp_parserParser::Type_BitContext * /*ctx*/) override { }

  virtual void enterType_Ptr(zsharp_parserParser::Type_PtrContext * /*ctx*/) override { }
  virtual void exitType_Ptr(zsharp_parserParser::Type_PtrContext * /*ctx*/) override { }

  virtual void enterType_param_number(zsharp_parserParser::Type_param_numberContext * /*ctx*/) override { }
  virtual void exitType_param_number(zsharp_parserParser::Type_param_numberContext * /*ctx*/) override { }

  virtual void enterType_param_type(zsharp_parserParser::Type_param_typeContext * /*ctx*/) override { }
  virtual void exitType_param_type(zsharp_parserParser::Type_param_typeContext * /*ctx*/) override { }

  virtual void enterType_param_list(zsharp_parserParser::Type_param_listContext * /*ctx*/) override { }
  virtual void exitType_param_list(zsharp_parserParser::Type_param_listContext * /*ctx*/) override { }

  virtual void enterType_param_name_list(zsharp_parserParser::Type_param_name_listContext * /*ctx*/) override { }
  virtual void exitType_param_name_list(zsharp_parserParser::Type_param_name_listContext * /*ctx*/) override { }

  virtual void enterType_param_anytype(zsharp_parserParser::Type_param_anytypeContext * /*ctx*/) override { }
  virtual void exitType_param_anytype(zsharp_parserParser::Type_param_anytypeContext * /*ctx*/) override { }

  virtual void enterIdentifier_type(zsharp_parserParser::Identifier_typeContext * /*ctx*/) override { }
  virtual void exitIdentifier_type(zsharp_parserParser::Identifier_typeContext * /*ctx*/) override { }

  virtual void enterIdentifier_var(zsharp_parserParser::Identifier_varContext * /*ctx*/) override { }
  virtual void exitIdentifier_var(zsharp_parserParser::Identifier_varContext * /*ctx*/) override { }

  virtual void enterIdentifier_param(zsharp_parserParser::Identifier_paramContext * /*ctx*/) override { }
  virtual void exitIdentifier_param(zsharp_parserParser::Identifier_paramContext * /*ctx*/) override { }

  virtual void enterIdentifier_func(zsharp_parserParser::Identifier_funcContext * /*ctx*/) override { }
  virtual void exitIdentifier_func(zsharp_parserParser::Identifier_funcContext * /*ctx*/) override { }

  virtual void enterIdentifier_field(zsharp_parserParser::Identifier_fieldContext * /*ctx*/) override { }
  virtual void exitIdentifier_field(zsharp_parserParser::Identifier_fieldContext * /*ctx*/) override { }

  virtual void enterIdentifier_enumoption(zsharp_parserParser::Identifier_enumoptionContext * /*ctx*/) override { }
  virtual void exitIdentifier_enumoption(zsharp_parserParser::Identifier_enumoptionContext * /*ctx*/) override { }

  virtual void enterIdentifier_module(zsharp_parserParser::Identifier_moduleContext * /*ctx*/) override { }
  virtual void exitIdentifier_module(zsharp_parserParser::Identifier_moduleContext * /*ctx*/) override { }

  virtual void enterIdentifier_unused(zsharp_parserParser::Identifier_unusedContext * /*ctx*/) override { }
  virtual void exitIdentifier_unused(zsharp_parserParser::Identifier_unusedContext * /*ctx*/) override { }

  virtual void enterLiteral_bool(zsharp_parserParser::Literal_boolContext * /*ctx*/) override { }
  virtual void exitLiteral_bool(zsharp_parserParser::Literal_boolContext * /*ctx*/) override { }

  virtual void enterLiteral(zsharp_parserParser::LiteralContext * /*ctx*/) override { }
  virtual void exitLiteral(zsharp_parserParser::LiteralContext * /*ctx*/) override { }

  virtual void enterNumber(zsharp_parserParser::NumberContext * /*ctx*/) override { }
  virtual void exitNumber(zsharp_parserParser::NumberContext * /*ctx*/) override { }

  virtual void enterNumber_bin(zsharp_parserParser::Number_binContext * /*ctx*/) override { }
  virtual void exitNumber_bin(zsharp_parserParser::Number_binContext * /*ctx*/) override { }

  virtual void enterNumber_oct(zsharp_parserParser::Number_octContext * /*ctx*/) override { }
  virtual void exitNumber_oct(zsharp_parserParser::Number_octContext * /*ctx*/) override { }

  virtual void enterNumber_dec(zsharp_parserParser::Number_decContext * /*ctx*/) override { }
  virtual void exitNumber_dec(zsharp_parserParser::Number_decContext * /*ctx*/) override { }

  virtual void enterNumber_hex(zsharp_parserParser::Number_hexContext * /*ctx*/) override { }
  virtual void exitNumber_hex(zsharp_parserParser::Number_hexContext * /*ctx*/) override { }

  virtual void enterNumber_char(zsharp_parserParser::Number_charContext * /*ctx*/) override { }
  virtual void exitNumber_char(zsharp_parserParser::Number_charContext * /*ctx*/) override { }

  virtual void enterOperator_arithmetic(zsharp_parserParser::Operator_arithmeticContext * /*ctx*/) override { }
  virtual void exitOperator_arithmetic(zsharp_parserParser::Operator_arithmeticContext * /*ctx*/) override { }

  virtual void enterOperator_arithmetic_unary(zsharp_parserParser::Operator_arithmetic_unaryContext * /*ctx*/) override { }
  virtual void exitOperator_arithmetic_unary(zsharp_parserParser::Operator_arithmetic_unaryContext * /*ctx*/) override { }

  virtual void enterOperator_logic(zsharp_parserParser::Operator_logicContext * /*ctx*/) override { }
  virtual void exitOperator_logic(zsharp_parserParser::Operator_logicContext * /*ctx*/) override { }

  virtual void enterOperator_logic_unary(zsharp_parserParser::Operator_logic_unaryContext * /*ctx*/) override { }
  virtual void exitOperator_logic_unary(zsharp_parserParser::Operator_logic_unaryContext * /*ctx*/) override { }

  virtual void enterOperator_comparison(zsharp_parserParser::Operator_comparisonContext * /*ctx*/) override { }
  virtual void exitOperator_comparison(zsharp_parserParser::Operator_comparisonContext * /*ctx*/) override { }

  virtual void enterOperator_bits(zsharp_parserParser::Operator_bitsContext * /*ctx*/) override { }
  virtual void exitOperator_bits(zsharp_parserParser::Operator_bitsContext * /*ctx*/) override { }

  virtual void enterOperator_bits_unary(zsharp_parserParser::Operator_bits_unaryContext * /*ctx*/) override { }
  virtual void exitOperator_bits_unary(zsharp_parserParser::Operator_bits_unaryContext * /*ctx*/) override { }

  virtual void enterOperator_assignment(zsharp_parserParser::Operator_assignmentContext * /*ctx*/) override { }
  virtual void exitOperator_assignment(zsharp_parserParser::Operator_assignmentContext * /*ctx*/) override { }

  virtual void enterEmpty_line(zsharp_parserParser::Empty_lineContext * /*ctx*/) override { }
  virtual void exitEmpty_line(zsharp_parserParser::Empty_lineContext * /*ctx*/) override { }

  virtual void enterNewline(zsharp_parserParser::NewlineContext * /*ctx*/) override { }
  virtual void exitNewline(zsharp_parserParser::NewlineContext * /*ctx*/) override { }

  virtual void enterComment(zsharp_parserParser::CommentContext * /*ctx*/) override { }
  virtual void exitComment(zsharp_parserParser::CommentContext * /*ctx*/) override { }

  virtual void enterString(zsharp_parserParser::StringContext * /*ctx*/) override { }
  virtual void exitString(zsharp_parserParser::StringContext * /*ctx*/) override { }

  virtual void enterCharacter(zsharp_parserParser::CharacterContext * /*ctx*/) override { }
  virtual void exitCharacter(zsharp_parserParser::CharacterContext * /*ctx*/) override { }

  virtual void enterIndent(zsharp_parserParser::IndentContext * /*ctx*/) override { }
  virtual void exitIndent(zsharp_parserParser::IndentContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

