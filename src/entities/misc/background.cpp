#include <SFML/Graphics.hpp>
#include "background.hpp"
#include <iostream>

void background::update() {
  // fade in new level?
  if (new_level != level && state != bgState::FADING) {
    // if it's the last level
    if (new_level >= 13) {
      new_level = 13; level = 13;
      state = bgState::STROBE;
      t_flash.restart();
      return;
    }

    level = new_level;
    alpha_fade = 0;
    state = bgState::FADING;

    // set new rects
    bg_fade_rect = sf::IntRect(0, 144*(level-1), 160, 144);
    bg_fade.setTextureRect(bg_fade_rect);
  }

  // process of fading in
  if (state == bgState::FADING) {
    alpha_fade += 5;

    // finished fading?
    if (alpha_fade > 254) {
      state = bgState::STATIC;
      alpha_fade = 0;

      // set the main rect
      bg_main_rect = sf::IntRect(0, 144*(level-1), 160, 144);
      bg_main.setTextureRect(bg_main_rect);
    }
  }

  // background rave WOOO
  if (state == bgState::STROBE) {
    sf::Time t_elapsed = t_flash.getElapsedTime();
    // std::cout << t_elapsed.asSeconds() << std::endl;

    if (t_elapsed.asSeconds() >= 0.5f) {
      flash_state++;
      if (flash_state == 6) flash_state = 0;

      bg_main_rect = sf::IntRect(0, 144*(12+flash_state), 160, 144);
      bg_main.setTextureRect(bg_main_rect);

      bg_fade_rect = sf::IntRect(0, 144*(18), 160, 144);
      bg_fade.setTextureRect(bg_fade_rect);
      alpha_fade = 255;

      t_flash.restart();
    }

    // update trail
    d_m.update();
  }
}

void background::draw() {
  this->game->window.draw(bg_main);

  if (state == bgState::STROBE)
    d_m.draw(this->game);

  // set the fade
  bg_fade.setColor(sf::Color(255, 255, 255, alpha_fade));
  this->game->window.draw(bg_fade);


}

void background::increment_level() {
  new_level++;
  std::cout << "level: " << new_level << std::endl;
}

void background::constructor(Game* game) {
  this->game = game;
  new_level = 1;

  // init
  bg_main.setTexture(game->texmgr.getRef("bg"));
  bg_fade.setTexture(game->texmgr.getRef("bg"));

  // set up the int rects
  bg_main_rect = sf::IntRect(0, 144*0, 160, 144);
  bg_fade_rect = sf::IntRect(0, 144*0, 160, 144);

  bg_main.setTextureRect(bg_main_rect);
  bg_fade.setTextureRect(bg_fade_rect);
}
