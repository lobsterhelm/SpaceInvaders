#pragma once
#include "SFML\Graphics.hpp"
#include "Object.h"
#include "Bullet.h"

class Player : public Object
{
public:
	Player(sf::RectangleShape ship, float size, sf::Color color);
	~Player();
	
	Bullet bulletRef;

	void Update(float dt);
	sf::RectangleShape GetShape() { return m_ship; }

private:
	sf::RectangleShape	m_ship;
	float				m_playerSpeed = 200;
};

