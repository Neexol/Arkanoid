#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Values.h"

class Entity
{
protected:
	float x, y;
	int width, height;
	sf::Texture texture;
	sf::Sprite sprite;

	bool fireBall = false;
	
public:
	Entity();
	Entity(float X, float Y, int Width, int Height, const std::string& textureStr);

	sf::Vector2f getPosition() { return sf::Vector2f{ x, y }; }
	void setPosition(sf::Vector2f pos);

	int getWidth() { return width; }
	int getHeight() { return height; }

	sf::FloatRect getRect() { return sf::FloatRect(x, y, width, height); }

	void show(sf::RenderWindow& window);

	void move(sf::Vector2f vector);

	void setTexture(std::string& texture);

	void setScale(float x, float y);

	bool isCollide(Entity& e);

	bool isFireBall() const { return fireBall; }

	~Entity();
};