#pragma once
#include <SFML/Graphics.hpp>
#include "SpriteObject.h"
#include "Assets.h"

class Pause
{
	int pointer;
	std::vector<std::shared_ptr<SpriteObject>> mButtons;
	//std::vector<std::shared_ptr<sf::Text>> mLvlText;
	std::shared_ptr<SpriteObject > mPointer;
	std::shared_ptr<SpriteObject > mBackground;
public:
	Pause(int LvlCount);
	void update();
	void draw(sf::RenderTarget& target);
	int handleEvents(sf::Event& event);
};

