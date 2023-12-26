#ifndef ENTITY_HPP_
#define ENTITY_HPP_ 69

#include "stl.hpp"
#include <SDL3/SDL.h>

namespace pl {

class Texture
{
public:
  Texture(string name) noexcept;
  ~Texture() = default;

  static const void loadTextures(string path) noexcept;

  const void setCoordinates(float x, float y) noexcept;
  const void setDimensions(float w, float h) noexcept;
  [[nodiscard]] pair<float, float> getCoordinates() const noexcept;
  [[nodiscard]] pair<float, float> getDimensions() const noexcept;

  SDL_Texture* getTexturePtr(string name) const noexcept;
  void blitTexture() const noexcept;
  void blitFlippedTexture() const noexcept;
  void blitClippedTexture(const SDL_FRect* srcRect) const noexcept;
  void blitFlippedAndClippedTexture(const SDL_FRect* srcRect) const noexcept;

public:
  inline static unordered_map<string, SDL_Texture*> Textures;

protected:
  string m_textureName;
  SDL_FRect m_dstRect;
};

} // pl

#endif // ENTITY_HPP_
