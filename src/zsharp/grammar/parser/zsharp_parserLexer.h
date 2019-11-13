
// Generated from c:\Users\marc\Documents\MyProjects\Zalt\Zlang\src\zsharp\grammar\zsharp_parser.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  zsharp_parserLexer : public antlr4::Lexer {
public:
  enum {
    U8 = 1, U16 = 2, U24 = 3, U32 = 4, I8 = 5, I16 = 6, I24 = 7, I32 = 8, 
    F16 = 9, F32 = 10, STR = 11, BOOL = 12, BIT = 13, MODULE = 14, IMPORT = 15, 
    EXPORT = 16, LOOP = 17, BREAK = 18, CONTINUE = 19, IF = 20, ELSE = 21, 
    RETURN = 22, IN = 23, SELF = 24, TRUE = 25, FALSE = 26, COMMENT = 27, 
    NUMBERbin = 28, NUMBERoct = 29, NUMBERdec = 30, NUMBERdec_prefix = 31, 
    NUMBERhex = 32, CHARACTER = 33, STRING = 34, UNUSED = 35, PLUS = 36, 
    MINUS_NEG = 37, MULT = 38, DIV = 39, MOD = 40, POW = 41, EQ_ASSIGN = 42, 
    NEQ = 43, GREAT_ANGLEclose = 44, SMALL_ANGLEopen = 45, GREQ = 46, SMEQ = 47, 
    AND = 48, OR = 49, NOT = 50, BIT_AND = 51, BIT_OR = 52, BIT_XOR = 53, 
    BIT_NOT = 54, BIT_SHL = 55, BIT_SHR = 56, BIT_ROLL = 57, BIT_ROLR = 58, 
    CONCAT = 59, SUBopen = 60, SUBclose = 61, PARENopen = 62, PARENclose = 63, 
    QUESTION = 64, COLON = 65, DOT = 66, RANGE = 67, SPREAD = 68, COMMA = 69, 
    META = 70, COMPTIME = 71, ERROR = 72, STR_QUOTE = 73, CHAR_QUOTE = 74, 
    COMMENTstart = 75, IDENTIFIERupper = 76, IDENTIFIERlower = 77, IDENTIFIERmixed = 78, 
    SP = 79, TAB = 80, INDENT = 81, EOL = 82
  };

  zsharp_parserLexer(antlr4::CharStream *input);
  ~zsharp_parserLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

