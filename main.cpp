#include "Stl.hpp"

#include <algorithm>
#include <boost/program_options.hpp>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

namespace po = boost::program_options;

int main(int argc, const char *argv[]) {
  try {
    po::options_description desc{"Options"};
    desc.add_options()("help,h", "Help screen")(
        "output,o", po::value<std::string>(), "Output file");

    po::positional_options_description pos_desc;
    pos_desc.add("input", 1);

    po::command_line_parser parser{argc, argv};
    parser.options(desc).positional(pos_desc);
    po::parsed_options parsed_options = parser.run();

    po::variables_map vm;
    store(parsed_options, vm);
    notify(vm);

    if (vm.count("help")) {
      std::cout << "Usage: " << argv[0] << " [OPTION]... [FILE]\n\n";
      std::cout << desc << '\n';
      return 0;
    }

    std::ifstream in(vm.count("input") ? vm["input"].as<std::string>() : "");

    std::ofstream out(vm.count("output") ? vm["output"].as<std::string>() : "");

    Stl::task(in.is_open() ? in : std::cin, out.is_open() ? out : std::cout);
  } catch (const po::error &ex) {
    std::cerr << ex.what() << '\n';
    return 1;
  }
}
