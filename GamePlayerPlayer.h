#pragma once
#ifndef _game_h_
#define _game_h_
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <Windows.h>
#include "Player.h"
#include "Ball.h"


class game
{
private:
	sf::RenderWindow *m_window;
	player *m_player1;
	player *m_player2;
	ball *m_ball;
public:
	game(sf::RenderWindow *window);
	bool update();
	void draw();
};

#endif

