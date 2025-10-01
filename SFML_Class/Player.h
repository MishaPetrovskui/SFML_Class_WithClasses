#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <map>
using namespace sf;
using namespace std;

class Player
{
public:
	Texture texture;
	Sprite sprite;
	float speed = 1.f;
	Vector2f direction = { 0.f, 0.f };
	Vector2f gravity = { 0.f, 0.5f };

	Vector2i frameSize = { 32, 64 };

	map<string, vector<IntRect>> animations =
	{
		{
			"idle", {IntRect({ 0 * 32, 0 * 64 }, frameSize)}
		},
		{
			"walk",
			{
				IntRect({ 1 * 32, 0 * 64 }, frameSize),
				IntRect({ 2 * 32, 0 * 64 }, frameSize),
				IntRect({ 3 * 32, 0 * 64 }, frameSize),
				IntRect({ 4 * 32, 0 * 64 }, frameSize),
				IntRect({ 5 * 32, 0 * 64 }, frameSize),
				IntRect({ 6 * 32, 0 * 64 }, frameSize),
			}
		},
	};

	string curentAnimation = "idle";
	float frameDuration = 0.8f;
	int currentFrame = -1;
	float elapsedTime = frameDuration;

	/*vector<IntRect> frames = 
	{
		IntRect({ 0 * 32, 0 * 64 }, frameSize),
		IntRect({ 1 * 32, 0 * 64 }, frameSize),
	};
	float frameDuration = 0.5f;
	int currentFrame = 0;
	float elapsedTimer = frameDuration;*/
public:
	Player();
	Player(const char[]);
	~Player();

	void updateDirection();
	void update(float);
	void updateAnimation(float);
	void draw(RenderWindow&);
	Vector2f getScale();
	void setScale(Vector2f);
	void setCurentAnimation(const char[]);
};