#include "Event.hpp"
#include "Game.hpp"
#include "PCH.hpp"
#include "SDL3/SDL.h" // IWYU pragma: export

namespace pl {

Event::Event(std::function<CallbackSigniture> keyDownCallback,
             std::function<CallbackSigniture> keyUpCallback,
             std::function<CallbackSigniture> handleEventsFunc) noexcept
{
  if (keyDownCallback != nullptr)
    KeyDownCallbacks.push_back(keyDownCallback);
  if (keyUpCallback != nullptr)
    KeyUpCallbacks.push_back(keyUpCallback);
  if (handleEventsFunc != nullptr)
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
