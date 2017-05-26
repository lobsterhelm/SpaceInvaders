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

bool Enemy::CheckCollision(Object* obj, sf::RenderWindow &win){
	if (this == obj) { return false; }															//If the object i'm checking the collision against is itself it returns false
	if (obj->GetShape().getGlobalBounds().intersects(this->GetShape().getGlobalBounds())) {		//If the object i'm checking against intersects with this object return true
		std::cout << "POW!!!!" << std::endl;													
		if (obj->GetShape().getSize().x == 32) {												//If the other object is the size of the player close the window the game is running in
			std::cout << "Player" << std::endl;
			win.close();
		}
		return true;
	}
	return false;
}

void Enemy::Update(float dt)
{
	m_ship.move(0, m_enemySpeed * dt);
}