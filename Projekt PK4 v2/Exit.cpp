#include "Exit.h"

Exit::Exit(SpriteInfo & info, sf::Vector2f pos,Settings set) :
	WorldObject(info, pos,set)
{
}
void Exit::Update()
{
	SpriteObject::Update();

	OldPhysicsPosition = PhysicsPosition;		//zapisanie poprzedniej pozycji
	PhysicsPosition += Velocity;				//ustawienie nowej pozycji
}

void Exit::Draw(sf::RenderTarget & target)
{
	SpriteObject::Draw(target);
	RenderPosition = PhysicsPosition;
}
