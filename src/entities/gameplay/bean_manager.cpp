#include "../gameplay/bean_manager.hpp"
#include <iostream>

void bean_manager::update(const float dt) {
    for (auto& i : beans) {
        i->update(dt);
        if (i->underTiles()) {
            t_mgr->destroy_tile(i->getX());
        }
    }
}

void bean_manager::draw() {
    for (auto& i : beans) {
        i->draw();
    }
}

void bean_manager::constructor(Game* game, tile_manager* t_mgr) {
    this->game = game;
    this->t_mgr = t_mgr;

    beans.emplace_back(new bean());
    beans[0]->constructor(game, 6, 0.3f);

    beans.emplace_back(new bean());
    beans[1]->constructor(game, 14, 0.4f);

    beans.emplace_back(new bean());
    beans[2]->constructor(game, 8, 0.25f);
}
