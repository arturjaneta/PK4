#pragma once
#include <map>
#include "SpriteInfo.h"

struct Assets
{
	static void loadAssets();
	static std::map<std::string, SpriteInfo> sprites;
};
