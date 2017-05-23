#include "Bullet.h"


Bullet::Bullet(sf::RectangleShape bullet, float size, sf::Color color, sf::Vector2f pos)
{
	bullet.setSize(sf::Vector2f(size, size));
	bullet.setFillColor(color);
	bullet.setOrigin(sf::Vector2f(size / 2, size / 2));
	bullet.setPosition(pos);
	m_bullet = bullet;
}


Bullet::~Bullet()
{
}

bool Bullet::CheckCollision(Object* obj){
	return false;
}

void Bullet::Update(float dt) 
{
	m_bullet.move(0, -m_bulletSpeed * dt);
}