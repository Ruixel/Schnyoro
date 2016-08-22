#ifndef EFFECT_H_INCLUDED
#define EFFECT_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "../../game.hpp"

class Effect {
public:
    virtual void fx_setup(sf::Vector2i pos, const sf::Texture& tex, float speed) = 0;
    virtual void fx_update(const float dt) = 0;
    virtual void fx_draw(Game* game) = 0;
};

#endif // EFFECT_H_INCLUDED
