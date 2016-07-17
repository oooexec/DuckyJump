#include "Floor.h"

Floor::Floor(float window_width, float window_height)
{
    
    texture.loadFromFile("./Graphics/bg.png");
    texture.setRepeated(true);
    
    sf::IntRect floor_rect(0.f,0.f,window_width + 60.f,70.f);
    
    sprite.setTexture(texture);
    sprite.setTextureRect(floor_rect);
    sprite.setPosition(0.f,window_height-70);
}

sf::Sprite Floor::getSprite(){
    return this->sprite;
}

void Floor::move(float horizontal_movement) {
    sprite.move(-horizontal_movement,0.f);
    this->update();
}

void Floor::update(){
    if(sprite.getPosition().x <= -20.f)
        sprite.move(20.f,0.f);
}
Floor::~Floor()
{
    
}

