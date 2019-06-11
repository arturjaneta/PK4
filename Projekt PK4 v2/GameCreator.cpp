#include "GameCreator.h"


GameCreator::GameCreator(int resx,int resy)
{
	set = Settings(resx,resy);
	window = std::make_shared<sf::RenderWindow>(sf::VideoMode(resx, resy), "Platformowka 2D", sf::Style::Fullscreen);
	window->setFramerateLimit(60);
	Assets::loadAssets();
	pScreen = Pause(set,world.GetWorldsCount());
	world.SetWorld(0);
}

void GameCreator::RunGameLoop()
{
	while (window->isOpen())
	{
			sf::Event event;
			while (window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window->close();
				
				if (event.type == sf::Event::KeyPressed&&event.key.code == sf::Keyboard::Escape) {
					std::cout << "PAUSE\n";
					if (pause == 0) {
						pause = 1;
					}
					else {
						pause = 0;
					}
				}
				if (pause != 1)
					world.GetActualWorld()->handleEvents(event);
				else
					pause = pScreen.handleEvents(event, world);
				if (pause == 2)
					window->close();
			}
			if (pause != 1)
				world.GetActualWorld()->update();
		window->clear();
		world.GetActualWorld()->draw(*window);
		if (pause == 1) {
			pScreen.update();
			pScreen.draw(*window);
		}
		window->display();
		if (world.GetActualWorld()->GetIfExit()) {
			world.SetNextWorld();
		}
	}
}

