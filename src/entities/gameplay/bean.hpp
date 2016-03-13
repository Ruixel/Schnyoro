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
    float y_pos;
    float speed;

    Animation anim_fall;
public:
    void constructor(Game* game, int x, float speed);

    void update(const float dt);
    void draw();

    bool underTiles();
    int getX();
};

#endif // BEAN_HPP
