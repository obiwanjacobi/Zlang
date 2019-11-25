parser grammar indentParser;

options {
    tokenVocab = indentLexer;
}

start: line* EOF;
line: (INDENT TOK DEDENT)* EOL;
