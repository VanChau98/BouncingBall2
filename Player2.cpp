#include "Player2.h"

Player2::Player2(sf::RenderWindow *window)
{
	this->m_window = window;
	sf::RectangleShape bat(sf::Vector2f(100,10));
	this->m_bat = bat;
	this->m_bat.setFillColor(sf::Color::Cyan);
	this->m_bat.setOrigin(this->m_bat.getSize().x / 2, this->m_bat.getSize().y / 2);
	this->m_bat.setPosition(250, 700);

	this->m_textureHeart.loadFromFile("images/heart.png");
	this->m_textureHeart.setSmooth(true);
	this->m_spriteHeart.setTexture(this->m_textureHeart);

	this->countHeart = 5;



}

void Player2::update()
{
	sf::Vector2f bat_postition = this->m_bat.getPosition();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		bat_postition.x -= 10;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		bat_postition.x += 10;
	if (bat_postition.x <= 50)
		bat_postition.x = 50;
	if (bat_postition.x >= 450)
		bat_postition.x = 450;
	this->m_bat.setPosition(bat_postition.x, bat_postition.y);
}

void Player2::draw()
{
	this->m_window->draw(this->m_bat);
	for (int i = 0; i < this->countHeart; i++)
	{
		this->m_spriteHeart.setPosition(10 + i * 15, 15);
		this->m_window->draw(this->m_spriteHeart);
	}
}

sf::Vector2f Player2::getPosition()
{
	return this->m_bat.getPosition();
}
int& Player2::getCountHeart()
{
	return this->countHeart;
}