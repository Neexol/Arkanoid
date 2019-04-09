#pragma once
#include "Brick.h"

class BrickTable
{
private:
	const static int height = valueNS::brickTableWidth;
	const static int width = valueNS::brickTableHeight;
	Brick table[height][width];

public:
	BrickTable();

	void show(sf::RenderWindow& window);

	bool checkCollision(Entity& ball);

	~BrickTable();
};