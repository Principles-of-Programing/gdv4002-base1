#include "Engine.h"

// Function prototypes
void myUpdate(GLFWwindow* window, double tDelta);
void myKeyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods);
void playerControls(GameObject2D* player, double tDelta);

float enemyPhase[3] = { 0.0f, 0.0f, 0.0f };
float enemyPhaseVelocity[3] = { glm::radians(90.f), glm::radians(90.f), glm::radians(90.f) };
bool wKeyPressed = false;
bool aKeyPressed = false;
bool sKeyPressed = false;
bool dKeyPressed = false;

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
	addObject("Player1", glm::vec2(-1.5f, 2.0f), glm::radians(0.0f), glm::vec2(0.5f, 0.5f), "resources\\textures\\USS Relaint.png");
	addObject("Enemy", glm::vec2(0.0f, 0.0f), glm::radians(0.0f), glm::vec2(0.5f, 0.5f), "resources\\textures\\player1_ship.png");
	addObject("Enemy", glm::vec2(1.5f, 0.0f), glm::radians(0.0f), glm::vec2(0.5f, 0.5f), "resources\\textures\\player1_ship.png");
	addObject("Enemy", glm::vec2(-1.5f, 0.0f), glm::radians(0.0f), glm::vec2(0.5f, 0.5f), "resources\\textures\\player1_ship.png");



	/*GameObject2D* Player1Object =
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
	*/
	// Variables to control object movement
	
	// Set the update function for the engine
	
	listObjectCounts();
	setUpdateFunction(myUpdate);
	setKeyboardHandler(myKeyboardHandler);


	// Enter main loop - this handles update and render calls
	engineMainLoop();



	// When we quit (close window for example), clean up engine resources
	engineShutdown();

	// return success :)
	return 0;
}
float anglesPerSecond = glm::radians(45.0f);
float playerVelocity = 1.0f; // units per second
float leftPlayerOrientationVelocity = glm::radians(20.0f); // radians per second
float rightPlayerOrientationVelocity = glm::radians(-20.0f); // radians per second

void myUpdate(GLFWwindow* window, double tDelta) {
	GameObject2D* player = getObject("Player1");
	playerControls(player, tDelta);

	GameObjectCollection enemies = getObjectCollection("Enemy");
	for (int i = 0; i < (enemies.objectCount); i++) {
		enemies.objectArray[i]->position.y = sinf(enemyPhase[i]);
		enemyPhase[i] += enemyPhaseVelocity[i] * (float)tDelta;
	}
}

void playerControls(GameObject2D* player, double tDelta) {
	if (wKeyPressed) {
		glm::vec2 forward = glm::vec2(cosf(player->orientation), sinf(player->orientation));
		player->position += forward * playerVelocity * (float)tDelta;
	}
	if (aKeyPressed) {
		player->orientation += anglesPerSecond * (float)tDelta;
		glm::vec2 left = leftPlayerOrientationVelocity * glm::vec2(-sinf(player->orientation), cosf(player->orientation));
	}
	if (sKeyPressed) {
		glm::vec2 backward = glm::vec2(-cosf(player->orientation), -sinf(player->orientation));
		player->position += backward * playerVelocity * (float)tDelta;
	}
	if (dKeyPressed) {
		player->orientation -= anglesPerSecond * (float)tDelta;
		glm::vec2 right = rightPlayerOrientationVelocity * glm::vec2(sinf(player->orientation), -cosf(player->orientation));
	}
}

void myKeyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods) {
	// check if the key is pressed 
	if (action == GLFW_PRESS) {
		switch (key) {
		case GLFW_KEY_W:
			wKeyPressed = true;
			break;
		case GLFW_KEY_A:
			aKeyPressed = true;
			break;
		case GLFW_KEY_S:
			sKeyPressed = true;
			break;
		case GLFW_KEY_D:
			dKeyPressed = true;
			break;
		}
	}

	if (action == GLFW_RELEASE)
	{
		switch (key) {
		case GLFW_KEY_W:
			wKeyPressed = false;
			std::cout << "W key released" << std::endl;
			break;
		case GLFW_KEY_A:
			aKeyPressed = false;
			std::cout << "A key released" << std::endl;
			break;
		case GLFW_KEY_S:
			sKeyPressed = false;
			std::cout << "S key released" << std::endl;
			break;
		case GLFW_KEY_D:
			dKeyPressed = false;
			std::cout << "D key released" << std::endl;
			break;

		}
	}
}