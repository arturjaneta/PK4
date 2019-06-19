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
	Player(SpriteInfo& info, sf::Vector2f pos,Settings set);
	void Update();
	void Death(sf::Vector2f pos);
	void Draw(sf::RenderTarget& target);
	void HandleEvents(sf::Event& event);
	bool ContactBegin(std::weak_ptr<ICollideable> object, bool fromLeft, bool fromTop);
private:
	bool OnGround;
	enum Dir Direction;		//do animacji
	Settings Set;
};
