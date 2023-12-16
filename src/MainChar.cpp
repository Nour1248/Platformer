#include "MainChar.hpp"
#include "Animation.hpp"
#include "Game.hpp"
#include "Texture.hpp"
#include <SDL3/SDL.h>

namespace pl {

_MainChar::_MainChar(string Texturename,
                     SDL_FRect dstRect,
                     float animationInterval)
  : Texture{ Texturename, dstRect }
  , Animation{ animationInterval }
{
}

void
_MainChar::handleEvents() noexcept
{
  switch (App.getEvent().type) {
    case SDL_EVENT_KEY_DOWN:
      switch (App.getEvent().key.keysym.scancode) {
        case SDL_SCANCODE_LEFT:
          this->setCoordinates(m_dstRect.x - 5, m_dstRect.y);
          m_direction = LEFT;
          m_event = WALK;
          break;
        case SDL_SCANCODE_RIGHT:
          this->setCoordinates(m_dstRect.x + 5, m_dstRect.y);
          m_direction = RIGHT;
          m_event = WALK;
          break;
        case SDL_SCANCODE_SPACE:
          // TODO
          break;
        case SDL_SCANCODE_LSHIFT:
          // TODO
          break;

        default:
          break;
      }
      break;
    default:
      m_event = IDLE;
      break;
  }
}

void
_MainChar::animate() noexcept
{
  static uint64_t clock;
  switch (m_event) {
    case IDLE:
      m_srcRect = SrcRects.at(1).toSDL_FRect();
      break;
    case ATTACK:
      break;
    case WALK:
      break;
    case JUMP:
      break;
    case LAND:
      break;
    case DIE:
      break;
    default:
      break;
  }
  this->blitClippedTexture(&m_srcRect);
}

void
_MainChar::registerAnimation() noexcept
{
  Animations.push_back(
    { .classID = _MainChar_, .dstRect = m_dstRect, .duration = -1 });
}

} // pl