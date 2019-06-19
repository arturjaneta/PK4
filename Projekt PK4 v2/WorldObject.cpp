#include "WorldObject.h"


WorldObject::WorldObject(SpriteInfo& info, sf::Vector2f pos,Settings _set) :
	SpriteObject(info, pos, _set),
	ICollideable(info.HitBox, info.FrameDim, _set, pos)
{
}

void WorldObject::Update()
{
	SpriteObject::Update();

	OldPhysicsPosition = PhysicsPosition;				//zapsanie poprzedniej pozycji
	PhysicsPosition += Velocity;						//ustawienie nowej pozycji
}

void WorldObject::Draw(sf::RenderTarget& target)
{
	SpriteObject::Draw(target);
	RenderPosition = PhysicsPosition;
}