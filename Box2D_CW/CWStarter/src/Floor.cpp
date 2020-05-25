#include "Floor.h"


Floor::Floor(b2World * world, const sf::Vector2f& position, const sf::Vector2f& size, const float& orientation) 
{
	//! Define the local construction items for the floor
	b2BodyDef bodyDef;
	b2PolygonShape polyShape;
	b2FixtureDef fixtureDef;

	//! Set the position and angle of the floor/platform
	bodyDef.position.Set(position.x, position.y);
	bodyDef.angle = orientation * DEG2RAD;
	//!Create the body in the game world
	m_body = world->CreateBody(&bodyDef);
	m_body->SetUserData(this); //!< Used by the CollisionListener
	//! Set the shape as a box (no curved floors).
	polyShape.SetAsBox(size.x * 0.5f, size.y * 0.5f);
	polyShape.m_radius = 0.0f;
	//! Apply properties of mass, friction, and bounciness
	fixtureDef.density = m_kfDensity;
	fixtureDef.friction = m_kfFriction;
	fixtureDef.restitution = m_kfRestitution;
	fixtureDef.shape = &polyShape;
	//! Create the fixture for the floor
	m_body->CreateFixture(&fixtureDef);
	//!< Set the attributes for drawing the floor in the game
	setPosition(position);
	setSize(size);
	setOrigin(size * 0.5f);
	setRotation(orientation);
	setFillColor(sf::Color::Green);
	setOutlineThickness(0.f);

}
