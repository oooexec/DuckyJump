#ifndef BIRD_H
#define BIRD_H
#include <SFML/Graphics.hpp>

class Bird
{
public:
    Bird();
    ~Bird();
protected:
private:
    bool is_alive;
    sf::Sprite sprite;
    float gravity_modifier;
    float horizontal_speed;
};

#endif // BIRD_H
