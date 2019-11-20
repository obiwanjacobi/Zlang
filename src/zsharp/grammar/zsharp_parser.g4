grammar zsharp_parser;

// entry point
file : (module_statement | definition_top | comment | empty_line)* EOF;

codeblock: (flow_statement | variable_assign | definition | comment | empty_line)+;

// modules
module_statement : statement_module | statement_import | statement_export;
module_name: identifier_module | module_name DOT identifier_module;
statement_module: keyword_module SP module_name newline;
statement_import: keyword_import SP module_name newline;
statement_export: keyword_export SP (identifier_func | identifier_type) newline;

// flow control
flow_statement: statement_if | statement_else | statement_elseif
    | statement_loop | statement_return | statement_break | statement_continue;
statement_return: indent keyword_return (SP expression_value)? newline;
statement_if: indent keyword_if SP expression_logic newline codeblock;
statement_else: indent keyword_else newline codeblock;
statement_elseif: indent keyword_else SP keyword_if SP expression_logic newline codeblock;
statement_break: indent keyword_break;
statement_continue: indent keyword_continue;
statement_loop: indent (statement_loop_infinite | statement_loop_while) newline codeblock;
statement_loop_infinite: keyword_loop;
statement_loop_while: keyword_loop SP expression_logic;

// definition
definition_top: function_def | enum_def | struct_def | variable_def_top;
definition: variable_def;

// expressions
expression_value: number | string | expression_bool
    | expression_arithmetic | expression_logic | expression_bitwise 
    | function_call;
comptime_expression_value: number | string | expression_bool;

expression_arithmetic: 
      expression_arithmetic SP operator_arithmetic SP expression_arithmetic
    | PARENopen expression_arithmetic PARENclose
    | operator_arithmetic_unary expression_arithmetic
    | arithmetic_operand
    ;
arithmetic_operand: expression_bitwise | number | variable_ref | parameter_ref;

expression_logic: 
      expression_logic SP operator_logic SP expression_logic
    | operator_logic_unary SP expression_logic
    | logic_operand;
logic_operand: expression_comparison | expression_bool;

expression_comparison: 
      comparison_operand SP operator_comparison SP comparison_operand
    | PARENopen expression_comparison PARENclose;
comparison_operand: expression_arithmetic | expression_bitwise | function_call | variable_ref | literal;

expression_bitwise: 
      bitwise_operand SP operator_bits SP bitwise_operand
    | operator_bits_unary bitwise_operand;
bitwise_operand: function_call | variable_ref | number;

expression_bool: literal_bool | identifier_bool;
identifier_bool: variable_ref | parameter_ref;

// functions
function_call: identifier_func PARENopen function_parameter_uselist? PARENclose;
function_def: identifier_func PARENopen function_parameter_list? PARENclose function_type? newline codeblock;
function_parameter_list: function_parameter | (COMMA SP function_parameter)+;
function_parameter: identifier_param function_type;
function_type: COLON SP type_any;
function_parameter_uselist: function_param_use | (COMMA SP function_param_use)+;
function_param_use: expression_value | (COMMA SP expression_value)+;

// variables
variable_ref: identifier_var;
parameter_ref: identifier_param;
variable_def_top: (variable_def_typed | variable_def_typed_init | variable_auto_assign) newline;
variable_def: indent (variable_def_typed | variable_def_typed_init | variable_auto_assign) newline;
variable_def_typed: identifier_var COLON SP type_any;
variable_def_typed_init: identifier_var COLON SP type_any SP EQ_ASSIGN SP expression_value;
variable_auto_assign: identifier_var SP EQ_ASSIGN SP expression_value;
variable_assign: indent identifier_var SP EQ_ASSIGN SP expression_value;

// structs
struct_def: identifier_type (COLON SP type_any)? newline struct_field_def_list;
struct_field_def_list: struct_field_def+;
struct_field_def: indent identifier_field COLON SP type_any newline;

// enums
enum_def: identifier_type (COLON SP enum_base_types)? newline enum_option_def_list;
enum_option_def_list: enum_option_def+;
enum_option_def: indent identifier_enumoption (SP EQ_ASSIGN SP comptime_expression_value)? COMMA? newline;
enum_base_types:       
      type_Bit | type_Str
    | type_F16 | type_F32 
    | type_I16 | type_I24 | type_I32 | type_I8  
    | type_U16 | type_U24 | type_U32 | type_U8;

// types
type_any: type_name | optional_type | error_type | optional_error_type;
optional_type: type_name QUESTION;
error_type: type_name ERROR;
optional_error_type: type_name ERROR QUESTION;

type_name: known_types | identifier_type;
known_types: 
      type_Bit | type_Bool | type_Str
    | type_F16 | type_F32 
    | type_I16 | type_I24 | type_I32 | type_I8  
    | type_U16 | type_U24 | type_U32 | type_U8;

type_U8: U8;
type_U16: U16;
type_U24: U24;
type_U32: U32;
type_I8: I8;
type_I16: I16;
type_I24: I24;
type_I32: I32;
type_F16: F16;
type_F32: F32;
type_Str: STR;
type_Bool: BOOL;
type_Bit: BIT; // TODO type parameter

// identifiers
identifier_type: IDENTIFIERupper;
identifier_var: IDENTIFIERlower;
identifier_param: IDENTIFIERlower;
identifier_func: IDENTIFIERmixed | IDENTIFIERupper | IDENTIFIERlower;
identifier_field: IDENTIFIERmixed | IDENTIFIERupper | IDENTIFIERlower;
identifier_enumoption: IDENTIFIERmixed | IDENTIFIERupper | IDENTIFIERlower;
identifier_module: IDENTIFIERmixed | IDENTIFIERupper | IDENTIFIERlower;
identifier_unused: UNUSED;

// keywords
keyword_module: MODULE;
keyword_import: IMPORT;
keyword_export: EXPORT;
keyword_loop: LOOP;
keyword_break: BREAK;
keyword_continue: CONTINUE;
keyword_if: IF;
keyword_else: ELSE;
keyword_return: RETURN;
keyword_in: IN;
keyword_self: SELF;

literal_bool: TRUE | FALSE;
literal: number | string;

// numbers
number: number_unsigned;
number_unsigned: number_bin | number_oct | number_dec | number_hex | number_char;
number_bin: NUMBERbin;
number_oct: NUMBERoct;
number_dec: NUMBERdec | NUMBERdec_prefix;
number_hex: NUMBERhex;
number_char: character;

// operators
operator_arithmetic: op_plus | op_minus_neg | op_div | op_mod | op_mult | op_pow;
operator_arithmetic_unary: op_minus_neg;
operator_logic: op_and | op_or;
operator_logic_unary: op_not;
operator_comparison: op_eq_assign | op_neq | op_great | op_small | op_greq | op_smeq;
operator_bits: op_bit_and | op_bit_or | op_bit_xor | op_bit_shl | op_bit_shr | op_bit_roll | op_bit_rolr;
operator_bits_unary: op_bit_not;
operator_assignment: op_eq_assign;

op_plus: PLUS;
op_minus_neg: MINUS_NEG;
op_mult: MULT;
op_div: DIV;
op_mod: MOD;
op_pow: POW;
op_eq_assign: EQ_ASSIGN;
op_neq: NEQ;
op_great: GREAT_ANGLEclose;
op_small: SMALL_ANGLEopen;
op_greq: GREQ;
op_smeq: SMEQ;
op_and: AND;
op_or: OR;
op_not: NOT;
op_bit_and: BIT_AND;
op_bit_or: BIT_OR;
op_bit_xor: BIT_XOR;
op_bit_not: BIT_NOT;
op_bit_shl: BIT_SHL;
op_bit_shr: BIT_SHR;
op_bit_roll: BIT_ROLL;
op_bit_rolr: BIT_ROLR;
op_concat: CONCAT;

empty_line: INDENT? EOL+;
newline: INDENT? COMMENT? EOL;
comment: INDENT? COMMENT EOL;
string: STRING;
character: CHARACTER;

indent: INDENT;

//
// Tokens
//

// type names
U8: 'U8';
U16: 'U16';
U24: 'U24';
U32: 'U32';
I8: 'I8';
I16: 'I16';
I24: 'I24';
I32: 'I32';
F16: 'F16';
F32: 'F32';
STR: 'Str';
BOOL: 'Bool';
BIT: 'Bit';

// keywords
MODULE: 'module';
IMPORT: 'import';
EXPORT: 'export';
LOOP: 'loop';
BREAK: 'break';
CONTINUE: 'continue';
IF: 'if';
ELSE: 'else';
RETURN: 'return';
IN: 'in';
SELF: 'self';
TRUE: 'true';
FALSE: 'false';

COMMENT: COMMENTstart .*? ~[\r\n]+;

NUMBERbin: PREFIXbin (DIGIT2 | UNUSED)+;
NUMBERoct: PREFIXoct (DIGIT8 | UNUSED)+;
NUMBERdec: DIGIT10+;
NUMBERdec_prefix: PREFIXdec (DIGIT10 | UNUSED)+;
NUMBERhex: PREFIXhex (DIGIT16 UNUSED)+;

fragment ALPHAlower: [a-z];
fragment ALPHAupper: [A-Z];
fragment DIGIT2: [0-1];
fragment DIGIT8: [0-7];
fragment DIGIT10: [0-9];
fragment DIGIT16: [0-9a-fA-F];

// literals
fragment PREFIXbin: '0b';
fragment PREFIXoct: '0c';
fragment PREFIXdec: '0d';
fragment PREFIXhex: '0x';

CHARACTER: CHAR_QUOTE . CHAR_QUOTE;
STRING: STR_QUOTE .*? STR_QUOTE;

// operators
UNUSED: '_';
PLUS: '+';
MINUS_NEG: '-';
MULT: '*';
DIV: '/';
MOD: '%';
POW: '**';
EQ_ASSIGN: '=';
NEQ: '<>';
GREAT_ANGLEclose: '>';
SMALL_ANGLEopen: '<';
GREQ: '>=';
SMEQ: '<=';
AND: 'and';
OR: 'or';
NOT: 'not';
BIT_AND: '&';
BIT_OR: '|';
BIT_XOR: '^';
BIT_NOT: '~';
BIT_SHL: '<<';
BIT_SHR: '>>';
BIT_ROLL: '|,';
BIT_ROLR: '>|';
CONCAT: '&&';
SUBopen: '[';
SUBclose: ']';
PARENopen: '(';
PARENclose: ')';
QUESTION: '?';
COLON: ':';
DOT: '.';
RANGE: '..';
SPREAD: '...';
COMMA: ',';
META : '#';
COMPTIME: '#!';
ERROR: '!';
STR_QUOTE: '"';
CHAR_QUOTE: '\'';
COMMENTstart: '//';

// identifiers
IDENTIFIERupper: ALPHAupper IDENTIFIERpart*;
IDENTIFIERlower: ALPHAlower IDENTIFIERpart*;
IDENTIFIERmixed: (ALPHAlower | ALPHAupper | UNUSED) IDENTIFIERpart*;
fragment IDENTIFIERpart: ALPHAlower | ALPHAupper | DIGIT10 | UNUSED;

// whitespace
SP: ' ';
TAB: '\t';
INDENT: SP+ | TAB+;
EOL: '\r'? '\n' | '\r';
