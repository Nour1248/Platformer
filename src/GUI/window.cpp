#include "window.hpp"
#include "PCH.hpp" // IWYU pragma: export

namespace gui {

GUI::GUI(int& argc, char** argv)
  : QApplication{ argc, argv }
{
}

int
GUI::GUI_main() noexcept
{
  return 0;
}

}