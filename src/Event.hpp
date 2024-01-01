#ifndef EVENTABLE_Hpp_
#define EVENTABLE_Hpp_

#include "PCH.hpp" // IWYU pragma: export
#include <SDL3/SDL.h>

namespace pl {

class Event
{
public:
  using CallbackSigniture = void();

  Event(std::function<CallbackSigniture> keyDownCallback,
        std::function<CallbackSigniture> keyUpCallback,
        std::function<CallbackSigniture> handleEventsCallback) noexcept;
  ~Event() = default;

public:
  constinit inline static SDL_Event CurrentEvent;
  inline static std::vector<std::function<CallbackSigniture>> KeyDownCallbacks;
  inline static std::vector<std::function<CallbackSigniture>> KeyUpCallbacks;
  inline static std::vector<std::function<CallbackSigniture>>
    HandleEventCallbacks;

  static void pollEvents() noexcept;
  static void handleEvents() noexcept;
};

}

#endif // EVENTABLE_Hpp_
