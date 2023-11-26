#ifndef MEZO_HPP_
#define MEZO_HPP_

#include <SDL3/SDL.h>
#include <SDL3/SDL_image.h>

namespace pl {
class MainChar
{
private:
  SDL_Texture* texture;

private:
  MainChar(/* args */) noexcept;

public:
  MainChar(MainChar const&) = delete;
  MainChar& operator=(MainChar const&) = delete;
  ~MainChar() noexcept;

  static MainChar getSingleton() noexcept;
  void jump() noexcept;
  void rotate() noexcept;
  void handleEvents() noexcept;
};
} // namespace pl
#endif