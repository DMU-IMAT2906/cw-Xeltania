/*!
\file main.cpp
\brief Contains the entry point for the application
*/

#include <Box2D/Box2D.h>

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Player.h"
#include "Floor.h"



void main() /** Entry point for the application */
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Castlevania"); // Open main window

	float fFrameTime = 1.f / 60.f; //!< 60fps

	//! Create instances of the player and level, and gain access to the Floor/Platforms
	Game* Level = Game::getInstance();
	Player* Player = Player::getInstance();
	Player->spawnPlayer(sf::Vector2f(5, 5));

	Floor Floor1(Level->getWorld(),sf::Vector2f(5,5), sf::Vector2f(100,50), 0.f );
	Floor Floor2(Level->getWorld(), sf::Vector2f(5, 5), sf::Vector2f(100, 20), 0.f);

	//! Start a clock to provide time for the physics
	sf::Clock clock;

	// Run a game loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			// window closed button pressed
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) //!< If a key is pressed
				Level->KeyEvent(event.key.code); //!< Check which key in the level class
			
		}

		// Find out how much time has elapsed

		float m_fElapsedTime = clock.getElapsedTime().asSeconds();
		// If a frame has past the update the physics
		if (m_fElapsedTime > fFrameTime)
		{

			clock.restart();
		}

		window.clear(sf::Color(120,120,120));
		
		//window.draw();
		//window.draw(Level);
		Level->draw(window, sf::RenderStates::Default);
		window.draw(Floor1);
		window.draw(Player->getSprite());
		window.display();
	}



}