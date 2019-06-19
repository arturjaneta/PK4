#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Assets.h"
#include "Player.h"
#include "World.h"
#include "WorldManager.h"
#include "Pause.h"
#include "Settings.h"

class GameCreator
{
	std::shared_ptr<sf::RenderWindow> Window;
	WorldManager World;
	Pause PauseScreen;
	Settings Set;
	int Paused = 0;
public:
	GameCreator(int resx=1920,int resy=1080);
	void RunGameLoop();
};

