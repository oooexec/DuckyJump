#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <array>
#include "Bird.h"
#include "Floor.h"
#include "Pipe.h"

#define PIPES_AMOUNT 5

class Game
{
    public:
        Game(sf::RenderWindow * new_window_pointer);
        virtual ~Game();
        void run();
    protected:
    private:
        void handleEvents();
        void update(sf::Time time_delta);
        void render();
        float getLastPipePos();
        sf::Time frame_time;
        sf::RenderWindow * window_pointer;
        sf::Music bg_music;
        float horizontal_speed;
        float space_beetwen_pipes;
        Bird bird;
        Floor floor;
        Pipe test_pipe;
        std::array<Pipe, PIPES_AMOUNT> pipes;
        
        bool is_game_running;
        bool is_paused;
};

#endif // GAME_H
