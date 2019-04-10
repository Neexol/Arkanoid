#pragma once
#include <SFML/Graphics.hpp>

namespace valueNS
{
	constexpr int windowWidth = 800;
	constexpr int windowHeight = 600;

	constexpr int paddleWidth = 100;
	constexpr int paddleHeight = 21;
	constexpr int paddleRectWidth = 80;
	constexpr int paddleBorderRadius = 10;
	const sf::Vector2f paddleSpeed { 600, 0 };

	constexpr int brickWidth = 80;
	constexpr int brickHeight = 37;

	constexpr int ballSize = 12;
	const sf::Vector2f ballSpeed{ 300, -300 };

	constexpr int backgroundWidth = 208;
	constexpr int backgroundHeight = 232;

	constexpr int wallWidth = 32;
	constexpr int wallHeight = 32;

	constexpr int brickTableWidth = 10;
	constexpr int brickTableHeight = 8;
}