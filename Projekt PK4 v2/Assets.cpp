#include "Assets.h"

std::map<std::string, SpriteInfo> Assets::Sprites;				//mapa zawierajaca nazwy oraz informacje np o animacjach

void Assets::LoadAssets()
{
	Sprites["background"] = SpriteInfo("Content/Textures/background.png");
	Sprites["background2"] = SpriteInfo("Content/Textures/background2.png");
	Sprites["exit"] = SpriteInfo("Content/Textures/exit.png");
	Sprites["pause"] = SpriteInfo("Content/Textures/pause.png");
	Sprites["player"] = SpriteInfo("Content/Textures/player.png", 32, 8);
	Sprites["player"].HitBox = sf::FloatRect(18.f, 6.f, 28.f, 56.f);
	Sprites["pointer"] = SpriteInfo("Content/Textures/pointer.png");
	Sprites["buttonbig1"] = SpriteInfo("Content/Textures/buttonbig1.png");
	Sprites["buttonbig2"] = SpriteInfo("Content/Textures/buttonbig2.png");
	Sprites["buttonsmall"] = SpriteInfo("Content/Textures/buttonsmall.png");
	Sprites["acid"] = SpriteInfo("Content/Textures/acid.png");
	Sprites["bigbox"] = SpriteInfo("Content/Textures/bigbox.png");
	Sprites["enemy"] = SpriteInfo("Content/Textures/enemy.png",2,2);
	Sprites["enemy"].HitBox = sf::FloatRect(0.f, 0.f, 89.f, 98.f);
	Sprites["filar"] = SpriteInfo("Content/Textures/filar.png");
	Sprites["kolce_dol"] = SpriteInfo("Content/Textures/kolce_dol.png");
	Sprites["kolce_gora"] = SpriteInfo("Content/Textures/kolce_gora.png");
	Sprites["kolce_lewa"] = SpriteInfo("Content/Textures/kolce_lewa.png");
	Sprites["kolce_prawa"] = SpriteInfo("Content/Textures/kolce_prawa.png");
	Sprites["platforma3x_pion"] = SpriteInfo("Content/Textures/platforma3x_pion.png");
	Sprites["platforma3x_poziom"] = SpriteInfo("Content/Textures/platforma3x_poziom.png");
	Sprites["ramka_pionowo"] = SpriteInfo("Content/Textures/ramka_pionowo.png");
	Sprites["ramka_poziomo"] = SpriteInfo("Content/Textures/ramka_poziomo.png");
	Sprites["saw1"] = SpriteInfo("Content/Textures/saw1.png");
	Sprites["saw2"] = SpriteInfo("Content/Textures/saw2.png");
	Sprites["saw3"] = SpriteInfo("Content/Textures/saw3.png");
	Sprites["smallbox"] = SpriteInfo("Content/Textures/smallbox.png");
	Sprites["stair_l"] = SpriteInfo("Content/Textures/stair_l.png");
	Sprites["stair_r"] = SpriteInfo("Content/Textures/stair_r.png");
	Sprites["Tile"] = SpriteInfo("Content/Textures/Tile.png");
}
