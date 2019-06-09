#include "Assets.h"

std::map<std::string, SpriteInfo> Assets::sprites;				//mapa zawierajaca nazwy oraz informacje np o animacjach

void Assets::loadAssets()
{
	sprites["background"] = SpriteInfo("Content/Textures/background.png");
	sprites["exit"] = SpriteInfo("Content/Textures/exit.png");
	sprites["pause"] = SpriteInfo("Content/Textures/pause.png");
	sprites["player"] = SpriteInfo("Content/Textures/player.png", 32, 8);
	sprites["player"].mHitBox = sf::FloatRect(18.f, 6.f, 28.f, 56.f);
	sprites["pointer"] = SpriteInfo("Content/Textures/pointer.png");
	sprites["buttonbig1"] = SpriteInfo("Content/Textures/buttonbig1.png");
	sprites["buttonbig2"] = SpriteInfo("Content/Textures/buttonbig2.png");
	sprites["buttonsmall"] = SpriteInfo("Content/Textures/buttonsmall.png");
	sprites["acid"] = SpriteInfo("Content/Textures/acid.png");
	sprites["bigbox"] = SpriteInfo("Content/Textures/bigbox.png");
	sprites["enemy_left"] = SpriteInfo("Content/Textures/enemy_left.png");
	sprites["enemy_right"] = SpriteInfo("Content/Textures/enemy_right.png");
	sprites["filar"] = SpriteInfo("Content/Textures/filar.png");
	sprites["kolce_dol"] = SpriteInfo("Content/Textures/kolce_dol.png");
	sprites["kolce_gora"] = SpriteInfo("Content/Textures/kolce_gora.png");
	sprites["kolce_lewa"] = SpriteInfo("Content/Textures/kolce_lewa.png");
	sprites["kolce_prawa"] = SpriteInfo("Content/Textures/kolce_prawa.png");
	sprites["platforma3x_pion"] = SpriteInfo("Content/Textures/platforma3x_pion.png");
	sprites["platforma3x_poziom"] = SpriteInfo("Content/Textures/platforma3x_poziom.png");
	sprites["ramka_pionowo"] = SpriteInfo("Content/Textures/ramka_pionowo.png");
	sprites["ramka_poziomo"] = SpriteInfo("Content/Textures/ramka_poziomo.png");
	sprites["saw1"] = SpriteInfo("Content/Textures/saw1.png");
	sprites["saw2"] = SpriteInfo("Content/Textures/saw2.png");
	sprites["saw3"] = SpriteInfo("Content/Textures/saw3.png");
	sprites["smallbox"] = SpriteInfo("Content/Textures/smallbox.png");
	sprites["stair_l"] = SpriteInfo("Content/Textures/stair_l.png");
	sprites["stair_r"] = SpriteInfo("Content/Textures/stair_r.png");
	sprites["Tile"] = SpriteInfo("Content/Textures/Tile.png");
}
