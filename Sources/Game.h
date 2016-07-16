#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Bird.h"
#include "Floor.h"

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
        sf::Time frame_time;
        sf::RenderWindow * window_pointer;
        sf::Music bg_music;
        float horizontal_speed;
        Bird bird;
        Floor floor;
        
        bool is_game_running;
        bool is_paused;
};

#endif // GAME_H
