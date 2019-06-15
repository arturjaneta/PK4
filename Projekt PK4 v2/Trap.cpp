#include "Trap.h"



Trap::Trap(SpriteInfo & info, sf::Vector2f pos,Settings set) :
	WorldObject(info, pos,set)
{
}

void Trap::update()
{
	SpriteObject::update();

	OldPhysicsPosition = PhysicsPosition;		//zapisanie poprzedniej pozycji
	PhysicsPosition += Velocity;				//ustawienie nowej pozycji
}

void Trap::draw(sf::RenderTarget & target)
{
	SpriteObject::draw(target);

	RenderPosition = PhysicsPosition;
}

