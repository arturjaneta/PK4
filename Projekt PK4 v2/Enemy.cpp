#include "Enemy.h"


Enemy::Enemy(SpriteInfo & info, sf::Vector2f pos,int shift,Settings set):WorldObject(info, pos,set),
Shift(shift),FirstPosition(pos)
{
	Static = false;
	Velocity = sf::Vector2f(1.5f, 0.f);
	Direction = right;
}

void Enemy::Update()
{
	SpriteObject::Update();
	OldPhysicsPosition = PhysicsPosition;		//zapisanie poprzedniej pozycji
	PhysicsPosition += Velocity;				//ustawienie nowej pozycji
	if (PhysicsPosition.x<FirstPosition.x - Shift || PhysicsPosition.x > FirstPosition.x + Shift) {
		PhysicsPosition = OldPhysicsPosition;
		Velocity.x = -Velocity.x;
		if (Direction == left) {
			setFrameLoop(0, 0);
			Direction = right;
		}
		else {
			setFrameLoop(1, 1);
			Direction = left;
		}
	}											//zmienic teksture
}

void Enemy::Draw(sf::RenderTarget & target)
{
	SpriteObject::Draw(target);
	RenderPosition = PhysicsPosition;
}
