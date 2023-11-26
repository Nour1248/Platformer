#include "Game.hpp"
#include <SDL3/SDL_image.h>
#include <iostream>

namespace pl {
App::App(std::pair<int32_t, int32_t> dimensions, std::string name) noexcept
{
  initSDL();
  SDL_CreateWindowAndRenderer(dimensions.first,
                              dimensions.second,
                              SDL_WINDOW_RESIZABLE,
                              &m_window,
                              &m_renderer);
  SDL_SetHint(SDL_HINT_APP_NAME, name.c_str());
  SDL_SetWindowTitle(m_window, name.c_str());
  if (!m_window || !m_renderer) {
    goto ERROR;
  }
  SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 0);

  m_windowShouldOpen = true;

  m_icon = IMG_Load("../assets/Icon.png");
  SDL_SetWindowIcon(m_window, m_icon);

  return;
ERROR:
  std::cout << SDL_GetError() << std::endl;
  exit(1);
}

App::~App() noexcept
{
  SDL_Quit();
  IMG_Quit();
  SDL_DestroyWindow(m_window);
  SDL_DestroyRenderer(m_renderer);
  SDL_DestroySurface(m_icon);
}

inline void
App::initSDL() noexcept
{
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_EVENTS) != 0 ||
      IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
    goto ERROR;
  }
  return;
ERROR:
  std::cout << SDL_GetError() << std::endl;
  exit(1);
}

inline void
App::pollEvents() noexcept
{
  SDL_PollEvent(&m_event);
}

inline void
App::handleEvents() noexcept
{
  switch (m_event.type) {
    case SDL_EVENT_QUIT:
      m_windowShouldOpen = false;
      break;
    case SDL_EVENT_MOUSE_BUTTON_UP:
      break;
    default:
      break;
  }
}

inline void
App::clearWindow() noexcept
{
  SDL_RenderClear(m_renderer);
}

inline void
App::renderScene() noexcept
{
  SDL_RenderPresent(m_renderer);
}

inline void
App::showMainMenu() noexcept
{
}

inline void
App::mapButtons() noexcept
{
}

int
App::mainLoop() noexcept
{
  while (m_windowShouldOpen) {
    this->clearWindow();
    this->showMainMenu();
    this->pollEvents();
    this->handleEvents();
    this->renderScene();
std::cout << SDL_GetTicks() << std::endl;
break;
  }
  return 0;
}

} // namespace pl

//  for benchmarking
