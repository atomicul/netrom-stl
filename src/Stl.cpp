#include "Stl.hpp"

#include <iostream>
#include <vector>

int Stl::task(std::istream &in, std::ostream &out) {
  std::vector<std::string> lines;
  while (!in.eof()) {
    std::string line;
    std::getline(in, line);
    out << line << '\n';
  }

  return 0;
}
