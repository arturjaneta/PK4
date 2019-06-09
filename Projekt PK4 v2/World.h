#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "Player.h"
#include "WorldObject.h"
#include "IColliderable.h"
#include "Trap.h"
#include "Enemy.h"
#include "Exit.h"


class World
{
public:
	World(std::string path= "Content/Worlds/world0.txt");
	~World() {}

	void update();
	void draw(sf::RenderTarget& target);
	void handleEvents(sf::Event& event);

	bool checkCollision(std::weak_ptr<ICollideable> a, std::weak_ptr<ICollideable> b);
	void resolveCollision(std::weak_ptr<ICollideable> a, std::weak_ptr<ICollideable> b);
	void loadWorld(std::string path);
	bool GetIfExit() { return ifExit; }
private:
	
	std::shared_ptr<Player> mPlayer;
	std::shared_ptr<Exit> mExit;
	std::vector<std::shared_ptr<WorldObject>> mWorldObjects;
	std::vector<std::weak_ptr<ICollideable>> mCollideables;
	std::vector<std::shared_ptr<Trap>> mTraps;
	std::vector<std::shared_ptr<Enemy>> mEnemies;

	sf::Vector2f Gravity;
	sf::Vector2f RespawnPoint;
	bool ifExit;
};

