#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(valueNS::windowWidth, valueNS::windowHeight), "Arkanoid", sf::Style::Close);
	window.setFramerateLimit(100);

	Game game(window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		game.update(window);
	}

	return 0;
}