#ifndef GAME_HPP
#define GAME_HPP

#include <stack>
#include <SFML/Graphics.hpp>

#include "tex_manager.hpp"

class GameState;

class Game {
private:
  void loadTextures();

public:
  std::stack<GameState*> states;

  sf::RenderWindow window;
  TextureManager texmgr;

  void pushState(GameState* state);
  void popState();
  void changeState(GameState* state);
  GameState* peekState();

  void gameLoop();


  Game();
  ~Game();

};

#endif
