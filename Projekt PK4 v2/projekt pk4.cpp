// projekt pk4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Assets.h"
#include "Player.h"
#include "World.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(1600, 900), "Platformowka 2D");
	Assets::loadAssets();

	World world("Content/Worlds/world.txt");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			world.handleEvents(event);
		}

		world.update();

		window.clear();
		world.draw(window);
		window.display();
	}

	return 0;
}
