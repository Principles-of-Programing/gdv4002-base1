#pragma once
#include "GameObject2D.h"
class asteroids : public GameObject2D {
private: 
	float mass;
	glm::vec2 velocity;
	float angleChangePerSecond;
public: 
		asteroids(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float mass, glm::vec2 initVelocity, float initAngleChangePerSecond);
		void update(double tDelta) override;
};

