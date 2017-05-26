#include "Player.h"


Player::Player(sf::RectangleShape ship, float size, sf::Color color)
{
	ship.setSize(sf::Vector2f(size, size));
	ship.setFillColor(color);
	ship.setOrigin(sf::Vector2f(size / 2, size / 2));
	ship.setPosition(sf::Vector2f(400, 640 - (size * 2)));
	m_ship = ship;
}


Player::~Player()
{
}

//Reads input and moves player
void Player::Update(float dt) {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		m_ship.move(m_playerSpeed * dt, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		m_ship.move(-m_playerSpeed * dt, 0);
	}
}

//Collision checking ended up being done on only the enemy
bool Player::CheckCollision(Object* obj, sf::RenderWindow &win) {
	return false;
}