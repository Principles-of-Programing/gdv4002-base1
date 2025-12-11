#include "asteroids.h"
extern glm::vec2 gravity;
asteroids::asteroids(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float mass, glm::vec2 initVelocity, float initAngleChangePerSecond)
	: GameObject2D(initPosition, initOrientation, initSize, initTextureID)
{
	this->mass = mass;
	velocity = glm::vec2(0.0f, 0.0f);
}
void asteroids::update(double tDelta)
{
	glm::vec2 F = gravity;
	glm::vec2 acceleration = F * (1.0f / mass);
	velocity = velocity + acceleration * (float)tDelta;
	position = position + velocity * (float)tDelta;
	orientation += angleChangePerSecond * (float)tDelta;
}
