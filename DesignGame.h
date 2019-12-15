#pragma once
#ifndef _designGame_h_
#define _desiignGame_h_
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>
class designGame
{
private:
	sf::RenderWindow *m_window;
	sf::RectangleShape m_station;
	sf::RectangleShape m_line;
	sf::CircleShape m_circle;
	sf::CircleShape m_ball;
	sf::Texture m_textureBackground;
	sf::Sprite m_spriteBackground;
public:
	designGame(sf::RenderWindow* window);
	void update();
	void draw();
};

#endif
