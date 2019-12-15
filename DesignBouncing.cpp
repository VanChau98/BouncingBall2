#include "DesignBouncing.h"



DesignBouncing::DesignBouncing(sf::RenderWindow *window)
{
	this->m_window = window;
	sf::RectangleShape station(sf::Vector2f(492, 712));
	this->m_station = station;
	this->m_station.setOutlineThickness(4);
	this->m_station.setOutlineColor(sf::Color::Green);
	this->m_station.setFillColor(sf::Color::Black);
}

void DesignBouncing::update()
{
	this->m_station.setPosition(4, 4);
}

void DesignBouncing::draw()
{
	this->m_window->draw(this->m_station);
}
