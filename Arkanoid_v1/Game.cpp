#include "Game.h"

Game::Game(sf::RenderWindow& window)
{
	background.loadFromFile("images/background.png");
	backgroundSprite.setTexture(background);
	backgroundSprite.setScale((float)valueNS::windowWidth / valueNS::backgroundWidth, (float)valueNS::windowWidth / valueNS::backgroundWidth);
	backgroundSprite.setColor(sf::Color::Green);
}


void Game::update(sf::RenderWindow& window)
{
	auto dt = clock.restart().asSeconds();

	if (playable)
	{
		auto ballPosition = ball.getPosition();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && paddle.getPosition().x > 0) { paddle.move({ -paddle.speed.x * dt, 0 }); }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && paddle.getPosition().x < window.getSize().x - paddle.getWidth()) { paddle.move({ paddle.speed.x * dt, 0 }); }

		ball.move({ ball.speed.x * dt, 0 });
		if (
			bricks.checkCollision(ball)
			|| (ballPosition.x > window.getSize().x - ball.getHeight() && ball.speed.x > 0
				|| ballPosition.x < 0 && ball.speed.x < 0)
			)
		{
			ball.move({ -ball.speed.x * dt, 0 });
			ball.speed.x *= -1;
		}

		ball.move({ 0, ball.speed.y * dt });
		if (
			bricks.checkCollision(ball)
			|| ballPosition.y < valueNS::wallHeight * 2 && ball.speed.y < 0
			|| paddle.isCollideSpeed(ball) && ball.speed.y > 0
			)
		{
			ball.move({ 0, -ball.speed.y * dt });
			ball.speed.y *= -1;
		}

		if (ballPosition.y > window.getSize().y - ball.getHeight() && ball.speed.y > 0)
		{
			paddle.setPosition({ (window.getSize().x - valueNS::paddleWidth) / 2.f, (float)window.getSize().y - valueNS::paddleHeight});
			ball.setPosition({ (window.getSize().x - valueNS::ballSize ) / 2.f, (float)paddle.getPosition().y - ball.getHeight() });
			ball.speed = valueNS::ballSpeed;
			ball.toggleFire();
			window.clear();
			bricks.show(window);
			ball.show(window);
			paddle.show(window);
			window.display();

			playable = false;
		}

		window.clear();
		window.draw(backgroundSprite);

		for (size_t i = 0; i < 2; i++)
		{
			for (size_t j = 0; j < valueNS::windowWidth / valueNS::wallWidth + 1; j++)
			{
				wall.setPosition({ j * (float)valueNS::wallHeight, i * (float)valueNS::wallWidth });
				wall.show(window);
			}
		}

		bricks.show(window);
		ball.show(window);
		paddle.show(window);
		window.display();
	}
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { ball.speed = valueNS::ballSpeed; ball.speed.x *= -1; playable = true; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { ball.speed = valueNS::ballSpeed; playable = true; }
	}
}


Game::~Game()
{
}
