#pragma once
#include <SFML/Graphics/RenderTarget.hpp>

class IRenderable
{
public:
	IRenderable() {}

	virtual void update() = 0;
	virtual void draw(sf::RenderTarget& target) = 0;
};
