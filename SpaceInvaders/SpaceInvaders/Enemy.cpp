#include "Enemy.h"


Enemy::Enemy(sf::RectangleShape ship, float size, sf::Color color, sf::Vector2f pos)
{
	ship.setSize(sf::Vector2f(size, size));
	ship.setFillColor(color);
	ship.setOrigin(sf::Vector2f(size / 2, size / 2));
	ship.setPosition(pos);
	m_ship = ship;
}

Enemy::~Enemy()
{
}

void Enemy::Update(float dt)
{
	m_ship.move(0, m_enemySpeed * dt);
}

