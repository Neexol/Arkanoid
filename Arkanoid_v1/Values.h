#pragma once
#include <SFML/Graphics.hpp>

namespace valueNS
{
	constexpr int windowWidth = 800;
	constexpr int windowHeight = 800;

	constexpr int paddleWidth = 100;
	constexpr int paddleHeight = 21;
	constexpr int paddleRectWidth = 80;
	constexpr int paddleBorderRadius = 10;
	const sf::Vector2f paddleSpeed { 600, 0 };

	constexpr int brickWidth = 80;
	constexpr int brickHeight = 37;

	constexpr int ballSize = 12;
	const sf::Vector2f ballSpeed{ 300, -300 };
	constexpr int ballVelocity = 71;
	constexpr int fireBallSpeed = 500;

	constexpr int wallWidth = 800;
	constexpr int wallHeight = 64;

	constexpr int brickTableWidth = 9;
	constexpr int brickTableHeight = 7;

	constexpr int arrowWidth = 40;
	constexpr int arrowHeight = 50;

	constexpr int health = 3;
	constexpr int maxLevel = 3;
}