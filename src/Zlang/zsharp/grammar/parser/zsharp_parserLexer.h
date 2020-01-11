
// Generated from c:\Users\marc\Documents\MyProjects\Zalt\Zlang\src\Zlang\zsharp\grammar\zsharp_parser.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  zsharp_parserLexer : public antlr4::Lexer {
public:
  enum {
    U8 = 1, U16 = 2, U24 = 3, U32 = 4, I8 = 5, I16 = 6, I24 = 7, I32 = 8, 
    F16 = 9, F32 = 10, STR = 11, BOOL = 12, BIT = 13, PTR = 14, MODULE = 15, 
    IMPORT = 16, EXPORT = 17, LOOP = 18, BREAK = 19, CONTINUE = 20, IF = 21, 
    ELSE = 22, RETURN = 23, IN = 24, SELF = 25, TRUE = 26, FALSE = 27, COMMENT = 28, 
    NUMBERbin = 29, NUMBERoct = 30, NUMBERdec = 31, NUMBERdec_prefix = 32, 
    NUMBERhex = 33, CHARACTER = 34, STRING = 35, UNUSED = 36, PLUS = 37, 
    MINUS_NEG = 38, MULT = 39, DIV = 40, MOD = 41, POW = 42, EQ_ASSIGN = 43, 
    NEQ = 44, GREAT_ANGLEclose = 45, SMALL_ANGLEopen = 46, GREQ = 47, SMEQ = 48, 
    AND = 49, OR = 50, NOT = 51, BIT_AND = 52, BIT_OR = 53, BIT_XOR = 54, 
    BIT_NOT = 55, BIT_SHL = 56, BIT_SHR = 57, BIT_ROLL = 58, BIT_ROLR = 59, 
    CONCAT = 60, SUBopen = 61, SUBclose = 62, PARENopen = 63, PARENclose = 64, 
    QUESTION = 65, COLON = 66, DOT = 67, RANGE = 68, SPREAD = 69, COMMA = 70, 
    META = 71, COMPTIME = 72, ERROR = 73, STR_QUOTE = 74, CHAR_QUOTE = 75, 
    COMMENTstart = 76, IDENTIFIERupper = 77, IDENTIFIERlower = 78, SP = 79, 
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

