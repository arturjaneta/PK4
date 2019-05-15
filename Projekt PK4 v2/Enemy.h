#pragma once
#include "WorldObject.h"

class Enemy:public WorldObject
{
	int Shift;
	sf::Vector2f FirstPosition;

public:	
	Enemy(SpriteInfo& info, sf::Vector2f pos, int shift);
	void update();
	void draw(sf::RenderTarget& target);
};

