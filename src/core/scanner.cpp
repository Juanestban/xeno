#include <cstddef>

#include "scanner.hpp"
#include "token.hpp"

namespace Xeno::Lexer {

template <typename Object>
Scanner<Object>::Scanner(string _source) : source(_source) {}

template <typename Object> void Scanner<Object>::init_keywords() {
  keywords = {
      {"int", TokenType::INT},
      {"float", TokenType::FLOAT},
      {"string", TokenType::STRING},
      {"double", TokenType::DOUBLE},
      {"bool", TokenType::BOOL},
      {"true", TokenType::TRUE},
      {"false", TokenType::FALSE},
      {"null", TokenType::_NULL},
      {"undefined", TokenType::UNDEFINED},
      {"unknow", TokenType::UNKNOW},
      {"fn", TokenType::FN},
      {"&&", TokenType::AND},
      {"||", TokenType::OR},
      {"class", TokenType::CLASS},
      {"extends", TokenType::EXTENDS},
      {"if", TokenType::IF},
      {"elif", TokenType::ELFI},
      {"else", TokenType::ELSE},
      {"for", TokenType::FOR},
      {"return", TokenType::RETURN},
      {"super", TokenType::SUPER},
      {"this", TokenType::THIS},
      {"var", TokenType::VAR},
      {"const", TokenType::CONST},
      {"while", TokenType::WHILE},
  };
}

template <typename Object> bool Scanner<Object>::is_at_end() {
  return current >= source.length();
}

template <typename Object> vector<Token<int>> Scanner<Object>::scan_tokens() {
  while (!is_at_end()) {
    start = current;
    scan_tokens();
  }

  tokens.push_back((const Token<int>)new Token(_EOF, "", NULL, line));

  return tokens;
}

} // namespace Xeno::Lexer
