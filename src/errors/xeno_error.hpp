#ifndef XENO_ERROR
#define XENO_ERROR

#include <string>

using namespace std;
using std::string;

namespace Xeno {

class XenoError {
public:
  static bool had_error;

public:
  static void error(int line, string message);

  static void report(int line, string where, string message);

private:
  XenoError() = delete;
};

} // namespace Xeno

#endif
