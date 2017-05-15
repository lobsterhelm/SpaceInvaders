#include "Player.h"

Player::Player(sf::RectangleShape ship)
{
	ship.setSize(sf::Vector2f(32, 32));
	ship.setFillColor(sf::Color::Green);
	ship.setPosition(sf::Vector2f(0, 0));
}


Player::~Player()
{
}

void Player::Update(float dt, sf::RectangleShape& ship) {

	static const int framesPerSecond = 60;
	static const float fixedFrameStep = 1.0f / (float)framesPerSecond;
	static float frameTime = 0.0f;

	frameTime += dt;
	if (frameTime > fixedFrameStep)
	{
		frameTime -= fixedFrameStep;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		ship.move(1 * dt, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		ship.move(0, 1 * dt);
	}
	
}

