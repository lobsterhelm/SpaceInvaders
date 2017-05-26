#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>
#include <vector>

class Object
{
public:
	Object();
	~Object();

	virtual void Update(float dt) = 0;
	virtual bool CheckCollision(Object* obj, sf::RenderWindow &win) = 0;

	virtual sf::RectangleShape GetShape() = 0;
	void DestroyObj(std::vector<Object*> &obj);
};

