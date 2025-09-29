#include "Player.h"
#include "Map.h"

Player::Player() :texture(), sprite(texture), direction(0.0f, 0.0f), speed(0.1f), gravity(0.0f, 0.1f), isJumping(false)
{
	texture.loadFromFile("p1_front.png");
	sprite = Sprite(texture);
}

Player::~Player() {}

void Player::updateDirection() 
{
	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && sprite.getPosition().x > 0) direction.x -= 0.1f;
	else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && sprite.getPosition().x + 70 < 700) direction.x += 0.1f;
	else direction.x = 0;
	if (Keyboard::isKeyPressed(Keyboard::Key::Up) && !isJumping) 
	{
		direction.y -= 20.0f;
		isJumping = true;
	}
	/*else if (sprite.getPosition().y + 90 >= 500) 
	{
		direction.y = 0;
		isJumping = false;
		sprite.setPosition({ sprite.getPosition().x, 410 });
	}*/
	else direction.y += 0.1f;
}
void Player::update() 
{
	updateDirection();
	sprite.move(gravity + direction * speed);
}
void Player::draw(RenderWindow& window) 
{
	window.draw(sprite);
}
