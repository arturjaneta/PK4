#pragma once

#include "WorldObject.h"
class Enemy:public WorldObject
{
public:
	Enemy(SpriteInfo& info, sf::Vector2f pos);
	void update();
	void draw(sf::RenderTarget& target);
};

