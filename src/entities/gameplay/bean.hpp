#ifndef BEAN_HPP
#define BEAN_HPP

#include <SFML/Graphics.hpp>
#include "../../game.hpp"
#include "../base/AnimatedSprite.hpp"
#include "../base/Animation.hpp"

class bean {
private:
    Game* game;
    AnimatedSprite bean_sprite;

    int x_quadrant;
    float x_pos, y_pos;
    float speed;
    bool beingEaten;

    Animation anim_fall;
public:
    void constructor(Game* game, int x, float speed);

    void update(const float dt);
    void update(const float dt, sf::Vector2i tPos);
    void draw();

    bool underTiles();
    void eaten();
    bool isEating();
    int getX();
    sf::Vector2i getPos();
};

#endif // BEAN_HPP
