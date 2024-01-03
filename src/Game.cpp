#include "Game.hpp"
#include "Animation.hpp"
#include "Event.hpp"
#include "MainChar.hpp"
#include "PCH.hpp"
#include "Texture.hpp"
#include "global.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_image.h>
#include <unistd.h>

namespace pl {

_App App;

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

SDL_Window*
_App::getWindow() const noexcept
{
  return m_window;
}

SDL_Renderer*
_App::getRenderer() const noexcept
{
  return m_renderer;
}

const std::atomic_uint64_t&
_App::getTicks() const noexcept
{
  return m_timer;
}

void
_App::setWindowState(bool shouldOpen) noexcept
{
  m_windowShouldOpen = shouldOpen;
}

void
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
        print("USAGE : Game -w {Width} -h {Height} \n");
        exit(EXIT_FAILURE);
    }
  }
}

void
_App::initSDL() noexcept
{
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_EVENTS) != 0 ||
      IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
    goto ERROR;
  }
  return;
ERROR:
  print("Couldnt init SDL : {} \n", SDL_GetError());
  exit(1);
}

void
_App::initWindow(std::pair<int, int> dimensions) noexcept
{
  m_window = SDL_CreateWindow(m_name.c_str(),
                              m_dimensions.first,
                              m_dimensions.second,
                              SDL_WINDOW_RESIZABLE);

  SDL_SetWindowIcon(m_window, m_icon);
  if (!m_window) {
    print("Error initializing the window : {} \n", SDL_GetError());
    exit(1);
  }
}

void
_App::initRenderer(const char* apiName, bool vSync) noexcept
{
  m_renderer = SDL_CreateRenderer(m_window, apiName, SDL_RENDERER_ACCELERATED);
  SDL_SetRenderVSync(m_renderer, vSync);
  if (!m_renderer) {
    print("Error initializing the renderer : {} \n", SDL_GetError());
    exit(1);
  }
}

int
_App::run(int& argc, char** argv) noexcept
{
  this->getOptions(argc, argv);

  this->initSDL();
  this->initWindow(m_dimensions);
  this->initRenderer(nullptr, true);

  Texture::loadTextures("../assets/");

  _MainChar MainChar{ "char_blue", 100.0f, 5 };
  MainChar.setCoordinates(300, 300);
  MainChar.setDimensions(50, 50);
  MainCharPtr = &MainChar;

  while (m_windowShouldOpen) {
    this->updateTicks();
    this->clearWindow();
    Event::pollEvents();
    Event::handleEvents();
    Animation::playAnimations();
    this->renderScene();
  }
  return 0;
}

} // pl
