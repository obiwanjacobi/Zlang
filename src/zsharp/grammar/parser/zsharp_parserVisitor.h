
// Generated from c:\Users\marc\Documents\MyProjects\Zalt\Zlang\src\zsharp\grammar\zsharp_parser.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "zsharp_parserParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by zsharp_parserParser.
 */
class  zsharp_parserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by zsharp_parserParser.
   */
    virtual antlrcpp::Any visitFile(zsharp_parserParser::FileContext *context) = 0;

    virtual antlrcpp::Any visitCodeblock(zsharp_parserParser::CodeblockContext *context) = 0;

    virtual antlrcpp::Any visitModule_statement(zsharp_parserParser::Module_statementContext *context) = 0;

    virtual antlrcpp::Any visitModule_name(zsharp_parserParser::Module_nameContext *context) = 0;

    virtual antlrcpp::Any visitStatement_module(zsharp_parserParser::Statement_moduleContext *context) = 0;

    virtual antlrcpp::Any visitStatement_import(zsharp_parserParser::Statement_importContext *context) = 0;

    virtual antlrcpp::Any visitStatement_export(zsharp_parserParser::Statement_exportContext *context) = 0;

    virtual antlrcpp::Any visitFlow_statement(zsharp_parserParser::Flow_statementContext *context) = 0;

    virtual antlrcpp::Any visitStatement_return(zsharp_parserParser::Statement_returnContext *context) = 0;

    virtual antlrcpp::Any visitStatement_if(zsharp_parserParser::Statement_ifContext *context) = 0;

    virtual antlrcpp::Any visitStatement_else(zsharp_parserParser::Statement_elseContext *context) = 0;

    virtual antlrcpp::Any visitDeclaration_top(zsharp_parserParser::Declaration_topContext *context) = 0;

    virtual antlrcpp::Any visitDeclaration(zsharp_parserParser::DeclarationContext *context) = 0;

    virtual antlrcpp::Any visitExpression_value(zsharp_parserParser::Expression_valueContext *context) = 0;

    virtual antlrcpp::Any visitComptime_expression_value(zsharp_parserParser::Comptime_expression_valueContext *context) = 0;

    virtual antlrcpp::Any visitExpression_arithmetic(zsharp_parserParser::Expression_arithmeticContext *context) = 0;

    virtual antlrcpp::Any visitArithmetic_operand(zsharp_parserParser::Arithmetic_operandContext *context) = 0;

    virtual antlrcpp::Any visitExpression_logic(zsharp_parserParser::Expression_logicContext *context) = 0;

    virtual antlrcpp::Any visitLogic_operand(zsharp_parserParser::Logic_operandContext *context) = 0;

    virtual antlrcpp::Any visitExpression_comparison(zsharp_parserParser::Expression_comparisonContext *context) = 0;

    virtual antlrcpp::Any visitComparison_operand(zsharp_parserParser::Comparison_operandContext *context) = 0;

    virtual antlrcpp::Any visitExpression_bitwise(zsharp_parserParser::Expression_bitwiseContext *context) = 0;

    virtual antlrcpp::Any visitBitwise_operand(zsharp_parserParser::Bitwise_operandContext *context) = 0;

    virtual antlrcpp::Any visitExpression_bool(zsharp_parserParser::Expression_boolContext *context) = 0;

    virtual antlrcpp::Any visitIdentifier_bool(zsharp_parserParser::Identifier_boolContext *context) = 0;

    virtual antlrcpp::Any visitFunction_call(zsharp_parserParser::Function_callContext *context) = 0;

    virtual antlrcpp::Any visitFunction_decl(zsharp_parserParser::Function_declContext *context) = 0;

    virtual antlrcpp::Any visitFunction_parameter_list(zsharp_parserParser::Function_parameter_listContext *context) = 0;

    virtual antlrcpp::Any visitFunction_parameter(zsharp_parserParser::Function_parameterContext *context) = 0;

    virtual antlrcpp::Any visitFunction_type(zsharp_parserParser::Function_typeContext *context) = 0;

    virtual antlrcpp::Any visitFunction_parameter_uselist(zsharp_parserParser::Function_parameter_uselistContext *context) = 0;

    virtual antlrcpp::Any visitFunction_param_use(zsharp_parserParser::Function_param_useContext *context) = 0;

    virtual antlrcpp::Any visitVariable_ref(zsharp_parserParser::Variable_refContext *context) = 0;

    virtual antlrcpp::Any visitParameter_ref(zsharp_parserParser::Parameter_refContext *context) = 0;

    virtual antlrcpp::Any visitVariable_decl(zsharp_parserParser::Variable_declContext *context) = 0;

    virtual antlrcpp::Any visitVariable_decl_typed(zsharp_parserParser::Variable_decl_typedContext *context) = 0;

    virtual antlrcpp::Any visitVariable_decl_auto(zsharp_parserParser::Variable_decl_autoContext *context) = 0;

    virtual antlrcpp::Any visitVariable_init(zsharp_parserParser::Variable_initContext *context) = 0;

    virtual antlrcpp::Any visitStruct_decl(zsharp_parserParser::Struct_declContext *context) = 0;

    virtual antlrcpp::Any visitStruct_field_decl_list(zsharp_parserParser::Struct_field_decl_listContext *context) = 0;

    virtual antlrcpp::Any visitStruct_field_decl(zsharp_parserParser::Struct_field_declContext *context) = 0;

    virtual antlrcpp::Any visitEnum_decl(zsharp_parserParser::Enum_declContext *context) = 0;

    virtual antlrcpp::Any visitEnum_option_decl_list(zsharp_parserParser::Enum_option_decl_listContext *context) = 0;

    virtual antlrcpp::Any visitEnum_option_decl(zsharp_parserParser::Enum_option_declContext *context) = 0;

    virtual antlrcpp::Any visitEnum_base_types(zsharp_parserParser::Enum_base_typesContext *context) = 0;

    virtual antlrcpp::Any visitType_any(zsharp_parserParser::Type_anyContext *context) = 0;

    virtual antlrcpp::Any visitOptional_type(zsharp_parserParser::Optional_typeContext *context) = 0;

    virtual antlrcpp::Any visitError_type(zsharp_parserParser::Error_typeContext *context) = 0;

    virtual antlrcpp::Any visitOptional_error_type(zsharp_parserParser::Optional_error_typeContext *context) = 0;

    virtual antlrcpp::Any visitType_name(zsharp_parserParser::Type_nameContext *context) = 0;

    virtual antlrcpp::Any visitKnown_types(zsharp_parserParser::Known_typesContext *context) = 0;

    virtual antlrcpp::Any visitType_U8(zsharp_parserParser::Type_U8Context *context) = 0;

    virtual antlrcpp::Any visitType_U16(zsharp_parserParser::Type_U16Context *context) = 0;

    virtual antlrcpp::Any visitType_U24(zsharp_parserParser::Type_U24Context *context) = 0;

    virtual antlrcpp::Any visitType_U32(zsharp_parserParser::Type_U32Context *context) = 0;

    virtual antlrcpp::Any visitType_I8(zsharp_parserParser::Type_I8Context *context) = 0;

    virtual antlrcpp::Any visitType_I16(zsharp_parserParser::Type_I16Context *context) = 0;

    virtual antlrcpp::Any visitType_I24(zsharp_parserParser::Type_I24Context *context) = 0;

    virtual antlrcpp::Any visitType_I32(zsharp_parserParser::Type_I32Context *context) = 0;

    virtual antlrcpp::Any visitType_F16(zsharp_parserParser::Type_F16Context *context) = 0;

    virtual antlrcpp::Any visitType_F32(zsharp_parserParser::Type_F32Context *context) = 0;

    virtual antlrcpp::Any visitType_Str(zsharp_parserParser::Type_StrContext *context) = 0;

    virtual antlrcpp::Any visitType_Bool(zsharp_parserParser::Type_BoolContext *context) = 0;

    virtual antlrcpp::Any visitType_Bit(zsharp_parserParser::Type_BitContext *context) = 0;

    virtual antlrcpp::Any visitIdentifier_type(zsharp_parserParser::Identifier_typeContext *context) = 0;

    virtual antlrcpp::Any visitIdentifier_var(zsharp_parserParser::Identifier_varContext *context) = 0;

    virtual antlrcpp::Any visitIdentifier_param(zsharp_parserParser::Identifier_paramContext *context) = 0;

    virtual antlrcpp::Any visitIdentifier_func(zsharp_parserParser::Identifier_funcContext *context) = 0;

    virtual antlrcpp::Any visitIdentifier_field(zsharp_parserParser::Identifier_fieldContext *context) = 0;

    virtual antlrcpp::Any visitIdentifier_enumoption(zsharp_parserParser::Identifier_enumoptionContext *context) = 0;

    virtual antlrcpp::Any visitIdentifier_module(zsharp_parserParser::Identifier_moduleContext *context) = 0;

    virtual antlrcpp::Any visitIdentifier_unused(zsharp_parserParser::Identifier_unusedContext *context) = 0;

    virtual antlrcpp::Any visitKeyword_module(zsharp_parserParser::Keyword_moduleContext *context) = 0;

    virtual antlrcpp::Any visitKeyword_import(zsharp_parserParser::Keyword_importContext *context) = 0;

    virtual antlrcpp::Any visitKeyword_export(zsharp_parserParser::Keyword_exportContext *context) = 0;

    virtual antlrcpp::Any visitKeyword_loop(zsharp_parserParser::Keyword_loopContext *context) = 0;

    virtual antlrcpp::Any visitKeyword_break(zsharp_parserParser::Keyword_breakContext *context) = 0;

    virtual antlrcpp::Any visitKeyword_continue(zsharp_parserParser::Keyword_continueContext *context) = 0;

    virtual antlrcpp::Any visitKeyword_if(zsharp_parserParser::Keyword_ifContext *context) = 0;

    virtual antlrcpp::Any visitKeyword_else(zsharp_parserParser::Keyword_elseContext *context) = 0;

    virtual antlrcpp::Any visitKeyword_return(zsharp_parserParser::Keyword_returnContext *context) = 0;

    virtual antlrcpp::Any visitKeyword_in(zsharp_parserParser::Keyword_inContext *context) = 0;

    virtual antlrcpp::Any visitKeyword_self(zsharp_parserParser::Keyword_selfContext *context) = 0;

    virtual antlrcpp::Any visitLiteral_bool(zsharp_parserParser::Literal_boolContext *context) = 0;

    virtual antlrcpp::Any visitLiteral(zsharp_parserParser::LiteralContext *context) = 0;

    virtual antlrcpp::Any visitNumber(zsharp_parserParser::NumberContext *context) = 0;

    virtual antlrcpp::Any visitNumber_unsigned(zsharp_parserParser::Number_unsignedContext *context) = 0;

    virtual antlrcpp::Any visitNumber_bin(zsharp_parserParser::Number_binContext *context) = 0;

    virtual antlrcpp::Any visitNumber_oct(zsharp_parserParser::Number_octContext *context) = 0;

    virtual antlrcpp::Any visitNumber_dec(zsharp_parserParser::Number_decContext *context) = 0;

    virtual antlrcpp::Any visitNumber_hex(zsharp_parserParser::Number_hexContext *context) = 0;

    virtual antlrcpp::Any visitNumber_char(zsharp_parserParser::Number_charContext *context) = 0;

    virtual antlrcpp::Any visitOperator_arithmetic(zsharp_parserParser::Operator_arithmeticContext *context) = 0;

    virtual antlrcpp::Any visitOperator_arithmetic_unary(zsharp_parserParser::Operator_arithmetic_unaryContext *context) = 0;

    virtual antlrcpp::Any visitOperator_logic(zsharp_parserParser::Operator_logicContext *context) = 0;

    virtual antlrcpp::Any visitOperator_logic_unary(zsharp_parserParser::Operator_logic_unaryContext *context) = 0;

    virtual antlrcpp::Any visitOperator_comparison(zsharp_parserParser::Operator_comparisonContext *context) = 0;

    virtual antlrcpp::Any visitOperator_bits(zsharp_parserParser::Operator_bitsContext *context) = 0;

    virtual antlrcpp::Any visitOperator_bits_unary(zsharp_parserParser::Operator_bits_unaryContext *context) = 0;

    virtual antlrcpp::Any visitOperator_assignment(zsharp_parserParser::Operator_assignmentContext *context) = 0;

    virtual antlrcpp::Any visitOp_plus(zsharp_parserParser::Op_plusContext *context) = 0;

    virtual antlrcpp::Any visitOp_minus_neg(zsharp_parserParser::Op_minus_negContext *context) = 0;

    virtual antlrcpp::Any visitOp_mult(zsharp_parserParser::Op_multContext *context) = 0;

    virtual antlrcpp::Any visitOp_div(zsharp_parserParser::Op_divContext *context) = 0;

    virtual antlrcpp::Any visitOp_mod(zsharp_parserParser::Op_modContext *context) = 0;

    virtual antlrcpp::Any visitOp_pow(zsharp_parserParser::Op_powContext *context) = 0;

    virtual antlrcpp::Any visitOp_eq_assign(zsharp_parserParser::Op_eq_assignContext *context) = 0;

    virtual antlrcpp::Any visitOp_neq(zsharp_parserParser::Op_neqContext *context) = 0;

    virtual antlrcpp::Any visitOp_great(zsharp_parserParser::Op_greatContext *context) = 0;

    virtual antlrcpp::Any visitOp_small(zsharp_parserParser::Op_smallContext *context) = 0;

    virtual antlrcpp::Any visitOp_greq(zsharp_parserParser::Op_greqContext *context) = 0;

    virtual antlrcpp::Any visitOp_smeq(zsharp_parserParser::Op_smeqContext *context) = 0;

    virtual antlrcpp::Any visitOp_and(zsharp_parserParser::Op_andContext *context) = 0;

    virtual antlrcpp::Any visitOp_or(zsharp_parserParser::Op_orContext *context) = 0;

    virtual antlrcpp::Any visitOp_not(zsharp_parserParser::Op_notContext *context) = 0;

    virtual antlrcpp::Any visitOp_bit_and(zsharp_parserParser::Op_bit_andContext *context) = 0;

    virtual antlrcpp::Any visitOp_bit_or(zsharp_parserParser::Op_bit_orContext *context) = 0;

    virtual antlrcpp::Any visitOp_bit_xor(zsharp_parserParser::Op_bit_xorContext *context) = 0;

    virtual antlrcpp::Any visitOp_bit_not(zsharp_parserParser::Op_bit_notContext *context) = 0;

    virtual antlrcpp::Any visitOp_bit_shl(zsharp_parserParser::Op_bit_shlContext *context) = 0;

    virtual antlrcpp::Any visitOp_bit_shr(zsharp_parserParser::Op_bit_shrContext *context) = 0;

    virtual antlrcpp::Any visitOp_bit_roll(zsharp_parserParser::Op_bit_rollContext *context) = 0;

    virtual antlrcpp::Any visitOp_bit_rolr(zsharp_parserParser::Op_bit_rolrContext *context) = 0;

    virtual antlrcpp::Any visitOp_concat(zsharp_parserParser::Op_concatContext *context) = 0;

    virtual antlrcpp::Any visitEmpty_line(zsharp_parserParser::Empty_lineContext *context) = 0;

    virtual antlrcpp::Any visitNewline(zsharp_parserParser::NewlineContext *context) = 0;

    virtual antlrcpp::Any visitComment(zsharp_parserParser::CommentContext *context) = 0;

    virtual antlrcpp::Any visitString(zsharp_parserParser::StringContext *context) = 0;

    virtual antlrcpp::Any visitCharacter(zsharp_parserParser::CharacterContext *context) = 0;

    virtual antlrcpp::Any visitIndent(zsharp_parserParser::IndentContext *context) = 0;


};

