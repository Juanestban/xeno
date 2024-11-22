#include <iostream>

#include "xeno_error.hpp"

namespace Xeno {
bool XenoError::had_error = false;

void XenoError::report(int line, string where, string message) {
  string line_str = to_string(line);

  cout << "[line " + line_str + " ] Error" + where + ": " + message << endl;
}

void XenoError::error(int line, string message) {
  report(line, "", message);
  had_error = true;
}

} // namespace Xeno
