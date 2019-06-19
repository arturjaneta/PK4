#pragma once

#include <memory>

class ICollideable
{
public:
	ICollideable(sf::FloatRect hitbox, sf::Vector2f dim, Settings set, sf::Vector2f pos = sf::Vector2f(), bool isStatic = true)
	{
		HitBox = sf::FloatRect(hitbox.left*set.getScale(), hitbox.top*set.getScale(), hitbox.width*set.getScale(), hitbox.height*set.getScale());
		Dimensions = sf::Vector2f(dim.x*set.getScale(), dim.y*set.getScale());
		PhysicsPosition = pos;
		Static = isStatic;
		CollisionActive = true;
	}

	virtual bool ContactBegin(std::weak_ptr<ICollideable> object, bool fromLeft, bool fromTop) { return true; }

	// Setters
	void setHitBox(sf::FloatRect hitbox) { HitBox = hitbox; }
	void setDimensions(sf::Vector2f dim) { Dimensions = dim; }
	void setPhysicsPosition(sf::Vector2f pos) { PhysicsPosition = pos; }
	void setVelocity(sf::Vector2f vel) { Velocity = vel; }
	void setStatic(bool stat) { Static=stat; }
	void setCollisionActive(bool act) { CollisionActive = act; }

	// Getters
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
