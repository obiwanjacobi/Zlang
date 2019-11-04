
// Generated from c:\Users\marc\Documents\MyProjects\Zalt\Zlang\zsharp\grammar\zsharp_parser.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  zsharp_parserLexer : public antlr4::Lexer {
public:
  enum {
    U8 = 1, U16 = 2, U24 = 3, U32 = 4, I8 = 5, I16 = 6, I24 = 7, I32 = 8, 
    F16 = 9, F32 = 10, STR = 11, BOOL = 12, BIT = 13, MODULE = 14, IMPORT = 15, 
    EXPORT = 16, LOOP = 17, BREAK = 18, CONTINUE = 19, IF = 20, ELSE = 21, 
    RETURN = 22, IN = 23, SELF = 24, TRUE = 25, FALSE = 26, IDENTIFIERupper = 27, 
    IDENTIFIERlower = 28, IDENTIFIERmixed = 29, COMMENT = 30, NUMBERbin = 31, 
    NUMBERoct = 32, NUMBERdec = 33, NUMBERdec_prefix = 34, NUMBERhex = 35, 
    CHARACTER = 36, STRING = 37, UNUSED = 38, PLUS = 39, MINUS_NEG = 40, 
    MULT = 41, DIV = 42, MOD = 43, POW = 44, EQ_ASSIGN = 45, NEQ = 46, GREAT_ANGLEclose = 47, 
    SMALL_ANGLEopen = 48, GREQ = 49, SMEQ = 50, AND = 51, OR = 52, NOT = 53, 
    BIT_AND = 54, BIT_OR = 55, BIT_XOR = 56, BIT_NOT = 57, BIT_SHL = 58, 
    BIT_SHR = 59, BIT_ROLL = 60, BIT_ROLR = 61, CONCAT = 62, SUBopen = 63, 
    SUBclose = 64, PARENopen = 65, PARENclose = 66, QUESTION = 67, COLON = 68, 
    DOT = 69, RANGE = 70, SPREAD = 71, COMMA = 72, META = 73, COMPTIME = 74, 
    ERROR = 75, STR_QUOTE = 76, CHAR_QUOTE = 77, COMMENTstart = 78, SP = 79, 
    TAB = 80, INDENT = 81, EOL = 82
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

