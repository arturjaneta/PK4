#include "Trap.h"



Trap::Trap(SpriteInfo & info, sf::Vector2f pos,Settings set) :
	WorldObject(info, pos,set)
{
}

void Trap::Update()
{
	SpriteObject::Update();

	OldPhysicsPosition = PhysicsPosition;		//zapisanie poprzedniej pozycji
	PhysicsPosition += Velocity;				//ustawienie nowej pozycji
}

void Trap::Draw(sf::RenderTarget & target)
{
	SpriteObject::Draw(target);

	RenderPosition = PhysicsPosition;
}

