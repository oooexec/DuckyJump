#ifndef BIRD_H
#define BIRD_H
#include <SFML/Graphics.hpp>

class Bird
{
public:
    Bird();
    ~Bird();
    void update(sf::Time time_delta);
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
    sf::Time frame_duration;
    sf::Time time_since_frame_change;
    int frame_amount = 3;
};

#endif // BIRD_H
