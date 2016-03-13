#include "../include/player_tongue.h"
#include <iostream>

int elength = -20;

void player_tongue::update(const float dt) {
    elength+=2;
}

void player_tongue::draw(Game* game) {
    if (elength < 0)
        return;

    std::cout << this->start_x << std::endl;
    for (int i = 0; i < elength; i++) {
        // Draw Tongue
        sf::Sprite tongue_bit;
        tongue_bit.setTexture(game->texmgr.getRef("pyoro"));
        tongue_bit.setTextureRect(sf::IntRect(0, 96, 1, 3));
        tongue_bit.setPosition(48+i, 122-i);
        game->window.draw(tongue_bit);
        /*sf::RectangleShape point(sf::Vector2f(1, 1));
        sf::Vector2f point_pos(start_x+i, 65+i);
        point.setPosition(point_pos);

        game->window.draw(point);*/
    }

    sf::Sprite tongueEnd2;
    tongueEnd2.setTexture(game->texmgr.getRef("pyoro"));
    tongueEnd2.setTextureRect(sf::IntRect(11, 96, -10, 10));
    tongueEnd2.setPosition(48+elength  -1, 122-elength  -7);
    game->window.draw(tongueEnd2);
}

player_tongue::player_tongue(int x, int y)   {
    this->tongue_length = 5;
    this->start_x = 50.0f;
    this->start_y = 50;
    std::cout << start_x << std::endl;
    //tongue_texture = game->texmgr.getRef("pyoro");
}
