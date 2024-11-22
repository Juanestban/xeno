#ifndef XENO_SCANNER
#define XENO_SCANNER

#include <string>
#include <vector>

#include "../errors/xeno_error.hpp"
#include "token.hpp"

using std::string;
using std::vector;

namespace Xeno::Lexer {

template <typename Object> class Scanner {
private:
  const string source;
  vector<Token<int>> tokens = {};
  int start = 0;
  int current = 0;
  int line = 1;

public:
  Scanner(string _source);

public:
  bool is_at_end();

  vector<Token<int>> scan_tokens();

private:
  char advance() { return source.at(current++); };

  void scan_token(enum TokenType type) {
    char c = advance();

    switch (c) {
    case '(': {
      add_token(LEFT_PAREN);
      break;
    }
    case ')': {
      add_token(RIGHT_PAREN);
      break;
    }
    case '{': {
      add_token(LEFT_BRACE);
      break;
    }
    case '}': {
      add_token(RIGHT_BRACE);
      break;
    }
    case ',': {
      add_token(COMMA);
      break;
    }
    case '.': {
      add_token(DOT);
      break;
    }
    case '-': {
      add_token(MINUS);
      break;
    }
    case '+': {
      add_token(PLUS);
      break;
    }
    case ';': {
      add_token(SEMICOLON);
      break;
    }
    case '*': {
      add_token(STAR);
      break;
    }
    case '!': {
      add_token(match('=') ? BANG_EQUAL : BANG);
      break;
    }
    case '=': {
      add_token(match('=') ? EQUAL_EQUAL : EQUAL);
      break;
    }
    case '<': {
      add_token(match('=') ? LESS_EQUAL : LESS);
      break;
    }
    case '>': {
      add_token(match('=') ? GREATER_EQUAL : GREATER);
      break;
    }
    case '/': {
      if (match('/')) {
        while (peek() != '\n' && !is_at_end()) {
          advance();
        }
      } else {
        add_token(SLASH);
      }

      break;
    }
    case ' ':
    case '\r':
    case '\t':
      break;
    case '\n':
      line++;
      break;
    case '"':
      _string();
      break;
    case '|': {
      if (match('|')) {
        // is cond [OR]
        add_token(OR);
      }
      break;
    }
    case '&': {
      if (match('&')) {
        // is cond [AND]
        add_token(AND);
      }
      break;
    }
    default: {
      if (is_digit(c)) {
        _number();
      } else if (is_alpha(c)) {
        identifier();
      } else {
        XenoError::error(line, "Unexpected character.");
      }
      break;
    }
    }
  };

private:
  bool is_alpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
  }

  void identifier() {
    while (is_alpha_numeric(peek())) {
      advance();
    }

    add_token(IDENTIFIER);
  }

  bool is_alpha_numeric(char c) { return is_alpha(c) || is_digit(c); }

  void _string() {
    while (peek() != '"' && !is_at_end()) {
      if (peek() == '\n')
        line++;
      advance();
    }

    if (is_at_end()) {
      XenoError::error(line, "Unterminated string");
      return;
    }

    advance();

    string value = source.substr(start + 1, current - 1);

    add_token(STRING, value);
  }

  bool is_digit(char c) { return c >= '0' && c <= '9'; }

  void _number() {
    while (is_digit(peek())) {
      advance();
    }

    // another functions after DOT
    // if (peek() == '.') {}

    // decimal/float using COMMA
    if (peek() == ',' && is_digit(next_peek())) {
      advance();

      while (is_digit(peek())) {
        advance();
      }

      add_token(FLOAT, std::stof(source.substr(start, current)));
    }

    add_token(INT, std::stoi(source.substr(start, current)));
  }

  char next_peek() {
    if (current + 1 >= source.length()) {
      return '\0';
    }

    return source.at(current + 1);
  }

  char peek() {
    if (is_at_end()) {
      return '\0';
    }

    return source.at(current);
  }

  bool match(char expected) {
    if (is_at_end()) {
      return false;
    }

    if (source.at(current) != expected) {
      return false;
    }

    current++;

    return true;
  }

  void add_token(enum TokenType type) { add_token(type, NULL); }

  void add_token(enum TokenType type, Object literal) {
    string text = source.substr(start, current);
    tokens.push_back((const Token<Object>)new Token(type, text, literal, line));
  };
};

} // namespace Xeno::Lexer

#endif
