#ifndef UTILS_HPP_
#define UTILS_HPP_ 69

#include <format>
#include <iostream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

#define LOG(X) cout << X << endl
#define LOGandEXIT(X)                                                          \
  cerr << X << endl;                                                           \
  exit(1)

namespace pl {
inline namespace ut {
using std::cout, std::cerr, std::endl, std::pair, std::vector, std::tuple,
  std::string, std::format;
}
} // namespace pl

#endif // UTILS_HPP_