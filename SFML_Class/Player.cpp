#include "Player.h"
#include <iostream>

using namespace std;

Player::Player() :texture(), sprite(texture)
{
	if (!texture.loadFromFile("p1_front.png"))
		cout << "Texture not loaded!" << endl;
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect({ 0, 0 }, { 66, 92 }));
}

Player::Player(const char _texturePath[])
	:texture(_texturePath), sprite(texture)
{
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect({ 0*70, 2*96 }, { 66, 92 }));
	/*
	sprite.setScale({
		100.f / (float)sprite.getTextureRect().size.x,
		100.f / (float)sprite.getTextureRect().size.y
		});
	*/

}

Player::~Player() {}

void Player::updateAnimation(float timer)
{
	if (direction.length()) setCurentAnimation("walk");
	else setCurentAnimation("idle");
	elapsedTime += timer;
	while (elapsedTime >= frameDuration)
	{
		elapsedTime -= frameDuration;
		currentFrame = (++currentFrame) % animations[curentAnimation].size();
		sprite.setTextureRect(animations[curentAnimation][currentFrame]);
	}
}

void Player::updateDirection()
{
	direction = { 0.f, 0.f };
	if (Keyboard::isKeyPressed(Keyboard::Key::A)) { direction.x -= 1.f; }
	if (Keyboard::isKeyPressed(Keyboard::Key::D)) { direction.x += 1.f; }
}

void Player::update(float time)
{
	updateDirection();
	updateAnimation(time);
	sprite.move(gravity + direction * speed);
}

void Player::draw(RenderWindow& window)
{
	window.draw(sprite);
}

Vector2f Player::getScale() { return sprite.getScale(); }
void Player::setScale(Vector2f _scale) { sprite.setScale(_scale); }

void Player::setCurentAnimation(const char _animName[])
{
	if (animations.count(_animName))
	{
		curentAnimation = std::string(_animName);
		elapsedTime = frameDuration;
	}
}