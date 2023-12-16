#ifndef APP_HPP_
#define APP_HPP_ 69

#include "MainChar.hpp"
#include "stl.hpp"
#include <SDL3/SDL.h>
namespace pl {

class _App final
{
public:
  _App() noexcept;
  _App(_App const&) = delete;
  _App& operator=(_App const&) = delete;
  ~_App() noexcept;

  [[nodiscard]] SDL_Renderer* getRenderer() noexcept;
  [[nodiscard]] SDL_Window* getWindow() noexcept;
  [[nodiscard]] SDL_Event& getEvent() noexcept;

  const void getOptions(int& argc, char** argv) noexcept;
  void initWindow(pair<int, int> dimensions) noexcept;

  inline void initSDL() noexcept;
  inline void getTicks() noexcept;
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
  atomic_uint64_t m_timer;
  mutex m_mutex;
};

extern _App App;
extern _MainChar* MainCharPtr;
} // pl

#endif // APP_HPP_
