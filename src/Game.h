#ifndef APP_HPP_
#define APP_HPP_ 69

#include "utils.h"
#include <SDL3/SDL.h>

namespace pl {

class _App final
{
public:
  _App() noexcept;
  _App(_App const&) = delete;
  _App& operator=(_App const&) = delete;
  ~_App() noexcept;

  SDL_Renderer* getRenderer() noexcept;
  SDL_Window* getWindow() noexcept;
  SDL_Event& getEvent() noexcept;

  const void getOptions(int& argc, char** argv) noexcept;

  inline void initSDL() noexcept;
  inline void initWindow(pair<int, int> dimensions) noexcept;
  inline void pollEvents() noexcept;
  inline void handleEvents() noexcept;
  inline void clearWindow() noexcept;
  inline void renderScene() noexcept;

  int run(int& argc, char** argv) noexcept;

private:
  string m_name;
  SDL_Surface* m_icon;
  SDL_Window* m_window;
  SDL_Renderer* m_renderer;
  SDL_Event m_event;
  bool m_windowShouldOpen;
  pair<int, int> m_mousePosition;
  pair<int, int> m_dimensions;
};
extern _App App;

} // pl

#endif // APP_HPP_
