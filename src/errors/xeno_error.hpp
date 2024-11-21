#include <string>

using namespace std;

namespace Xeno {

class XenoError {
private:
  static bool had_error;

public:
  static void error(int line, string message);

  static void report(int line, string where, string message);
};

} // namespace Xeno
