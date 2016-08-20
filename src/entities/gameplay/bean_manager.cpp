#include "../gameplay/bean_manager.hpp"
#include <iostream>

bool bean_manager::AABBcollision(sf::Vector2i tPos)
{
    // AABB collision check with tongue
    sf::Vector2i tPos_min = sf::Vector2i(tPos.x - 6, tPos.y - 4);
    sf::Vector2i tPos_max = sf::Vector2i(tPos.x - 0, tPos.y + 12);

    for (auto& i : beans)
    {
        sf::Vector2i bPos = i->getPos();

        // AABB-Point
        if  (bPos.x > tPos_min.x && bPos.x < tPos_max.x
          && bPos.y > tPos_min.y && bPos.y < tPos_max.y
          && !i->isEating())
        {
            std::cout << "eat!" << std::endl;
            i->eaten();

            return true;
        }
    }

    return false;
}

void bean_manager::update(const float dt, sf::Vector2i tPos, int tLength) {
    // Update all beans
    for (size_t c = 0; c < beans.size(); c++) {
        std::shared_ptr<bean> i = beans[c];
        if (!i->isEating())
        {
            i->update(dt);
            if (i->underTiles()) {
                t_mgr->destroy_tile(i->getX());
                beans.erase( beans.begin() + c);
            }
        } else {
            if (tLength > 0)
                i->update(dt, tPos);
            else
                beans.erase( beans.begin() + c);
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
