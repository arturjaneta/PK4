#pragma once
#include "WorldObject.h"
#include "Player.h"

class Enemy:public WorldObject
{
	enum Dir direction;
	int Shift;
	sf::Vector2f FirstPosition;

public:	
	Enemy(SpriteInfo& info, sf::Vector2f pos, int shift);
	void update();
	void draw(sf::RenderTarget& target);
};

