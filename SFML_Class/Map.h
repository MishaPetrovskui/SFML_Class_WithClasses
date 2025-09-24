#include <SFML/Graphics.hpp>;
#include <iostream>;
#include <cmath>;
#include <map>;
#include "Player.h";
using namespace sf;
using namespace std;
class Map
{
public:
	
	const static int MAP_WIDTH = 10;
	const static int MAP_HEIGHT = 5;
	const static int MAP_TILE_SIZE = 70;
	char MAP[MAP_HEIGHT][MAP_WIDTH + 1] =
	{
		"          ",
		"          ",
		"         l",
		"          ",
		"gggggggggg"
	};
	map<char, Sprite> spriteSheet;

	public:
	Map();
	~Map();
	void draw_map(RenderWindow& window, map<char, Sprite>& spriteSheet);
	void checkCollision(Sprite& player, bool& isJumping);
};

