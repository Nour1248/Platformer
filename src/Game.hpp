#ifndef GAME_HPP_
#define GAME_HPP_ 69

#include "PCH.hpp"
#include "global.h"
#include <SDL3/SDL.h>

namespace pl {

class _App final
{
public:
  _App() noexcept;
  _App(_App const&) = delete;
  _App& operator=(_App const&) = delete;
  ~_App() noexcept;

  [[nodiscard]] SDL_Renderer* getRenderer() const noexcept;
  [[nodiscard]] SDL_Window* getWindow() const noexcept;
  [[nodiscard]] const SDL_Event& getEvent() const noexcept;
  [[nodiscard]] const std::atomic_uint64_t& getTicks() const noexcept;

  void setWindowState(bool shouldOpen) noexcept;

  void getOptions(int& argc, char** argv) noexcept;
  void initSDL() noexcept;
  void initWindow(std::pair<int, int> dimensions) noexcept;
  void initRenderer(const char* apiName, bool vSync) noexcept;

  FORCE_INLINE_ void updateTicks() noexcept { m_timer = SDL_GetTicks(); }

  FORCE_INLINE_ void clearWindow() noexcept { SDL_RenderClear(m_renderer); }

  FORCE_INLINE_ void renderScene() noexcept { SDL_RenderPresent(m_renderer); }

  FORCE_INLINE_ void delay(int ms) noexcept { SDL_Delay(ms); }

  int run(int& argc, char** argv) noexcept;

private:
  std::string m_name;
  SDL_Surface* m_icon;
  SDL_Window* m_window;
  SDL_Renderer* m_renderer;
  bool m_windowShouldOpen;
  std::pair<int, int> m_mousePosition;
  std::pair<int, int> m_dimensions;
  std::atomic_uint64_t m_timer;
  QSettings m_settings;
};

extern _App App;
} // pl

#endif // GAME_HPP_
