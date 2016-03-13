#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "tongue.hpp"
#include "../gameplay/tile_manager.hpp"
#include "../../game_state.hpp"
#include "../base/AnimatedSprite.hpp"

enum class pyState { NORMAL, EATING, CHEWING, DYING };

class player {
private:
  Game* game;
  pyState state;

  // Base
  sf::Texture* sprite;
  AnimatedSprite pyoro;
  tongue* Tongue;

  // Variables
  int x, y;
  float velocity_x, acceleration_x;
  bool leftKeyDown, rightKeyDown;
  bool facingRight;

  // Animations
  Animation Idle;
  Animation Walking;
  Animation StartEating;
  Animation* currentAnimation;

  void swallowTongue();
  void flipPlayer(bool faceRight);
public:
  void constructor(Game* game);

  void startMovingLeft();
  void startMovingRight();
  void stopMovingLeft();
  void stopMovingRight();
  void beginEating();
  void stopEating();

  void retractTongue();
  void die();

  void moveRight();
  void moveLeft();
  void stopMoving(bool bothKeysPressed);

  void update(const float dt, tile_manager& tm);
  void draw();
};


#endif
