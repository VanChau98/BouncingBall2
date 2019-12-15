#pragma once
#ifndef _Player2_h_
#define _Player2_h_
#include <SFML/Graphics.hpp>
#include <Windows.h>
class Player2
{
private:
	sf::RenderWindow		*m_window;
	sf::RectangleShape		m_bat;

	sf::Texture				m_textureHeart;
	sf::Sprite				m_spriteHeart;
	int						countHeart;

public:
	Player2(sf::RenderWindow *window);
	void update();
	void draw();
	sf::Vector2f getPosition();
	int& getCountHeart();
};

#endif

