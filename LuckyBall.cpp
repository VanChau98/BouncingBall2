#include "LuckyBall.h"



LuckyBall::LuckyBall(sf::RenderWindow *window, sf::Color color, float x, float y)
{
	this->m_window = window;
	this->radius = 15;
	this->m_color = color;
	sf::CircleShape ball(this->radius);
	this->m_ball = ball;
	this->m_ball.setFillColor(this->m_color);
	this->m_ball.setOrigin(this->m_ball.getRadius(), this->m_ball.getRadius());

	/*std::srand(time(NULL));
	float a;
	float b;
	do {
		a = std::rand() % 450 + 50;
		b = std::rand() % 350 + 50;
	} while (abs(a - x) <= 30 && abs(b - y) <= 30);*/
	this->m_ball.setPosition(x, y);
}


void LuckyBall::update()
{
	return;
}
void LuckyBall::draw()
{
	this->m_window->draw(this->m_ball);
}
sf::Vector2f LuckyBall::getPosition()
{
	return this->m_ball.getPosition();
}
float LuckyBall::getRadius()
{
	return this->radius;
}
sf::Color LuckyBall::getColor()
{
	return this->m_color;
}

void LuckyBall::setPosition(float x, float y)
{
	this->m_ball.setPosition(x, y);
}