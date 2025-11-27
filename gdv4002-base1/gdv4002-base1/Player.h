#pragma once
#include "GameObject2D.h"
class Player : public GameObject2D
{
private:
	float anglesPerSecond = glm::radians(45.0f);
	float playerVelocity = 0.0f; // units per second
	float leftPlayerOrientationVelocity = glm::radians(20.0f); // radians per second
	float rightPlayerOrientationVelocity = glm::radians(-20.0f); // radians per second


public:
	Player(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID);
	void update(double tDelta) override;
};