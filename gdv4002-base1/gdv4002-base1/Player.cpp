#include "Player.h"
#include "Engine.h"
extern bool wKeyPressed;
extern bool aKeyPressed;
extern bool sKeyPressed;
extern bool dKeyPressed;
Player::Player(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float mass)
	: GameObject2D(initPosition, initOrientation, initSize, initTextureID)
{
	velocity = glm::vec2(0, 0);
	//Force = 0.02f; // units per second
	this->mass = mass;
}
void Player::update(double tDelta)
{
	glm::vec2 F = glm::vec2(0.0f, 0.0f);
	const float Thrust = 1.5f; // Force Applied 
	if (wKeyPressed) {
		glm::vec2 forward = glm::vec2(cosf(orientation), sinf(orientation));
		F += forward * Thrust;

	}
	if (aKeyPressed) {
		orientation += anglesPerSecond * (float)tDelta;
	}
	if (sKeyPressed) {
		glm::vec2 backward = -glm::vec2(cosf(orientation), sinf(orientation));
		F += backward * Thrust;
	}
	if (dKeyPressed) {
		orientation -= anglesPerSecond * (float)tDelta;
	}
	// Add Impule Forces for collision impact
	if (position.y < -getViewplaneHeight() / 2.0f) {
		F += glm::vec2(0.0f, 20.0f);
	}
	if (position.y > getViewplaneHeight() / 2.0f) {
		F += glm::vec2(0.0f, -20.0f);
	}
	if (position.x < -getViewplaneHeight() / 2.0f) {
		F += glm::vec2(20.0f, 0.0f);
	}
	if (position.x > getViewplaneHeight() / 2.0f) {
		F += glm::vec2(-20.0f, 0.0f);
	}
	
	//Caculate acceleration from force and mass
	glm::vec2 acceleration = F / mass;

	// Intergrate acceleration to get new velocity
	velocity += (acceleration * (float)tDelta);


	// Applying a Max Speed Limit to the Player mimicing the speed limit of a spaceship due to 
	if (glm::length(velocity) > maxSpeed)
	{
		velocity = glm::normalize(velocity) * maxSpeed; // Velocity clamping
	}
	// Apply friction when no movement keys are pressed to mimic inertial dampers in space
	if (glm::length(velocity) != 0.0f && !wKeyPressed && !sKeyPressed)
	{
		velocity *= 0.98f; // Friction

	}
	// Update position based on velocity
	position += (velocity * (float)tDelta);

	
}