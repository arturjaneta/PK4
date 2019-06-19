#pragma once
#include <SFML/Graphics.hpp>

struct SpriteInfo
{
	SpriteInfo() {}
	SpriteInfo(std::string path, int frames = 1, int framesPerRow = 1) :
		Frames(frames),
		FramesPerRow(framesPerRow)
	{
		Texture.loadFromFile(path);
		FrameDim = sf::Vector2f(Texture.getSize().x / FramesPerRow, Texture.getSize().y / (Frames / FramesPerRow));
		HitBox = sf::FloatRect(0.f, 0.f, FrameDim.x, FrameDim.y);
	}
	sf::Texture Texture;
	int Frames;
	int FramesPerRow;
	sf::Vector2f FrameDim;
	sf::FloatRect HitBox;
};
