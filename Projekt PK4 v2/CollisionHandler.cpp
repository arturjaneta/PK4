#include "CollisionHandler.h"

auto y_collision(float overlapY, bool fromTop, std::weak_ptr<ICollideable> a)
{
	a.lock()->setVelocity(sf::Vector2f(a.lock()->getVelocity().x, 0.f));
	if (fromTop)
	{
		a.lock()->setPhysicsPosition(sf::Vector2f(a.lock()->getPhysicsPosition().x, a.lock()->getPhysicsPosition().y - overlapY));
	}
	else if (!fromTop)
	{
		a.lock()->setPhysicsPosition(sf::Vector2f(a.lock()->getPhysicsPosition().x, a.lock()->getPhysicsPosition().y + overlapY));
	}
}

auto x_collision(float overlapX, bool fromLeft, std::weak_ptr<ICollideable> a)
{
	a.lock()->setVelocity(sf::Vector2f(0.f, a.lock()->getVelocity().y));
	if (fromLeft)
	{
		a.lock()->setPhysicsPosition(sf::Vector2f(a.lock()->getPhysicsPosition().x - overlapX, a.lock()->getPhysicsPosition().y));
	}
	else if (!fromLeft)
	{
		a.lock()->setPhysicsPosition(sf::Vector2f(a.lock()->getPhysicsPosition().x + overlapX, a.lock()->getPhysicsPosition().y));
	}
}

void calculate_overlap(std::weak_ptr<ICollideable> a, std::weak_ptr<ICollideable> b,bool &fromLeft,bool &fromTop, float &minOverlapX, float &minOverlapY) {
	auto aLeft = a.lock()->getPhysicsPosition().x + a.lock()->getHitBox().left;
	auto aTop = a.lock()->getPhysicsPosition().y + a.lock()->getHitBox().top;
	auto aRight = aLeft + a.lock()->getHitBox().width;
	auto aBottom = aTop + a.lock()->getHitBox().height;

	auto bLeft = b.lock()->getPhysicsPosition().x + b.lock()->getHitBox().left;
	auto bTop = b.lock()->getPhysicsPosition().y + b.lock()->getHitBox().top;
	auto bRight = bLeft + b.lock()->getHitBox().width;
	auto bBottom = bTop + b.lock()->getHitBox().height;

	float overlapLeft{ aRight - bLeft };
	float overlapRight{ bRight - aLeft };
	float overlapTop{ aBottom - bTop };
	float overlapBottom{ bBottom - aTop };

	fromLeft=(std::abs(overlapLeft) < std::abs(overlapRight));
	fromTop=(std::abs(overlapTop) < std::abs(overlapBottom));
	minOverlapX={ fromLeft ? overlapLeft : overlapRight };
	minOverlapY={ fromTop ? overlapTop : overlapBottom };
}

bool special_collision_handler(std::weak_ptr<ICollideable> a, std::weak_ptr<ICollideable> b, std::shared_ptr<Player> mPlayer, sf::Vector2f &RespawnPoint, bool &ifExit,bool fromTop) {
	auto tmp = b.lock();
	auto tmp1 = a.lock();
	if (a.lock() == mPlayer && typeid(*tmp).name() == typeid(Trap).name()) {					//RTTI
		mPlayer->Death(RespawnPoint);
		return true;
	}
	else if (a.lock() == mPlayer && typeid(*tmp).name() == typeid(Exit).name()) {
		ifExit = true;
	}
	if (a.lock() == mPlayer && typeid(*tmp).name() == typeid(Enemy).name()) {					//RTTI
		if (fromTop) {
			b.lock()->setPhysicsPosition(sf::Vector2f(500, 1500));	// poza ekran
			b.lock()->setVelocity(sf::Vector2f(0, 0));
			b.lock()->setStatic(true);
			return true;
		}
		else {
			mPlayer->Death(RespawnPoint);
			return true;
		}
	}
	else if ((b.lock() == mPlayer && typeid(*tmp1).name() == typeid(Enemy).name()))
	{
		if (!fromTop) {
			a.lock()->setPhysicsPosition(sf::Vector2f(500, 1500));		//poza ekran
			a.lock()->setVelocity(sf::Vector2f(0, 0));
			a.lock()->setStatic(true);
			return true;
		}
		else {
			mPlayer->Death(RespawnPoint);
			return true;
		}
	}
	return false;
}


void CollisionHandler::ResolveCollision(std::weak_ptr<ICollideable> a, std::weak_ptr<ICollideable> b, std::shared_ptr<Player> mPlayer, sf::Vector2f &RespawnPoint, bool &ifExit)
{
	bool fromLeft,fromTop;
	float minOverlapX, minOverlapY;
	calculate_overlap(a,b,fromLeft,fromTop,minOverlapX,minOverlapY);
	if (special_collision_handler(a, b, mPlayer, RespawnPoint, ifExit, fromTop))
		return;

	if (a.lock()->ContactBegin(b, fromLeft, fromTop) && b.lock()->ContactBegin(a, fromLeft, fromTop))
	{
		if (std::abs(minOverlapX) > std::abs(minOverlapY)) // y overlap
		{
			y_collision(minOverlapY, fromTop, a);
		}
		else if (std::abs(minOverlapX) < std::abs(minOverlapY)) // x overlap
		{
			x_collision(minOverlapX, fromLeft, a);
		}
	}
	a.lock()->ContactEnd(b);
	b.lock()->ContactEnd(a);
}

bool CollisionHandler::CheckCollision(std::weak_ptr<ICollideable> a, std::weak_ptr<ICollideable> b)
{
	sf::Vector2f a1 = a.lock()->getPhysicsPosition() + sf::Vector2f(a.lock()->getHitBox().left, a.lock()->getHitBox().top);
	sf::Vector2f a2 = sf::Vector2f(a.lock()->getHitBox().width, a.lock()->getHitBox().height);

	sf::Vector2f b1 = b.lock()->getPhysicsPosition() + sf::Vector2f(b.lock()->getHitBox().left, b.lock()->getHitBox().top);
	sf::Vector2f b2 = sf::Vector2f(b.lock()->getHitBox().width, b.lock()->getHitBox().height);

	sf::FloatRect aRect(a1, a2);
	sf::FloatRect bRect(b1, b2);

	if (aRect.intersects(bRect))
		return true;

	return false;
}

void CollisionHandler::CollisionChecker(std::vector<std::weak_ptr<ICollideable>> mCollideables, std::shared_ptr<Player> mPlayer, sf::Vector2f &RespawnPoint, bool &ifExit) {
	for (std::size_t x = 0; x < mCollideables.size(); x++)
	{
		for (std::size_t y = x + 1; y < mCollideables.size(); y++)
		{
			auto dynamic = mCollideables[x];
			auto _static = mCollideables[y];

			if (!mCollideables[x].lock()->isStatic())
				dynamic = mCollideables[x];
			else if (!mCollideables[y].lock()->isStatic())
				dynamic = mCollideables[y];

			if (mCollideables[x].lock()->isStatic())
				_static = mCollideables[x];
			else if (mCollideables[y].lock()->isStatic())
				_static = mCollideables[y];

			if (CheckCollision(dynamic, _static) && dynamic.lock()->isCollisionActive() && _static.lock()->isCollisionActive() && dynamic.lock() != _static.lock())
				ResolveCollision(dynamic, _static,mPlayer,RespawnPoint,ifExit);
		}
	}
}