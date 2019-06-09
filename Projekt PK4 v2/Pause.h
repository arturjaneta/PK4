#pragma once
#include <SFML/Graphics.hpp>
#include "SpriteObject.h"
#include "Assets.h"
#include <SFML/Window.hpp>
#include "WorldManager.h"

class Pause
{
	int pointer;
	int WorldsCount;
	std::vector<std::shared_ptr<SpriteObject>> mButtons;
	std::shared_ptr<SpriteObject > mPointer;
	std::shared_ptr<SpriteObject > mBackground;
public:
	Pause(int LvlCount=1);
	void update();
	void draw(sf::RenderTarget& target);
	int handleEvents(sf::Event& event,WorldManager& world);
};

