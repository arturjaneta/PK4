#pragma once
#ifndef ICOLLIDEABLE_H
#define ICOLLIDEABLE_H

#include <memory>

class ICollideable
{
public:
	ICollideable(sf::FloatRect hitbox, sf::Vector2f dim, sf::Vector2f pos = sf::Vector2f(), bool _static = true)
	{
		HitBox = hitbox;
		Dimensions = dim;
		PhysicsPosition = pos;
		Static = _static;
		CollisionActive = true;
	}

	virtual bool ContactBegin(std::weak_ptr<ICollideable> object, bool fromLeft, bool fromTop) { return true; }
	virtual void ContactEnd(std::weak_ptr<ICollideable> object) {}

	// Mutators
	void setHitBox(sf::FloatRect hitbox) { HitBox = hitbox; }
	void setDimensions(sf::Vector2f dim) { Dimensions = dim; }
	void setPhysicsPosition(sf::Vector2f pos) { PhysicsPosition = pos; }
	void setVelocity(sf::Vector2f vel) { Velocity = vel; }

	// Accessors
	sf::FloatRect getHitBox() { return HitBox; }
	sf::Vector2f getDimensions() { return Dimensions; }
	sf::Vector2f& getPhysicsPosition() { return PhysicsPosition; }
	sf::Vector2f getVelocity() { return Velocity; }
	bool isCollisionActive() { return CollisionActive; }
	bool isStatic() { return Static; }

protected:
	sf::FloatRect HitBox;
	sf::Vector2f Dimensions;
	sf::Vector2f PhysicsPosition;
	sf::Vector2f OldPhysicsPosition;
	sf::Vector2f Velocity;
	bool CollisionActive;
	bool Static;
};

#endif // ICOLLIDEABLE_H
