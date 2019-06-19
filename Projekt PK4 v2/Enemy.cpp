#include "Enemy.h"
#define SpeedX 1.5f
#define SpeedY 0.f

Enemy::Enemy(SpriteInfo & info, sf::Vector2f pos,int shift,Settings set):WorldObject(info, pos,set),
Shift(shift),FirstPosition(pos)
{
	Static = false;
	Velocity = sf::Vector2f(SpeedX, SpeedY);
	Direction = right;
}

void Enemy::Update()
{
	SpriteObject::Update();
	OldPhysicsPosition = PhysicsPosition;		
	PhysicsPosition += Velocity;				
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
	}		
}

void Enemy::Draw(sf::RenderTarget & target)
{
	SpriteObject::Draw(target);
	RenderPosition = PhysicsPosition;
}
