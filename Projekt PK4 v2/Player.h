#pragma once
#include <SFML/Graphics.hpp>
#include "WorldObject.h"
#include "Settings.h"
enum Dir
{
	left,right,stat_left,stat_right
};


class Player :public WorldObject
{
public:
	Player(SpriteInfo& info, sf::Vector2f pos,Settings _set);
	void update();
	void death(sf::Vector2f pos);
	void draw(sf::RenderTarget& target);
	void handleEvents(sf::Event& event);
	bool ContactBegin(std::weak_ptr<ICollideable> object, bool fromLeft, bool fromTop);
private:
	bool onGround;
	enum Dir Direction;		//do animacji
	Settings set;
};
