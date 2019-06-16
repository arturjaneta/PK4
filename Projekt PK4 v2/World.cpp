#include "WorldManager.h"
#include "World.h"
#include <fstream>
#include "Assets.h"
#include "CollisionHandler.h"

World::World(std::string path, Settings _set):ifExit(false)
{
	set = _set;
	loadWorld(path);
	mPlayer = std::make_shared<Player>(Assets::sprites["player"], RespawnPoint,set);
	mCollideables.push_back(mPlayer);
	Gravity = sf::Vector2f(set.getXgravity(), set.getYgravity());
}


void World::update()
{
	//sprawdzenie czy na mapie
	sf::FloatRect tmp = mPlayer->getHitBox();
	tmp.left += mPlayer->getPhysicsPosition().x;
	tmp.top += mPlayer->getPhysicsPosition().y;

	if (!tmp.intersects(sf::FloatRect(0.f, 0.f, set.getResolutionX(), set.getResolutionY())))
		mPlayer->death(RespawnPoint);
	//grawitacja
	mPlayer->update();
	mPlayer->setVelocity(mPlayer->getVelocity() + Gravity * 0.0166f);
	mExit->update();
	for (auto& obj : mWorldObjects) {
		obj->update();
		if (!obj->isStatic()) {
			obj->setVelocity(obj->getVelocity() + Gravity * 0.0166f);
		}
	}
	for (auto& obj : mTraps) {
		obj->update();
		if (!obj->isStatic()) {
			obj->setVelocity(obj->getVelocity() + Gravity * 0.0166f);
		}
	}
	for (auto& obj : mEnemies) {
		obj->update();
		if (!obj->isStatic()) {
			obj->setVelocity(obj->getVelocity() + Gravity * 0.0166f);
		}
	}

	// check collisions
	CollisionHandler CollisionHandler;
	CollisionHandler.CollisionChecker(mCollideables, mPlayer, RespawnPoint, ifExit);
}

void World::draw(sf::RenderTarget& target)
{
	for (auto& obj : mWorldObjects)
		obj->draw(target);
	for (auto& obj : mTraps)
		obj->draw(target);
	for (auto& obj : mEnemies)
		obj->draw(target);
	mExit->draw(target);
	mPlayer->draw(target);
}

void World::handleEvents(sf::Event& event)
{
	mPlayer->handleEvents(event);
}

void World::loadWorld(std::string path)
{
	std::ifstream file(path);

	if (file.is_open())
	{
		std::string id = "";
		float x = 0;
		float y = 0;
		char z;
		//respawn
		file >> x >> y;
		x *= set.getScale();
		y *= set.getScale();
		RespawnPoint = sf::Vector2f(x*set.getScale(), y*set.getScale());
		file >> x >> y;
		x *= set.getScale();
		y *= set.getScale();
		auto newObj = std::make_shared<Exit>(Assets::sprites["exit"], sf::Vector2f(x, y),set);
		mExit = newObj;
		mCollideables.push_back(newObj);
		while (!file.eof())
		{
			file >> id >> x >> y >> z;
			x *= set.getScale();
			y *= set.getScale();
			if (z == 'n') {
				auto newObj = std::make_shared<WorldObject>(Assets::sprites[id], sf::Vector2f(x, y), set);
				mWorldObjects.push_back(newObj);
			}
			else if (z == 't') {
				auto newObj = std::make_shared<Trap>(Assets::sprites[id], sf::Vector2f(x, y), set);
				mTraps.push_back(newObj);
				mCollideables.push_back(newObj);
			}
			else if (z == 'e') {
				int tmp;
				file >> tmp;
				auto newObj = std::make_shared<Enemy>(Assets::sprites[id], sf::Vector2f(x, y), tmp*set.getScale(), set);
				mEnemies.push_back(newObj);
				mCollideables.push_back(newObj);
			}
			else {
				auto newObj = std::make_shared<WorldObject>(Assets::sprites[id], sf::Vector2f(x, y), set);
				mWorldObjects.push_back(newObj);
				mCollideables.push_back(newObj);
			}
		}
		mWorldObjects.pop_back();
		mCollideables.pop_back();
	}
}