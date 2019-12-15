#include "GamePlayer.h"



GamePlayer::GamePlayer(sf::RenderWindow *window):score(0)
{
	this->m_window = window;
	this->m_player = new Player2(this->m_window);
	this->m_ball = new ball(this->m_window);
	for (int i = 0; i < 36; i++) {
		this->m_threat.push_back(Threat(this->m_window));
	}

	this->m_font.loadFromFile("fonts/MarkerFelt.ttf");
	this->m_text.setFont(this->m_font);
	this->m_text.setCharacterSize(15);
	this->m_text.setString("Score: ");
	this->m_text.setPosition(250, 10);

	RenderBallScore();//Hiển thị vật phẩm
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
		this->m_ball->setSpeed(this->m_ball->getSpeed() + this->m_ball->getSpeed()*0.1);
	}
	if (this->m_ball->getPosition().y >= 700)
	{
		this->m_player->getCountHeart()--;
		this->m_ball->setPosition(250,400);
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
		DrawBallScore();
	}
	this->m_window->draw(this->m_text);
}
void GamePlayer::RenderBallScore()
{
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

void GamePlayer::DrawBallScore()
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