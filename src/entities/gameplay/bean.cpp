#include "bean.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

void bean::update(const float dt) {
    y_pos += 50 * speed * (dt);

    bean_sprite.update(sf::seconds(dt));
}

void bean::draw() {
    bean_sprite.setPosition(x_quadrant * 8 - 4, y_pos);
    game->window.draw(bean_sprite);
}

void bean::constructor(Game* game, int x, float speed) {
    this->game = game;
    this->speed = speed;
    this->y_pos = -18;
    this->x_quadrant = x;

    anim_fall.setSpriteSheet(game->texmgr.getRef("bean1"));
    anim_fall.addFrame(sf::IntRect(0, 0, 16, 16));
    anim_fall.addFrame(sf::IntRect(16, 0, 16, 16));
    anim_fall.addFrame(sf::IntRect(32, 0, 16, 16));
    anim_fall.addFrame(sf::IntRect(16, 0, 16, 16));
    bean_sprite.setAnimation(anim_fall);
    bean_sprite.setFrameTime(sf::seconds(speed));
}

bool bean::underTiles() { //y_pos > 136.0f) ? true : false; }
    if (y_pos > 120) {
        return true;
    }
    return false;
}

int bean::getX() { return x_quadrant; }
