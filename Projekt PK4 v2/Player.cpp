
#include "Player.h"
#define movSpeed 0.5f

Player::Player(SpriteInfo& info, sf::Vector2f pos) :
	WorldObject(info, pos)
{
	Static = false;
}

void Player::update()
{
	SpriteObject::update();

	OldPhysicsPosition = PhysicsPosition;		//zapisanie poprzedniej pozycji
	PhysicsPosition += Velocity;				//ustawienie nowej pozycji
}

void Player::draw(sf::RenderTarget& target)
{
	SpriteObject::draw(target);

	RenderPosition = PhysicsPosition;			//taka sama fizyczna pozycja i widoczna
}

void Player::handleEvents(sf::Event& event)							//poruszanie sie
{
	if (event.type == sf::Event::KeyPressed)					
	{
		if (event.key.code == sf::Keyboard::Space && onGround) {
			Velocity.y = -movSpeed;
			onGround = false;
		}

		if (event.key.code == sf::Keyboard::A)
			Velocity.x = -movSpeed;
		else if (event.key.code == sf::Keyboard::D)
			Velocity.x = movSpeed;
	}
	else if (event.type == sf::Event::KeyReleased)
	{
		if (event.key.code == sf::Keyboard::A)
			Velocity.x = 0.f;
		else if (event.key.code == sf::Keyboard::D)
			Velocity.x = 0.f;
	}
}

bool Player::ContactBegin(std::weak_ptr<ICollideable> object, bool fromLeft, bool fromTop)
{
	if (object.lock()->isStatic())
		onGround = true;

	return true;
}