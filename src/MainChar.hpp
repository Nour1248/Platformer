#include "SDL3/SDL_rect.h"
#ifndef MAINCHAR_HPP_
#define MAINCHAR_HPP_ 69

#include "Animation.hpp"
#include "Rect.hpp"
#include "Texture.hpp"
#include "stl.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_image.h>

#define MainCharSpriteCount 48

namespace pl {

// after a big fight with the compiler i couldnt do anything else , auctully i
// can but i wont
static consteval array<Rect<int>, MainCharSpriteCount>
initSrcRects() noexcept
{
  array<Rect<int>, MainCharSpriteCount> _ = { {
    { 18, 24, 22, 32 },   { 74, 24, 22, 32 },   { 130, 24, 22, 32 },
    { 186, 25, 22, 31 },  { 242, 25, 22, 31 },  { 298, 25, 22, 31 },
    { 11, 80, 28, 32 },   { 64, 78, 28, 34 },   { 123, 80, 29, 32 },
    { 179, 80, 43, 32 },  { 243, 81, 23, 31 },  { 299, 81, 18, 31 },
    { 16, 136, 25, 32 },  { 74, 136, 21, 32 },  { 131, 135, 17, 33 },
    { 184, 135, 23, 30 }, { 241, 136, 22, 32 }, { 299, 136, 18, 32 },
    { 354, 135, 22, 33 }, { 408, 135, 25, 30 }, { 16, 195, 20, 29 },
    { 75, 190, 18, 34 },  { 128, 187, 23, 34 }, { 184, 187, 23, 34 },
    { 240, 187, 23, 34 }, { 296, 187, 23, 34 }, { 346, 185, 29, 31 },
    { 402, 185, 29, 28 }, { 12, 241, 26, 30 },  { 72, 242, 25, 35 },
    { 128, 242, 25, 35 }, { 184, 242, 25, 35 }, { 240, 243, 25, 34 },
    { 296, 245, 24, 35 }, { 354, 253, 18, 27 }, { 410, 250, 19, 30 },
    { 17, 304, 22, 32 },  { 73, 305, 24, 31 },  { 129, 306, 28, 30 },
    { 182, 305, 31, 29 }, { 234, 304, 35, 30 }, { 289, 306, 35, 28 },
    { 344, 308, 36, 28 }, { 394, 321, 43, 15 }, { 2, 380, 44, 12 },
    { 58, 378, 45, 14 },  { 114, 379, 45, 13 }, { 170, 381, 45, 11 },
  } };
  return _;
}

enum MainCharEvent
{
  IDLE,
  ATTACK,
  WALK,
  JUMP,
  LAND,
  DIE,
  EVENTCOUNT
};

using BeginIdx = int;
using EndIdx = int;
static consteval array<pair<BeginIdx, EndIdx>, EVENTCOUNT>
initSrcRectsEventRange() noexcept
{
  array<pair<BeginIdx, EndIdx>, EVENTCOUNT> _ = {
    { { 0, 5 }, { 6, 11 }, { 12, 19 }, { 20, 27 }, { 28, 35 }, { 36, 47 } }
  };
  return _;
}

class _MainChar final
  : public Texture
  , public Animation
{
public:
  _MainChar(string Texturename, SDL_FRect dstRect, float animationInterval);
  _MainChar(_MainChar const&) = delete;
  _MainChar& operator=(_MainChar const&) = delete;
  ~_MainChar() noexcept = default;

  [[nodiscard]] int getSpeed() noexcept;
  void setSpeed(int s) noexcept;

  void handleEvents() noexcept;
  void animate() noexcept;
  void registerAnimation() noexcept;

public:
  constinit inline static array<Rect<int>, MainCharSpriteCount> SrcRects =
    initSrcRects();
  constinit inline static array<pair<BeginIdx, EndIdx>, EVENTCOUNT>
    SrcRectsEventRange = initSrcRectsEventRange();

private:
  MainCharEvent m_event;
  SDL_FRect m_srcRect;
  int m_speed; // in pixels per frame
};

} // pl
#endif // MAINCHAR_HPP_