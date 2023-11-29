#include <SDL3/SDL.h>

namespace pl {

class Entity
{
public:
  Entity(const char* path);
  ~Entity();

  void handleEvents() noexcept;

private:
  SDL_Texture* m_texture;
};

} // namespace pl