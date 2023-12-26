#include "MainChar.hpp"
#include "Animation.hpp"
#include "Eventable.hpp"
#include "SDL3/SDL_scancode.h"
#include <SDL3/SDL.h>

namespace pl {

constinit _MainChar* MainCharPtr{ nullptr };

_MainChar::_MainChar(string Texturename,
                     float animationInterval,
                     int speed) noexcept
  : Animation{ Texturename, animationInterval, -1 }
  , Event{ &keyDownCallback, &keyUpCallback, &handleEvents }
  , m_speed{ speed }
{
}

int
_MainChar::getSpeed() const noexcept
{
  return m_speed;
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
      MainCharPtr->WALK = true;
      MainCharPtr->m_direction = LEFT;
      break;
    case SDL_SCANCODE_RIGHT:
      MainCharPtr->WALK = true;
      MainCharPtr->m_direction = RIGHT;
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
        MainCharPtr->WALK = false;
      break;
    case SDL_SCANCODE_RIGHT:
      if (MainCharPtr->m_direction == RIGHT)
        MainCharPtr->WALK = false;
      break;
    default:
      break;
  }
}

void
_MainChar::handleEvents() noexcept
{
  if (MainCharPtr->WALK && MainCharPtr->m_direction == LEFT) {
    MainCharPtr->setCoordinates(MainCharPtr->getCoordinates().first -
                                  MainCharPtr->getSpeed(),
                                MainCharPtr->getCoordinates().second);
  }

  if (MainCharPtr->WALK && MainCharPtr->m_direction == RIGHT) {
    MainCharPtr->setCoordinates(MainCharPtr->getCoordinates().first +
                                  MainCharPtr->getSpeed(),
                                MainCharPtr->getCoordinates().second);
  }

  if (MainCharPtr->isIdle()) {
    MainCharPtr->IDLE = true;
  }
}

FORCE_INLINE_
bool
_MainChar::isIdle() const noexcept
{
  if (!this->WALK && !this->ATTACK && !this->JUMP && !this->LAND && !this->DIE)
    return true;
  else
    return false;
}

FORCE_INLINE_
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
  static constinit int idx{ 0 };
  m_srcRect = SrcRects[idx];

  this->blit();
}

} // pl
