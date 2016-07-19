#include "Pipe.h"

Pipe::Pipe(float hole_position, float window_width, float window_height)
{
    texture.loadFromFile("./Graphics/pipe.png");
    sprite_up.setTexture(texture);
    sprite_down.setTexture(texture);
    // we have to rotate sprite 
    sprite_up.rotate(180.f);
    sprite_up.move(texture.getSize().x,texture.getSize().y);
    sprite_up.setOrigin(0.f,0.f);
    
    sprite_down.move(0.f,texture.getSize().y + this->vertical_space_beetwen);
    
    //calculate position based on hole_position
    sprite_up.move(250.f,hole_position - texture.getSize().y);
    sprite_down.move(250.f,hole_position - texture.getSize().y);
    
    
}

void Pipe::move(float horizontal_movement){
    sprite_down.move(-horizontal_movement,0.f);
    sprite_up.move(-horizontal_movement,0.f);
    
}

sf::RectangleShape  Pipe::getHoleShape(){
    // declare hole object
    sf::RectangleShape hole;
    // position is: 
    // upper sprite X pos
    // and upper_sprite_pos Y pos + upper_sprite height
    hole.setPosition(sprite_up.getPosition().x,sprite_up.getPosition().y + sprite_up.getGlobalBounds().height);
    
    //size is width of texture and vertical space beetwen pipes
    hole.setSize(sf::Vector2f(50,vertical_space_beetwen));
    return hole;
}

sf::Sprite Pipe::getSpriteNr(unsigned int number_of_sprite){
    if(number_of_sprite == 0)
        return sprite_up;
    else
        return sprite_down;
}

Pipe::~Pipe()
{
}

