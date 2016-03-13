#ifndef DISCO_LIGHTS_HPP
#define DISCO_LIGHTS_HPP

#include <SFML/Graphics.hpp>
#include "../../game_state.hpp"
#include <vector>

// DISCO PARTICLE

struct disco_particle {
    sf::Vector2f pos;
    int trail_length;
    disco_particle(int x, int y);
};

class disco_manager {
private:
  std::vector<disco_particle*> trails;
public:
  disco_manager();

  void update();
  void draw(Game* game);
};

#endif
