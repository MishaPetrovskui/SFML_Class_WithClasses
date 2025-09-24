#include "Map.h"

Map::Map() {}
Map::~Map() {}

void Map::draw_map(RenderWindow &window, map<char, Sprite>& spriteSheet) {
	for (int i = 0; i < MAP_HEIGHT; i++)
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			auto sprite = spriteSheet.find(MAP[i][j]);
			if (sprite != spriteSheet.end())
			{
				sprite->second.setPosition({ float(j * 70), float(i * 70) });
				window.draw(sprite->second);
			}
		}
}

void Map::checkCollision(Sprite& player, bool& isJumping) {
	FloatRect playerRect = player.getGlobalBounds();
	for (int i = 0; i < MAP_HEIGHT; i++)
		for (int j = 0; j < MAP_WIDTH; j++)
			if (MAP[i][j] == 'g')
			{
				FloatRect tileRect = FloatRect({ float(j * 70), float(i * 70) }, { 70.f, 70.f });
				auto intersection = playerRect.findIntersection(tileRect);
				if (intersection.has_value())
				{
					Vector2f sepapationVector = { 0.f,0.f };
					FloatRect interRect = intersection.value();
					if (interRect.size.x < interRect.size.x)
					{
						if (playerRect.position.x < tileRect.position.x)
							sepapationVector = { -interRect.size.x, 0.f };
						else
							sepapationVector = { interRect.size.x, 0.f };
					}
					else
					{
						if (playerRect.position.y < tileRect.position.y)
						{
							sepapationVector = { 0.f, -interRect.size.y };
							isJumping = false;
						}
						else
							sepapationVector = { 0.f, interRect.size.y };
					}
					player.move(sepapationVector);
					playerRect = player.getGlobalBounds();
				}
			}
}