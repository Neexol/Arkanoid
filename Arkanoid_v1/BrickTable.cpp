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
			{
				table[i][j].setPosition(sf::Vector2f{ 40 + (float)valueNS::brickWidth * i, 37 + (float)valueNS::wallHeight + valueNS::brickHeight * j });
				if (rand() % 2)
					if (table[i][j].activate(Entity()))
						numberOfDeletedBricks++;
			}
			else
			{
				table[i][j].setPosition(sf::Vector2f{ -100.f, -100.f });
				numberOfDeletedBricks++;
			}
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
				if (table[i][j].activate(ball))
					numberOfDeletedBricks++;
				return true;
			}
		}
	}

	return false;
}

void BrickTable::newTable()
{
	numberOfDeletedBricks = 0;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (rand() % 2)
			{
				table[i][j].setPosition(sf::Vector2f{ 40 + (float)valueNS::brickWidth * i, 37 + (float)valueNS::wallHeight + valueNS::brickHeight * j });
				if (rand() % 2)
					if (table[i][j].activate(Entity()))
						numberOfDeletedBricks++;
			}
			else
			{
				table[i][j].setPosition(sf::Vector2f{ -100.f, -100.f });
				numberOfDeletedBricks++;
			}
		}
	}
}

BrickTable::~BrickTable()
{
}