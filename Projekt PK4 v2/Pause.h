#pragma once
#include <SFML/Graphics.hpp>
#include "SpriteObject.h"
#include "Assets.h"
#include <SFML/Window.hpp>
#include "WorldManager.h"

class Pause
{
	int PointerPos;
	int WorldsCount;
	std::vector<std::shared_ptr<SpriteObject>> Buttons;
	std::shared_ptr<SpriteObject > Pointer;
	std::shared_ptr<SpriteObject > Background;
	Settings Set;
public:
	Pause(Settings set=Settings(),int lvlCount = 1);
	void Update();
	void Draw(sf::RenderTarget& target);
	int HandleEvents(sf::Event& event,WorldManager& world);
};

