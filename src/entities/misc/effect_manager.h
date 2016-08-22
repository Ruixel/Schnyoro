#ifndef EFFECT_MANAGER_H_INCLUDED
#define EFFECT_MANAGER_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>
#include "../../game.hpp"
#include "../base/AnimatedSprite.hpp"
#include "../base/Animation.hpp"
#include "effect.h"
#include "explosion.h"
#include <memory>

class EffectManager {
private:
    Game* game;
    std::vector<std::unique_ptr<Effect>> fx;

public:
    void constructor(Game* game);

    void update(const float dt);
    void draw(Game* game);

    void createExplosion(int x_quadrant);
};

#endif // EFFECT_MANAGER_H_INCLUDED
