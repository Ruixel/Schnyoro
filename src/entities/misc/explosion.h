#ifndef EXPLOSION_H_INCLUDED
#define EXPLOSION_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "../../game.hpp"
#include "../base/AnimatedSprite.hpp"
#include "../base/Animation.hpp"
#include "effect.h"

class Explosion: public Effect {
private:
    AnimatedSprite fx_sprite;
    Animation fx_anim;

    sf::Clock timer;
    float timeToExpire;

public:
    void fx_setup(sf::Vector2i pos, const sf::Texture& tex, float speed);
    void fx_update(const float dt);
    void fx_draw(Game* game);
};

#endif // EXPLOSION_H_INCLUDED
