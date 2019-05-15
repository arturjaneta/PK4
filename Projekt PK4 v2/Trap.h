#pragma once

#include "WorldObject.h"
class Trap:public WorldObject
{
public:
	Trap(SpriteInfo& info, sf::Vector2f pos);
	void update();
	void draw(sf::RenderTarget& target);
};

