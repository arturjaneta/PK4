#pragma once
#include "WorldObject.h"
class Exit :public WorldObject
{
public:
	Exit(SpriteInfo& info, sf::Vector2f pos,Settings set);
	void update();
	void draw(sf::RenderTarget& target);
};

