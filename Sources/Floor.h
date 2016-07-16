#ifndef FLOOR_H
#define FLOOR_H
#include <SFML/Graphics.hpp>

class Floor
{
public:
    Floor(float window_width = 400.f, float window_height = 600.f);
    ~Floor();
    sf::Sprite getSprite();
    void update();
    void move(float horizontal_movement = 0);
private:
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif // FLOOR_H
