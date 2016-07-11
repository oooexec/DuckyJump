#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include "Game.h"

class Engine
{
public:
    Engine();
    ~Engine();
    void switch_game_state();
    void run();
private:
    sf::RenderWindow window;
    // 1 = Gameplay
    // 0 = Start menu
    int game_state = 1;
};

#endif // ENGINE_H
