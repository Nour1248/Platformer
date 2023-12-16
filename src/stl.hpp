#ifndef UTILS_HPP_
#define UTILS_HPP_ 69

// just keeping track of what i learned from the STL
#include <array>
#include <atomic>
#include <cstdint>
#include <cstdio>
#include <filesystem>
#include <format>
#include <list>
#include <mutex>
#include <stdexcept>
#include <string>
#include <string_view>
#include <thread>
#include <tuple>
#include <unordered_map>
#include <utility>

namespace pl {
inline namespace ut {

using std::fprintf, std::FILE, std::unordered_map, std::array, std::pair,
  std::tuple, std::list, std::thread, std::mutex, std::lock_guard, std::string,
  std::vformat, std::string_view, std::make_format_args,
  std::filesystem::recursive_directory_iterator,
  std::filesystem::directory_entry, std::out_of_range, std::atomic_uint64_t,
  std::uint64_t;

// until c++23 print is implemented in libstdc++
template<typename... A>
void
print(FILE* stream, const string_view fmt, A&&... args)
{
  fprintf(stream, vformat(fmt, make_format_args(args...)).c_str());
  fflush(stream);
}

} // ut
} // pl

#endif // UTILS_HPP_