#include "Player.h"


Player* Player::m_playerInstance = NULL; //!< Default the player instance to null.

Player::Player() //!< Initialise values.
{

	m_PlayerTex.loadFromFile("./Assets/Images/Player.png");
	m_PlayerSprite.setTexture(m_PlayerTex);
	
}

Player::~Player() //!< Dereference pointers, unload textures etc.
{

}

Player* Player::getInstance() 
{
	if (m_playerInstance == NULL) //!< If there is no existing instance, create new player instance.
	{
		m_playerInstance = new Player();
	}
	return m_playerInstance; //!< Return pointer to the instance.
}

void Player::MovePlayer()
{
	//if()
}

void Player::Attack()
{
}

int Player::getHealth()
{
	return m_Health;
}

float Player::getRotation()
{
	return m_PlayerSprite.getRotation();
}

sf::FloatRect Player::getPosition()
{
	return m_PlayerSprite.getLocalBounds();
}

sf::Sprite Player::getSprite()
{
	return m_PlayerSprite;
}

sf::Vector2f Player::getCentre()
{
	return m_Position;
}

void Player::spawnPlayer(sf::Vector2f pos)
{
	m_PlayerSprite.setPosition(pos);
}


void Player::HurtPlayer()
{
	m_Health -= 1;
}
