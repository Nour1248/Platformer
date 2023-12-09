#include "Texture.h"
#include "Game.h"
#include "utils.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_image.h>

namespace pl {

Texture::Texture(string name) noexcept
  : m_textureName(name)
{
}

SDL_Texture*
Texture::getTexturePtr(string name) const
{
  SDL_Texture* temp;
  try {
    temp = g_textures.at(name + ".png");
  } catch (out_of_range) {
    print("Wrong Name DumbAss : {}", name);
  }
  return temp;
}

void
Texture::blitTexture() const noexcept
{
  SDL_RenderTexture(
    App.getRenderer(), getTexturePtr(m_textureName), nullptr, nullptr);
}

void
Texture::blitClippedTexture(int idx) const noexcept
{
  SDL_RenderTexture(
    App.getRenderer(), getTexturePtr(m_textureName), nullptr, nullptr);
}

unordered_map<string, SDL_Texture*> g_textures;

const void
Texture::loadTextures(string path) noexcept
{
  pair<string, SDL_Texture*> dummyNode;

  for (const directory_entry& dirEntry : recursive_directory_iterator(path)) {
    if (dirEntry.is_regular_file() &&
        !(dirEntry.path().filename().string().compare("Icon.png") == 0)) {

      dummyNode.first = dirEntry.path().filename().string();
      dummyNode.second = IMG_LoadTexture(
        App.getRenderer(), dirEntry.path().relative_path().c_str());

      g_textures.insert(dummyNode);
      print("loaded texture : {}", dummyNode.first);

      if (dummyNode.second == NULL)
        print("Couldn't load texture : {}", dummyNode.first);
    }
  }
}

} // pl