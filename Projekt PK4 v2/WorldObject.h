#pragma once

#include "SpriteObject.h"
#include "IColliderable.h"
class WorldObject : public SpriteObject , public ICollideable
{
public:
	WorldObject(SpriteInfo& info, sf::Vector2f pos,Settings set);
	~WorldObject() {}

	void Update();
	void Draw(sf::RenderTarget& target);

private:
};
