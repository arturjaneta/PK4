
#include "Assets.h"

std::map<std::string, SpriteInfo> Assets::sprites;				//mapa zawierajaca nazwy oraz informacje np o animacjach

void Assets::loadAssets()
{
	sprites["ammocrate"] = SpriteInfo("Content/Textures/ammocrate.png");
	sprites["player"] = SpriteInfo("Content/Textures/player.png");
}
