#ifndef BIRD_H
#define BIRD_H
#include <SFML/Graphics.hpp>

class Bird
{
public:
    Bird();
    ~Bird();
    void update();
    sf::Sprite getCurrentFrame();
protected:
private:
    bool is_alive;
    sf::Texture spritesheet;
    sf::Sprite sprite;
    float gravity_modifier;
    float horizontal_speed;
    int current_frame = 0;
    int frame_duration = 8;
};

#endif // BIRD_H
