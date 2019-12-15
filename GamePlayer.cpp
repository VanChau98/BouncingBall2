#include "GamePlayer.h"



GamePlayer::GamePlayer(sf::RenderWindow *window):score(0)
{
	this->m_window = window;
	this->m_player = new Player2(this->m_window);
	this->m_ball = new ball(this->m_window);
	this->m_ball->setPosition(250, 450);
	
	this->m_font.loadFromFile("fonts/MarkerFelt.ttf");
	this->m_text.setFont(this->m_font);
	this->m_text.setCharacterSize(15);
	this->m_text.setString("Score: ");
	this->m_text.setPosition(250, 10);

	RenderBallScore();//Hiển thị vật phẩm
	this->m_luckyBall.push_back(LuckyBall(this->m_window, sf::Color::Green));

}

bool GamePlayer::update()
{
	this->m_player->update();
	this->m_ball->update(0, 500, 0, 720);

	float _x = abs(this->m_ball->getPosition().x - this->m_player->getPosition().x);
	float _y = abs(this->m_ball->getPosition().y - this->m_player->getPosition().y);
	if (_x <= 65 && _y <= 20)
	{
		this->m_ball->update(0, 500, 0, 695);
		if (this->m_ball->getSpeed() < 0.1f)
			this->m_ball->setSpeed(this->m_ball->getSpeed() + this->m_ball->getSpeed()*0.1);
		else this->m_ball->setSpeed(0.1f);
	}
	if (this->m_ball->getPosition().y >= 700)
	{
		this->m_player->getCountHeart()--;
		this->m_ball->setPosition(250,450);
		this->m_ball->setSpeed(0.03f);
	}

	if (this->m_threat.size() > 0)
	{
		for (std::list<Threat>::iterator it = this->m_threat.begin(); it != this->m_threat.end(); it++)
		{
			int x = abs(this->m_ball->getPosition().x - it->getPosition().x);
			int y = abs(this->m_ball->getPosition().y - it->getPosition().y);

			if (x <= 20 && y <= 20)
			{
				this->m_threat.erase(it);
				this->score += 10;
				break;
			}
		}

	}
	this->m_text.setString("Score: " + std::to_string(this->score));
	
	if (this->m_luckyBall.size() > 0)
	{
		for (std::list<LuckyBall>::iterator it = this->m_luckyBall.begin(); it != this->m_luckyBall.end(); it++)
		{
			it->update();

			int x = std::abs(this->m_ball->getPosition().x - it->getPosition().x);
			int y = std::abs(this->m_ball->getPosition().y - it->getPosition().y);
			if (x <= 20 && y <= 20)
			{
				if (it->getColor() == sf::Color::Green)
					this->score = this->score * 2;
				if (it->getColor() == sf::Color::Cyan)
					this->score += this->score * 0.5;
				if (it->getColor() == sf::Color::White)
					this->score = this->score * 0.5;
				this->m_luckyBall.erase(it);
				break;
			}
		}
	}

	this->m_time = this->m_clock.getElapsedTime();
	if (this->m_time.asSeconds() > 5)
	{
		switch (std::rand()%3)
		{
		case 1:
			this->m_luckyBall.push_back(LuckyBall(this->m_window, sf::Color::Green));
			break;
		case 2:
			this->m_luckyBall.push_back(LuckyBall(this->m_window, sf::Color::Cyan));
			break;
		case 3:
			this->m_luckyBall.push_back(LuckyBall(this->m_window, sf::Color::White));
			break;
		}
		this->m_clock.restart();
	}



	if (this->m_player->getCountHeart()<0)
	{
		std::string Information = "Your Score: " + std::to_string(this->score);
		if (MessageBox(NULL, Information.c_str(), "Game Over", MB_OKCANCEL) == IDOK)
			return false;
		else return false;
	}

}

void GamePlayer::draw()
{
	this->m_player->draw();
	this->m_ball->draw();
	if (this->m_threat.size() > 0)
	{
		DrawBallLine();
	}
	this->m_window->draw(this->m_text);

	for (std::list<LuckyBall>::iterator it = this->m_luckyBall.begin(); it != this->m_luckyBall.end(); it++)
	{
		it->draw();
	}
}
void GamePlayer::RenderBallScore()
{
	for (int i = 0; i < 36; i++) {
		this->m_threat.push_back(Threat(this->m_window));
	}
	int i = 0, j= 100;
	int dem = 0;
	for (std::list<Threat>::iterator it = this->m_threat.begin(); it != this->m_threat.end(); it++)
	{
		it->update(30 + i, j);
		i += 40;
		dem++;
		if (dem == 12)
		{
			i = 0;
			j += 100;
			dem = 0;
		}
	}

}

void GamePlayer::DrawBallLine()
{
	int i = 0, j = 100;
	int dem = 0;
	for (std::list<Threat>::iterator it = this->m_threat.begin(); it != this->m_threat.end(); it++)
	{
		it->draw();
		i += 40;
		dem++;
		if (dem == 12)
		{
			i = 0;
			j += 100;
			dem = 0;
		}
	}
}
