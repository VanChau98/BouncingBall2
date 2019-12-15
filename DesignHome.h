#pragma once
#pragma once
#ifndef _DesignHome_h_
#define _DesignHome_h_
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <Windows.h>
#include <iostream>
class designHome
{
private:
	sf::RenderWindow *m_window;

	sf::Font m_font;
	sf::Text m_text;
	sf::Texture m_textureLogo;
	sf::CircleShape m_logo;
	sf::Texture m_background;
	sf::Sprite m_spriteBackground;

public:
	designHome(sf::RenderWindow *window);
	void update();
	void draw();
};
#endif

