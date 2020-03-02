#pragma once

#include "Camera.h"

class Game : public sf::Drawable
{
private:
	bool m_bDebugMode;
	Camera m_Camera;

protected:

public:
	Game();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};