#include "BrickTable.h"

BrickTable::BrickTable()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			table[i][j].setPosition(sf::Vector2f{ (float)valueNS::brickWidth * i, 2.f * valueNS::wallHeight + valueNS::brickHeight * j});
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
				table[i][j].activate();
				return true;
			}
		}
	}

	return false;
}

BrickTable::~BrickTable()
{
}