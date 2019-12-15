#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>
class LuckyBall
{
private:
	sf::RenderWindow *m_window;
	sf::CircleShape m_ball;
	float			radius;
	sf::Color		m_color;
public:
	LuckyBall(sf::RenderWindow *window, sf::Color);
	void update();
	void draw();
	sf::Vector2f getPosition();
	float getRadius();
	sf::Color getColor();
	void setPosition(float, float);
};

