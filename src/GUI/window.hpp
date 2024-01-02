#ifndef GUI_HPP_
#define GUI_HPP_

#include "PCH.hpp" // IWYU pragma: export

namespace gui {

class GUI : public QApplication
{
  Q_OBJECT
  Q_DISABLE_COPY_MOVE(GUI)
public:
  GUI(int& argc, char** argv);

  int GUI_main() noexcept;
};

}
#endif // GUI_HPP_