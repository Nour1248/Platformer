#ifndef EVENTABLE_Hpp_
#define EVENTABLE_Hpp_

#include "stl.hpp"
#include <SDL3/SDL.h> 

namespace pl {

class Event
{
public:
  using CallbackSigniture = void();

  Event(function<CallbackSigniture> keyDownCallback,
        function<CallbackSigniture> keyUpCallback,
        function<CallbackSigniture> handleEventsCallback) noexcept;
  ~Event() = default;

  // virtual void handleEvents() noexcept = 0;

public:
  constinit inline static SDL_Event CurrentEvent;
  inline static vector<function<CallbackSigniture>> KeyDownCallbacks;
  inline static vector<function<CallbackSigniture>> KeyUpCallbacks;
  inline static vector<function<CallbackSigniture>> HandleEventsCallbacks;

  static void pollEvents() noexcept;
  static void handleEvents() noexcept;
};

}

#endif // EVENTABLE_Hpp_
