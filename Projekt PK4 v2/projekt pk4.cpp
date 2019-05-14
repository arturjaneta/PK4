// projekt pk4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Assets.h"
#include "Player.h"
#include "World.h"
#include "Pause.h"
#include <Windows.h>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Platformowka 2D", sf::Style::Fullscreen);
	Assets::loadAssets();

	World world("Content/Worlds/world.txt");
	Pause pScreen(10);
	sf::Clock clk;
	sf::Time acc = sf::Time::Zero;
	sf::Time step=sf::seconds(1.f/60.f);
	int pause = 0;
	
	/*sf::Font font;
	if (!font.loadFromFile("Content/Fonts/Calibri.ttf"))
	{
		std::cout << "Font error\n";
	}*/
	/*sf::Text pointsText;
	pointsText.setString("something");
	pointsText.setFont(font);
	pointsText.setCharacterSize(100);
	pointsText.setStyle(sf::Text::Bold);
	pointsText.setFillColor(sf::Color::Red);
	pointsText.setPosition(sf::Vector2f(0,0));*/

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
				world.handleEvents(event);
				else
				pause = pScreen.handleEvents(event);
				if (pause == 2)
					window.close();
			}
			if (pause != 1)
			world.update();
			acc -= step;
		}
		window.clear();
		world.draw(window);
		if (pause == 1) {
			pScreen.update();
			pScreen.draw(window);
		}
		//window.draw(pointsText);
		window.display();
		
	}

	return 0;
}

//void Board::SetPointsText()
//{
//	pointsText.setFont(font);
//	pointsText.setCharacterSize(20);
//	pointsText.setStyle(sf::Text::Bold);
//	pointsText.setFillColor(sf::Color::Red);
//	sf::FloatRect textRect = pointsText.getLocalBounds();
//	pointsText.setOrigin(textRect.width, textRect.height);
//	pointsText.setPosition(sf::Vector2f(screen.screenWidth * .1f, screen.screenHeight * .95f));
//}