#include "SFML\Graphics.hpp"
#include <iostream>
#include "Player.h"
int main() {

	const sf::Vector2u WINDOW_SIZE(800, 640);

	sf::RectangleShape ship;

	Player player(ship);

	sf::Time time;
	sf::Clock clock;
	float dt = 0;

	sf::RenderWindow window(sf::VideoMode(800, 640), "Space Invaders!");
	window.setSize(WINDOW_SIZE);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Keyboard::Escape:
				window.close();
				break;
			}
		}

		window.clear(sf::Color::Black);

		time = clock.restart();
		dt = time.asSeconds();

		window.draw(ship);

		player.Update(dt, ship);

		window.display();
	}

	return 0;
}