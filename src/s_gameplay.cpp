#include <SFML/Graphics.hpp>
#include <iostream>

#include "entities/misc/background.hpp"
#include "s_gameplay.hpp"

void sGameplay::draw(const float dt) {
  game->window.clear(sf::Color::Black);

  // Set View
  game->window.setView(view);

  obj_bg.draw();
  obj_tilemgr.draw();
  obj_plr.draw();
  obj_beanmgr.draw();

  return;
}

void sGameplay::update(const float dt) {
  obj_plr.update(dt, obj_tilemgr);

  if (obj_plr.canEat())
      if (obj_beanmgr.AABBcollision(obj_plr.returnTonguePos()))
        obj_plr.retractTongue();

  obj_beanmgr.update(dt, obj_plr.returnTonguePos(), obj_plr.tongueLength());
  obj_tilemgr.update();
  obj_bg.update();

  return;
}

sGameplay::sGameplay(Game* game) {
  this->game = game;
  view = sf::View(sf::FloatRect(0,0,160,144));
  view.zoom(1);
  game->window.setView(view);

  obj_bg.constructor(game);
  obj_plr.constructor(game);
  obj_tilemgr.constructor(game);

  obj_beanmgr.constructor(game, &obj_tilemgr);

  std::cout << "Heyoo" << std::endl;
}

void sGameplay::handleInput()
{
    sf::Event event;

    while(this->game->window.pollEvent(event))
    {
        switch(event.type)
        {
            /* Close the window */
            case sf::Event::Closed:
            {
                game->window.close();
                break;
            }

            // keyboard event
            case sf::Event::KeyPressed:
            {
                /* press Z */
                if (event.key.code == sf::Keyboard::Z) {
                    obj_bg.increment_level();
                    obj_tilemgr.increment_level();
                }

                /* Escape pressed */
                if(event.key.code == sf::Keyboard::Escape)
                    this->game->window.close();

                if (event.key.code == sf::Keyboard::Left)
                    obj_plr.startMovingLeft();

                if (event.key.code == sf::Keyboard::Right)
                    obj_plr.startMovingRight();

                if (event.key.code == sf::Keyboard::Q)
                    obj_plr.beginEating();

                break;
            }

            case sf::Event::KeyReleased:
            {
                if (event.key.code == sf::Keyboard::Left)
                    obj_plr.stopMovingLeft();

                if (event.key.code == sf::Keyboard::Right)
                    obj_plr.stopMovingRight();

                if (event.key.code == sf::Keyboard::Q)
                    obj_plr.retractTongue();

                break;
            }

            default: break;
        }
    }

    return;
}
