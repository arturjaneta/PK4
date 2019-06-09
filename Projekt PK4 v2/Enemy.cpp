#include "Enemy.h"


Enemy::Enemy(SpriteInfo & info, sf::Vector2f pos,int shift):WorldObject(info, pos),
Shift(shift),FirstPosition(pos)
{
	Static = false;
	Velocity = sf::Vector2f(1.5f, 0.f);
}

void Enemy::update()
{
	SpriteObject::update();
	OldPhysicsPosition = PhysicsPosition;		//zapisanie poprzedniej pozycji
	PhysicsPosition += Velocity;				//ustawienie nowej pozycji
	if (PhysicsPosition.x<FirstPosition.x - Shift || PhysicsPosition.x > FirstPosition.x + Shift) {
		PhysicsPosition = OldPhysicsPosition;
		Velocity.x = -Velocity.x;
	}											//zmienic teksture
}

void Enemy::draw(sf::RenderTarget & target)
{
	SpriteObject::draw(target);
	RenderPosition = PhysicsPosition;
}
