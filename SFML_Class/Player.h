#include <SFML/Graphics.hpp>;
#include <iostream>;
#include <Math.h>;
#include <map>
#include "Map"
using namespace sf;
using namespace std;

class Player
{
public:
	float speed = 0.001f;
	bool isJumping = true;
	Texture texture;
	Sprite sprite;
	Vector2f direction;
	Vector2f gravity = { 0.f, 0.1f };
public:
	Player();
	~Player();
	void updateDirection();
	void update();
	void draw(RenderWindow&);
};

