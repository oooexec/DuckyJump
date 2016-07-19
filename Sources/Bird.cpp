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
    max_gravity_modifier = 4.0f;
    min_gravity_modifier = -1 * max_gravity_modifier;
    jump_strength = 2*max_gravity_modifier;
    frame_duration  = sf::seconds(16.f/60.f);
    time_since_frame_change = sf::Time::Zero;

}

void Bird::update(sf::Time time_delta){
    time_since_frame_change += time_delta;
    if(time_since_frame_change >= frame_duration){
        current_frame++;
        time_since_frame_change = sf::Time::Zero;
    }
    if(current_frame >= frame_amount){
        current_frame = 0;
    }
    sprite.setTextureRect(sf::IntRect(current_frame*24, 0, 24, 24));
    sprite.move(0,-gravity_modifier);
    if (sprite.getPosition().y < 0)
        sprite.move(0,-sprite.getPosition().y);
    gravity_modifier -= 0.2f;
    
    if(gravity_modifier < min_gravity_modifier)
        gravity_modifier = min_gravity_modifier;
        
    this->updateRotation();
}

void Bird::updateRotation(){
    sprite.setRotation(3*gravity_modifier);
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
