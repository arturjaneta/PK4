#include "GameCreator.h"
#define resolutionx 1920
#define resolutiony 1080

GameCreator::GameCreator()
{
	window = std::make_shared<sf::RenderWindow>(sf::VideoMode(resolutionx, resolutiony), "Platformowka 2D", sf::Style::Fullscreen);
	Assets::loadAssets();
	pScreen = Pause(world.GetWorldsCount());
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
