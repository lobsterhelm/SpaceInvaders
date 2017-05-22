#pragma once
#include "SFML\Graphics.hpp"
#include "Object.h"

class Bullet : public Object
{
public:
	Bullet();
	Bullet(sf::RectangleShape bullet, float size, sf::Color color, sf::Vector2f pos);
	~Bullet();

	void Update(float dt);
	sf::RectangleShape GetShape() { return m_bullet; }

private:
	sf::RectangleShape m_bullet;
	float m_bulletSpeed = 500;
};

