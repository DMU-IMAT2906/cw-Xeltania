#pragma once
#include <Box2D/Box2D.h>
#include "Camera.h"
#include "SFMLDebugDraw.h"
#include "Player.h"

#define DEG2RAD 0.017453f
#define RAD2DEG 57.29577f

class Game : public sf::Drawable
{
private:
	//! Game is a singleton: contstruction and destruction are private.
	Game();
	~Game();
	static Game* m_instance; //!< The single instance of the class.
	//! World Setup
	b2World* m_pWorld = nullptr;
	sf::Vector2f m_WorldSize = sf::Vector2f(8.f, 6.f); //!< Size of the physical world.
	const b2Vec2 m_kgravity = b2Vec2(0.f, 9.81f);
	const int mk_iVelIterations = 7; //!< On each update there will be 7 velocity iterations in the physics engine.
	const int mk_iPosIterations = 5; //!< On each update there will be 5 position iterations on each update.


	bool m_bDebug;
	sf::Texture m_LevelTex; //!< Texutre of the background of the game.
	sf::RectangleShape m_LevelRect; //!< RectangleShape to use Tex as Level background.
	
	Camera m_Camera;
	SFMLDebugDraw m_DebugDraw;
protected:

public:
	static Game* getInstance(); //!< How the single instance is accessed.
	b2World* getWorld();
	void KeyEvent(sf::Keyboard::Key key);
	void update(float timestep);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void ToggleDebug() { m_bDebug = !m_bDebug; }
};