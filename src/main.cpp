#include <Game.hpp>
#include <SDL3/SDL.h>

int
main(int argc, char** argv)
{
  pl::App game{ std::pair<int32_t, int32_t>(600, 600), "Ice Tower" };
  return game.mainLoop();
}