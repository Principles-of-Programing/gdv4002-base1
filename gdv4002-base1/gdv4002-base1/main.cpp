#include "Engine.h"

// Function prototypes
void myUpdate(GLFWwindow* window, double tDelta);


int main(void) {
	const float pi = 3.14159265359f;
	// Initialise the engine (create window, setup OpenGL backend)
	int initResult = engineInit("David's Asteroid Game", 1024, 1024);

	// If the engine initialisation failed report error and exit
	if (initResult != 0) {

		printf("Cannot setup game window!!!\n");
		return initResult; // exit if setup failed
	}
	printf("System Loaded Accessing...\n");

	hideAxisLines();

	//
	// Setup game scene objects here
	//
	addObject("Player1", glm::vec2(0.0f, 0.0f), glm::radians(0.0f), glm::vec2(1.0f, 1.0f));
	addObject("Enemy Ship", glm::vec2(0.0f, 0.0f), glm::radians(0.0f), glm::vec2(1.0f, 1.0f));

	GameObject2D* Player1Object =
	getObject("Enemy Ship");
	if (Player1Object != nullptr) {
		Player1Object->position = glm::vec2(-1.0f, -1.0f);
		Player1Object->orientation = glm::radians(45.0f);
		Player1Object->size = glm::vec2(0.25f, 0.25f);
		Player1Object->textureID = loadTexture("resources\\textures\\player1_ship.png");
	}
	GameObject2D* EnemyShipObject =
		getObject("Player1");
	if (EnemyShipObject != nullptr) {
		EnemyShipObject->position = glm::vec2(1.0f, 1.0f);
		EnemyShipObject->orientation = glm::radians(225.0f);
		EnemyShipObject->size = glm::vec2(0.25f, 0.25f);
		EnemyShipObject->textureID = loadTexture("resources\\textures\\USS Relaint.png");
	}
	
	setUpdateFunction(myUpdate);
	float anglesPerSecond = glm::radians(45.0f);
	float playerVelocity = 2.0f; // units per second

	// Enter main loop - this handles update and render calls
	engineMainLoop();



	// When we quit (close window for example), clean up engine resources
	engineShutdown();

	// return success :)
	return 0;
}

void myUpdate(GLFWwindow* window, double tDelta) {
	float player1RotationSpeed = glm::radians(90.0f); // degrees per second
	GameObject2D* player1 = getObject("Player1");
	player1->orientation += player1RotationSpeed * tDelta;
}

