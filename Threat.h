#pragma once
#ifndef _Threat_h_
#define _Threat_h_
#include <SFML/Graphics.hpp>
#include <Windows.h>
class Threat
{
private:
	sf::RenderWindow *m_window;
	sf::CircleShape m_threat;
public:
	Threat(sf::RenderWindow *window);
	void update(float, float);
	void draw();
	sf::Vector2f getPosition();
};


#endif