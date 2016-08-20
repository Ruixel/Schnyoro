#include "bean.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

void bean::update(const float dt) {
    y_pos += 50 * speed * (dt);

    bean_sprite.update(sf::seconds(dt));
}

void bean::update(const float dt, sf::Vector2i tPos) {
    y_pos = tPos.y - 8;
    x_pos = tPos.x - 8;

    bean_sprite.update(sf::seconds(dt));
}

void bean::draw() {
    bean_sprite.setPosition(x_pos, y_pos);
    game->window.draw(bean_sprite);
}

void bean::constructor(Game* game, int x, float speed) {
    this->game = game;
    this->speed = speed;
    this->x_quadrant = x;
    this->beingEaten = false;
    this->x_pos = x_quadrant * 8 - 4; this->y_pos = -18;

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

void bean::eaten() { beingEaten = true; }
bool bean::isEating() { return beingEaten; }

int bean::getX() { return x_quadrant; }

sf::Vector2i bean::getPos()
{
    return sf::Vector2i( getX() * 8 - 2, y_pos + 12);
}
