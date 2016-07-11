#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>

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
        sf::CircleShape shape;
        sf::RenderWindow * window_pointer;
        
        bool is_game_running;
        bool is_paused;
};

#endif // GAME_H
