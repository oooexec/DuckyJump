#include "Game.h"
#include <iostream>



Game::Game(sf::RenderWindow * new_window_pointer)
{
    window_pointer = new_window_pointer;
    bg_music.openFromFile("./Sounds/bg_music.ogg");
    bg_music.setVolume(33.f);
    bg_music.setLoop(true);
    
    is_game_running = true;
    is_paused = false;
    
    frame_time  = sf::seconds(1.f/60.f);
    horizontal_speed = 1.0f;
    space_beetwen_pipes = 200.f;
    
    for(int i = 0;i<PIPES_AMOUNT;i++){
        pipes[i].move((500.f+i*space_beetwen_pipes)*-1);
    }
    
    this->run();
}

float Game::getLastPipePos(){
    float last_pipe_pos = 0.f;
    for(int i = 0;i<PIPES_AMOUNT;i++){
        if(pipes[i].getX() > last_pipe_pos)
            last_pipe_pos = pipes[i].getX();
        
    }
    return last_pipe_pos;
}

Game::~Game()
{
    bg_music.stop();
}

void Game::handleEvents(){    
    sf::Event event;
    while (( * window_pointer ).pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            ( * window_pointer ).close();
            

        switch(event.key.code){
            case sf::Keyboard::Escape:
                ( * window_pointer ).close();
                break;
            case sf::Keyboard::R:
                is_game_running = false;
                break;
            case sf::Keyboard::P:
                is_paused = true;
                break;
            case sf::Keyboard::Space:
                bird.jump();
                break;
            default:
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
            this->render();
        }
    }
}

void Game::update(sf::Time time_delta){
    if(!is_paused){
        floor.move(horizontal_speed);
        
        // lets handle every pipe in game!
        for(int i = 0;i<PIPES_AMOUNT;i++){
            // moving every pipe
            pipes[i].move(horizontal_speed);
            // now if pipe pass the screen lets move it on end
            if(pipes[i].hasPassPlayerAndView()){
                pipes[i].setX(this->getLastPipePos() + space_beetwen_pipes);
            }
            std::cout << pipes[i].getX() << "\t";
        }
        std::cout << std::endl;
        
        bird.update(time_delta);
    }
}

void Game::render(){
        ( * window_pointer ).clear(sf::Color(75,203,208));
        for(int i = 0;i<PIPES_AMOUNT;i++){
            ( * window_pointer ).draw(pipes[i].getSpriteNr(0));
            ( * window_pointer ).draw(pipes[i].getSpriteNr(1));
        }
        ( * window_pointer ).draw(floor.getSprite());
        ( * window_pointer ).draw(bird.getCurrentFrame());
        ( * window_pointer ).display();
        
}