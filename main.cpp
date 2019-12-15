#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h>
#include <cstdlib>
#include <time.h>
#include "DesignHome.h"
#include "DesignGame.h"
#include "GamePlayerPlayer.h"
#include "GamePlayerComputer.h"
#include "GamePlayer.h"
#include "DesignBouncing.h"


int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	sf::RenderWindow window(sf::VideoMode(400, 600), "Bouncing Ball", sf::Style::Close);
	window.setFramerateLimit(60);
	tgui::Gui gui;
	designHome des(&window);
	gui.setTarget(window);

	std::srand(time(NULL));
	sf::Music music;
	music.openFromFile("music/opengame.ogg");
	music.play();

	tgui::Button::Ptr PP = tgui::Button::create("Player & Player");
	PP->setSize(200, 50);
	PP->setPosition(100, 170);

	tgui::Button::Ptr PC = tgui::Button::create("Player & Computer");
	PC->setSize(200, 50);
	PC->setPosition(100, 240);

	tgui::Button::Ptr BouncingBall = tgui::Button::create("Bouncing Ball");
	BouncingBall->setSize(200, 50);
	BouncingBall->setPosition(100, 310);

	tgui::Button::Ptr quitgame = tgui::Button::create("Quit Game");
	quitgame->setSize(200, 50);
	quitgame->setPosition(100, 380);

	gui.add(PP);
	gui.add(PC);
	gui.add(BouncingBall);
	gui.add(quitgame);


	PP->connect("pressed", [&]() {
		sf::RenderWindow PPWindow(sf::VideoMode(1200, 650), "Player & Player", sf::Style::Close);
		PPWindow.setFramerateLimit(60);
		designGame DG(&PPWindow);
		game Game(&PPWindow);
		while (PPWindow.isOpen())
		{
			sf::Event event;
			while (PPWindow.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					PPWindow.close();

				}
			}

			PPWindow.clear(sf::Color::Transparent);
			DG.update();
			DG.draw();
			if (!Game.update())
				break;
			Game.draw();
			PPWindow.display();

		}

	});

	PC->connect("pressed", [&]() {
		sf::RenderWindow PCWindow(sf::VideoMode(1200, 650), "Player & Player", sf::Style::Close);
		PCWindow.setFramerateLimit(60);
		designGame DG(&PCWindow);
		GamePC Game(&PCWindow);
		while (PCWindow.isOpen())
		{
			sf::Event event;
			while (PCWindow.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					PCWindow.close();

				}
			}

			PCWindow.clear(sf::Color::Transparent);
			DG.update();
			DG.draw();
			//if (!Game.update())
				//break;
			//Game.draw();
			PCWindow.display();

		}

	});

	BouncingBall->connect("pressed", [&]() {
		sf::RenderWindow BouncingWindow(sf::VideoMode(500, 720), "Catch Ball", sf::Style::Close);
		BouncingWindow.setFramerateLimit(60);
		DesignBouncing DB(&BouncingWindow);
		GamePlayer GP(&BouncingWindow);
		while (BouncingWindow.isOpen())
		{
			sf::Event event;
			while (BouncingWindow.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					BouncingWindow.close();
				}
			}
			BouncingWindow.clear(sf::Color::Black);
			DB.update();
			DB.draw();
			if (!GP.update())
				break;
			GP.draw();

			BouncingWindow.display();
		}
	}); 

	quitgame->connect("pressed", [&]() {
		window.close();
	});

	bool checkChooseWindow = true;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::LostFocus)
				checkChooseWindow = false;
			if (event.type == sf::Event::GainedFocus)
				checkChooseWindow = true;
		}

		window.clear(sf::Color::Transparent);
		gui.handleEvent(event);
		des.update();
		des.draw();
		gui.draw();
		window.display();

	}

	return EXIT_SUCCESS;

}
