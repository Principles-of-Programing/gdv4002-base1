#include "enemy.h"
enemy::Enemy(
	glm::vec2 initposition,
	float initorientation,
	glm::vec2 initsize,
	GLuint inittextureID,
	float initphaseAngle,
	float initphaseVelocity);
: GameObject2D(initposition, initorientation, initsize, inittextureID),
phaseAngle(initphaseAngle),
phaseVelocity(initphaseVelocity)
{
	void enemy::update(double tDelta)
		set position.y = sinf(phaseAngle);
	phaseAngle += phaseVelocity * tDelta;

}