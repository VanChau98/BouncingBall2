#pragma once
#ifndef _GamePlayer_h_
#define _GamePlayer_h_
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <list>
#include "Player2.h"
#include "Threat.h"
#include "Ball.h"
class GamePlayer
{
private:
	sf::RenderWindow	*m_window;
	Player2				*m_player;
	ball				*m_ball;
	std::list<Threat>	m_threat;
	unsigned int		score;

	sf::Font			m_font;
	sf::Text			m_text;
	
public:
	GamePlayer(sf::RenderWindow *window);
	bool update();
	void draw();
	void RenderBallScore();
	void DrawBallScore();
};

#endif