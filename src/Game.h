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

  SDL_Renderer* getmRenderer() noexcept;
  SDL_Window* getmWindow() noexcept;
  const SDL_Event getmEvent() noexcept;

  using argVector = vector<string>;
  argVector getOptions(int argc, char** argv) noexcept;
  void handleCmd(argVector av) noexcept;

  inline void initSDL() noexcept;
  inline void initWindow(pair<int, int> dimensions) noexcept;
  inline void pollEvents() noexcept;
  inline void handleEvents() noexcept;
  inline void clearWindow() noexcept;
  inline void renderScene() noexcept;

  int run(int& argc, char** argv) noexcept;

private:
  SDL_Window* m_window;
  SDL_Renderer* m_renderer;
  SDL_Surface* m_icon;
  SDL_Event m_event;
  SDL_Point m_mousePosition;
  string m_name;
  pair<int, int> m_dimensions;
  vector<pair<string, SDL_Rect>> m_textures;
  bool m_windowShouldOpen;
};

extern _App App;

} // namespace pl

#endif // APP_HPP_
