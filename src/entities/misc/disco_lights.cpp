#include <SFML/Graphics.hpp>
#include "disco_lights.hpp"

#include <stdlib.h>

void disco_manager::update() {
  // move upwards
  for (auto& t : trails) {
    t->pos += sf::Vector2f(0, -5);

    // check if particle is at the top
    if (t->pos.y < -30) {
      // 1 in 4 chance they'll "respawn"
      int r_chance = rand() % 4 + 1;
      if (r_chance == 1) {
        t->pos = sf::Vector2f(t->pos.x, 150);
      }
    }
  }
}

void disco_manager::draw(Game* game) {
  for (auto& t : trails) {
    for (int i = 0; i < 6; i++){
      sf::RectangleShape point(sf::Vector2f(1, 1));
      sf::Vector2f point_pos(t->pos.x, t->pos.y + (i * 5));
      point.setFillColor(sf::Color(255, 255, 255, 255 - (i*42)));
      point.setPosition(point_pos);

      game->window.draw(point);
    }
  }
}

// constructor
disco_particle::disco_particle(int x, int y) {
  this->pos = sf::Vector2f(x, y);
  trail_length = 1;
}

// manager constructor
disco_manager::disco_manager() {
  for (int i = 0; i < 16; i++) {
    // generate number between 0 and 20
    int y = rand() % 250 + 100;
    this->trails.push_back(new disco_particle((i * 10) + 4, 344 + y));
  }
}
