#include "Stl.hpp"

#include <algorithm>
#include <boost/program_options.hpp>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

namespace po = boost::program_options;
using namespace std::literals::string_literals;

int main(int argc, const char *argv[]) {
  const std::string k_input = "input";
  const std::string k_output = "output";

  try {
    po::options_description desc{"Options"};
    desc.add_options()("help,h", "Help screen")(
        (k_output + ",o"s).c_str(), po::value<std::string>(),
        "Output file")((k_input + ",i"s).c_str(),
                       po::value<std::vector<std::string>>(), "Input file");

    po::positional_options_description pos_desc;
    pos_desc.add(k_input.c_str(), -1);

    po::command_line_parser parser{argc, argv};
    parser.options(desc).positional(pos_desc);
    po::parsed_options parsed_options = parser.run();

    po::variables_map vm;
    po::store(parsed_options, vm);
    po::notify(vm);

    if (vm.count("help")) {
      std::cout << "Usage: " << argv[0] << " [OPTION]... [FILE]\n\n";
      std::cout << desc << '\n';
      return 0;
    }

    std::ifstream in(
        vm.count(k_input) ? vm[k_input].as<std::vector<std::string>>()[0] : "");

    std::ofstream out(vm.count(k_output) ? vm[k_output].as<std::string>() : "");

    Stl::task(in.is_open() ? in : std::cin, out.is_open() ? out : std::cout);

  } catch (const po::error &ex) {
    std::cerr << ex.what() << '\n';
    return 1;
  }
}
