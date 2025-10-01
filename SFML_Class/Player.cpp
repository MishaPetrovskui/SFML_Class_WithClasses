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
	elapsedTimer += timer;
	if (elapsedTimer >= frameDuration)
	{
		elapsedTimer -= frameDuration;
		currentFrame = (++currentFrame) % frames.size();
		sprite.setTextureRect(frames[currentFrame]);
	}
}

void Player::updateDirection()
{
	direction = { 0.f, 0.f };
	if (Keyboard::isKeyPressed(Keyboard::Key::A)) { direction.x -= 1.f; updateAnimation(0.85); }
	if (Keyboard::isKeyPressed(Keyboard::Key::D)) { direction.x += 1.f; updateAnimation(0.85); }
}

void Player::update()
{
	updateDirection();
	//updateAnimation(0.85);
	sprite.move(gravity + direction * speed);
}

void Player::draw(RenderWindow& window)
{
	window.draw(sprite);
}