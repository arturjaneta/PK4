#include "Assets.h"
#include <fstream>

std::map<std::string, SpriteInfo> Assets::Sprites;				//mapa zawierajaca nazwy oraz informacje np o animacjach

void Assets::LoadAssets(std::string fpath)
{
	std::ifstream file(fpath);
	std::string id = "";
	std::string path = "";
	float tmp,tmp2,tmp3,tmp4;
	file >> id;
	file >> path;
	file >> tmp;
	file >> tmp2;
	Sprites[id] = SpriteInfo(path, tmp, tmp2);
	file >> tmp;
	file >> tmp2;
	file >> tmp3;
	file >> tmp4;
	Sprites[id].HitBox = sf::FloatRect(tmp, tmp2, tmp3, tmp4);
	while (!file.eof()) {
		file >> id;
		file >> path;
		Sprites[id] = SpriteInfo(path);
	}
}

