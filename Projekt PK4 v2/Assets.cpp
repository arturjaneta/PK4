
#include "Assets.h"

std::map<std::string, SpriteInfo> Assets::sprites;				//mapa zawierajaca nazwy oraz informacje np o animacjach

void Assets::loadAssets()
{
	sprites["background1"] = SpriteInfo("Content/Textures/background1.jpg");
	sprites["pause"] = SpriteInfo("Content/Textures/pause.png");
	sprites["ammocrate"] = SpriteInfo("Content/Textures/ammocrate.png");
	sprites["player"] = SpriteInfo("Content/Textures/player.png", 36, 6);
	sprites["player"].mHitBox = sf::FloatRect(20.f, 10.f, 24.f, 44.f);
	sprites["enemy"] = SpriteInfo("Content/Textures/enemy.png");
	sprites["pointer"] = SpriteInfo("Content/Textures/pointer.png");
	sprites["buttonbig"] = SpriteInfo("Content/Textures/buttonbig.png");
	sprites["buttonsmall"] = SpriteInfo("Content/Textures/buttonsmall.png");
}
