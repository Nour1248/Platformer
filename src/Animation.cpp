#include "Animation.hpp"
#include "Game.hpp"

namespace pl {

Animation::Animation(float interval)
  : m_interval{ interval }
{
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
  for (const auto& a : Animations) {
    switch (a.classID) {
      case _MainChar_:
        MainCharPtr->animate();
        break;
    }
  }
}

}