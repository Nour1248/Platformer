#include "MainChar.hpp"
#include "Animation.hpp"
#include "Event.hpp"
#include "Game.hpp"
#include <SDL3/SDL.h>

namespace pl {

constinit _MainChar* MainCharPtr{ nullptr };

_MainChar::_MainChar(std::string Texturename,
                     float animationInterval,
                     int speed) noexcept
  : Animation{ Texturename, animationInterval, -1 }
  , Event{ &keyDownCallback, &keyUpCallback, &handleEvents }
  , m_speed{ speed }
{
}

const int
_MainChar::getSpeed() const noexcept
{
  return m_speed;
}

const int
_MainChar::getRangeIdx() const noexcept
{
  if (m_event.DIE)
    return DieIdx;
  if (m_event.LAND)
    return LandIdx;
  if (m_event.JUMP)
    return JumpIdx;
  if (m_event.ATTACK)
    return AttackIdx;
  if (m_event.WALK)
    return WalkIdx;
  if (isIdle())
    return IdleIdx;

  return -69;
}

void
_MainChar::setSpeed(int s) noexcept
{
  m_speed = s;
}

void
_MainChar::keyDownCallback() noexcept
{
  switch (Event::CurrentEvent.key.keysym.scancode) {
    case SDL_SCANCODE_LEFT:
      MainCharPtr->m_event.WALK = true;
      MainCharPtr->m_direction = LEFT;
      break;
    case SDL_SCANCODE_RIGHT:
      MainCharPtr->m_event.WALK = true;
      MainCharPtr->m_direction = RIGHT;
      break;
    case SDL_SCANCODE_SPACE:
      MainCharPtr->m_event.JUMP = true;
      break;
    case SDL_SCANCODE_LSHIFT:
      MainCharPtr->m_event.ATTACK = true;
      break;
    default:
      break;
  }
}

void
_MainChar::keyUpCallback() noexcept
{
  switch (Event::CurrentEvent.key.keysym.scancode) {
    case SDL_SCANCODE_LEFT:
      if (MainCharPtr->m_direction == LEFT)
        MainCharPtr->m_event.WALK = false;
      break;
    case SDL_SCANCODE_RIGHT:
      if (MainCharPtr->m_direction == RIGHT)
        MainCharPtr->m_event.WALK = false;
      break;
    case SDL_SCANCODE_SPACE:
      MainCharPtr->m_event.JUMP = false;
      break;
    case SDL_SCANCODE_LSHIFT:
      MainCharPtr->m_event.ATTACK = false;
      break;
    default:
      break;
  }
}

void
_MainChar::handleEvents() noexcept
{
  if (MainCharPtr->m_event.WALK && MainCharPtr->m_direction == LEFT) {
    MainCharPtr->setCoordinates(MainCharPtr->getCoordinates().first -
                                  MainCharPtr->getSpeed(),
                                MainCharPtr->getCoordinates().second);
  }

  if (MainCharPtr->m_event.WALK && MainCharPtr->m_direction == RIGHT) {
    MainCharPtr->setCoordinates(MainCharPtr->getCoordinates().first +
                                  MainCharPtr->getSpeed(),
                                MainCharPtr->getCoordinates().second);
  }

  if (MainCharPtr->isIdle()) {
    MainCharPtr->m_event.IDLE = true;
  }
}

bool
_MainChar::isIdle() const noexcept
{
  if (!this->m_event.WALK && !this->m_event.ATTACK && !this->m_event.JUMP &&
      !this->m_event.LAND && !this->m_event.DIE)
    return true;
  else
    return false;
}

void
_MainChar::blit() const noexcept
{
  switch (m_direction) {
    case LEFT:
      this->blitFlippedAndClippedTexture(&m_srcRect);
      break;
    case RIGHT:
      this->blitClippedTexture(&m_srcRect);
      break;
  }
}

void
_MainChar::animate() noexcept
{
  static constinit std::pair<BeginIdx, EndIdx> range{ 0, 5 };
  static constinit int idx{ 0 };
  static uint64_t lastFrameRegisteredTime = App.getTicks();

  range = SrcRectsEventRange.at(getRangeIdx());
  m_srcRect = SrcRects[idx];

  if (lastFrameRegisteredTime + m_interval < App.getTicks()) {
    lastFrameRegisteredTime = App.getTicks();
    if (idx < range.first || idx >= range.second) {
      idx = range.first;
    } else [[likely]] {
      idx++;
    }
  }

  this->blit();
}

} // pl
