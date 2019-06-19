#pragma once

#include "WorldObject.h"
class Trap:public WorldObject
{
public:
	Trap(SpriteInfo& info, sf::Vector2f pos,Settings set);
	void Update();
	void Draw(sf::RenderTarget& target);
};

