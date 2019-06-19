#include "Pause.h"
#include "Settings.h"
#include <iostream>

Pause::Pause(Settings _set,int LvlCount):PointerPos(0),Set(_set)
{
	WorldsCount = LvlCount;
	Background=std::make_shared<SpriteObject>(Assets::Sprites["pause"], sf::Vector2f(0, 0), Set);
	Buttons.push_back(std::make_shared<SpriteObject>(Assets::Sprites["buttonbig2"], sf::Vector2f((Set.getResolutionX() - Assets::Sprites["buttonbig2"].FrameDim.x)/2, 0), Set));
	Buttons.push_back(std::make_shared<SpriteObject>(Assets::Sprites["buttonbig1"], sf::Vector2f((Set.getResolutionX() - Assets::Sprites["buttonbig2"].FrameDim.x) / 2, Assets::Sprites["buttonbig2"].FrameDim.y+12), Set));
	Pointer = std::make_shared<SpriteObject>(Assets::Sprites["pointer"], sf::Vector2f(Buttons[0]->getRenderPosition().x- (Assets::Sprites["pointer"].FrameDim.x+12), 0), Set);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; Assets::Sprites["buttonsmall"].FrameDim.x +j* (Assets::Sprites["buttonsmall"].FrameDim.y+4) < Set.getResolutionY(); j++) {
			if (LvlCount > 0) {
				auto newObj = std::make_shared<SpriteObject>(Assets::Sprites["buttonsmall"], sf::Vector2f(i * Assets::Sprites["buttonsmall"].FrameDim.x +(i+1)*(Set.getResolutionX() -3* Assets::Sprites["buttonsmall"].FrameDim.x)/4, 
					2*(Assets::Sprites["buttonbig2"].FrameDim.y + 12)+40+ j * (Assets::Sprites["buttonsmall"].FrameDim.y + 4)), Set);
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
	text.setCharacterSize(40);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::White);
	text.setOutlineColor(sf::Color::Black);
	text.setOutlineThickness(2);
	int tmp = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j <9 ; j++) {
			if (tmp < WorldsCount) {
				text.setString(std::to_string(tmp + 1));
				text.setPosition(sf::Vector2f(255+ i * Assets::Sprites["buttonsmall"].FrameDim.x + (i + 1)*(Set.getResolutionX() - 3* Assets::Sprites["buttonsmall"].FrameDim.x) / 4, 2 * (Assets::Sprites["buttonbig2"].FrameDim.y + 12) + 50 + j * (Assets::Sprites["buttonsmall"].FrameDim.y + 4)));
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
