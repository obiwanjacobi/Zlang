lexer grammar indentLexer;

options {
    superClass = IndentingLexer;
}

@lexer::postinclude {
#include "../IndentingLexer.h"
}

tokens { INDENT, DEDENT }

TOK: 'tok';

EOL: '\r'? '\n' | '\r';
WS: ' '+ -> skip;