#include "Game.h"
#include <iostream>

Game* Game::m_instance = NULL;
Game::Game()
{
	//! World Setup
	m_pWorld = new b2World(m_kgravity);
	m_DebugDraw.setWorld(m_pWorld);
	//! Set debug mode to false on start
	m_bDebug = false;
	//! Load the background of the level
	m_LevelTex.loadFromFile("./Assets/Images/Level.png");
	//! Set the size for the game level and apply the texture
	m_LevelRect.setSize(sf::Vector2f(3584, 624));
	m_LevelRect.setTexture(&m_LevelTex);
	//Camera Setup
	m_Camera.setBoundaries(sf::FloatRect(0.f,0.f,1.f,1.f));
	Player* m_Player = Player::getInstance();
	
	//m_Camera.setCentre(m_Player->getCentre()); //!< Sets the camera to the player's position (follows the player).
}

Game* Game::getInstance()
{
	if (m_instance == NULL)
	{
		m_instance = new Game();
	}
	return m_instance;
}

b2World* Game::getWorld()
{
	return m_pWorld;
}

void Game::KeyEvent(sf::Keyboard::Key key) //!< Method to evaluate key press events.
{
	if (key == sf::Keyboard::Right) //!< If the right arrow is pressed, move player right.
	{
		m_Camera.panCam(1);
	}
	if (key == sf::Keyboard::Left) //!< If the right arrow is pressed, move player right.
	{
		m_Camera.panCam(-1);
	}
	if (key == sf::Keyboard::Tab) 
	{
		std::cout << "Debug Mode Toggled" << std::endl;
		ToggleDebug();
	}
}
void Game::update(float timestep) //!< Used to update the world every timestep
{
	m_pWorld->Step(timestep, mk_iVelIterations, mk_iPosIterations);

	if (m_bDebug) m_DebugDraw.clear();
		
}
void Game::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	//! Set the veiw to the player camera.
	target.setView(m_Camera.getView());
	//! Drawing
	target.draw(m_LevelRect);
	//! Debug Draw
	if (m_bDebug) target.draw(m_DebugDraw);

}

Game::~Game() //!< Destructor to unload the game
{
	delete m_pWorld;
	m_pWorld = nullptr;
}