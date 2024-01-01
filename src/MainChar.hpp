#ifndef MAINCHAR_HPP_
#define MAINCHAR_HPP_ 69

#include "Animation.hpp"
#include "Event.hpp"
#include "PCH.hpp" // IWYU pragma: export
#include <SDL3/SDL.h>
#include <SDL3/SDL_image.h>

#define MainCharSpriteCount 48
#define MainCharEventCount 6

namespace pl {

class _MainChar final
  : public Animation
  , public Event
{
public:
  _MainChar(std::string Texturename,
            float animationInterval,
            int speed) noexcept;
  _MainChar(_MainChar const&) = delete;
  _MainChar& operator=(_MainChar const&) = delete;
  ~_MainChar() noexcept = default;

  [[nodiscard]] const int getSpeed() const noexcept;
  [[nodiscard]] const int getRangeIdx() const noexcept;

  void setSpeed(int s) noexcept;

  static void keyDownCallback() noexcept;
  static void keyUpCallback() noexcept;
  static void handleEvents() noexcept;

  bool isIdle() const noexcept;
  void blit() const noexcept;
  void animate() noexcept;

  void jump() noexcept;
  void attack() noexcept;

  struct M_Event
  {
    bool IDLE = false;
    bool ATTACK = false;
    bool WALK = false;
    bool JUMP = false;
    bool LAND = false;
    bool DIE = false;
  };

  enum Direction
  {
    LEFT,
    RIGHT
  };

private:
  SDL_FRect m_srcRect;
  Direction m_direction = RIGHT;
  M_Event m_event;
  int m_speed; // in pixels / frame

public:
  static constinit inline std::array<SDL_FRect, MainCharSpriteCount>
    SrcRects = { {
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

  using BeginIdx = int;
  using EndIdx = int;
  static constinit inline std::array<std::pair<BeginIdx, EndIdx>,
                                     MainCharEventCount>
    SrcRectsEventRange = {
      // idle ,attack ,walk ,jump ,land ,die
      { { 0, 5 }, { 6, 11 }, { 12, 19 }, { 20, 27 }, { 28, 35 }, { 36, 47 } }
    };
};
#define IdleIdx 0
#define AttackIdx 1
#define WalkIdx 2
#define JumpIdx 3
#define LandIdx 4
#define DieIdx 5

extern constinit _MainChar* MainCharPtr;

} // pl
#endif // MAINCHAR_HPP_
