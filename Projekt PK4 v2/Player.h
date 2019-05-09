#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "WorldObject.h"

enum Dir
{
	left,right,stat_left,stat_right
};


class Player :public WorldObject
{
public:
	Player(SpriteInfo& info, sf::Vector2f pos);
	void update();
	void draw(sf::RenderTarget& target);
	void handleEvents(sf::Event& event);
	bool ContactBegin(std::weak_ptr<ICollideable> object, bool fromLeft, bool fromTop);
private:
	bool onGround;
	enum Dir Direction;		//do animacji
};

#endif // PLAYER_H