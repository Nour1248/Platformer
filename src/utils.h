#include <iostream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

#define LOG(X) cout << X << endl

namespace pl {
inline namespace ut {
using std::cout, std::endl, std::pair, std::vector, std::tuple, std::string;

int
getOpt(int argc, char** argv, char** opts) noexcept;

}
} // namespace pl