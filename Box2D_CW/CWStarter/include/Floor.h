#pragma once
#include "Game.h"
#include "Collidables.h"

class Floor : public Collidables , public sf::RectangleShape //!< Class to create Static Objects that will act as the level's floor.
{
private:

public:
	Floor(b2World * world, const sf::Vector2f& position, const sf::Vector2f& size, const float& orientation); //!< Constructor for the floor/platforms
};