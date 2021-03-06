grammar zsharp_parser;

// entry point
file : source* EOF;
source: (module_statement | definition_top | comment | empty_line);
codeblock: (flow_statement | variable_assign | function_call | definition | comment | empty_line)+;

// modules
module_statement : statement_module | statement_import | statement_export;
module_name: identifier_module | module_name DOT identifier_module;
statement_module: MODULE SP module_name newline;
statement_import: IMPORT SP module_name newline;
statement_export: EXPORT SP (identifier_func | identifier_type) newline;

// flow control
flow_statement: statement_if | statement_else | statement_elseif
    | statement_loop | statement_return | statement_break | statement_continue;
statement_return: indent RETURN (SP expression_value)? newline;
statement_if: indent IF SP expression_logic newline codeblock;
statement_else: indent ELSE newline codeblock;
statement_elseif: indent ELSE SP IF SP expression_logic newline codeblock;
statement_break: indent BREAK;
statement_continue: indent CONTINUE;
statement_loop: indent (statement_loop_infinite | statement_loop_while) newline codeblock;
statement_loop_infinite: LOOP;
statement_loop_while: LOOP SP expression_logic;

// definition
definition_top: function_def_export | function_def | enum_def | struct_def 
    | type_def | type_alias | variable_def_top;
definition: variable_def;

// expressions
expression_value: number | string | expression_bool
    | expression_arithmetic | expression_logic
    | function_call;
comptime_expression_value: number | string | expression_bool;

expression_arithmetic: 
      expression_arithmetic SP operator_arithmetic SP expression_arithmetic
    | expression_arithmetic SP operator_bits SP expression_arithmetic
    | PARENopen expression_arithmetic PARENclose
    | operator_arithmetic_unary expression_arithmetic
    | operator_bits_unary expression_arithmetic
    | arithmetic_operand;
arithmetic_operand: number | variable_ref | function_call;

expression_logic: 
      expression_logic SP operator_logic SP expression_logic
    | PARENopen expression_logic PARENclose
    | operator_logic_unary SP expression_logic
    | logic_operand;
logic_operand: expression_comparison | expression_bool;

expression_comparison: 
      expression_comparison SP operator_comparison SP expression_comparison
    | PARENopen expression_comparison PARENclose
    | comparison_operand;
comparison_operand: expression_arithmetic | function_call | variable_ref | literal;

expression_bool: literal_bool | variable_ref;

// functions
function_call: indent identifier_func PARENopen function_parameter_uselist? PARENclose newline;
function_def: identifier_func PARENopen function_parameter_list? PARENclose type_ref_use? newline codeblock;
function_def_export: EXPORT SP function_def;
function_parameter_list: (function_parameter | function_parameter_self) (COMMA SP function_parameter)*;
function_parameter: identifier_param type_ref_use;
function_parameter_self: SELF type_ref_use?;
function_parameter_uselist: function_param_use (COMMA SP function_param_use)*;
function_param_use: expression_value (COMMA SP expression_value)*;

// variables
variable_ref: identifier_var;
variable_def_top: (variable_def_typed | variable_def_typed_init | variable_assign_auto) newline;
variable_def: indent (variable_def_typed | variable_def_typed_init | variable_assign_auto) newline;
variable_def_typed: identifier_var type_ref_use;
variable_def_typed_init: identifier_var type_ref_use SP EQ_ASSIGN SP expression_value;
variable_assign_auto: identifier_var SP EQ_ASSIGN SP expression_value;
variable_assign: indent variable_assign_auto;

// structs
struct_def: identifier_type type_param_list? (type_ref_use)? (newline struct_field_def_list);
struct_field_def_list: struct_field_def+;
struct_field_def: indent identifier_field type_ref_use newline;

// enums
enum_def: identifier_type (COLON SP enum_base_type)? newline (enum_option_def_list | enum_option_def_listline);
enum_option_def_listline: indent (identifier_enumoption COMMA SP)* identifier_enumoption COMMA? newline;
enum_option_def_list: (enum_option_def COMMA newline)* enum_option_def COMMA? newline;
enum_option_def: indent identifier_enumoption enum_option_value?;
enum_option_value: SP EQ_ASSIGN SP comptime_expression_value;
enum_base_type: type_Bit 
    | STR
    | F16 | F32 
    | I16 | I24 | I32 | I8
    | U16 | U24 | U32 | U8;

// types
type_def: identifier_type type_param_list? type_ref_use SP UNUSED newline;
type_alias: identifier_type type_param_list? SP EQ_ASSIGN SP type_ref newline;
type_ref_use: COLON SP type_ref;
type_ref: type_name ERROR? QUESTION?;

type_name: known_types | identifier_type type_param_list?;
known_types:
    type_Bit | type_Ptr
    | BOOL | STR
    | F16 | F32 
    | I16 | I24 | I32 | I8  
    | U16 | U24 | U32 | U8;

type_Bit: BIT type_param_number;
type_Ptr: PTR type_param_type_use;

type_param_number: SMALL_ANGLEopen number GREAT_ANGLEclose;
type_param_list: SMALL_ANGLEopen type_param_name_list GREAT_ANGLEclose;
type_param_name_list: type_param_type (COMMA SP type_param_type)*;
type_param_type_use: SMALL_ANGLEopen type_param_type GREAT_ANGLEclose;
type_param_type: type_name | number;

// identifiers
identifier_type: IDENTIFIERupper;
identifier_var: IDENTIFIERlower;
identifier_param: IDENTIFIERlower;
identifier_func: IDENTIFIERupper | IDENTIFIERlower;
identifier_field: IDENTIFIERupper | IDENTIFIERlower;
identifier_enumoption: IDENTIFIERupper | IDENTIFIERlower;
identifier_module: IDENTIFIERupper | IDENTIFIERlower;
identifier_unused: UNUSED;

literal_bool: TRUE | FALSE;
literal: number | string;

// numbers
number: number_bin | number_oct | number_dec | number_hex | number_char;
number_bin: NUMBERbin;
number_oct: NUMBERoct;
number_dec: NUMBERdec | NUMBERdec_prefix;
number_hex: NUMBERhex;
number_char: character;

// operators
operator_arithmetic: PLUS | MINUS_NEG | DIV | MOD | MULT | POW;
operator_arithmetic_unary: MINUS_NEG;
operator_logic: AND | OR;
operator_logic_unary: NOT;
operator_comparison: EQ_ASSIGN | NEQ | GREAT_ANGLEclose | SMALL_ANGLEopen | GREQ | SMEQ;
operator_bits: BIT_AND | BIT_OR | BIT_XOR | BIT_SHL | BIT_SHR | BIT_ROLL | BIT_ROLR;
operator_bits_unary: BIT_NOT;
operator_assignment: EQ_ASSIGN;

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
PTR: 'Ptr';

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
NUMBERhex: PREFIXhex (DIGIT16 | UNUSED)+;

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
fragment IDENTIFIERpart: ALPHAlower | ALPHAupper | DIGIT10 | UNUSED;

// whitespace
SP: ' ';
TAB: '\t';
INDENT: SP+;
EOL: '\r'? '\n' | '\r';
