#ifndef TEXTURE_HPP_
#define TEXTURE_HPP_ 69

#include "Game.hpp"
#include "PCH.hpp"
#include <SDL3/SDL.h>

namespace pl {

class Texture
{
public:
  Texture(std::string name) noexcept;
  ~Texture() = default;

  static const void loadTextures(std::string path) noexcept;

  const void setCoordinates(float x, float y) noexcept;
  const void setDimensions(float w, float h) noexcept;
  [[nodiscard]] std::pair<float, float> getCoordinates() const noexcept;
  [[nodiscard]] std::pair<float, float> getDimensions() const noexcept;

  SDL_Texture* getTexturePtr(std::string name) const noexcept;

  FORCE_INLINE_ void blitTexture() const noexcept
  {
    SDL_RenderTexture(
      App.getRenderer(), getTexturePtr(m_textureName), nullptr, &m_dstRect);
  }

  FORCE_INLINE_ void blitFlippedTexture() const noexcept
  {
    SDL_RenderTextureRotated(App.getRenderer(),
                             getTexturePtr(m_textureName),
                             nullptr,
                             &m_dstRect,
                             0.0f,
                             nullptr,
                             SDL_FLIP_HORIZONTAL);
  }

  FORCE_INLINE_ void blitClippedTexture(const SDL_FRect* srcRect) const noexcept
  {
    SDL_RenderTexture(
      App.getRenderer(), getTexturePtr(m_textureName), srcRect, &m_dstRect);
  }

  FORCE_INLINE_ void blitFlippedAndClippedTexture(
    const SDL_FRect* srcRect) const noexcept
  {
    SDL_RenderTextureRotated(App.getRenderer(),
                             getTexturePtr(m_textureName),
                             srcRect,
                             &m_dstRect,
                             0.0f,
                             nullptr,
                             SDL_FLIP_HORIZONTAL);
  }

public:
  inline static std::unordered_map<std::string, SDL_Texture*> Textures;

protected:
  std::string m_textureName;
  SDL_FRect m_dstRect;
};

} // pl

#endif // TEXTURE_HPP_
