#pragma once
#include "memory"
#include "World.h"
#include <iostream>

class CollisionHandler
{
public:
	void ResolveCollision(std::weak_ptr<ICollideable> a, std::weak_ptr<ICollideable> b, std::shared_ptr<Player> mPlayer, sf::Vector2f &respawnPoint, bool &ifExit);
	bool CheckCollision(std::weak_ptr<ICollideable> a, std::weak_ptr<ICollideable> b);
	void CollisionChecker(std::vector<std::weak_ptr<ICollideable>> mCollideables, std::shared_ptr<Player> mPlayer, sf::Vector2f &respawnPoint, bool &ifExit);
};

