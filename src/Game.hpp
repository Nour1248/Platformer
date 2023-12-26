#ifndef APP_HPP_
#define APP_HPP_ 69

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

  [[nodiscard]] SDL_Renderer* getRenderer() const noexcept;
  [[nodiscard]] SDL_Window* getWindow() const noexcept;
  [[nodiscard]] const SDL_Event& getEvent() const noexcept;
  [[nodiscard]] const atomic_uint64_t& getTicks() const noexcept;

  void setWindowState(bool shouldOpen) noexcept;

  void getOptions(int& argc, char** argv) noexcept;
  void initSDL() noexcept;
  FORCE_INLINE_ void initWindow(pair<int, int> dimensions) noexcept;
  FORCE_INLINE_ void initRenderer(const char* apiName, bool vSync) noexcept;

  FORCE_INLINE_ void updateTicks() noexcept;
  FORCE_INLINE_ void clearWindow() noexcept;
  FORCE_INLINE_ void renderScene() noexcept;
  FORCE_INLINE_ void delay(int ms) noexcept;

  int run(int& argc, char** argv) noexcept;

private:
  string m_name;
  SDL_Surface* m_icon;
  SDL_Window* m_window;
  SDL_Renderer* m_renderer;
  bool m_windowShouldOpen;
  pair<int, int> m_mousePosition;
  pair<int, int> m_dimensions;
  atomic_uint64_t m_timer;
};

extern _App App;
} // pl

#endif // APP_HPP_
