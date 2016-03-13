#ifndef BEAN_MANAGER_HPP
#define BEAN_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include "bean.hpp"
#include "../gameplay/tile_manager.hpp"
#include "../../game.hpp"
#include <vector>
#include <memory>

class bean_manager {
private:
    Game* game;
    tile_manager* t_mgr;

    std::vector<std::shared_ptr<bean>> beans;
public:
    void constructor(Game* game, tile_manager* t_mgr);

    void update(const float dt);
    void draw();
};

#endif // BEAN_MANAGER_HPP
