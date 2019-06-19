#include "GameCreator.h"


GameCreator::GameCreator(int resx,int resy)
{
	Set = Settings(resx,resy);
	World = WorldManager(Set);
	Window = std::make_shared<sf::RenderWindow>(sf::VideoMode(resx, resy), "Platformowka 2D", sf::Style::Fullscreen);
	Window->setFramerateLimit(Set.getFrameRate());
	Assets::LoadAssets();
	PauseScreen = Pause(Set,World.getWorldsCount());
	World.setWorld(0);	//od pierwszego swiata
}

void GameCreator::RunGameLoop()
{
	while (Window->isOpen())
	{
			sf::Event event;
			while (Window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					Window->close();
				if (event.type == sf::Event::KeyPressed&&event.key.code == sf::Keyboard::Escape) {
					if (Paused == 0) {
						Paused = 1;
					}
					else {
						Paused = 0;
					}
				}
				if (Paused != 1)
					World.getActualWorld()->HandleEvents(event);
				else
					Paused = PauseScreen.HandleEvents(event, World);
				if (Paused == 2)		//exit
					Window->close();
			}
			if (Paused != 1)
				World.getActualWorld()->Update();
		Window->clear();
		World.getActualWorld()->Draw(*Window);
		if (Paused == 1) {
			PauseScreen.Update();
			PauseScreen.Draw(*Window);
		}
		Window->display();
		if (World.getActualWorld()->GetIfExit()) {
			World.setNextWorld();
		}
	}
}

