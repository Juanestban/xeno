#include "token.hpp"

namespace Xeno::Lexer {

template <typename T>
Token<T>::Token(TokenType _type, string _lexeme, T _literal, int _line)
    : type(_type), lexeme(_lexeme), literal(_literal), line(_line) {}

template <typename T> string Token<T>::to_string() {
  return type + " " + lexeme + " " + literal;
}
} // namespace Xeno::Lexer
