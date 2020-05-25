#include "Camera.h"

Camera::Camera() 
{
	m_View.setSize(sf::Vector2f(1500, 1500));
	m_View.setCenter(sf::Vector2f(700, 350));
	
}

sf::View Camera::getView() const
{
	return m_View;
}

void Camera::setCentre(sf::Vector2f centre)
{
	m_View.setCenter(centre);
}

sf::Vector2f Camera::getCentre()
{
	return m_View.getCenter();
}

void Camera::setBoundaries(sf::FloatRect bounds)
{
	bounds = m_viewBoundaries;
}

void Camera::setSize(sf::Vector2f size)
{
	m_View.setSize(size); 
}

void Camera::panCam(int x)
{
	// pan cam by changing position by x,y ?
	m_View.move(sf::Vector2f(x,0));
	// Replace with tracking player body
	
}

void Camera::zoomCam(float zoom)
{
	// zoom view by changing bounds? 
}
