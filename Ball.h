#pragma once
#ifndef _ball_h_
#define _ball_h_
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <cstdlib>
#include <time.h>
#include <random>
#include <functional>
#include <iostream>
class ball
{
private:
	sf::RenderWindow		*m_window;
	sf::CircleShape			 m_ball;
	sf::Vector2f			direction;
	float					radius;
	float					velocity;
	float					speed;

public:
	ball(sf::RenderWindow *window);
	void update(int, int, int, int);
	void draw();
	sf::Vector2f getPosition();
	void setPosition(float, float);
	float getRadius();
	float getSpeed();
	void setSpeed(float);
};

#endif
