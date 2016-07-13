#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow * new_window_pointer)
{
    window_pointer = new_window_pointer;
    shape.setRadius(150.f);
    shape.setFillColor(sf::Color::Green);
    bg_music.openFromFile("./Sounds/bg_music.ogg");
    bg_music.setVolume(33.f);
    bg_music.setLoop(true);
    
    is_game_running = true;
    is_paused = false;
    
    frame_time  = sf::seconds(1.f/60.f);
    
    this->run();
}

Game::~Game()
{
}

void Game::handleEvents(){    
    sf::Event event;
    while (( * window_pointer ).pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            ( * window_pointer ).close();
            

        switch(event.key.code){
            case sf::Keyboard::Escape:
                is_game_running = false;
                break;
            case sf::Keyboard::P:
                is_paused = true;
                break;
        }
    }
}


void Game::run()
{
    bg_music.play();
    
	sf::Clock clock;
	sf::Time elapsed_time_since_update = sf::Time::Zero;
    while (is_game_running)
    {
        
		sf::Time elapsed_time = clock.restart();
		elapsed_time_since_update += elapsed_time;
        if(elapsed_time_since_update > frame_time){
            elapsed_time_since_update -= frame_time;
            this->handleEvents();
            this->update(frame_time);
            ( * window_pointer ).clear();
            ( * window_pointer ).draw(shape);
            ( * window_pointer ).draw(bird.getCurrentFrame());
            ( * window_pointer ).display();
        }
    }
}

void Game::update(sf::Time time_delta){
    if(!is_paused){
        shape.move(1.0,0.0);
        bird.update();
    }
}