#ifndef ANIMATION_HPP_
#define ANIMATION_HPP_ 69

#include "stl.hpp"
#include <SDL3/SDL.h>

namespace pl {

class Animation
{
public:
  Animation(float interval);
  ~Animation() = default;

  [[nodiscard]] float getInterval() const noexcept;
  void setInterval(float interval) noexcept;

  // struct AnimationEntry;
  // virtual void animate(const AnimationEntry&) = 0;
  // virtual void handleEvents() = 0;

  static void playAnimations() noexcept;

public:
  enum Classes //... that inherit from this class
  {
    _MainChar_
  };
  enum Direction
  {
    RIGHT,
    LEFT
  };
  struct AnimationEntry
  {
    Classes classID;
    SDL_FRect& dstRect;
    int duration; // -1 if infinite
  };
  inline static list<AnimationEntry> Animations;

protected:
  float m_interval;
  Direction m_direction;
};

}

#endif // ANIMATION_HPP_