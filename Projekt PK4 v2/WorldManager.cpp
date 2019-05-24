#include "WorldManager.h"

#include <string>

WorldManager::WorldManager(int LvlCount):WorldsCount(LvlCount),ActualWorldNb(0)
{
	std::string path,path_1, path_2;
	path_1 = "Content/Worlds/world";
	path_2 = ".txt";
	for (int i = 0; i < LvlCount; i++) {
		path = path_1 + std::to_string(i) + path_2;
		auto newObj = std::make_shared<World>(path);
		mWorlds.push_back(newObj);
	}
	ActualWorld = *mWorlds[0];	//zaczynamy od 1 swiata
}

void WorldManager::SetWorld(int World_nb)
{
	if (World_nb > WorldsCount - 1) {
		//ekarn koncowy
	}
	ActualWorld = *mWorlds[World_nb];
	ActualWorldNb = World_nb;
}


