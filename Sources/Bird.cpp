#include "Bird.h"

Bird::Bird()
{
    spritesheet.loadFromFile("./Graphics/bird.png");
    sprite.setTexture(spritesheet);
    sprite.setTextureRect(sf::IntRect(0, 0, 24, 24));
    sprite.scale(2.0f,2.0f);
    current_frame = 0;
    gravity_modifier = 0.5f;
    horizontal_speed = 1.0f;
}

Bird::~Bird()
{
}

void Bird::update(){
    current_frame++;
    current_frame = current_frame % 3*frame_duration;
    sprite.setTextureRect(sf::IntRect(current_frame/frame_duration*24, 0, 24, 24));
    sprite.move(horizontal_speed,gravity_modifier);
}

sf::Sprite Bird::getCurrentFrame(){
    return sprite;
}