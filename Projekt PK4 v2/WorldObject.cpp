#include "WorldObject.h"


WorldObject::WorldObject(SpriteInfo& info, sf::Vector2f pos) :
	SpriteObject(info, pos),
	ICollideable(info.mHitBox, info.mFrameDim, pos)
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