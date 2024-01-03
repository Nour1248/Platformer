#ifndef GUI_HPP_
#define GUI_HPP_

#include "PCH.hpp" // IWYU pragma: export

namespace gui {

class GUIApp : public QApplication
{
  Q_OBJECT
  Q_DISABLE_COPY_MOVE(GUIApp)
public:
  GUIApp(int& argc, char** argv) noexcept;

  int GUI_main(QSettings s) noexcept;
};

}
#endif // GUI_HPP_