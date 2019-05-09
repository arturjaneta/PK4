#pragma once
#ifndef IRENDERABLE_H
#define IRENDERABLE_H

#include <SFML/Graphics/RenderTarget.hpp>

class IRenderable
{
public:
	IRenderable() {}

	virtual void update() = 0;
	virtual void draw(sf::RenderTarget& target) = 0;
};

#endif // IRENDERABLE_H