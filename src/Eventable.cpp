#include "Eventable.hpp"
#include "Game.hpp"
#include "SDL3/SDL.h" // IWYU pragma: export
#include "stl.hpp"

namespace pl {

Event::Event(function<CallbackSigniture> keyDownCallback,
             function<CallbackSigniture> keyUpCallback,
             function<CallbackSigniture> handleEventsFunc) noexcept
{
  KeyDownCallbacks.push_back(keyDownCallback);
  KeyUpCallbacks.push_back(keyUpCallback);
  HandleEventCallbacks.push_back(handleEventsFunc);
}

void
Event::pollEvents() noexcept
{
  while (SDL_PollEvent(&CurrentEvent)) {
    switch (CurrentEvent.type) {
      case SDL_EVENT_QUIT:
        App.setWindowState(false);
        break;

      case SDL_EVENT_KEY_DOWN:
        for (const auto& f : KeyDownCallbacks)
          f();
        break;

      case SDL_EVENT_KEY_UP:
        for (const auto& f : KeyUpCallbacks)
          f();
        break;

      default:
        break;
    }
  }
}

void
Event::handleEvents() noexcept
{
  for (const auto& f : HandleEventCallbacks)
    f();
}

}
