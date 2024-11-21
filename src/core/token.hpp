#include <string>

using namespace std;

namespace Xeno::Lexer {

enum TokenType {
  // single character tokens.
  LEFT_PAREN,
  RIGHT_PAREN,
  LEFT_BRACE,
  RIGHT_BRACE,
  COMMA,
  DOT,
  MINUS,
  PLUS,
  SEMICOLON,
  SLASH,
  STAR,

  // one or two character tokens.
  BANG,
  BANG_EQUAL,
  EQUAL,
  EQUAL_EQUAL,
  GREATER,
  GREATER_EQUAL,
  LESS,
  LESS_EQUAL,

  // literals.
  IDENTIFIER,
  STRING,
  INT,
  FLOAT,
  DOUBLE,
  BOOL,

  // keywords
  AND,
  CLASS,
  ELSE,
  FALSE,
  FN,
  FOR,
  IF,
  _NULL,
  UNDEFINED,
  UNKNOW,
  OR,
  PRINTLN,
  RETURN,
  SUPER,
  THIS,
  TRUE,
  VAR,
  WHILE,
  CONST,

  _EOF
};

template <class Object> class Token {
private:
  const TokenType type;
  const string lexeme;
  const Object literal;
  const int line;

public:
  Token(TokenType _type, string _lexeme, Object _literal, int _line);

  string to_string();
};

} // namespace Xeno::Lexer
