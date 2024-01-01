#ifndef STL_HPP_
#define STL_HPP_ 69

#include <array>         // IWYU pragma: export
#include <atomic>        // IWYU pragma: export
#include <cstdint>       // IWYU pragma: export
#include <filesystem>    // IWYU pragma: export
#include <format>        // IWYU pragma: export
#include <functional>    // IWYU pragma: export
#include <iostream>      // IWYU pragma: export
#include <list>          // IWYU pragma: export
#include <mutex>         // IWYU pragma: export
#include <stdexcept>     // IWYU pragma: export
#include <string>        // IWYU pragma: export
#include <string_view>   // IWYU pragma: export
#include <thread>        // IWYU pragma: export
#include <unordered_map> // IWYU pragma: export
#include <utility>       // IWYU pragma: export
#include <vector>        // IWYU pragma: export

#if defined(__GNUC__)
#define FORCE_INLINE_ __attribute__((always_inline)) inline
#elif defined(_MSC_VER)
#define FORCE_INLINE_ __forceinline
#else
#define FORCE_INLINE_ inline
#endif

namespace pl {
inline namespace ut {

template<typename... A>
FORCE_INLINE_ void
print(const std::string_view fmt, A&&... args)
{
  std::cout << vformat(fmt, std::make_format_args(args...)) << std::flush;
}

} // ut
} // pl

#endif // STL_HPP_
