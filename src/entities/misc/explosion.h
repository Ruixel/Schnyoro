#ifndef EXPLOSION_H_INCLUDED
#define EXPLOSION_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "../../game.hpp"
#include "../base/AnimatedSprite.hpp"
#include "../base/Animation.hpp"

class Explosion {
private:
    Game* game;

    AnimatedSprite exp_sprite;
    Animation exp_anim;

public:
};

#endif // EXPLOSION_H_INCLUDED
