#ifndef MAINCHAR_HPP_
#define MAINCHAR_HPP_ 69

#include "Entity.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_image.h>

namespace pl {
class MainChar final : virtual public Entity
{
private:
  MainChar() noexcept;

public:
  MainChar(MainChar const&) = delete;
  MainChar& operator=(MainChar const&) = delete;
  ~MainChar() noexcept;

  static MainChar getSingleton() noexcept;
};
} // namespace pl
#endif // MAINCHAR_HPP_