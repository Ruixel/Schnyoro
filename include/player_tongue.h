#ifndef PLAYER_TONGUE_H
#define PLAYER_TONGUE_H

#include <SFML/Graphics.hpp>
#include "../src/game.hpp"

class player_tongue
{
private:
    sf::Sprite tongueEnd;
    //sf::Texture tongue_texture;

    int tongue_length;
    float start_x;
    int start_y;
public:
    player_tongue(int x, int y);

    void draw(Game* game);
    void update(const float dt);
};


#endif // PLAYER_TONGUE_H
