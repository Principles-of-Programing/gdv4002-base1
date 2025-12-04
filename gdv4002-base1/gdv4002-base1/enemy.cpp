#include "enemy.h"
enemy::enemy(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float initPhaseAngle, float initPhaseVelocity)
	: GameObject2D(initPosition, initOrientation, initSize, initTextureID), phaseAngle(initPhaseAngle), phaseVelocity(initPhaseVelocity)
{
	phaseAngle = initPhaseAngle;
	phaseVelocity = initPhaseVelocity;
}
void enemy::update(double tDelta)
{
	//Set the position based on a phase angle
	position.y = sinf(phaseAngle);
	//Update the phase angle based on the phase velocity * time elapsed
	phaseAngle += phaseVelocity * (float)tDelta;
}