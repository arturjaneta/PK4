#pragma once
#include "memory"
#include "World.h"
#include <iostream>

class CollisionHandler
{
public:
	void resolveCollision(std::weak_ptr<ICollideable> a, std::weak_ptr<ICollideable> b, std::shared_ptr<Player> mPlayer, sf::Vector2f &RespawnPoint, bool &ifExit);
	bool checkCollision(std::weak_ptr<ICollideable> a, std::weak_ptr<ICollideable> b);
	void CollisionChecker(std::vector<std::weak_ptr<ICollideable>> mCollideables, std::shared_ptr<Player> mPlayer, sf::Vector2f &RespawnPoint, bool &ifExit);
};

