#pragma once
#include "GameObject2D.h"
class Bullets : public GameObject2D
{
	private:
		float mass;
		glm::vec2 velocity;
public:
	Bullets(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float mass, glm::vec2 initVelocity);
	void update(double tDelta) override;

};

