#include "Pause.h"



Pause::Pause(int LvlCount):pointer(0)
{
	mScreenObjects.push_back(std::make_shared<SpriteObject>(Assets::sprites["pause"], sf::Vector2f(0, 0)));
	mScreenObjects.push_back(std::make_shared<SpriteObject>(Assets::sprites["pointer"], sf::Vector2f(400, 0)));
	mScreenObjects.push_back(std::make_shared<SpriteObject>(Assets::sprites["buttonbig"], sf::Vector2f(500, 500)));
	mScreenObjects.push_back(std::make_shared<SpriteObject>(Assets::sprites["buttonbig"], sf::Vector2f(500, 152)));
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 10; j++) {
			if (LvlCount > 0) {
				auto newObj = std::make_shared<SpriteObject>(Assets::sprites["buttonsmall"], sf::Vector2f(100 + i * 550, 320 + j * 80));
				mScreenObjects.push_back(newObj);
			}
			LvlCount--;
		}
	}

}

void Pause::update()
{
	for (auto& obj : mScreenObjects) {
		obj->update();
	}
	mScreenObjects[1]->setPosition(sf::Vector2f(mScreenObjects[pointer]->getRenderPosition().x - 100, mScreenObjects[pointer]->getRenderPosition().y));
}

void Pause::draw(sf::RenderTarget & target)
{
	for (auto& obj : mScreenObjects)
		obj->SpriteObject::draw(target);
}

void Pause::handleEvents(sf::Event & event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::W) {
			pointer--;
		}
		else if (event.key.code == sf::Keyboard::S) {
			pointer++;
		}
		else if (event.key.code == sf::Keyboard::Enter) {
			//switch do odpowiedniej akcji
		}

		if (pointer < 0) {
			pointer = mScreenObjects.size();
		}
		else if(pointer > mScreenObjects.size()){
			pointer = 0;
		}
	}
}
