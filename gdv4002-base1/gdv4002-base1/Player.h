#pragma once
#include "GameObject2D.h"
#include "Engine.h"
class Player : public GameObject2D
{
private:
	float anglesPerSecond = glm::radians(45.0f);
	//float Force = 0.0f; // units per second
	float leftPlayerOrientationVelocity = glm::radians(20.0f); // radians per second
	float rightPlayerOrientationVelocity = glm::radians(-20.0f); // radians per second
	glm::vec2 velocity;
	float maxSpeed = 2.0f;
	float mass;
	// Adding the ability for the player to fire bullets
	float fireInterval = 0.2f; // seconds between shots
	float emitCounter = 0;
	unsigned long long bulletNumber = 0; //monotonically increasing bullet index index / number used to set key
public:
	Player(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float mass);
	void update(double tDelta) override;

};