#include "game.hpp"
#include "s_gameplay.hpp"

int main(int argc, char const *argv[]) {
  Game game;

  game.pushState(new sGameplay(&game));
  game.gameLoop();
  return 0;
}
