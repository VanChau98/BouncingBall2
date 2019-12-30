#include "GamePlayerComputer.h"

GamePC::GamePC(sf::RenderWindow *window)
{
	this->m_window = window;
	this->m_player = new player(this->m_window, 60, 350);
	this->m_computer = new Computer(this->m_window);
	this->m_ball = new ball(this->m_window);

}

bool GamePC::update()
{
	sf::Vector2f pos = this->m_ball->getPosition();
	this->m_player->update(1);
	this->m_computer->update(pos);
	this->m_ball->update(50, 1150, 25, 525);

	//Computer
	


	// va chậm thanh trượt
	int x1 = std::abs(this->m_ball->getPosition().x - this->m_player->getPosition().x);
	int x2 = std::abs(this->m_ball->getPosition().x - this->m_computer->getPosition().x);
	int y1 = std::abs(this->m_ball->getPosition().y - this->m_player->getPosition().y);
	int y2 = std::abs(this->m_ball->getPosition().y - this->m_computer->getPosition().y);

	if (y1 <= 65 && x1 <= 20) {
		this->m_ball->update(70, 1150, 25, 525);
		if (this->m_ball->getSpeed() < 0.1f)
			this->m_ball->setSpeed(this->m_ball->getSpeed() + this->m_ball->getSpeed()*0.1);
		else  this->m_ball->setSpeed(0.1f);
	}
	if (y2 <= 65 && x2 <= 20) {
		this->m_ball->update(50, 1130, 25, 525);
		if (this->m_ball->getSpeed() < 0.1f)
			this->m_ball->setSpeed(this->m_ball->getSpeed() + this->m_ball->getSpeed()*0.1);
		else  this->m_ball->setSpeed(0.1f);
	}

	//Xử lý kết thúc game
	int a = this->m_ball->getPosition().x - this->m_ball->getRadius();
	int b = this->m_ball->getPosition().x + this->m_ball->getRadius();
	if (a <= 50) {
		this->m_player->getCountHeart()--;
		this->m_ball->setPosition(600, 275);
		this->m_ball->setSpeed(0.03f);
	}
	if (b >= 1150) {
		this->m_computer->getCountHeart()--;
		this->m_ball->setPosition(600, 275);
		this->m_ball->setSpeed(0.03f);
	}
	if (this->m_computer->getCountHeart() >= 0 && this->m_player->getCountHeart() >= 0)
		return true;
	else {
		if (this->m_computer->getCountHeart() < 0) {
			if (MessageBox(NULL, "PLAYER WIN!", "Game Over", MB_OKCANCEL) == IDOK)
				return false;
			else return false;
		}
		if (this->m_player->getCountHeart() < 0) {
			if (MessageBox(NULL, "COMPUTER WIN!", "Game Over", MB_OKCANCEL) == IDOK)
				return false;
			else return false;

		}
	}
}

void GamePC::draw()
{
	this->m_player->draw(1);
	this->m_computer->draw();
	this->m_ball->draw();
}