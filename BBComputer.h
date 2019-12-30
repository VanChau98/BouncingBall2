#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>
class BBComputer
{
private:
	sf::RenderWindow		*m_window;
	sf::RectangleShape		m_bat;

	sf::Texture				m_textureHeart;
	sf::Sprite				m_spriteHeart;
	int						countHeart;
public:
	BBComputer(sf::RenderWindow *window);
	void update(sf::Vector2f);
	void draw();
	sf::Vector2f getPosition();
	int& getCountHeart();
};

