#include "tile_manager.hpp"
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

void tile_manager::draw() {
    tile_sprite.setTextureRect(rect);
    tile_fade.setTextureRect(sf::IntRect(rect.left - 8, 0, 8, 8));

    for (int i = 0; i < 20; i++) {
        if (tiles[i]){

            tile_sprite.setPosition(i*8, 144-8);
            game->window.draw(tile_sprite);
            if (fade > 0) {
                tile_fade.setColor(sf::Color(255, 255, 255, fade));
                tile_fade.setPosition(i*8, 144-8);
                game->window.draw(tile_fade);
            }
        }
    }
}

void tile_manager::update() {
    if (fade > 0)
        fade -= 5;
    else
        fade = 0;
}

void tile_manager::increment_level() {
    fade = 255;
    rect = sf::IntRect(rect.left+8, 0, 8, 8);
}

void tile_manager::constructor(Game* game) {
    this->game = game;
    this->tile_sprite.setTexture(game->texmgr.getRef("tiles"));
    this->tile_fade.setTexture(game->texmgr.getRef("tiles"));
    this->fade = 0;
    this->rect = sf::IntRect(0, 0, 8, 8);
    // create tiles
    for (int i = 0; i < 20; i++) {
        tiles.push_back(true);
    }

    tiles[12] = false;
    tiles[1] = false;
}

bool tile_manager::safeToWalkOn(int x) {
    if (x < 0)
        return false;

    return !tiles[floor(x / 8)] ? true : false;
}

void tile_manager::destroy_tile(int tile) { tiles[tile] = false; }
