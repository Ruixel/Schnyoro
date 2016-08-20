#ifndef TONGUE_HPP
#define TONGUE_HPP

#include <SFML/Graphics.hpp>
#include "../../game_state.hpp"
#include "../../game.hpp"

enum class tgState { EXPAND, RETRACT };

class tongue
{
private:
    Game* game;
    sf::Texture tongue_texture;

    bool faceRight;

    tgState state;
    int length;
    unsigned int start_x;
    int start_y;
public:
    void constructor(Game* game, int x, int y, bool faceRight);

    void draw();
    void update(const float dt);

    sf::Vector2i getPos();

    bool canSwallow();
    bool canEat();
    void retract();
    int getLength();
};

#endif // TONGUE_HPP
