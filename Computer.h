#pragma once
#ifndef _Computer_h_
#define _Computer_h_
#include <SFML/Graphics.hpp>
#include <Windows.h>

class Computer
{
private:
	sf::RenderWindow *m_window;
	sf::RectangleShape m_bat;

	sf::Font m_font;
	sf::Text m_text;

	sf::Texture m_textureHeart;
	sf::Sprite m_spriteHeart;
	int countHeart;

	sf::Texture m_texture;
	sf::CircleShape people;

public:
	Computer(sf::RenderWindow *window);
	void update(sf::Vector2f);
	void draw();
	sf::Vector2f getPosition();
	int& getCountHeart();
};

#endif