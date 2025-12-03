#include "Player.h"
extern bool wKeyPressed;
extern bool aKeyPressed;
extern bool sKeyPressed;
extern bool dKeyPressed;
Player::Player(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID)
	: GameObject2D(initPosition, initOrientation, initSize, initTextureID)
{
	velocity = glm::vec2(0, 0);
	playerVelocity = 0.02f; // units per second
}
void Player::update(double tDelta)
{

	if (wKeyPressed) {
		glm::vec2 forward = glm::vec2(cosf(orientation), sinf(orientation));
		velocity += forward * playerVelocity * (float)tDelta;

	}
	if (aKeyPressed) {
		orientation += anglesPerSecond * (float)tDelta;
	}
	if (sKeyPressed) {
		glm::vec2 backward = glm::vec2(-cosf(orientation), -sinf(orientation));
		velocity += backward * playerVelocity * (float)tDelta;
	}
	if (dKeyPressed) {
		orientation -= anglesPerSecond * (float)tDelta;
	}


	if (glm::length(velocity) > maxSpeed)
	{
		velocity = glm::normalize(velocity) * maxSpeed; // Velocity clamping
	}
	
	if (glm::length(velocity) != 0.0f && !wKeyPressed && !sKeyPressed)
	{
		velocity *= 0.98f; // Friction

	}


	position += velocity;
}