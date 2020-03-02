#include "Camera.h"


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

void Camera::panCam()
{
	// pan cam by changing position by x,y ?
}

void Camera::zoomCam(float zoom)
{
	// zoom view by changing bounds? 
}
