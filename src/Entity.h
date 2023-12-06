#ifndef ENTITY_HPP_
#define ENTITY_HPP_ 69

#include "utils.h"
#include <SDL3/SDL.h>

namespace pl {

class Entity
{
public:
  Entity(const char* path);
  ~Entity();

  // virtual void handleEvents() noexcept;
  void blitSprite(int x, int y) noexcept;
  SDL_Texture* clipSheet(int idx) noexcept;

private:
  mutable atomic<SDL_Texture*> m_texture;
};

} // pl

#endif // ENTITY_HPP_