#ifndef ANIMATION_HPP_
#define ANIMATION_HPP_ 69

#include "Texture.hpp"
#include "stl.hpp"
#include <SDL3/SDL.h>

namespace pl {

class Animation : public Texture
{
public:
  Animation(string name, float interval, int duration);
  ~Animation() = default;

  [[nodiscard]] float getInterval() const noexcept;
  void setInterval(float interval) noexcept;

  virtual void animate() = 0;

  static void playAnimations() noexcept;

public:
  inline static vector<Animation*> Animations;

protected:
  float m_interval;
};

}

#endif // ANIMATION_HPP_