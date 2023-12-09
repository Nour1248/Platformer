#ifndef UTILS_HPP_
#define UTILS_HPP_ 69

// just keeping track of what i learned from the STL

#include <atomic>
#include <filesystem>
#include <format>
#include <iostream>
#include <mutex>
#include <stdexcept>
#include <string>
#include <string_view>
#include <thread>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

namespace pl {
inline namespace ut {

using std::cout, std::endl, std::unordered_map, std::pair, std::vector,
  std::tuple, std::thread, std::mutex, std::lock_guard, std::string,
  std::vformat, std::string_view, std::make_format_args,
  std::filesystem::recursive_directory_iterator,
  std::filesystem::directory_entry, std::atomic, std::out_of_range;

// begin copy cat
// until c++23 print is implemented in libstdc++
template<typename... A>
void
print(const string_view fmt, A&&... args)
{
  cout << vformat(fmt, make_format_args(args...)).c_str() << endl;
}
// end copy cat

} // ut
} // pl

#endif // UTILS_HPP_