#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;

class Player
{
public:
	Texture texture;
	Sprite sprite;
	float speed = 3.f;
	Vector2f direction = { 0.f, 0.f };
	Vector2f gravity = { 0.f, 0.5f };

	Vector2i frameSize = { 66, 92 };
	vector<IntRect> frames = 
	{
		IntRect({ 0 * 70, 2 * 96 }, frameSize),
		IntRect({ 1 * 70, 2 * 96 }, frameSize),
	};
	float frameDuration = 0.5f;
	int currentFrame = 0;
	float elapsedTimer = 0.f;
public:
	Player();
	Player(const char[]);
	~Player();

	void updateDirection();
	void update();
	void updateAnimation(float);
	void draw(RenderWindow&);
};