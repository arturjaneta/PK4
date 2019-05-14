#pragma once
#include "World.h"

class WorldManager
{
	int ActualWorldNb;
	int WorldsCount;
	World ActualWorld;
	std::vector<std::shared_ptr<World>> mWorlds;
public:
	WorldManager(int LvlCount);
	void SetWorld(int World_nb);
	int GetWorldsCount() { return WorldsCount; }
	int GetActualWorldNb() { return ActualWorldNb; }
	World GetActualWorld() { return ActualWorld; }
};

