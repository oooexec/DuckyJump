#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>

class Game
{
    public:
        Game();
            virtual ~Game();
        void run();
    protected:
    private:
        void handleEvents();
        void update(sf::Time time_delta);
        void render();
        sf::Time frame_time;
        sf::RenderWindow window;
        sf::CircleShape shape;
};

#endif // GAME_H
