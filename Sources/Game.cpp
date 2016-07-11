#include "Game.h"

Game::Game()
{
    window.create(sf::VideoMode(400, 600),"DuckyJump");
    shape.setRadius(150.f);
    shape.setFillColor(sf::Color::Green);
    
    frame_time  = sf::seconds(1.f/60.f);
    
    this->run();
}

Game::~Game()
{
}

void Game::run()
{
	sf::Clock clock;
	sf::Time elapsed_time_since_update = sf::Time::Zero;
    while (window.isOpen())
    {
        
		sf::Time elapsed_time = clock.restart();
		elapsed_time_since_update += elapsed_time;
        if(elapsed_time_since_update > frame_time){
            elapsed_time_since_update -= frame_time;
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            shape.move(1.0,0.0);
            window.clear();
            window.draw(shape);
            window.display();
        }
    }
}
