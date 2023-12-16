#ifndef RECT_HPP_
#define RECT_HPP_ 69

#include <SDL3/SDL.h>

namespace pl {
inline namespace ut {

template<typename T>
struct Rect
{
public:
  consteval Rect<T>() = default;

  consteval Rect<T>(T x, T y, T w, T h)
    : x(x)
    , y(y)
    , w(w)
    , h(h)
  {
  }

  constexpr Rect<T>(SDL_FRect sdlRect)
    : x(static_cast<T>(sdlRect.x))
    , y(static_cast<T>(sdlRect.y))
    , w(static_cast<T>(sdlRect.w))
    , h(static_cast<T>(sdlRect.h))
  {
  }

  constexpr Rect<T>(SDL_Rect& sdlRect)
    : x(static_cast<T>(sdlRect.x))
    , y(static_cast<T>(sdlRect.y))
    , w(static_cast<T>(sdlRect.w))
    , h(static_cast<T>(sdlRect.h))
  {
  }

  [[nodiscard]] inline constexpr SDL_Rect toSDL_Rect()
  {
    return { .x = static_cast<int>(this->x),
             .y = static_cast<int>(this->y),
             .w = static_cast<int>(this->w),
             .h = static_cast<int>(this->h) };
  }

  [[nodiscard]] inline constexpr SDL_FRect toSDL_FRect()
  {
    return { .x = static_cast<float>(this->x),
             .y = static_cast<float>(this->y),
             .w = static_cast<float>(this->w),
             .h = static_cast<float>(this->h) };
  }

public:
  T x;
  T y;
  T w;
  T h;
};

}

}

#endif // RECT_HPP_