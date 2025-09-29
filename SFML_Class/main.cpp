#include <SFML/Graphics.hpp>;
#include <iostream>;
#include <cmath>;
#include <map>;
#include "Player.h";
#include "Map.h";

using namespace sf;
using namespace std;

int randint(int min, int max)
{
	return (rand() % (max - min + 1)) + min;
}

const Font font("Inkfree.ttf");

//void draw_map(RenderWindow& window, Sprite &groundSprite, map<char, Sprite>& spriteSheet)
//{
//	for (int i = 0; i < MAP_HEIGHT; i++)
//		for (int j = 0; j < MAP_WIDTH; j++)
//		{
//			auto sprite = spriteSheet.find(MAP[i][j]);
//			if (sprite != spriteSheet.end())
//			{
//				sprite->second.setPosition({ float(j * 70), float(i * 70) });
//				window.draw(sprite->second);
//			}
//		}
//}


//void checkCollision(Sprite& player, bool& isJumping)
//{
//	FloatRect playerRect = player.getGlobalBounds();
//	for (int i = 0; i < MAP_HEIGHT; i++)
//		for (int j = 0; j < MAP_WIDTH; j++)
//			if (MAP[i][j] == 'g')
//			{
//				FloatRect tileRect = FloatRect({ float(j * 70), float(i * 70) }, { 70.f, 70.f });
//				auto intersection = playerRect.findIntersection(tileRect);
//				if (intersection.has_value())
//				{
//					Vector2f sepapationVector = { 0.f,0.f };
//					FloatRect interRect = intersection.value();
//					if (interRect.size.x < interRect.size.x)
//					{
//						if (playerRect.position.x < tileRect.position.x)
//							sepapationVector = { -interRect.size.x, 0.f };
//						else
//							sepapationVector = { interRect.size.x, 0.f };
//					}
//					else
//					{
//						if (playerRect.position.y < tileRect.position.y)
//						{
//							sepapationVector = { 0.f, -interRect.size.y };
//							isJumping = false;
//						}
//						else
//							sepapationVector = { 0.f, interRect.size.y };
//					}
//					player.move(sepapationVector);
//					playerRect = player.getGlobalBounds();
//				}
//			}
//}

int main()
{
	srand(time(0));
	RenderWindow window(VideoMode({ 700,350 }), "SFML");

	Texture grass;
	grass.loadFromFile("grass.png");
	Sprite sprite_grass(grass);

	Texture boxTexture;
	boxTexture.loadFromFile("boxAlt.png");
	Sprite sprite_box(boxTexture);

	Text scoreText(font, "Score: 0", 24);
	scoreText.setFillColor(Color::Black);
	scoreText.setPosition({ 10.f, 10.f });

	Player player;
	Map map;
	

	Texture tx_tiles;
	tx_tiles.loadFromFile("tiles_spritesheet.png");

	/*map<char, Sprite> spriteSheet =
	{
		{'g', sprite_grass},
		{'b', sprite_box},
		{'l', Sprite(tx_tiles, IntRect({0,72*2},{70,70}))}
	};*/

	while (window.isOpen())
	{
		while (const optional event = window.pollEvent())
		{
			if (event->is<Event::Closed>())
				window.close();
			if (event->is<Event::KeyPressed>())
				if (event->getIf<Event::KeyPressed>()->code == Keyboard::Key::Escape)
					window.close();
		}

		window.clear(Color::White);
		
		player.update();
		map.checkCollision(player.sprite);
		map.draw(window);
		player.draw(window);

		window.display();

	}






	/*Vector2f playerPos = sprite_player.getPosition();
		Vector2f diamondPos = diamondSprite.getPosition();

		float dx = abs(playerPos.x - diamondPos.x);
		float dy = abs(playerPos.y - diamondPos.y);

		if (dx < 50 && dy < 50)
		{
			score++;
			scoreText.setString("Score: " + to_string(score));
			diamondSprite.setPosition(getRandomDiamondPosition());
		}

		window.draw(diamondSprite);
		window.draw(scoreText);*/
	return 0;
}