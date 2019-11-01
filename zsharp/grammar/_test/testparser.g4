parser grammar testparser;
options { tokenVocab=testlexer; }
test: TOKEN (TOKEN)*;
