#include "WorldManager.h"
#include "World.h"
#include <fstream>
#include "Assets.h"
#include "CollisionHandler.h"

World::World(std::string path, Settings _set):IfExit(false)
{
	Set = _set;
	LoadWorld(path);
	PlayerOne = std::make_shared<Player>(Assets::Sprites["player"], RespawnPoint,Set);
	Collideables.push_back(PlayerOne);
	Gravity = sf::Vector2f(Set.getXgravity(), Set.getYgravity());
}


void World::Update()
{
	//sprawdzenie czy na mapie
	sf::FloatRect tmp = PlayerOne->getHitBox();
	tmp.left += PlayerOne->getPhysicsPosition().x;
	tmp.top += PlayerOne->getPhysicsPosition().y;

	if (!tmp.intersects(sf::FloatRect(0.f, 0.f, Set.getResolutionX(), Set.getResolutionY())))
		PlayerOne->Death(RespawnPoint);
	//grawitacja
	PlayerOne->Update();
	PlayerOne->setVelocity(PlayerOne->getVelocity() + Gravity);
	Exits->Update();
	for (auto& obj : WorldObjects) {
		obj->Update();
		if (!obj->isStatic()) {
			obj->setVelocity(obj->getVelocity() + Gravity);
		}
	}
	for (auto& obj : Traps) {
		obj->Update();
		if (!obj->isStatic()) {
			obj->setVelocity(obj->getVelocity() + Gravity);
		}
	}
	for (auto& obj : Enemies) {
		obj->Update();
		if (!obj->isStatic()) {
			obj->setVelocity(obj->getVelocity() + Gravity);
		}
	}

	// check collisions
	CollisionHandler CollisionHandler;
	CollisionHandler.CollisionChecker(Collideables, PlayerOne, RespawnPoint, IfExit);
}

void World::Draw(sf::RenderTarget& target)
{
	for (auto& obj : WorldObjects)
		obj->Draw(target);
	for (auto& obj : Traps)
		obj->Draw(target);
	for (auto& obj : Enemies)
		obj->Draw(target);
	Exits->Draw(target);
	PlayerOne->Draw(target);
}

void World::HandleEvents(sf::Event& event)
{
	PlayerOne->HandleEvents(event);
}

void World::LoadWorld(std::string path)
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
		x *= Set.getScale();
		y *= Set.getScale();
		RespawnPoint = sf::Vector2f(x*Set.getScale(), y*Set.getScale());
		file >> x >> y;
		x *= Set.getScale();
		y *= Set.getScale();
		auto newObj = std::make_shared<Exit>(Assets::Sprites["exit"], sf::Vector2f(x, y),Set);
		Exits = newObj;
		Collideables.push_back(newObj);
		while (!file.eof())
		{
			file >> id >> x >> y >> z;
			x *= Set.getScale();
			y *= Set.getScale();
			if (z == 'n') {
				auto newObj = std::make_shared<WorldObject>(Assets::Sprites[id], sf::Vector2f(x, y), Set);
				WorldObjects.push_back(newObj);
			}
			else if (z == 't') {
				auto newObj = std::make_shared<Trap>(Assets::Sprites[id], sf::Vector2f(x, y), Set);
				Traps.push_back(newObj);
				Collideables.push_back(newObj);
			}
			else if (z == 'e') {
				int tmp;
				file >> tmp;
				auto newObj = std::make_shared<Enemy>(Assets::Sprites[id], sf::Vector2f(x, y), tmp*Set.getScale(), Set);
				Enemies.push_back(newObj);
				Collideables.push_back(newObj);
			}
			else {
				auto newObj = std::make_shared<WorldObject>(Assets::Sprites[id], sf::Vector2f(x, y), Set);
				WorldObjects.push_back(newObj);
				Collideables.push_back(newObj);
			}
		}
		WorldObjects.pop_back();
		Collideables.pop_back();
	}
}