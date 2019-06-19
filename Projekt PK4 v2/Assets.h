#pragma once
#include <map>
#include "SpriteInfo.h"

struct Assets
{
	static void LoadAssets(std::string path);
	static std::map<std::string, SpriteInfo> Sprites;
};
