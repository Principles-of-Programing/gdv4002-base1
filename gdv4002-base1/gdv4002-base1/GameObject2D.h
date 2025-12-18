#pragma once

#include "GraphicsCore.h"
#include <glm/glm.hpp>

class GameObject2D {

public:

	glm::vec2		position = glm::vec2(0.0f, 0.0f);

	// angle of rotation in radians
	float			orientation = 0.0f; 

	// scale (default 1.0)
	glm::vec2		size = glm::vec2(1.0f, 1.0f); 
	
	// textureID for assigned "sprite" image
	GLuint			textureID;

	GameObject2D();
	GameObject2D(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID);

	virtual ~GameObject2D();

	virtual void render();
	virtual void update(double tDelta);
};