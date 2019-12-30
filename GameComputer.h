#pragma once
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <Windows.h>
#include <fstream>
#include <list>
#include "Player2.h"
#include "Threat.h"
#include "LuckyBall.h"
#include "Ball.h"
#include "BBComputer.h"
class GameComputer
{
private:
	sf::RenderWindow	*m_window;
	BBComputer				*m_player;
	ball				*m_ball;
	std::list<Threat>	m_threat;
	unsigned int		score;

	sf::Font			m_font;
	sf::Text			m_text;

	std::list<LuckyBall>m_luckyBall;
	sf::Time			m_time;
	sf::Clock			m_clock;
public:
	GameComputer(sf::RenderWindow *window);
	bool update();
	void draw();
	void RenderBallScore();
	void DrawBallLine();
	bool saveGame();
	void Report();
	sf::Vector2f getPositionThreat();
};

