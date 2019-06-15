#pragma once
#include "World.h"

class WorldManager
{
	int ActualWorldNb;
	int WorldsCount;
	std::shared_ptr<World> ActualWorld;
	Settings set;
public:
	WorldManager() {};
	WorldManager(Settings set);
	void SetWorld(int World_nb);
	void SetNextWorld();
	int GetWorldsCount() { return WorldsCount; }
	int GetActualWorldNb() { return ActualWorldNb; }
	std::shared_ptr<World> GetActualWorld() { return ActualWorld; }
};

