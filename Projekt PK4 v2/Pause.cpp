#include "Pause.h"

#include <iostream>

Pause::Pause(int LvlCount):pointer(0)
{
	/*int lvlnb=1;
	sf::Font font;
	if (!font.loadFromFile("Content/Fonts/Calibri.ttf"))
	{
		std::cout << "Font error\n";
	}*/
	mPointer = std::make_shared<SpriteObject>(Assets::sprites["pointer"], sf::Vector2f(560, 0));
	mBackground=std::make_shared<SpriteObject>(Assets::sprites["pause"], sf::Vector2f(0, 0));
	mButtons.push_back(std::make_shared<SpriteObject>(Assets::sprites["buttonbig2"], sf::Vector2f(660, 0)));
	mButtons.push_back(std::make_shared<SpriteObject>(Assets::sprites["buttonbig1"], sf::Vector2f(660, 152)));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 9; j++) {
			if (LvlCount > 0) {
				/*auto text=std::make_shared<sf::Text>(std::to_string(lvlnb),font,40);
				text->setPosition(180 + i * 580, 320 + j * 80);
				text->setFillColor(sf::Color::White);
				mLvlText.push_back(text);*/
				auto newObj = std::make_shared<SpriteObject>(Assets::sprites["buttonsmall"], sf::Vector2f(180 + i * 580, 320 + j * 80));
				mButtons.push_back(newObj);
				//lvlnb++;
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
	/*for (auto& obj : mLvlText)
		target.draw(*obj);*/
	mPointer->draw(target);
	
}

int Pause::handleEvents(sf::Event & event)
{
	int tmp = 1;
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::W) {
			pointer--;
		}
		else if (event.key.code == sf::Keyboard::S) {
			pointer++;
		}

		if (event.key.code == sf::Keyboard::E) {
			//switch do odpowiedniej akcji
			switch (pointer) 
			{
			case 0: tmp=0;
					break;
			case 1: tmp=2;
				break;
			default://load wold pointer-2
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
