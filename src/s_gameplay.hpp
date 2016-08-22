#ifndef S_GAMEPLAY_HPP
#define S_GAMEPLAY_HPP

#include <SFML/Graphics.hpp>

#include "entities/player/player.hpp"
#include "entities/misc/background.hpp"
#include "entities/gameplay/tile_manager.hpp"
#include "entities/gameplay/bean_manager.hpp"
#include "entities/misc/effect_manager.h"
#include "game_state.hpp"

class sGameplay : public GameState {
private:
  sf::View view;
  background obj_bg;
  player obj_plr;
  tile_manager obj_tilemgr;

  bean_manager obj_beanmgr;
  EffectManager obj_fxmgr;
public:

  virtual void draw(const float dt);
  virtual void update(const float dt);
  virtual void handleInput();

  sGameplay(Game* game);

};

#endif
