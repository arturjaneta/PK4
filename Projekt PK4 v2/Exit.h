#pragma once
#include "WorldObject.h"
class Exit :public WorldObject
{
public:
	Exit(SpriteInfo& info, sf::Vector2f pos,Settings set);
	void Update();
	void Draw(sf::RenderTarget& target);
};

