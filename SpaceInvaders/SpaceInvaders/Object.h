#pragma once
#include "SFML\Graphics.hpp"

class Object
{
public:
	Object();
	~Object();

	virtual void Update(float dt) = 0;
	virtual sf::RectangleShape GetShape() = 0;
	void DestroyObj(std::vector<Object*> &obj);
};

