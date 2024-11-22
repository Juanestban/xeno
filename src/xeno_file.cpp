#include <exception>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

#include "xeno_file.hpp"

namespace fs = filesystem;

namespace Xeno {

void XenoFile::read_file(string &path) {
  try {
    fs::path sandbox{path};

    if (!fs::exists(sandbox)) {
      throw runtime_error("File don't exist");
    }

    ifstream file(path, ios::binary);

    if (!file) {
      throw runtime_error("Can't open/read file");
    }

    ostringstream buffer;
    buffer << file.rdbuf();
    file.close();

    string content = buffer.str();
    cout << "[+] content:\n" + content << endl;
  } catch (const exception &err) {
    cerr << "\n[-] Error: " << err.what() << endl;
  }
}

} // namespace Xeno
