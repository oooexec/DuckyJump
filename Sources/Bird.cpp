#include "Bird.h"

Bird::Bird()
{
    spritesheet.loadFromFile("./Graphics/bird.png");
    sprite.setTexture(spritesheet);
    sprite.setTextureRect(sf::IntRect(0, 0, 24, 24));
    sprite.scale(2.0f,2.0f);
    sprite.setPosition(200-24,300-24);
    current_frame = 0;
    gravity_modifier = -0.0f;
    min_gravity_modifier = -4.0f;
    max_gravity_modifier = +4.0f;
    jump_strength = 8.0f;
}

void Bird::update(){
    current_frame++;
    current_frame = current_frame % 3*frame_duration;
    sprite.setTextureRect(sf::IntRect(current_frame/frame_duration*24, 0, 24, 24));
    sprite.move(0,-gravity_modifier);
    if (sprite.getPosition().y < 0)
        sprite.move(0,-sprite.getPosition().y);
    gravity_modifier -= 0.2f;
    
    if(gravity_modifier < min_gravity_modifier)
        gravity_modifier = min_gravity_modifier;
}

sf::Sprite Bird::getCurrentFrame(){
    return sprite;
}

void Bird::jump(){
    if(gravity_modifier <= 0.0f)
        gravity_modifier += jump_strength;
}


Bird::~Bird()
{
}
