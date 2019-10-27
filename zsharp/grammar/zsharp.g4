grammar zsharp;

// entry point
file : comment EOF;


// modules
module_name: module_name_part | module_name DOT module_name_part;
module_name_part: ALPHA ALPHANUMex*;
import_statement: keyword_import module_name;
export_statement: keyword_export (identifier_func | identifier_type | function_decl);

statement_if: keyword_if expression_logic;
statement_else: keyword_else statement_if?;

// expressions
expression_logic: 
      (logic_operand operator_logic logic_operand) 
    | (operator_logic_unary logic_operand);
logic_operand: expression_comparison;

expression_comparison: comparison_operand operator_comparison comparison_operand;
comparison_operand: expression_bitwise | function_call | variable_ref | literal;

expression_bitwise: 
      (bitwise_operand operator_bits bitwise_operand) 
    | (operator_bits_unary bitwise_operand);
bitwise_operand: function_call | variable_ref | number;

// functions
function_call: identifier_func PARENopen function_parameters? PARENclose;
function_decl: identifier_func PARENopen function_parameters? PARENclose function_return?;
function_parameters: identifier_param COLON type_name;
function_return: COLON type_name;

// variables
variable_ref: identifier_var;

// types
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
type_Bit: BIT;

// identifiers
identifier_type: ALPHAupper ALPHANUMex*;
identifier_var: ALPHAlower ALPHANUMex*;
identifier_param: ALPHAlower ALPHANUMex*;
identifier_func: ALPHAex ALPHANUMex*;
identifier_field: ALPHAex ALPHANUMex*;
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

literal: number | string;

// numbers
number: number_unsigned;
number_unsigned: number_bin | number_oct | number_dec | number_hex | number_char;
number_bin: NUMBERbin;
number_oct: NUMBERoct;
number_dec: NUMBERdec;
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
operator_assignment: op_eq_assign | op_cpy_assign;

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
op_cpy_assign: CPY_ASSIGN;
op_concat: CONCAT;

comment: COMMENT;
string: STRING;
character: CHARACTER;

indent: TAB;

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

COMMENT: COMMENTstart .*? ~[\r\n]+;

ALPHAlower: [a-z];
ALPHAupper: [A-Z];
ALPHA: [a-zA-Z];
ALPHAex: ALPHA | UNUSED;
ALPHANUM: [a-zA-Z0-9];
ALPHANUMex: ALPHANUM | UNUSED;

DIGIT2: [0-1];
DIGIT8: [0-7];
DIGIT10: [0-9];
DIGIT16: [0-9a-zA-Z];

// literals
PREFIXbin: '0b';
PREFIXoct: '0c';
PREFIXdec: '0d';
PREFIXhex: '0x';

NUMBERbin: PREFIXbin (DIGIT2 | UNUSED)+;
NUMBERoct: PREFIXoct (DIGIT8 | UNUSED)+;
NUMBERdec: (PREFIXdec (DIGIT10 | UNUSED)+) | DIGIT10+;
NUMBERhex: PREFIXhex (DIGIT16 | UNUSED)+;

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
CPY_ASSIGN: ':=';
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
META: '!';
PRAGMA: '#!';
STR_QUOTE: '"';
CHAR_QUOTE: '\'';
COMMENTstart: '//';

// whitespace
SP: ' ' -> skip;
TAB: '\t';
EOL: '\r'? '\n' | '\r';
