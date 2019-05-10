
#include "Player.h"
#define movSpeed 2.f

Player::Player(SpriteInfo& info, sf::Vector2f pos) :
	WorldObject(info, pos)
{
	Static = false;
	onGround = false;
}

void Player::update()
{
	SpriteObject::update();

	OldPhysicsPosition = PhysicsPosition;		//zapisanie poprzedniej pozycji
	PhysicsPosition += Velocity;				//ustawienie nowej pozycji


	//animacje
	if (onGround) {
		if (Direction == left)
			setFrameLoop(12, 17);
		else if(Direction == right)
			setFrameLoop(18, 23);
		else if (Direction == stat_left)
			setFrameLoop(0, 5);
		else if (Direction == stat_right)
			setFrameLoop(6, 11);
	}
	else {
		if (Direction == left)
			setFrameLoop(33, 33);
		else if (Direction == right)
			setFrameLoop(30, 30);
		else if (Direction == stat_left)
			setFrameLoop(35, 35);
		else if (Direction == stat_right)
			setFrameLoop(32, 32);
	}

}

void Player::death(sf::Vector2f pos)
{
	setPhysicsPosition(pos);
	setVelocity(sf::Vector2f(0,0));
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
			Velocity.y = -movSpeed*2;
			onGround = false;
		}

		if (event.key.code == sf::Keyboard::A) {
			Velocity.x = -movSpeed;
			Direction = left;
		}
		else if (event.key.code == sf::Keyboard::D) {
			Velocity.x = movSpeed;
			Direction = right;
		}
	}
	else if (event.type == sf::Event::KeyReleased)
	{
		if (event.key.code == sf::Keyboard::A) {
			Velocity.x = 0.f;
			Direction = stat_left;
		}
		else if (event.key.code == sf::Keyboard::D) {
			Velocity.x = 0.f;
			Direction = stat_right;
		}
	}
}

bool Player::ContactBegin(std::weak_ptr<ICollideable> object, bool fromLeft, bool fromTop)
{
	if (object.lock()->isStatic())
		onGround = true;

	return true;
}