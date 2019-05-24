// projekt pk4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Assets.h"
#include "Player.h"
#include "World.h"
#include "WorldManager.h"
#include "Pause.h"
#include <Windows.h>

#define WorldsCount 2

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Platformowka 2D", sf::Style::Fullscreen);
	Assets::loadAssets();

	WorldManager world(WorldsCount);
	Pause pScreen(world.GetWorldsCount());
	sf::Clock clk;
	sf::Time acc = sf::Time::Zero;
	sf::Time step=sf::seconds(1.f/60.f);
	int pause = 0;
	

	while (window.isOpen())
	{
		sf::Time dt = clk.restart();
		acc += dt;
		while (acc > step) {
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				sf::Time PauseTime = sf::Time::Zero;
				if (event.type == sf::Event::KeyPressed&&event.key.code == sf::Keyboard::Escape) {
					std::cout << "PAUSE\n";
					if (pause == 0) {
						pause = 1;
					}
					else {
						pause = 0;
					}
				}
				if(pause!=1)
				world.GetActualWorld().handleEvents(event);
				else
				pause = pScreen.handleEvents(event,world);
				if (pause == 2)
					window.close();
			}
			if (pause != 1)
				world.GetActualWorld().update();
			acc -= step;
		}
		window.clear();
		world.GetActualWorld().draw(window);
		if (pause == 1) {
			pScreen.update();
			pScreen.draw(window);
		}
		window.display();
		
	}

	return 0;
}

