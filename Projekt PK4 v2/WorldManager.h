#pragma once
#include "World.h"

class WorldManager
{
	int ActualWorldNb;
	int WorldsCount;
	std::shared_ptr<World> ActualWorld;
	Settings Set;
public:
	WorldManager() {};
	WorldManager(Settings set);
	void setWorld(int World_nb);
	void setNextWorld();
	int getWorldsCount() { return WorldsCount; }
	int getActualWorldNb() { return ActualWorldNb; }
	std::shared_ptr<World> getActualWorld() { return ActualWorld; }
};

