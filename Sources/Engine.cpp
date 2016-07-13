#include "Engine.h"
#include "Game.h"

Engine::Engine()
{
    window.create(sf::VideoMode(400, 600),"DuckyJump");
    window.setFramerateLimit(60);
    window.setMouseCursorVisible(false);
    
}


Engine::~Engine()
{
}

void Engine::run(){
    while (window.isOpen())
    {
        if(game_state == 1){
            Game game(&window);
            game.run();
            switch_game_state();
        }

    }
}

void Engine::switch_game_state(){

//    game_state = (1 + game_state) % 2;
}