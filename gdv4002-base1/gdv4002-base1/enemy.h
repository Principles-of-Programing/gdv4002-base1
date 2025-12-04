#pragma once
#include "GameObject2D.h"
#include <glm/glm.hpp>
class enemy : public GameObject2D
{
private:
	float phaseAngle; // in radians
	float phaseVelocity; // in radians per second


public:
	enemy(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float phaseAngle, float phaseVelocity);
	void update(double tDelta) override;

};