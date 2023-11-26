#ifndef MEZO_HPP_
#define MEZO_HPP_

#include <SDL3/SDL.h>
#include <SDL3/SDL_image.h>

namespace it {
class Mezo
{
private:
  SDL_Texture* texture;

private:
  Mezo(/* args */) noexcept;

public:
  Mezo(Mezo const&) = delete;
  Mezo& operator=(Mezo const&) = delete;
  ~Mezo() noexcept;

  static Mezo getSingleton() noexcept;
  void jump() noexcept;
  void rotate() noexcept;
  void handleEvents() noexcept;
};
} // namespace it
#endif