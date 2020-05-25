#pragma once
#include "Game.h"
#include "Collidables.h"
class Player : public Collidables
{
	
private:
	//! Player is a singleton class, therefore set the construction and destruction to private 
	Player();
	~Player();
	static Player* m_playerInstance; //!< Object instance.

	int m_Health; //!< The amount of lives the player has. 
	const int m_kSpeed = 5; //!< How fast the player moves.
	bool m_bJumping; //!< Checks if the player is already grounded.
	bool m_bGrounded; //!< Checks if the player is colliding with the floor.
	//! Body attributes
	sf::Sprite m_PlayerSprite; //!< The sprite for the player. How it will be seen in the game.
	sf::Texture m_PlayerTex; //!< Player texture to be applied to the sprite.
	sf::Vector2f m_Position; //!< Where the player is in the world.


public:
	static Player* getInstance(); //!< Get access to the player instance.
	void MovePlayer(); //!< Moves the player (left, right, jump) based on keypress. 
	void Attack(); //!< Handles player swinging weapons.
	void HurtPlayer(); //!< Deals damage to the player on collision with an enemy.
	int getHealth(); //!< Returns the player's health to the console.
	float getRotation(); //!< Returns the rotation of the player (left/right facing). Used to know which way to fire the projectile.
	sf::FloatRect getPosition();
	sf::Sprite getSprite();
	sf::Vector2f getCentre();
	void spawnPlayer(sf::Vector2f pos);

	

};