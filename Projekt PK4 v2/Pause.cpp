#include "Pause.h"
#include <iostream>
#define resolutionx 1920
#define resolutiony 1080

Pause::Pause(int LvlCount):pointer(0)
{
	WorldsCount = LvlCount;
	mBackground=std::make_shared<SpriteObject>(Assets::sprites["pause"], sf::Vector2f(0, 0));
	mButtons.push_back(std::make_shared<SpriteObject>(Assets::sprites["buttonbig2"], sf::Vector2f((resolutionx-600)/2, 0)));
	mButtons.push_back(std::make_shared<SpriteObject>(Assets::sprites["buttonbig1"], sf::Vector2f((resolutionx - 600) / 2, 152)));
	mPointer = std::make_shared<SpriteObject>(Assets::sprites["pointer"], sf::Vector2f(mButtons[0]->getRenderPosition().x-100, 0));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; 400+j*80 < resolutiony; j++) {
			if (LvlCount > 0) {
				auto newObj = std::make_shared<SpriteObject>(Assets::sprites["buttonsmall"], sf::Vector2f(i * 400+(i+1)*(resolutionx-1200)/4, 320 + j * 80));
				mButtons.push_back(newObj);
			}
			LvlCount--;
		}
	}
}
void Pause::update()
{
	mPointer->setPosition(mButtons[pointer]->getRenderPosition()-sf::Vector2f(100, -(mButtons[pointer]->getSpriteInfo().mHitBox.height-76)/2));
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
				text.setPosition(sf::Vector2f(255+ i * 400 + (i + 1)*(resolutionx - 1200) / 4, 330 + j * 80));
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
