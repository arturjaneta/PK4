#pragma once
#include "WorldObject.h"
#include "Player.h"

class Enemy:public WorldObject
{
	enum Dir Direction;
	int Shift;
	sf::Vector2f FirstPosition;
public:	
	Enemy(SpriteInfo& info, sf::Vector2f pos, int shift,Settings set);
	void Update();
	void Draw(sf::RenderTarget& target);
};

