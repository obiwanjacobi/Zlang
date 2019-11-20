
// Generated from c:\Users\marc\Documents\MyProjects\Zalt\Zlang\src\zsharp\grammar\zsharp_parser.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "zsharp_parserVisitor.h"


/**
 * This class provides an empty implementation of zsharp_parserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  zsharp_parserBaseVisitor : public zsharp_parserVisitor {
public:

  virtual antlrcpp::Any visitFile(zsharp_parserParser::FileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCodeblock(zsharp_parserParser::CodeblockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_statement(zsharp_parserParser::Module_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_name(zsharp_parserParser::Module_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement_module(zsharp_parserParser::Statement_moduleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement_import(zsharp_parserParser::Statement_importContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement_export(zsharp_parserParser::Statement_exportContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlow_statement(zsharp_parserParser::Flow_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement_return(zsharp_parserParser::Statement_returnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement_if(zsharp_parserParser::Statement_ifContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement_else(zsharp_parserParser::Statement_elseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement_elseif(zsharp_parserParser::Statement_elseifContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement_break(zsharp_parserParser::Statement_breakContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement_continue(zsharp_parserParser::Statement_continueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement_loop(zsharp_parserParser::Statement_loopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement_loop_infinite(zsharp_parserParser::Statement_loop_infiniteContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement_loop_while(zsharp_parserParser::Statement_loop_whileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefinition_top(zsharp_parserParser::Definition_topContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefinition(zsharp_parserParser::DefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression_value(zsharp_parserParser::Expression_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitComptime_expression_value(zsharp_parserParser::Comptime_expression_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression_arithmetic(zsharp_parserParser::Expression_arithmeticContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArithmetic_operand(zsharp_parserParser::Arithmetic_operandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression_logic(zsharp_parserParser::Expression_logicContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogic_operand(zsharp_parserParser::Logic_operandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression_comparison(zsharp_parserParser::Expression_comparisonContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitComparison_operand(zsharp_parserParser::Comparison_operandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression_bitwise(zsharp_parserParser::Expression_bitwiseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitwise_operand(zsharp_parserParser::Bitwise_operandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression_bool(zsharp_parserParser::Expression_boolContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifier_bool(zsharp_parserParser::Identifier_boolContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_call(zsharp_parserParser::Function_callContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_def(zsharp_parserParser::Function_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_parameter_list(zsharp_parserParser::Function_parameter_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_parameter(zsharp_parserParser::Function_parameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_type(zsharp_parserParser::Function_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_parameter_uselist(zsharp_parserParser::Function_parameter_uselistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_param_use(zsharp_parserParser::Function_param_useContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable_ref(zsharp_parserParser::Variable_refContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameter_ref(zsharp_parserParser::Parameter_refContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable_def_top(zsharp_parserParser::Variable_def_topContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable_def(zsharp_parserParser::Variable_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable_def_typed(zsharp_parserParser::Variable_def_typedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable_def_typed_init(zsharp_parserParser::Variable_def_typed_initContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable_auto_assign(zsharp_parserParser::Variable_auto_assignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable_assign(zsharp_parserParser::Variable_assignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStruct_def(zsharp_parserParser::Struct_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStruct_field_def_list(zsharp_parserParser::Struct_field_def_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStruct_field_def(zsharp_parserParser::Struct_field_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnum_def(zsharp_parserParser::Enum_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnum_option_def_list(zsharp_parserParser::Enum_option_def_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnum_option_def(zsharp_parserParser::Enum_option_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnum_base_types(zsharp_parserParser::Enum_base_typesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_any(zsharp_parserParser::Type_anyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOptional_type(zsharp_parserParser::Optional_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitError_type(zsharp_parserParser::Error_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOptional_error_type(zsharp_parserParser::Optional_error_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_name(zsharp_parserParser::Type_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitKnown_types(zsharp_parserParser::Known_typesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_U8(zsharp_parserParser::Type_U8Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_U16(zsharp_parserParser::Type_U16Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_U24(zsharp_parserParser::Type_U24Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_U32(zsharp_parserParser::Type_U32Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_I8(zsharp_parserParser::Type_I8Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_I16(zsharp_parserParser::Type_I16Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_I24(zsharp_parserParser::Type_I24Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_I32(zsharp_parserParser::Type_I32Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_F16(zsharp_parserParser::Type_F16Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_F32(zsharp_parserParser::Type_F32Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_Str(zsharp_parserParser::Type_StrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_Bool(zsharp_parserParser::Type_BoolContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_Bit(zsharp_parserParser::Type_BitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifier_type(zsharp_parserParser::Identifier_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifier_var(zsharp_parserParser::Identifier_varContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifier_param(zsharp_parserParser::Identifier_paramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifier_func(zsharp_parserParser::Identifier_funcContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifier_field(zsharp_parserParser::Identifier_fieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifier_enumoption(zsharp_parserParser::Identifier_enumoptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifier_module(zsharp_parserParser::Identifier_moduleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifier_unused(zsharp_parserParser::Identifier_unusedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteral_bool(zsharp_parserParser::Literal_boolContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteral(zsharp_parserParser::LiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumber(zsharp_parserParser::NumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumber_unsigned(zsharp_parserParser::Number_unsignedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumber_bin(zsharp_parserParser::Number_binContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumber_oct(zsharp_parserParser::Number_octContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumber_dec(zsharp_parserParser::Number_decContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumber_hex(zsharp_parserParser::Number_hexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumber_char(zsharp_parserParser::Number_charContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperator_arithmetic(zsharp_parserParser::Operator_arithmeticContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperator_arithmetic_unary(zsharp_parserParser::Operator_arithmetic_unaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperator_logic(zsharp_parserParser::Operator_logicContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperator_logic_unary(zsharp_parserParser::Operator_logic_unaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperator_comparison(zsharp_parserParser::Operator_comparisonContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperator_bits(zsharp_parserParser::Operator_bitsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperator_bits_unary(zsharp_parserParser::Operator_bits_unaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperator_assignment(zsharp_parserParser::Operator_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOp_plus(zsharp_parserParser::Op_plusContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOp_minus_neg(zsharp_parserParser::Op_minus_negContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOp_mult(zsharp_parserParser::Op_multContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOp_div(zsharp_parserParser::Op_divContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOp_mod(zsharp_parserParser::Op_modContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOp_pow(zsharp_parserParser::Op_powContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOp_eq_assign(zsharp_parserParser::Op_eq_assignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOp_neq(zsharp_parserParser::Op_neqContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOp_great(zsharp_parserParser::Op_greatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOp_small(zsharp_parserParser::Op_smallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOp_greq(zsharp_parserParser::Op_greqContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOp_smeq(zsharp_parserParser::Op_smeqContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOp_and(zsharp_parserParser::Op_andContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOp_or(zsharp_parserParser::Op_orContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOp_not(zsharp_parserParser::Op_notContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOp_bit_and(zsharp_parserParser::Op_bit_andContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOp_bit_or(zsharp_parserParser::Op_bit_orContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOp_bit_xor(zsharp_parserParser::Op_bit_xorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOp_bit_not(zsharp_parserParser::Op_bit_notContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOp_bit_shl(zsharp_parserParser::Op_bit_shlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOp_bit_shr(zsharp_parserParser::Op_bit_shrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOp_bit_roll(zsharp_parserParser::Op_bit_rollContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOp_bit_rolr(zsharp_parserParser::Op_bit_rolrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOp_concat(zsharp_parserParser::Op_concatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEmpty_line(zsharp_parserParser::Empty_lineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNewline(zsharp_parserParser::NewlineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitComment(zsharp_parserParser::CommentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitString(zsharp_parserParser::StringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCharacter(zsharp_parserParser::CharacterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIndent(zsharp_parserParser::IndentContext *ctx) override {
    return visitChildren(ctx);
  }


};

