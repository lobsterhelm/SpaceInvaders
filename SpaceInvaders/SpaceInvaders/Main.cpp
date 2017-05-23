#include "SFML\Graphics.hpp"
#include <random>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Object.h"

void SpawnEnemy(std::vector<Object*> &vec, sf::Time &time, sf::Clock &clock, int windowSize) {

	time = clock.getElapsedTime();

	if (time.asSeconds() >= 1.0f) {
		for (int i = 0; i < vec.size(); i++) {
			if (vec[i] == nullptr) {
				vec[i] = new Enemy(sf::RectangleShape(), 32, sf::Color::Red, sf::Vector2f(rand() % windowSize, 0));
				clock.restart();
				//std::cout << "Enemy replaced nullptr" << std::endl;
				return;
			}
		}
		vec.push_back(new Enemy(sf::RectangleShape(), 32, sf::Color::Red,sf::Vector2f(rand() % windowSize, 0)));
		clock.restart();

		//std::cout << "Enemy Spawn" << std::endl;
	}
}

void SpawnBullet(std::vector<Object*> &vec, int index) {
		for (int i = 0; i < vec.size(); i++) {
			if (vec[i] == nullptr) {
				vec[i] = new Bullet(sf::RectangleShape(), 16, sf::Color::White, vec[index]->GetShape().getPosition());
				//std::cout << "Bullet replaced nullptr" << std::endl;
				return;
			}
		}
		vec.push_back(new Bullet(sf::RectangleShape(), 16, sf::Color::White, vec[index]->GetShape().getPosition()));

		//std::cout << "Bullet Spawn" << std::endl;
}

int main() {
	srand(time(NULL));

	const sf::Vector2u WINDOW_SIZE(800, 640);

	bool fire = true;

	std::vector<Object*> objects;

	objects.push_back(new Player(sf::RectangleShape(), 32, sf::Color::Green));

	sf::Time spawnTimer;
	sf::Clock spawnClock;

	sf::Time timer;
	sf::Clock clock;
	float dt = 0;

	sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), "Space Invaders!");

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) {
					window.close();
				}
				if (event.key.code == sf::Keyboard::Space && fire == true) {
					SpawnBullet(objects, 0);
					fire = false;
				}
			}
			if (event.type == sf::Event::KeyReleased) {
				if (event.key.code == sf::Keyboard::Space && fire == false) {
					fire = true;
				}
			}
		}

		window.clear(sf::Color::Black);

		dt = timer.asSeconds();
		timer = clock.restart();

		SpawnEnemy(objects, spawnTimer, spawnClock, WINDOW_SIZE.x);

		for (int i = 0; i < objects.size(); i++) {
			if (objects[i] == nullptr) { continue; }
			window.draw(objects[i]->GetShape());
			objects[i]->Update(dt);
			for (int j = 0; j < objects.size(); j++) {
				if (objects[i] == nullptr || objects[j] == nullptr) { continue; }
				if (objects[i]->CheckCollision(objects[j])) {
					delete objects[i];
					delete objects[j];
					objects[i] = nullptr;
					objects[j] = nullptr;
				}
			}
			if (objects[i] == nullptr) { continue; }
			if(objects[i]->GetShape().getPosition().y > WINDOW_SIZE.y || objects[i]->GetShape().getPosition().y < 0) {
				delete objects[i];
				objects[i] = nullptr;
			}
		}
		window.display();
	}

	for (Object* obj : objects) {
		delete obj;
		obj = nullptr;
	}
	objects.clear();

	return 0;
}