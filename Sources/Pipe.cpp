#include "Pipe.h"

Pipe::Pipe(float hole_position, float start_x_pos, float window_width, float window_height)
{
    texture.loadFromFile("./Graphics/pipe.png");
    texture_up.loadFromFile("./Graphics/pipe_up.png");
    sprite_up.setTexture(texture_up);
    sprite_down.setTexture(texture);
    
    sprite_down.move(0.f,texture.getSize().y + this->vertical_space_beetwen);
    
    //calculate position based on hole_position
    sprite_up.move(-start_x_pos,hole_position - texture.getSize().y);
    sprite_down.move(-start_x_pos,hole_position - texture.getSize().y);
    
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

bool Pipe::hasPassPlayerAndView(){
    // checking is position below 0 and any part of sprite isnt visible
    if(sprite_down.getPosition().x + texture.getSize().x < 0){
        return true;
    }
    else{
        return false;
    }
}

float Pipe::getX(){
    return sprite_down.getPosition().x;
}

void Pipe::setX(float new_x_pos){
    sprite_down.move(new_x_pos-sprite_down.getPosition().x,0.f);
    sprite_up.move(new_x_pos-sprite_up.getPosition().x,0.f);
}

Pipe::~Pipe()
{
}

