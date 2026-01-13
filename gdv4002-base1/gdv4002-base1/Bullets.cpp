#include "Bullets.h"
extern glm::vec2 gravity;
Bullets::Bullets(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float mass, glm::vec2 initVelocity)
	: GameObject2D(initPosition, initOrientation, initSize, initTextureID)
{
	this->mass = mass;
	velocity = initVelocity;
}
void Bullets::update(double tDelta)
{
	glm::vec2 F = gravity;
	glm::vec2 acceleration = F * (1.0f / mass);
	velocity = velocity + acceleration * (float)tDelta;
	position = position + velocity * (float)tDelta;
}
