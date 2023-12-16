#include "Texture.hpp"
#include "Game.hpp"
#include "stl.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_image.h>
#include <cstdio>

namespace pl {

Texture::Texture(string name, Rect<float> dstRect) noexcept
  : m_textureName{ name }
  , m_dstRect{ dstRect.toSDL_FRect() }
{
}

const void
Texture::loadTextures(string path) noexcept
{
  pair<string, SDL_Texture*> dNode;

  for (const directory_entry& dirEntry : recursive_directory_iterator(path)) {
    if (dirEntry.is_regular_file() &&
        !(dirEntry.path().filename().string().compare("Icon.png") == 0)) {

      dNode.first = dirEntry.path().filename().string();
      dNode.second = IMG_LoadTexture(App.getRenderer(),
                                     dirEntry.path().relative_path().c_str());

      Textures.insert(dNode);
      print(stdout, "loaded texture : {}\n", dNode.first);

      if (dNode.second == nullptr)
        print(stderr, "Couldn't load texture : {}\n", dNode.first);
    }
  }
}

const void
Texture::setCoordinates(float x, float y) noexcept
{
  m_dstRect.x = x;
  m_dstRect.y = y;
}

const void
Texture::setDimensions(float w, float h) noexcept
{
  m_dstRect.w = w;
  m_dstRect.h = h;
}

pair<float, float>
Texture::getCoordinates() const noexcept
{
  return { m_dstRect.x, m_dstRect.y };
}

pair<float, float>
Texture::getDimensions() const noexcept
{
  return { m_dstRect.x, m_dstRect.y };
}

SDL_Texture*
Texture::getTexturePtr(string name) const
try {
  return Textures.at(name + ".png");
} catch (out_of_range) {
  print(stderr, "Wrong Name DumbAss : {} \n", name);
  return nullptr;
}

void
Texture::blitTexture() const noexcept
{
  SDL_RenderTexture(
    App.getRenderer(), getTexturePtr(m_textureName), nullptr, &m_dstRect);
}

void
Texture::blitClippedTexture(const SDL_FRect* srcRect) const noexcept
{
  SDL_RenderTexture(
    App.getRenderer(), getTexturePtr(m_textureName), srcRect, &m_dstRect);
}

} // pl