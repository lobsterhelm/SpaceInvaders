#pragma once
#include "SFML\Graphics.hpp"
class Player
{
public:
	Player(sf::RectangleShape ship);
	~Player();

	void Update(float dt, sf::RectangleShape& ship);
};

