#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& window)
{
	backgroundTexture.loadFromFile("images/background.png");
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setScale((float)valueNS::windowWidth / valueNS::backgroundWidth, (float)valueNS::windowWidth / valueNS::backgroundWidth);
	backgroundSprite.setColor(sf::Color::Green);
	
	arrowsTexture.loadFromFile("images/arrow.png");
	arrowsSprite.setTexture(arrowsTexture);
	arrowsSprite.setColor(sf::Color::Green);
	arrowsSprite.setPosition(0, 0);
	arrowsSprite.setOrigin(valueNS::arrowWidth + 80, valueNS::arrowHeight / 2.f);
	arrowsSprite.setPosition(valueNS::windowWidth / 2.f, valueNS::windowHeight - valueNS::arrowHeight / 2.f - valueNS::paddleHeight);

	heartTexture.loadFromFile("images/heart.png");
	heartSprite.setTexture(heartTexture);

	window.clear();

	window.draw(backgroundSprite);
	window.draw(arrowsSprite);
	arrowsSprite.setRotation(180);
	window.draw(arrowsSprite);
	wall.show(window);

	for (int i = 1; i <= health; i++)
	{
		heartSprite.setPosition(valueNS::windowWidth - (40 * i + 10), 19);
		window.draw(heartSprite);
	}

	bricks.show(window);
	ball.show(window);
	paddle.show(window);
	window.display();
}


void Game::update(sf::RenderWindow& window)
{
	auto dt = clock.restart().asSeconds();

	if (playable && health > 0)
	{
		auto ballPosition = ball.getPosition();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && paddle.getPosition().x > 0) { paddle.move({ -paddle.speed.x * dt, 0 }); }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && paddle.getPosition().x < window.getSize().x - paddle.getWidth()) { paddle.move({ paddle.speed.x * dt, 0 }); }

		ball.move({ ball.speed.x * dt, 0});
		if (
			bricks.checkCollision(ball)
			|| (ballPosition.x > window.getSize().x - ball.getHeight() && ball.speed.x > 0
			|| ballPosition.x < 0 && ball.speed.x < 0)
			|| paddle.isCollide(ball) && ((paddle.getPosition().x - ball.getPosition().x) * ball.speed.x) > 0
			)
		{
			ball.move({ -ball.speed.x * dt, 0 });
			ball.speed.x *= -1;
		}

		ball.move({ 0, ball.speed.y * dt });
		if (
			bricks.checkCollision(ball)
			|| ballPosition.y < valueNS::wallHeight && ball.speed.y < 0
			|| paddle.isCollideSpeed(ball) && ball.speed.y > 0
			)
		{
			ball.move({ 0, -ball.speed.y * dt });
			ball.speed.y *= -1;
		}

		window.clear();
		window.draw(backgroundSprite);

		if (ballPosition.y > window.getSize().y - ball.getHeight() && ball.speed.y > 0)
		{
			health--;

			paddle.setPosition({ (window.getSize().x - valueNS::paddleWidth) / 2.f, (float)window.getSize().y - valueNS::paddleHeight });
			ball.setPosition({ (window.getSize().x - valueNS::ballSize) / 2.f, (float)paddle.getPosition().y - ball.getHeight() });
			ball.speed = sf::Vector2f{ 0.f, 0.f };
			ball.toggleFire();

			window.draw(arrowsSprite);
			arrowsSprite.rotate(180);
			window.draw(arrowsSprite);

			playable = false;
		}

		if (bricks.getNumberOfDeletedBricks() == valueNS::brickTableHeight * valueNS::brickTableWidth)
		{
			level++;
			std::cout << std::endl << "Current level: " << level << std::endl;
			bricks.newTable();

			paddle.setPosition({ (window.getSize().x - valueNS::paddleWidth) / 2.f, (float)window.getSize().y - valueNS::paddleHeight });
			ball.setPosition({ (window.getSize().x - valueNS::ballSize) / 2.f, (float)paddle.getPosition().y - ball.getHeight() });
			ball.speed = sf::Vector2f{ 0.f, 0.f };
			ball.toggleFire();

			window.draw(arrowsSprite);
			arrowsSprite.rotate(180);
			window.draw(arrowsSprite);

			playable = false;
		}

		wall.show(window);

		for (int i = 1; i <= health; i++)
		{
			heartSprite.setPosition(valueNS::windowWidth - (40 * i + 10), 20);
			window.draw(heartSprite);
		}

		bricks.show(window);
		ball.show(window);
		paddle.show(window);

		if (!health)
		{
			sf::Texture gameOverTexture;
			gameOverTexture.loadFromFile("images/GameOver.png");
			sf::Sprite gameOverSprite;
			gameOverSprite.setTexture(gameOverTexture);
			window.clear();
			window.draw(gameOverSprite);
		}

		if (level == valueNS::maxLevel + 1)
		{
			sf::Texture youWinTexture;
			youWinTexture.loadFromFile("images/YouWin.png");
			sf::Sprite youWinSprite;
			youWinSprite.setTexture(youWinTexture);
			window.clear();
			window.draw(youWinSprite);
		}

		window.display();
	}
	else if (!playable && health > 0)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && health) { ball.speed = valueNS::ballSpeed; ball.speed.x *= -1; playable = true; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && health) { ball.speed = valueNS::ballSpeed; playable = true; }
	}
}


Game::~Game()
{
}
