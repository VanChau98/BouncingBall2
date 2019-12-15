#pragma once
#ifndef _DesignBouncing_h_
#define _DesignBouncing_h_
#include <SFML/Graphics.hpp>
#include <Windows.h>

class DesignBouncing
{
private:
	sf::RenderWindow		*m_window;
	sf::RectangleShape		m_station;
public:
	DesignBouncing(sf::RenderWindow *window);
	void update();
	void draw();
};

#endif
