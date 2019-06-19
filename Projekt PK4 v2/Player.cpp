#include "Player.h"

Player::Player(SpriteInfo& info, sf::Vector2f pos,Settings _set) :
	WorldObject(info, pos,_set)
{
	Set = _set;
	Static = false;
	OnGround = false;
}

void Player::Update()
{
	SpriteObject::Update();

	OldPhysicsPosition = PhysicsPosition;		//zapisanie poprzedniej pozycji
	PhysicsPosition += Velocity;				//ustawienie nowej pozycji
	//animacje
	if (OnGround) {
		if (Direction == left)
			setFrameLoop(16, 23);		//pozycja w tablicy tekstur
		else if(Direction == right)
			setFrameLoop(0, 7);
		else if (Direction == stat_left)
			setFrameLoop(27, 27);
		else if (Direction == stat_right)
			setFrameLoop(11, 11);
	}
	else {
		if (Direction == left)
			setFrameLoop(24, 26);
		else if (Direction == right)
			setFrameLoop(8, 10);
		else if (Direction == stat_left)
			setFrameLoop(26, 26);
		else if (Direction == stat_right)
			setFrameLoop(10, 10);
	}

}

void Player::Death(sf::Vector2f pos)
{
	setPhysicsPosition(pos);
	setVelocity(sf::Vector2f(0,0));
}


void Player::Draw(sf::RenderTarget& target)
{
	SpriteObject::Draw(target);

	RenderPosition = PhysicsPosition;			//taka sama fizyczna pozycja i widoczna
}

void Player::HandleEvents(sf::Event& event)							//poruszanie sie
{
	if (event.type == sf::Event::KeyPressed)					
	{
		if (event.key.code == sf::Keyboard::Space && OnGround) {
			Velocity.y = -(Set.getPlayerSpeed())*2;
			OnGround = false;
		}

		if (event.key.code == sf::Keyboard::A) {
			Velocity.x = -Set.getPlayerSpeed();
			Direction = left;
		}
		else if (event.key.code == sf::Keyboard::D) {
			Velocity.x = Set.getPlayerSpeed();
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
	if (object.lock()->isStatic()&&fromTop&&Velocity.y<0.2)
		OnGround = true;

	return true;
}