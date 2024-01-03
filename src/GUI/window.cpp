#include "window.hpp"
#include "PCH.hpp" // IWYU pragma: exports

namespace gui {

GUIApp::GUIApp(int& argc, char** argv) noexcept
  : QApplication{ argc, argv }
{
}

int
GUIApp::GUI_main(QSettings s) noexcept
{
  return 0;
}

}