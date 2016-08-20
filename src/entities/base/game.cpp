#include <stack>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "game_state.hpp"
#include "game.hpp"
#include "tex_manager.hpp"

void Game::pushState(GameState* state) {
  this->states.push(state);
  return;
}

void Game::popState() {
  delete this->states.top();
  this->states.pop();

  return;
}

void Game::changeState(GameState* state) {
  if (!states.empty())
    popState();

  pushState(state);

  return;
}

GameState* Game::peekState() {
  if (states.empty()) return nullptr;
  return states.top();
}

void Game::gameLoop() {
  sf::Clock clock;
  while (this->window.isOpen()) {
    sf::Time elapsed = clock.restart();
    float dt = elapsed.asSeconds();

    if (peekState() == nullptr) continue;

    peekState()->handleInput();
    peekState()->update(dt);
    this->window.clear(sf::Color::Black);
    peekState()->draw(dt);
    this->window.display();
  }
}

void Game::loadTextures() {
  texmgr.loadTexture("img/backdrop2.png", "bg");
  texmgr.loadTexture("img/pyoro.png", "pyoro");
  texmgr.loadTexture("img/tiles.png", "tiles");
  texmgr.loadTexture("img/seed1.png", "bean1");

  return;
}

Game::Game() {
  this->loadTextures();

  this->window.create(sf::VideoMode(640, 576), "Schnyoro", sf::Style::Default);
  this->window.setFramerateLimit(60);
}

Game::~Game() {
  while(!this->states.empty())
    popState();
}
