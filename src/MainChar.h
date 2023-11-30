#ifndef MAINCHAR_HPP_
#define MAINCHAR_HPP_ 69

#include "Entity.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_image.h>

namespace pl {

class _MainChar final : virtual public Entity
{
public:
  _MainChar() noexcept;
  _MainChar(_MainChar const&) = delete;
  _MainChar& operator=(_MainChar const&) = delete;
  ~_MainChar() noexcept;

  void handleEvents() noexcept override;
};

extern _MainChar MainChar;

} // pl
#endif // MAINCHAR_HPP_