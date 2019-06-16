#include "WorldObject.h"


WorldObject::WorldObject(SpriteInfo& info, sf::Vector2f pos,Settings _set) :
	SpriteObject(info, pos, _set),
	ICollideable(info.mHitBox, info.mFrameDim, _set, pos)
{
}

void WorldObject::update()
{
	SpriteObject::update();

	OldPhysicsPosition = PhysicsPosition;				//zapsanie poprzedniej pozycji
	PhysicsPosition += Velocity;						//ustawienie nowej pozycji
}

void WorldObject::draw(sf::RenderTarget& target)
{
	SpriteObject::draw(target);
	RenderPosition = PhysicsPosition;
}