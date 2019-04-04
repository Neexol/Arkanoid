#pragma once
#include "Entity.h"

enum TypeBricks
{
	DEFAULT
};

class Brick : public Entity
{
private:
	TypeBricks type;

public:

	Brick();
	Brick(float X, float Y, int Width, int Height, std::string textureStr, TypeBricks Type, int value = 0);

	void setTexture(std::string& texture);

	void activate();

	~Brick();
};