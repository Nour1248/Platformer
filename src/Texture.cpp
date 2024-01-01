#include "Texture.hpp"
#include "Game.hpp"
#include "PCH.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_image.h>

namespace pl {

Texture::Texture(std::string name) noexcept
  : m_textureName{ name }
{
}

const void
Texture::loadTextures(std::string path) noexcept
{
  std::pair<std::string, SDL_Texture*> dNode;

  for (const auto& dirEntry :
       std::filesystem::recursive_directory_iterator(path)) {
    if (dirEntry.is_regular_file() &&
        !(dirEntry.path().filename().string().compare("Icon.png") == 0))
      [[likely]] {

      dNode.first = dirEntry.path().filename().string();
      dNode.second = IMG_LoadTexture(App.getRenderer(),
                                     dirEntry.path().relative_path().c_str());

      Textures.insert(dNode);
      print("loaded texture : {}\n", dNode.first);

      if (dNode.second == nullptr)
        print("Couldn't load texture : {}\n", dNode.first);
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

std::pair<float, float>
Texture::getCoordinates() const noexcept
{
  return { m_dstRect.x, m_dstRect.y };
}

std::pair<float, float>
Texture::getDimensions() const noexcept
{
  return { m_dstRect.x, m_dstRect.y };
}

SDL_Texture*
Texture::getTexturePtr(std::string name) const noexcept
try {
  return Textures.at(name + ".png");
} catch (...) {
  print("Wrong Name DumbAss : {} \n", name);
  return nullptr;
}

} // namespace pl