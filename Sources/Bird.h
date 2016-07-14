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
    void jump();
protected:
private:
    bool is_alive;
    sf::Texture spritesheet;
    sf::Sprite sprite;
    float gravity_modifier;
    float min_gravity_modifier;
    float max_gravity_modifier;
    float jump_strength;
    int current_frame = 0;
    int frame_duration = 16;
};

#endif // BIRD_H
