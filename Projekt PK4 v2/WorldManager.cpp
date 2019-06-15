#include "WorldManager.h"
#include <string>
#include <fstream>

void WorldManager::SetWorld(int World_nb)
{
	std::string path, path_1, path_2;
	path_1 = "Content/Worlds/world";
	path_2 = ".txt";
	if (World_nb > WorldsCount - 1) {
		ActualWorld = std::make_shared<World>("Content/Worlds/world0.txt",set);	//od poczatku
		ActualWorldNb = 0;
		return;
	}
	else if (World_nb < 0) {
		return;
	}
	path = path_1 + std::to_string(World_nb) + path_2;
	ActualWorld = std::make_shared<World>(path,set);
	ActualWorldNb = World_nb;
}


WorldManager::WorldManager(Settings _set):ActualWorldNb(0)
{
	set = _set;
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
	SetWorld(0);//zaczynamy od 1 swiata
}



void WorldManager::SetNextWorld()
{
	SetWorld(ActualWorldNb + 1);
}


