#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include <SFML/Graphics.hpp>
#include "../../game_state.hpp"
#include "disco_lights.hpp"

enum class bgState { STATIC, FADING, STROBE };

// BACKGROUND

class background {
private:
  Game* game;

  bgState state = bgState::STATIC;
  unsigned int level;
  unsigned int new_level;

  sf::Clock t_flash;
  unsigned int flash_state;

  // Main Background
  sf::Sprite bg_main;
  sf::IntRect bg_main_rect;

  // Fading in
  sf::Sprite bg_fade;
  sf::Uint8 alpha_fade;
  sf::IntRect bg_fade_rect;

  // DISCO
  disco_manager d_m;

public:
  //background (Game* game);
  void constructor(Game* game);

  void update();
  void draw();
  void increment_level();
};

#endif
