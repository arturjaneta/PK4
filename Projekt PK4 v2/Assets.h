#pragma once
#include <map>
#include "SpriteInfo.h"

struct Assets
{
	static void LoadAssets();
	static std::map<std::string, SpriteInfo> Sprites;
};
