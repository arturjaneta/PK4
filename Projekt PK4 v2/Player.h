#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "WorldObject.h"

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
};

#endif // PLAYER_H