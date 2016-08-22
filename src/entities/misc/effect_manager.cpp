#include "effect_manager.h"

void EffectManager::constructor(Game* game)
{
    this->game = game;
}

void EffectManager::update(const float dt)
{
    for (auto& i : fx)
    {
        i->fx_update(dt);
    }
}

void EffectManager::draw(Game* game)
{
    for (auto& i : fx)
    {
        i->fx_draw(game);
    }
}

void EffectManager::createExplosion(int x_quadrant)
{
    //Explosion exp = Explosion();
    //exp.fx_setup(sf::Vector2i(x_quadrant * 8, 70), game->texmgr.getRef("explosion"), 0.5);

    //fx.push_back(std::make_unique<Explosion>(exp));
}
