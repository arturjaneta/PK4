#pragma once
#include <SFML/Graphics.hpp>
#include "SpriteObject.h"
#include "Assets.h"
class Pause
{
	int pointer;
	std::vector<std::shared_ptr<SpriteObject>> mScreenObjects;
public:
	Pause(int LvlCount);
	void update();
	void draw(sf::RenderTarget& target);
	void handleEvents(sf::Event& event);
};

