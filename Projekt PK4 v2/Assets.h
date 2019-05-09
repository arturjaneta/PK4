#pragma once
#ifndef ASSETS_H
#define ASSETS_H

#include <map>

#include "SpriteInfo.h"

struct Assets
{
	static void loadAssets();

	static std::map<std::string, SpriteInfo> sprites;
};

#endif // ASSETS_H