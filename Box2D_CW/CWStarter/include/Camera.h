#pragma once
#include <SFML/Graphics.hpp>

class Camera
{
private:
	sf::View m_View; // Camera View 
	sf::FloatRect m_viewSize; // Defines the constraints for the camera.
	sf::FloatRect m_viewBoundaries; //!< Defines the bounds.
	sf::Vector2f m_viewPos; //!< Position of the camera.

protected:

public:
	Camera();
	// Setters //
	void setCentre(sf::Vector2f centre);
	void setBoundaries(sf::FloatRect bounds);
	void setSize(sf::Vector2f size);
	// Getters //
	sf::View getView() const;
	sf::Vector2f getCentre();
	// Camera Controls //
	void panCam(int x);
	void zoomCam(float zoom);
};