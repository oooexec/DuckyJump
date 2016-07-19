#ifndef PIPE_H
#define PIPE_H
#include <SFML/Graphics.hpp>

class Pipe
{
public:
    Pipe(float hole_position = 300.f, float window_width = 400.f, float window_height = 600.f);
    ~Pipe();
    void update();
    sf::RectangleShape getHoleShape();
    void move(float horizontal_movement = 0);
    sf::Sprite getSpriteNr(unsigned int number_of_sprite);
private:
    sf::Texture texture;
    sf::Sprite sprite_up;
    sf::Sprite sprite_down;
    float vertical_space_beetwen = 100.f;
};

#endif // PIPE_H
