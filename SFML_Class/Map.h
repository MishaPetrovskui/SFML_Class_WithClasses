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
	
	Vector2i mapSize = { 10,5 };
	const static int MAP_TILE_SIZE = 70;
	char** location;
	Texture tx_tiles;

	void freeMemoruForMap();

	public:
	Map();
	Map(Vector2i, char**);
	~Map();
	void draw(RenderWindow&);
	Vector2f getSeparationVector(FloatRect, FloatRect);
	void checkCollision(Sprite& player);
};

