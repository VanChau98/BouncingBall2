#include "DesignHome.h"



designHome::designHome(sf::RenderWindow *window)
{
	this->m_window = window;

	this->m_font.loadFromFile("fonts/MarkerFelt.ttf");
	this->m_text.setFont(this->m_font);
	this->m_text.setString("Bouncing Ball");
	this->m_text.setCharacterSize(30);
	this->m_text.setFillColor(sf::Color::Green);

	this->m_textureLogo.loadFromFile("images/logo.png");
	this->m_textureLogo.setSmooth(true);
	sf::CircleShape logo(35);
	this->m_logo = logo;
	this->m_logo.setTexture(&m_textureLogo);

	this->m_background.loadFromFile("images/background1.jpg");
	this->m_background.setSmooth(true);
	this->m_spriteBackground.setTexture(this->m_background);


}

void designHome::update()
{
	this->m_logo.setPosition(165, 30);
	this->m_text.setPosition(120, 110);
	float ScaleX = (float)this->m_window->getSize().x / this->m_background.getSize().x;
	float ScaleY = (float)this->m_window->getSize().y / this->m_background.getSize().y;
	this->m_spriteBackground.setScale(ScaleX, ScaleY);
}
void designHome::draw()
{
	this->m_window->draw(this->m_spriteBackground);
	this->m_window->draw(this->m_logo);
	this->m_window->draw(this->m_text);
}

