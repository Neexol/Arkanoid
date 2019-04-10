#include "BrickTable.h"
#include <ctime>

BrickTable::BrickTable()
{
	srand(time(nullptr));
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (rand() % 2)
				table[i][j].setPosition(sf::Vector2f{ (float)valueNS::brickWidth * i, 2.f * valueNS::wallHeight + valueNS::brickHeight * j}); else
				table[i][j].setPosition(sf::Vector2f{ -100.f, -100.f});
		}
	}
}

void BrickTable::show(sf::RenderWindow& window)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			table[i][j].show(window);
		}
	}
}

bool BrickTable::checkCollision(Entity& ball)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (table[i][j].isCollide(ball))
			{
				table[i][j].activate(ball);
				return true;
			}
		}
	}

	return false;
}

BrickTable::~BrickTable()
{
}