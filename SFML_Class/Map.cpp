#include "Map.h"

Map::Map() : mapSize{10,5} {
	location = new char* [mapSize.y];
	for (int i = 0; i < mapSize.y; i++)
		location[i] = new char[mapSize.x];
	tx_tiles.loadFromFile("tiles_spritesheet.png");
}

Map::Map(Vector2i _size, char** _map) : mapSize(_size)
{
	location = new char* [mapSize.y];
	for (int i = 0; i < mapSize.y; i++)
		location[i] = new char[mapSize.x];
	for (int y = 0; y < mapSize.y; y++)
		for (int j = 0; j < mapSize.x; j++)
			location[y][j] = _map[y][j];
}

Map::~Map() {}

void Map::freeMemoruForMap()
{
	for (int i = 0; i < mapSize.y; i++)
		delete[] location[i];
	delete[] location;
}

void Map::draw(RenderWindow &window) {
	map<char, Sprite> spriteSheet =
	{
		{'g', Sprite(tx_tiles, IntRect({ 72 * 9,0},{ 70, 70 }))},
		{'b', Sprite(tx_tiles, IntRect({ 0,72*11},{ 70, 70 }))},
		{'l', Sprite(tx_tiles, IntRect({0,72 * 2},{70,70}))}
	};
	for (int i = 0; i < mapSize.y; i++)
		for (int j = 0; j < mapSize.x; j++)
		{
			auto sprite = spriteSheet.find(location[i][j]);
			if (sprite != spriteSheet.end())
			{
				sprite->second.setPosition({ float(j * 70), float(i * 70) });
				window.draw(sprite->second);
			}
		}
}


Vector2f Map::getSeparationVector (FloatRect rect1, FloatRect rect2)
{
    Vector2f separationVector(0.f, 0.f);
    auto intersection = rect1.findIntersection(rect2);

    if (intersection.has_value())
    {

        FloatRect intersectionRect = intersection.value();

        if (intersectionRect.size.x < intersectionRect.size.x)
        {
            if (rect1.position.x < rect2.position.x)
                separationVector = { -intersectionRect.size.x, 0.f };
            else
                separationVector = { intersectionRect.size.x, 0.f };
        }
        else
        {
            if (rect1.position.y < rect2.position.y)
                separationVector = { 0.f, -intersectionRect.size.y };
            else
                separationVector = { 0.f, intersectionRect.size.y };
        }
    }

    return separationVector;
}

void Map::checkCollision(Sprite& player)
{
    FloatRect playerRect = player.getGlobalBounds();
    Vector2f totalVector(0.f, 0.f);

    for (int y = 0; y < mapSize.y; y++)
    {
        for (int x = 0; x < mapSize.x; x++)
        {
            if (location[y][x] != ' ')
            {
                FloatRect tileRect = FloatRect(
                    { (float)(x * 70.f), (float)(y * 70.f) },
                    { (float)70.f, (float)70.f });

                totalVector += getSeparationVector(playerRect, tileRect);
            }
        }
    }

    player.move(totalVector);
}