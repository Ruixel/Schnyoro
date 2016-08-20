#include "tongue.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

void tongue::update(const float dt) {
    if (state == tgState::EXPAND)
        length+=2;

    if (state == tgState::RETRACT) {
        length-=10;
    }

    // Collision //
    sf::Vector2i tongue_pos = this->getPos();

    if (tongue_pos.x > 164 || tongue_pos.y < 0 || tongue_pos.x < -4)
        state = tgState::RETRACT;
}

void tongue::draw() {
    if (length < 0)
        return;

    for (int i = 0; i < length; i++) {
        // Draw Tongue
        sf::Sprite tongue_bit;
        tongue_bit.setTexture(tongue_texture);
        tongue_bit.setTextureRect(sf::IntRect(0, 96, 1, 3));
        if (faceRight)
            tongue_bit.setPosition((start_x + 16) + i, (start_y + 2) - i);
        else
            tongue_bit.setPosition((start_x - 1) - i, (start_y + 2) - i);
        game->window.draw(tongue_bit);
    }

    sf::Sprite tongueEnd2;
    tongueEnd2.setTexture(tongue_texture);
    tongueEnd2.setTextureRect(sf::IntRect(11, 96, -10, 10));
    if (faceRight) {
        tongueEnd2.setScale(1, 1);
        tongueEnd2.setPosition(start_x+length + 15, start_y-length  - 5);
    } else {
        tongueEnd2.setScale(-1, 1);
        tongueEnd2.setPosition(start_x-length + 1, start_y-length  - 5);
    }
    game->window.draw(tongueEnd2);

    return;
}

void tongue::constructor(Game* game, int x, int y, bool faceRight) {
    this->game = game;
    this->tongue_texture = game->texmgr.getRef("pyoro");
    this->faceRight = faceRight;
    this->state = tgState::EXPAND;
    this->length = -20;
    this->start_x = x;
    this->start_y = y;
    std::cout << start_x << std::endl;
}

void tongue::retract() {
    if (state == tgState::EXPAND)
        state = tgState::RETRACT;
}

bool tongue::canSwallow() {
    return (length < -12 && state == tgState::RETRACT) ? true : false;
}

bool tongue::canEat() {
    return (length > 0 && state != tgState::RETRACT) ? true : false;
}

int tongue::getLength() {
    return length;
}

sf::Vector2i tongue::getPos()
{
    sf::Vector2i tongue_pos(0, 0);
    if (faceRight)
        tongue_pos = sf::Vector2i(start_x+length + 25, start_y-length  - 5);
    else
        tongue_pos = sf::Vector2i(start_x-length - 8, start_y-length  - 5);

    return tongue_pos;
}
