#pragma once
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

class Collidables //!< Class to define all the requirements of a collidable 'thing' in the game (Player, Enemy, Floor etc.)
{	
protected:
	
	b2Body * m_body = nullptr; //!< Box2D body for the objects.
	const float m_kfDensity = 1.0f; //!< Mass of the 'thing' 
	const float m_kfFriction = 0.4f; //!< Friction (only used by moving 'things' e.g. the player and enemies.
	const float m_kfRestitution = 0.6f; //!< Bounciness of the 'thing'

public:
	void setUserData(void* data) { m_body->SetUserData(data); }; //!< Set the userdata of the body
};