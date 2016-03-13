#ifndef TILE_MANAGER_HPP
#define TILE_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "../../game.hpp"

class tile_manager {
private:
    Game* game;

    sf::Sprite tile_sprite;
    sf::Sprite tile_fade;
    int fade;

    std::vector<bool> tiles;
    sf::IntRect rect;
public:
    void constructor(Game* game);

    void update();
    void draw();

    void increment_level();
    bool safeToWalkOn(int x);

    void destroy_tile(int tile);
};

#endif // TILE_MANAGER_HPP
