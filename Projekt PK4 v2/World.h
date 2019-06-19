#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "Player.h"
#include "WorldObject.h"
#include "IColliderable.h"
#include "Trap.h"
#include "Enemy.h"
#include "Exit.h"
#include "Settings.h"

class World
{
public:
	World(std::string path = "Content/Worlds/world0.txt",Settings set=Settings());
	~World() {}
	void Update();
	void Draw(sf::RenderTarget& target);
	void HandleEvents(sf::Event& event);
	void LoadWorld(std::string path);
	bool GetIfExit() { return IfExit; }
private:
	Settings Set;
	std::shared_ptr<Player> PlayerOne;		//inteligetne wskazniki
	std::shared_ptr<Exit> Exits;
	std::vector<std::shared_ptr<WorldObject>> WorldObjects;
	std::vector<std::weak_ptr<ICollideable>> Collideables;
	std::vector<std::shared_ptr<Trap>> Traps;
	std::vector<std::shared_ptr<Enemy>> Enemies;

	sf::Vector2f Gravity;
	sf::Vector2f RespawnPoint;
	bool IfExit;
};

