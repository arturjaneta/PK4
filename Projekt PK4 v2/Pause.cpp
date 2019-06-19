#include "Pause.h"
#include "Settings.h"
#include <iostream>
#define BigButtonsXpos 660*Set.getScale()
#define BigButtonsYspace 152*Set.getScale()
#define SmallButtonsXpos 580*Set.getScale()
#define SmallButtonsYpos 80*Set.getScale()
#define SmallButtonsXspace 180*Set.getScale()
#define SmallButtonsYspace 320*Set.getScale()
#define PointerLeftSpace 560*Set.getScale()
#define DownSpace 4*Set.getScale()
#define TextSize 40*Set.getScale()

Pause::Pause(Settings set,int LvlCount):PointerPos(0),Set(set)
{
	WorldsCount = LvlCount;
	Background=std::make_shared<SpriteObject>(Assets::Sprites["pause"], sf::Vector2f(0, 0), Set);
	Buttons.push_back(std::make_shared<SpriteObject>(Assets::Sprites["buttonbig2"], sf::Vector2f(BigButtonsXpos, 0), Set));
	Buttons.push_back(std::make_shared<SpriteObject>(Assets::Sprites["buttonbig1"], sf::Vector2f(BigButtonsXpos, BigButtonsYspace), Set));
	Pointer = std::make_shared<SpriteObject>(Assets::Sprites["pointer"], sf::Vector2f(PointerLeftSpace, 0), Set);
	for (int i = 0; i < 3; i++) {		//3 rzedy
		for (int j = 0; Assets::Sprites["buttonsmall"].FrameDim.x +j* (Assets::Sprites["buttonsmall"].FrameDim.y+ DownSpace) < Set.getResolutionY(); j++) {
			if (LvlCount > 0) {
				auto newObj = std::make_shared<SpriteObject>(Assets::Sprites["buttonsmall"], sf::Vector2f(SmallButtonsXspace + i * SmallButtonsXpos, SmallButtonsYspace + j * SmallButtonsYpos),Set);
				Buttons.push_back(newObj);
			}
			LvlCount--;
		}
	}
}
void Pause::Update()
{
	Pointer->setPosition(Buttons[PointerPos]->getRenderPosition()-sf::Vector2f((Assets::Sprites["pointer"].FrameDim.x + 12), -(Buttons[PointerPos]->getSpriteInfo().HitBox.height- Assets::Sprites["buttonsmall"].FrameDim.y)/2));
	
	for_each(Buttons.begin(), Buttons.end(), [](std::shared_ptr<SpriteObject> &button) {button->Update(); });			//algorytmy i iteratiory stl

	Background->Update();
	Pointer->Update();
}
void Pause::Draw(sf::RenderTarget & target)
{
	Background->Draw(target);
	for (auto& obj : Buttons)
		obj->SpriteObject::Draw(target);
	sf::Text text;
	sf::Font font;
	if (!font.loadFromFile("Content/Fonts/Calibri.ttf"))
	{
		std::cout << "Font error\n";
	}
	text.setFont(font);
	text.setCharacterSize(TextSize);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::White);
	text.setOutlineColor(sf::Color::Black);
	text.setOutlineThickness(2);
	int tmp = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; Assets::Sprites["buttonsmall"].FrameDim.x + j * (Assets::Sprites["buttonsmall"].FrameDim.y + DownSpace) < Set.getResolutionY(); j++) {
			if (tmp < WorldsCount) {
				text.setString(std::to_string(tmp + 1));
				text.setPosition(sf::Vector2f(SmallButtonsXspace*2 + i * Assets::Sprites["buttonsmall"].FrameDim.x + (i + 1)*(Set.getResolutionX() - 3* Assets::Sprites["buttonsmall"].FrameDim.x) / 4, 2 * (Assets::Sprites["buttonbig2"].FrameDim.y + 12) + BigButtonsYspace/3 + j * (Assets::Sprites["buttonsmall"].FrameDim.y + 4)));
				target.draw(text);
			}
			tmp++;
		}
	}
	Pointer->Draw(target);
}
int Pause::HandleEvents(sf::Event & event,WorldManager& world)
{
	int tmp = 1;
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::W) {
			PointerPos--;
		}else if (event.key.code == sf::Keyboard::S) {
			PointerPos++;
		}
		if (event.key.code == sf::Keyboard::Enter) {
			switch (PointerPos) //switch do odpowiedniej akcji
			{
			case 0: tmp=0;	//resume
					break;
			case 1: tmp=2;	//exit
				break;
			default:
				world.setWorld(PointerPos - 2);		//world change
				tmp = 0;
				break;
			}
		}
		if (PointerPos < 0) {
			PointerPos = Buttons.size()-1;
		}
		else if(PointerPos >= Buttons.size()){
			PointerPos = 0;
		}
	}
	std::cout << tmp;
	return tmp;
}
