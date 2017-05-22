#pragma once
#include "SFML\Graphics.hpp"
#include "Object.h"

class Enemy : public Object
{
public:
	Enemy(sf::RectangleShape ship, float size, sf::Color color, sf::Vector2f pos);
	~Enemy();

	void Update(float dt);
	sf::RectangleShape GetShape() { return m_ship; }
	
private:
	sf::RectangleShape	m_ship;
	float				m_enemySpeed = 100;
};

