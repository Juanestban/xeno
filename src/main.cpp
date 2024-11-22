#include <cstdio>
#include <string>

#include "xeno_file.hpp"

// using namespace Xeno;
using namespace std;
using namespace Xeno;

void run(string source) {}

int main(int _, char *argv[]) {
  puts("Xeno version: 0.0.0");
  string path = argv[1];
  XenoFile *xeno_file = new XenoFile();

  xeno_file->read_file(path);

  return 0;
}
