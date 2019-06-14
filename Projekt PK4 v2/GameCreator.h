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
#include <Windows.h>

class GameCreator
{
	std::shared_ptr<sf::RenderWindow> window;
	WorldManager world;
	Pause pScreen;
	Settings set;
	sf::Clock clk;
	sf::Time acc;
	sf::Time step = sf::seconds(1.f / 60.f);
	int pause = 0;
public:
	GameCreator(int resx=1920,int resy=1080);
	void RunGameLoop();
};
