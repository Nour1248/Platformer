#ifndef APP_HPP_
#define APP_HPP_

#include <SDL3/SDL.h>
#include <string>
#include <utility>
#include <vector>

namespace pl {
class App
{
private:
  SDL_Window* m_window;
  SDL_Renderer* m_renderer;
  SDL_Surface* m_icon;
  SDL_Event m_event;
  SDL_Point m_mousePosition;
  std::vector<std::pair<std::string, SDL_Rect>> m_Buttons;
  std::vector<std::pair<std::string, SDL_Rect>> m_textures;

  bool m_windowShouldOpen;

public:
  explicit App(std::pair<int32_t, int32_t> dimensions, std::string name) noexcept;
  ~App() noexcept;

  inline void initSDL() noexcept;
  inline void pollEvents() noexcept;
  inline void handleEvents() noexcept;
  inline void clearWindow() noexcept;
  inline void renderScene() noexcept;
  inline void showMainMenu() noexcept;
  inline void mapButtons() noexcept;

  int mainLoop() noexcept;
};

} // namespace pl

#endif // APP_HPP_
