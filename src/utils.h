#ifndef UTILS_HPP_
#define UTILS_HPP_ 69

#include <format>
#include <iostream>
#include <string>
#include <string_view>
#include <tuple>
#include <utility>
#include <vector>

namespace pl {
inline namespace ut {

using std::cout, std::endl, std::pair, std::vector, std::tuple, std::string,
  std::vformat, std::string_view, std::make_format_args;

// begin copy cat
template<typename... A>
auto
print(const string_view fmt, A&&... args)
{
  cout << vformat(fmt, make_format_args(args...)).c_str() << endl;
}
// end copy cat

} // ut
} // pl

#endif // UTILS_HPP_