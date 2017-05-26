#include "SFML\Graphics.hpp"
#include <random>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Object.h"

//This spawns enemys
void SpawnEnemy(std::vector<Object*> &vec, sf::Time &time, sf::Clock &clock, int windowSize) {

	time = clock.getElapsedTime();

	//True once every second
	if (time.asSeconds() >= 1.0f) {
		for (int i = 0; i < vec.size(); i++) {
			//If there are any nullptrs in our vector they'll be replaced before we create new enemys
			if (vec[i] == nullptr) {
				vec[i] = new Enemy(sf::RectangleShape(), 32, sf::Color::Red, sf::Vector2f(rand() % windowSize, 0));
				clock.restart();
				return;
			}
		}
		//Creates a new enemy
		vec.push_back(new Enemy(sf::RectangleShape(), 32, sf::Color::Red,sf::Vector2f(rand() % windowSize, 0)));
		clock.restart();
	}
}

//This spawns bullets
void SpawnBullet(std::vector<Object*> &vec, int index) {
		for (int i = 0; i < vec.size(); i++) {
			//If there are any nullptrs replace them before we create new bullets
			if (vec[i] == nullptr) {
				vec[i] = new Bullet(sf::RectangleShape(), 16, sf::Color::White, vec[index]->GetShape().getPosition());
				return;
			}
		}
		//Creates new bullets
		vec.push_back(new Bullet(sf::RectangleShape(), 16, sf::Color::White, vec[index]->GetShape().getPosition()));
}

int main() {
	srand(time(NULL));

	const sf::Vector2u WINDOW_SIZE(800, 640);

	bool fire = true;

	std::vector<Object*> objects;	//The vector that holds pointers to all our objects in the game

	objects.push_back(new Player(sf::RectangleShape(), 32, sf::Color::Green));	//Create the player and store it in the vector

	sf::Time spawnTimer;
	sf::Clock spawnClock;

	sf::Time timer;
	sf::Clock clock;
	float dt = 0;

	sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), "Space Invaders!");

	//Game loop
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

		window.clear(sf::Color::Black);	//Clear the window color

		dt = timer.asSeconds();
		timer = clock.restart();

		SpawnEnemy(objects, spawnTimer, spawnClock, WINDOW_SIZE.x);	//Start spawning enemys

														
		for (int i = 0; i < objects.size(); i++) {		//Loop through the objects vector
			if (objects[i] == nullptr) { continue; }	//If element contains nullptr, skip it
			window.draw(objects[i]->GetShape());		//Draw the objects shapes
			objects[i]->Update(dt);						//Update the objects
			
			
			for (int j = 0; j < objects.size(); j++) {									//Loop through the objects again
				if (objects[i] == nullptr || objects[j] == nullptr) { continue; }		//If element contains a nullptr, skip it
				if (objects[i]->CheckCollision(objects[j], window)) {					//Check collision between objects[i] and objects[j]
					delete objects[i];													//Delete the pointers and replace them with nullptrs
					delete objects[j];
					objects[i] = nullptr;
					objects[j] = nullptr;
				}
			}
			if (objects[i] == nullptr) { continue; } //New check for nullptrs since we might have some after the collision check
														
			if(objects[i]->GetShape().getPosition().y > WINDOW_SIZE.y || objects[i]->GetShape().getPosition().y < 0) {	//Delete objects that's outside the screen
				delete objects[i];
				objects[i] = nullptr;
			}
		}
		window.display();
	}

	//Clear the vector of pointers
	for (Object* obj : objects) {
		delete obj;
		obj = nullptr;
	}
	objects.clear();

	return 0;
}