#include "Enemy.h"



Enemy::Enemy(SpriteInfo & info, sf::Vector2f pos) :
	WorldObject(info, pos)
{
}

void Enemy::update()
{
	SpriteObject::update();

	OldPhysicsPosition = PhysicsPosition;		//zapisanie poprzedniej pozycji
	PhysicsPosition += Velocity;				//ustawienie nowej pozycji
}

void Enemy::draw(sf::RenderTarget & target)
{
	SpriteObject::draw(target);

	RenderPosition = PhysicsPosition;
}

