#include "Animation.hpp"
#include "Texture.hpp"

namespace pl {

Animation::Animation(std::string name, float interval, int duration)
  : Texture{ name }
  , m_interval{ interval }
{
  Animations.push_back(this);
}

float
Animation::getInterval() const noexcept
{
  return m_interval;
}

void
Animation::setInterval(float interval) noexcept
{
  m_interval = interval;
}

void
Animation::playAnimations() noexcept
{
  for (auto& a : Animations)
    a->animate();
}

}
