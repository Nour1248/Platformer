#ifndef MAINCHAR_HPP_
#define MAINCHAR_HPP_ 69

#include "Texture.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_image.h>

namespace pl {

class _MainChar final : virtual public Texture
{
public:
  _MainChar();
  _MainChar(_MainChar const&) = delete;
  _MainChar& operator=(_MainChar const&) = delete;
  ~_MainChar() noexcept = default;

  // void handleEvents() noexcept override;
};

extern _MainChar MainChar;

} // pl
#endif // MAINCHAR_HPP_