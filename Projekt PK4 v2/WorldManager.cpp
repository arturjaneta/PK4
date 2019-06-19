#include "WorldManager.h"
#include <string>
#include <fstream>

void WorldManager::setWorld(int World_nb)
{
	std::string path, path_1, path_2;
	path_1 = "Content/Worlds/world";
	path_2 = ".txt";
	if (World_nb > WorldsCount - 1) {
		ActualWorld = std::make_shared<World>("Content/Worlds/world0.txt",Set);	//od poczatku
		ActualWorldNb = 0;
		return;
	}
	else if (World_nb < 0) {
		return;
	}
	path = path_1 + std::to_string(World_nb) + path_2;
	ActualWorld = std::make_shared<World>(path,Set);
	ActualWorldNb = World_nb;
}


WorldManager::WorldManager(Settings _set):ActualWorldNb(0)
{
	Set = _set;
	int i = 0;
	std::fstream file;
	do {
		std::string path, path_1, path_2;
		path_1 = "Content/Worlds/world";
		path_2 = ".txt";
		path = path_1 + std::to_string(i) + path_2;
		file.open(path);
		i++;
	} while (file.good());
	WorldsCount = i;
	setWorld(0);//zaczynamy od 1 swiata
}



void WorldManager::setNextWorld()
{
	setWorld(ActualWorldNb + 1);
}


