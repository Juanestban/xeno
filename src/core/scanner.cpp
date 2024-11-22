#include <cstddef>

#include "scanner.hpp"

namespace Xeno::Lexer {

template <typename Object>
Scanner<Object>::Scanner(string _source) : source(_source) {}

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
