#pragma once
#include <SFML/Graphics/RenderTarget.hpp>

class IRenderable
{
public:
	IRenderable() {}

	virtual void Update() = 0;
	virtual void Draw(sf::RenderTarget& target) = 0;
};
