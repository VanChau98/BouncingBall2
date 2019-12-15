#pragma once
#ifndef _GamePC_h_
#define _GamePC_h_
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "Player.h"
#include "Ball.h"
#include "Computer.h"

class GamePC
{
private:
	sf::RenderWindow *m_window;
	ball *m_ball;
	player *m_player;
	Computer *m_computer;

public:
	GamePC(sf::RenderWindow *window);
	bool update();
	void draw();

};

#endif