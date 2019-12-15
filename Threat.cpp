#include "Threat.h"



Threat::Threat(sf::RenderWindow *window)
{
	this->m_window = window;
	sf::CircleShape threat(15);
	this->m_threat = threat;
	this->m_threat.setFillColor(sf::Color::Red);
	this->m_threat.setOrigin(this->m_threat.getRadius(), this->m_threat.getRadius());
}
void Threat::update(float x, float y)
{
	this->m_threat.setPosition(x, y);
}
void Threat::draw()
{
	this->m_window->draw(this->m_threat);
}

sf::Vector2f Threat::getPosition()
{
	return this->m_threat.getPosition();
}
