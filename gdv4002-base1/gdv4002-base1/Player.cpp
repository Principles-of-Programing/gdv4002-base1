#include "Player.h"
extern bool wKeyPressed;
extern bool aKeyPressed;
extern bool sKeyPressed;
extern bool dKeyPressed;
Player::Player(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID)
	: GameObject2D(initPosition, initOrientation, initSize, initTextureID)
{
	playerVelocity = 1.0f; // units per second
}
void Player::update(double tDelta)
{
	if (wKeyPressed) {
		glm::vec2 forward = glm::vec2(cosf(orientation), sinf(orientation));
		position += forward * playerVelocity * (float)tDelta;
	}
	if (aKeyPressed) {
		orientation += anglesPerSecond * (float)tDelta;
	}
	if (sKeyPressed) {
		glm::vec2 backward = glm::vec2(-cosf(orientation), -sinf(orientation));
		position += backward * playerVelocity * (float)tDelta;
	}
	if (dKeyPressed) {
		orientation -= anglesPerSecond * (float)tDelta;
	}
}