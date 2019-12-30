#include "GameComputer.h"

GameComputer::GameComputer(sf::RenderWindow *window) :score(0)
{
	this->m_window = window;
	this->m_player = new BBComputer(this->m_window);
	this->m_ball = new ball(this->m_window);
	this->m_ball->setPosition(250, 450);

	this->m_font.loadFromFile("fonts/MarkerFelt.ttf");
	this->m_text.setFont(this->m_font);
	this->m_text.setCharacterSize(15);
	this->m_text.setString("Score: ");
	this->m_text.setPosition(250, 10);

	RenderBallScore();//Hiển thị vật phẩm
	//this->m_luckyBall.push_back(LuckyBall(this->m_window, sf::Color::Green));

}

bool GameComputer::update()
{
	sf::Vector2f pos = this->m_ball->getPosition();
	this->m_player->update(pos);
	this->m_ball->update(0, 500, 0, 720);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		return saveGame();
	}
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
		this->m_ball->setPosition(250, 450);
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
				if (it->getColor() == sf::Color::Green) //Bóng xanh 50 điểm
					this->score += 50;
				if (it->getColor() == sf::Color::Cyan)	//Bóng xanh dương cộng 0.5 điểm
					this->score += this->score * 0.5;
				if (it->getColor() == sf::Color::White)	//Bóng trắng trừ 1/2 điểm
					this->score = this->score * 0.5;
				this->m_luckyBall.erase(it);
				break;
			}
		}
	}

	this->m_time = this->m_clock.getElapsedTime();
	if (this->m_time.asSeconds() > 3)
	{
		sf::Vector2f temp = getPositionThreat();
		switch (std::rand() % 3)
		{
		case 1:
			this->m_luckyBall.push_back(LuckyBall(this->m_window, sf::Color::Green, temp.x, temp.y));
			break;
		case 2:
			this->m_luckyBall.push_back(LuckyBall(this->m_window, sf::Color::Cyan, temp.x, temp.y));
			break;
		case 3:
			this->m_luckyBall.push_back(LuckyBall(this->m_window, sf::Color::White, temp.x, temp.y));
			break;
		}
		this->m_clock.restart();
	}

	//sf::sleep(sf::milliseconds(3000));
	if (this->m_player->getCountHeart() < 0 )
	{
		return saveGame();
	}

}

void GameComputer::draw()
{
	this->m_player->draw();
	this->m_ball->draw();
	if (this->m_threat.size() > 0)
	{
		DrawBallLine();
	}
	for (std::list<LuckyBall>::iterator it = this->m_luckyBall.begin(); it != this->m_luckyBall.end(); it++)
	{
		it->draw();
	}
	this->m_window->draw(this->m_text);
}
void GameComputer::RenderBallScore()
{
	for (int i = 0; i < 36; i++) {
		this->m_threat.push_back(Threat(this->m_window));
	}
	int i = 0, j = 100;
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

void GameComputer::DrawBallLine()
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

sf::Vector2f GameComputer::getPositionThreat()
{
	sf::Vector2f temp;
	std::srand(time(NULL));
	float a, b;
	for (std::list<Threat>::iterator it = this->m_threat.begin(); it != this->m_threat.end(); it++)
	{
		float x = it->getPosition().x;
		float y = it->getPosition().y;
		do {
			a = std::rand() % 450 + 50;
			b = std::rand() % 350 + 50;
		} while (abs(a - x) <= 30 && abs(b - y) <= 30);
		temp.x = a;
		temp.y = b;
	}
	return temp;
}

bool GameComputer::saveGame()
{
	sf::RenderWindow SaveGame(sf::VideoMode(400, 200), "Save Game", sf::Style::Close);
	SaveGame.setFramerateLimit(60);
	tgui::Gui savegui;
	savegui.setTarget(SaveGame);

	tgui::TextBox::Ptr username = tgui::TextBox::create();
	username->setTextSize(15);
	username->setSize(200, 30);
	username->setPosition(130, 50);

	tgui::TextBox::Ptr pass = tgui::TextBox::create();
	pass->setTextSize(15);
	pass->setSize(200, 30);
	pass->setPosition(130, 100);

	tgui::Button::Ptr save = tgui::Button::create("Save Game");
	save->setSize(100, 30);
	save->setPosition(150, 150);

	sf::Text usertext;
	sf::Text passtext;
	usertext.setFont(this->m_font);
	usertext.setCharacterSize(18);
	usertext.setString("Username:");
	usertext.setPosition(50, 55);

	passtext.setFont(this->m_font);
	passtext.setCharacterSize(18);
	passtext.setString("Password:");
	passtext.setPosition(50, 105);

	savegui.add(username);
	savegui.add(pass);
	savegui.add(save);

	save->connect("pressed", [&]() {
		std::string name = username->getText().toAnsiString();
		std::string Pass = pass->getText().toAnsiString();
		if (name.length() == 0 || Pass.length() == 0)
		{
			Report();
		}
		else {
			std::ofstream user("user.txt", std::ios::app);
			user << name << Pass << std::to_string(this->score) << std::endl;
			user.close();
			SaveGame.close();
		}
	});

	while (SaveGame.isOpen())
	{
		sf::Event event;
		while (SaveGame.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				SaveGame.close();
				return false;
			}
			savegui.handleEvent(event);
		}
		SaveGame.clear(sf::Color::Black);
		savegui.draw();
		SaveGame.draw(usertext);
		SaveGame.draw(passtext);
		SaveGame.display();


	}
}
void GameComputer::Report()
{
	sf::RenderWindow report(sf::VideoMode(350, 150), "Thong Bao", sf::Style::Close);
	report.setFramerateLimit(60);
	tgui::Gui gui;
	gui.setTarget(report);

	sf::Text rep;
	rep.setFont(this->m_font);
	rep.setString("Ban chua nhap Username or Password!");
	rep.setCharacterSize(16);
	rep.setFillColor(sf::Color::Red);
	rep.setPosition(50, 40);

	tgui::Button::Ptr ok = tgui::Button::create("OK");
	ok->setPosition(125, 100);
	ok->setSize(100, 30);
	gui.add(ok);

	ok->connect("pressed", [&]() {
		report.close();
	});

	while (report.isOpen())
	{
		sf::Event event;
		while (report.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				report.close();
		}
		report.clear(sf::Color::White);
		gui.handleEvent(event);
		report.draw(rep);
		gui.draw();
		report.display();
	}
}