#pragma once
#include "Brick.h"

class BrickTable
{
private:
	const static int height = 10;
	const static int width = 8;
	Brick table[height][width];

public:
	BrickTable();

	void show(sf::RenderWindow& window);

	bool checkCollision(Entity& ball);

	~BrickTable();
};