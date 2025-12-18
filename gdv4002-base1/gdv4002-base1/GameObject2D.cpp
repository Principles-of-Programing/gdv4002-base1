#include "GameObject2D.h"

GameObject2D::GameObject2D() {
}

GameObject2D::GameObject2D(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID) {

	position = initPosition;
	orientation = initOrientation;
	size = initSize;
	textureID = initTextureID;
}

GameObject2D::~GameObject2D() {
}


void GameObject2D::render() {

	// Render objects here...

	glPushMatrix();
	
	glTranslatef(position.x, position.y, 0.0f);
	glRotatef(glm::degrees(orientation), 0.0f, 0.0f, 1.0f);
	glScalef(size.x, size.y, 1.0f);

	if (textureID > 0) {

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureID);
	}

	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(1.0f, 1.0f, 1.0f);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.0f);

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.0f);

	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5f, 0.5f, 0.0f);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5f, 0.5f, 0.0f);

	glEnd();

	if (textureID > 0) {

		glDisable(GL_TEXTURE_2D);
	}

	glPopMatrix();
}

void GameObject2D::update(double tDelta) {}
