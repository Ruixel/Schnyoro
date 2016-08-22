#include "Explosion.h"

void Explosion::fx_setup(sf::Vector2i pos, const sf::Texture& tex, float timeAlive)
{
    fx_anim.setSpriteSheet(tex);
    fx_anim.addFrame(sf::IntRect(0, 0, 16, 16));
    fx_anim.addFrame(sf::IntRect(16, 0, 16, 16));
    fx_anim.addFrame(sf::IntRect(32, 0, 16, 16));

    fx_sprite.setAnimation(fx_anim);
    fx_sprite.setFrameTime(sf::seconds(timeAlive/3));
    //fx_sprite.setLooped(false);

    timeToExpire = timeAlive;
}

void Explosion::fx_update(const float dt)
{
    fx_sprite.update(sf::seconds(dt));
}

void Explosion::fx_draw(Game* game)
{
    game->window.draw(fx_sprite);
}
