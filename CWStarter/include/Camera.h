#pragma once
#include <SFML/Graphics.hpp>

class Camera
{
private:
	sf::View m_View; // Camera View 
	sf::FloatRect m_viewBoundaries; // Defines the constraints for the camera.

protected:

public:
	// Setters //
	void setCentre(sf::Vector2f centre);
	void setBoundaries(sf::FloatRect bounds);
	void setSize(sf::Vector2f size);
	// Getters //
	sf::View getView() const;
	sf::Vector2f getCentre();
	// Camera Controls //
	void panCam();
	void zoomCam(float zoom);
};