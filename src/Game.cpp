#include "Game.hpp"
#include "Animation.hpp"
#include "MainChar.hpp"
#include "Texture.hpp"
#include "stl.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_image.h>
#include <cstdio>
#include <unistd.h>

namespace pl {

_App App;
_MainChar* MainCharPtr;

_App::_App() noexcept
  : m_name{ "Platformer" }
  , m_icon{ IMG_Load("../assets/Icon.png") }
  , m_windowShouldOpen{ true }
{
  SDL_SetHint(SDL_HINT_APP_NAME, m_name.c_str());
}

_App::~_App() noexcept
{
  SDL_DestroyRenderer(m_renderer);
  SDL_DestroySurface(m_icon);
  SDL_DestroyWindow(m_window);
  IMG_Quit();
  SDL_Quit();
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
  print(stderr, "Error initializing the window : {} \n", SDL_GetError());
  exit(1);
}

SDL_Event&
_App::getEvent() noexcept
{
  return m_event;
}

SDL_Window*
_App::getWindow() noexcept
{
  return m_window;
}

SDL_Renderer*
_App::getRenderer() noexcept
{
  return m_renderer;
}

const void
_App::getOptions(int& argc, char** argv) noexcept
{
  int opt;
  while ((opt = getopt(argc, argv, "w:h:")) != -1) {
    switch (opt) {
      case 'w':
        m_dimensions.first = std::stoi(optarg);
        break;
      case 'h':
        m_dimensions.second = std::stoi(optarg);
        break;
      default:
        print(stdout, "USAGE : Game -w {Width} -h {Height} \n");
        exit(EXIT_FAILURE);
    }
  }
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
  print(stderr, "Couldnt init SDL : {} \n", SDL_GetError());
  exit(1);
}

inline void
_App::handleEvents() noexcept
{
  switch (m_event.type) {
    case SDL_EVENT_QUIT:
      m_windowShouldOpen = false;
      break;
    default:
      break;
  }
}

inline void
_App::pollEvents() noexcept
{
  SDL_PollEvent(&m_event);
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

inline void
_App::getTicks() noexcept
{
  m_timer = SDL_GetTicks();
}

int
_App::run(int& argc, char** argv) noexcept
{
  getOptions(argc, argv);

  initSDL();
  initWindow(m_dimensions);

  Texture::loadTextures("../assets/");

  _MainChar MainChar{ "char_blue", { 100, 100, 100, 100 }, 0.875 };
  MainCharPtr = &MainChar;
  MainChar.registerAnimation();

  while (m_windowShouldOpen) {
    this->getTicks();
    this->clearWindow();
    this->pollEvents();
    MainChar.handleEvents();
    Animation::playAnimations();
    this->handleEvents();
    this->renderScene();
  }
  return 0;
}

} // pl
