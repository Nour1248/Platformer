#ifndef ENTITY_HPP_
#define ENTITY_HPP_ 69

#include "utils.h"
#include <SDL3/SDL.h>

namespace pl {

class Texture
{
public:
  Texture(string name) noexcept;
  ~Texture() = default;

  static const void loadTextures(string path) noexcept;

  const void setCoordinates(int x, int y) noexcept;
  const void setDimensions(int w, int h) noexcept;
  void getCoordinates() const noexcept;
  void getDimensions() const noexcept;

  // virtual void handleEvents() noexcept;
  SDL_Texture* getTexturePtr(string name) const; // adds a png extention
  void blitTexture() const noexcept;
  void blitClippedTexture(int idx) const noexcept;

private:
  mutable string m_textureName;
  mutable SDL_FRect m_dstRect;
};

extern unordered_map<string, SDL_Texture*> g_textures;

} // pl

#endif // ENTITY_HPP_