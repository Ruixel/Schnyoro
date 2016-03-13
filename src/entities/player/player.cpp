#include "player.hpp"
#include "tongue.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <algorithm>

namespace  {
  const float SlowdownFactor = 0.7f;
  const float WalkingAcceleration = 0.0012f / 2;
  const float MaxSpeed = 0.325f / 4;
} /* */

// Movement Functions
void player::moveLeft() {
  flipPlayer(false);

  acceleration_x = -WalkingAcceleration;
  currentAnimation = &Walking;
}

void player::moveRight() {
  std::cout << "Moving Right" << std::endl;
  flipPlayer(true);

  acceleration_x = WalkingAcceleration;
  currentAnimation = &Walking;
}

void player::stopMoving(bool bothKeysPressed) {
  if (acceleration_x < 0.0f && bothKeysPressed) {
    flipPlayer(true);
  } else if (acceleration_x > 0.0f && bothKeysPressed) {
    flipPlayer(false);
  }

  currentAnimation = &Idle;
  acceleration_x = 0.0f;

}

void player::flipPlayer(bool faceRight) {
    if (this->facingRight == faceRight)
        return;

    if (faceRight) {
        pyoro.setScale(-1, 1);
        pyoro.setOrigin(16, 0);
    } else {
        pyoro.setScale(1, 1);
        pyoro.setOrigin(0, 0);
    }

    facingRight = faceRight;
}

// Base Functions

void player::update(const float dt, tile_manager& tm) {
  if (state == pyState::NORMAL  || state == pyState::CHEWING) {
    // Check keyboard events
    if (leftKeyDown && rightKeyDown) { // Both held down at the same time
      stopMoving(true);
    } else if (leftKeyDown) {
      moveLeft(); // Move Left
    } else if (rightKeyDown) {
      moveRight(); // Move Right
    } else {
      stopMoving(false); // No key presses
    }

    // Check if colliding against the wall
    if (x < 0)
      x = 0;
    if (x > 144)
      x = 144;

    // update movement
    int x_move = round(velocity_x * (dt*1000));
    //if (!tm.safeToWalkOn(x + 8 + (facingRight*3) - ((!facingRight)*4))) {
    if ((!tm.safeToWalkOn(x + 8 + 3) && facingRight) || (!tm.safeToWalkOn(x + 8 - 4)) && !facingRight) {
        x += x_move;
        velocity_x += acceleration_x * (dt*1000);
        if (acceleration_x < 0.0f) {
          velocity_x = std::max(velocity_x, -MaxSpeed);
        } else if (acceleration_x > 0.0f) {
          velocity_x = std::min(velocity_x, MaxSpeed);
        } else {
          velocity_x *= SlowdownFactor;
        }
    } else {
        velocity_x = 0;
    }
    pyoro.setPosition(x, y);

    // Animation
    pyoro.setLooped(true);
    pyoro.play(*currentAnimation);

  }

  if (state == pyState::EATING) {
    Tongue->update(dt);

    if (Tongue->canSwallow())
        this->swallowTongue();
  }

  sf::Time deltaTime = sf::seconds(dt);
  pyoro.update(deltaTime);

}

void player::draw() {
  if (state == pyState::EATING) {
    Tongue->draw();
  }

  game->window.draw(pyoro);


  return;
}

void player::constructor(Game* game) {
  this->game = game;
  this->state = pyState::NORMAL;
  // this->sprite = game->texmgr.getRef("pyoro");
  this->pyoro = AnimatedSprite(sf::seconds(0.05f), true, false);
  this->facingRight = false;
  this->x = 32;
  this->y = 120;
  this->velocity_x = 0.0f;
  this->acceleration_x = 0.0f;
  pyoro.setPosition(x, y);
  tongue Tongue = tongue();

  // Create Animations
  Idle.setSpriteSheet(game->texmgr.getRef("pyoro"));
  Idle.addFrame(sf::IntRect(0, 0, 16, 16));

  Walking.setSpriteSheet(game->texmgr.getRef("pyoro"));
  Walking.addFrame(sf::IntRect(0, 0, 16, 16));
  Walking.addFrame(sf::IntRect(16, 0, 16, 16));

  StartEating.setSpriteSheet(game->texmgr.getRef("pyoro"));
  StartEating.addFrame(sf::IntRect(0, 0, 16, 16));
  StartEating.addFrame(sf::IntRect(32, 0, 16, 16));
  StartEating.addFrame(sf::IntRect(48, 0, 16, 16));
  StartEating.addFrame(sf::IntRect(64, 0, 16, 16));

  flipPlayer(true);
  currentAnimation = &Idle;
}

// Get key presses
void player::startMovingLeft() { leftKeyDown = true; }
void player::startMovingRight() { rightKeyDown = true; }
void player::stopMovingLeft() { leftKeyDown = false; }
void player::stopMovingRight() { rightKeyDown = false; }

void player::beginEating() {
    if (state == pyState::NORMAL || state == pyState::CHEWING) {
        state = pyState::EATING;
        velocity_x = 0;
        currentAnimation = &StartEating;
        pyoro.play(*currentAnimation);

        pyoro.setFrameTime(sf::seconds(0.05f));
        pyoro.setLooped(false);

        // Create tongue
        Tongue = new tongue;
        Tongue->constructor(this->game, x, y, facingRight);;
        //tongue Tongue = tongue(this->game);
        //Tongue = &pyoro_tongue;
    }
}

void player::swallowTongue() {
    delete Tongue;

    currentAnimation = &Idle;
    pyoro.play(*currentAnimation);

    state = pyState::NORMAL;
}

void player::retractTongue() {
    if (state == pyState::EATING)
        Tongue->retract();
}

void player::die() {
    // TODO: remove tongue (disappear)
    state = pyState::DYING;
}
