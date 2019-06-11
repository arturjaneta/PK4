#include "Pause.h"
#include "Settings.h"
#include <iostream>

Pause::Pause(Settings _set,int LvlCount):pointer(0),set(_set)
{
	WorldsCount = LvlCount;
	mBackground=std::make_shared<SpriteObject>(Assets::sprites["pause"], sf::Vector2f(0, 0));
	mButtons.push_back(std::make_shared<SpriteObject>(Assets::sprites["buttonbig2"], sf::Vector2f((set.getResolutionX() - Assets::sprites["buttonbig2"].mFrameDim.x)/2, 0)));
	mButtons.push_back(std::make_shared<SpriteObject>(Assets::sprites["buttonbig1"], sf::Vector2f((set.getResolutionX() - Assets::sprites["buttonbig2"].mFrameDim.x) / 2, Assets::sprites["buttonbig2"].mFrameDim.y+12)));
	mPointer = std::make_shared<SpriteObject>(Assets::sprites["pointer"], sf::Vector2f(mButtons[0]->getRenderPosition().x- (Assets::sprites["pointer"].mFrameDim.x+12), 0));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; Assets::sprites["buttonsmall"].mFrameDim.x +j* (Assets::sprites["buttonsmall"].mFrameDim.y+4) < set.getResolutionY(); j++) {
			if (LvlCount > 0) {
				auto newObj = std::make_shared<SpriteObject>(Assets::sprites["buttonsmall"], sf::Vector2f(i * Assets::sprites["buttonsmall"].mFrameDim.x +(i+1)*(set.getResolutionX() -3* Assets::sprites["buttonsmall"].mFrameDim.x)/4, 2*(Assets::sprites["buttonbig2"].mFrameDim.y + 12)+40+ j * (Assets::sprites["buttonsmall"].mFrameDim.y + 4)));
				mButtons.push_back(newObj);
			}
			LvlCount--;
		}
	}
}
void Pause::update()
{
	mPointer->setPosition(mButtons[pointer]->getRenderPosition()-sf::Vector2f((Assets::sprites["pointer"].mFrameDim.x + 12), -(mButtons[pointer]->getSpriteInfo().mHitBox.height- Assets::sprites["buttonsmall"].mFrameDim.y)/2));
	for (auto& obj : mButtons) {
		obj->update();
	}
	mBackground->update();
	mPointer->update();
}
void Pause::draw(sf::RenderTarget & target)
{
	mBackground->draw(target);
	for (auto& obj : mButtons)
		obj->SpriteObject::draw(target);
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
				text.setPosition(sf::Vector2f(255+ i * Assets::sprites["buttonsmall"].mFrameDim.x + (i + 1)*(set.getResolutionX() - 3* Assets::sprites["buttonsmall"].mFrameDim.x) / 4, 2 * (Assets::sprites["buttonbig2"].mFrameDim.y + 12) + 50 + j * (Assets::sprites["buttonsmall"].mFrameDim.y + 4)));
				target.draw(text);
			}
			tmp++;
		}
	}
	mPointer->draw(target);
}
int Pause::handleEvents(sf::Event & event,WorldManager& world)
{
	int tmp = 1;
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::W) {
			pointer--;
		}else if (event.key.code == sf::Keyboard::S) {
			pointer++;
		}
		if (event.key.code == sf::Keyboard::Enter) {
			switch (pointer) //switch do odpowiedniej akcji
			{
			case 0: tmp=0;	//resume
					break;
			case 1: tmp=2;	//exit
				break;
			default:
				world.SetWorld(pointer - 2);		//world change
				tmp = 0;
				break;
			}
		}
		if (pointer < 0) {
			pointer = mButtons.size()-1;
		}
		else if(pointer >= mButtons.size()){
			pointer = 0;
		}
	}
	std::cout << tmp;
	return tmp;
}
