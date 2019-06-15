#include "Exit.h"

Exit::Exit(SpriteInfo & info, sf::Vector2f pos,Settings set) :
	WorldObject(info, pos,set)
{
}
void Exit::update()
{
	SpriteObject::update();

	OldPhysicsPosition = PhysicsPosition;		//zapisanie poprzedniej pozycji
	PhysicsPosition += Velocity;				//ustawienie nowej pozycji
}

void Exit::draw(sf::RenderTarget & target)
{
	SpriteObject::draw(target);
	RenderPosition = PhysicsPosition;
}
