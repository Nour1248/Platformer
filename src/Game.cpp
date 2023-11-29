#include "Game.h"
#include "utils.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_image.h>

namespace pl {

_App App;

_App::_App() noexcept
  : m_windowShouldOpen(true)
  , m_icon(IMG_Load("../assets/Icon.png"))
{
  SDL_SetHint(SDL_HINT_APP_NAME, m_name.c_str());
}

_App::~_App() noexcept
{
  SDL_Quit();
  IMG_Quit();
  SDL_DestroyRenderer(m_renderer);
  SDL_DestroySurface(m_icon);
  SDL_DestroyWindow(m_window);
}

inline void
_App::initSDL() noexcept
{
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_EVENTS) != 0 ||
      IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
    goto ERROR;
  }
  return;
ERROR:
  cout << SDL_GetError() << endl;
  exit(1);
}

void
_App::initWindow(pair<int, int> dimensions) noexcept
{
  SDL_CreateWindowAndRenderer(m_dimensions.first,
                              m_dimensions.second,
                              SDL_WINDOW_RESIZABLE,
                              &m_window,
                              &m_renderer);
  if (!m_window || !m_renderer) {
    goto ERROR;
  }
  SDL_SetWindowTitle(m_window, m_name.c_str());
  SDL_SetWindowIcon(m_window, m_icon);

  return;
ERROR:
  LOG(SDL_GetError());
  exit(1);
}

inline void
_App::pollEvents() noexcept
{
  SDL_PollEvent(&m_event);
}

const SDL_Event
_App::getmEvent() noexcept
{
  return m_event;
}

SDL_Window*
_App::getmWindow() noexcept
{
  return m_window;
}

SDL_Renderer*
_App::getmRenderer() noexcept
{
  return m_renderer;
}

inline void
_App::handleEvents() noexcept
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

_App::argVector
_App::getOptions(int argc, char** argv) noexcept
{
  argVector av;
  for (int i = 0; i < argc; i++) {
    av.push_back(argv[i]);
  }
  return av;
}

inline void
_App::handleCmd(_App::argVector av) noexcept
{
}

inline void
_App::clearWindow() noexcept
{
  SDL_RenderClear(m_renderer);
}

inline void
_App::renderScene() noexcept
{
  SDL_RenderPresent(m_renderer);
}

int
_App::run(int& argc, char** argv) noexcept
{
  handleCmd(getOptions(argc, argv));
  initSDL();
  initWindow(m_dimensions);
  while (m_windowShouldOpen) {
    this->clearWindow();
    this->pollEvents();
    this->handleEvents();
    this->renderScene();
  }
  return 0;
}

} // namespace pl
