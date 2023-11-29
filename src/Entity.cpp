#include "Entity.h"
#include "Game.h"
#include "SDL3/SDL_image.h"

namespace pl {

Entity::Entity(const char* path)
  : m_texture(IMG_LoadTexture(App.getmRenderer(), path))
{
}

} // namespace pl