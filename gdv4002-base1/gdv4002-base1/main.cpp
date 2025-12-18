#include "Engine.h"
#include "glPrint.h"
#include "Player.h"
#include "enemy.h"
// Function prototypes
//void myUpdate(GLFWwindow* window, double tDelta);
void myKeyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods);
//void playerControls(GameObject2D* player, double tDelta);
void windowcontrols(GLFWwindow* window, double tDelta);
glm::vec2 gravity = glm::vec2(0.0f, -1.0f);

float enemyPhase[3] = { 0.0f, 0.5f, 0.5f };
float enemyPhaseVelocity[3] = { glm::radians(90.f), glm::radians(80.f), glm::radians(80.f) };
bool wKeyPressed = false;
bool aKeyPressed = false;
bool sKeyPressed = false;
bool dKeyPressed = false;
bool escapeKeyPressed = false;

int main(void) {
	const float pi = 3.14159265359f;
	// Initialise the engine (create window, setup OpenGL backend)
	int initResult = engineInit("GDV4002 - Program", 1024, 1024);

	// If the engine initialisation failed report error and exit
	if (initResult != 0) {

		printf("Cannot setup game window!!!\n");
		return initResult; // exit if setup failed
	}
	printf("GDV4002 Asteroid Version: 0.7 Merry Christmas\n");
	printf("Please ensure that the Engine is Version 1.4 or higher if code is not working correctly\n");

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDepthFunc(GL_ALWAYS);
	// Optionally hide axis lines
	hideAxisLines();

	//
	// Setup game scene objects here
	//
	/*addObject("Player1", glm::vec2(-1.5f, 2.0f), glm::radians(0.0f), glm::vec2(0.5f, 0.5f), "resources\\textures\\USS Relaint.png");
	addObject("Enemy", glm::vec2(0.0f, 0.0f), glm::radians(-90.0f), glm::vec2(0.5f, 0.5f), "resources\\textures\\BattleCruiser.png");
	addObject("Enemy", glm::vec2(1.5f, 0.0f), glm::radians(-90.0f), glm::vec2(0.5f, 0.5f), "resources\\textures\\BattleCruiser.png");
	addObject("Enemy", glm::vec2(-1.5f, 0.0f), glm::radians(-90.0f), glm::vec2(0.5f, 0.5f), "resources\\textures\\BattleCruiser.png");*/
	//Player(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID);
	GLuint playerTexture = loadTexture("resources\\textures\\USS Relaint.png");
	Player* mainPlayer = new Player(glm::vec2(-1.5f, 2.0f), glm::radians(0.0f), glm::vec2(0.5f, 0.5f), playerTexture, 1.0f);
	addObject("player", mainPlayer);
	GLuint enemyTexture = loadTexture("resources\\textures\\BattleCruiser.png");
	enemy* enemy1 = new enemy(glm::vec2(0.0f, 0.0f), glm::radians(-90.0f), glm::vec2(0.5f, 0.5f), enemyTexture, enemyPhase[0], enemyPhaseVelocity[0]);
	enemy* enemy2 = new enemy(glm::vec2(1.5f, 0.0f), glm::radians(-90.0f), glm::vec2(0.5f, 0.5f), enemyTexture, enemyPhase[1], enemyPhaseVelocity[1]);
	enemy* enemy3 = new enemy(glm::vec2(-1.5f, 0.0f), glm::radians(-90.0f), glm::vec2(0.5f, 0.5f), enemyTexture, enemyPhase[2], enemyPhaseVelocity[2]);
	addObject("enemy1", enemy1);
	addObject("enemy2", enemy2);
	addObject("enemy3", enemy3);
	// Variables to control object movement
	
	// Set the update function for the engine
	
	//listObjectCounts();
	//setUpdateFunction(myUpdate);
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

/*void myUpdate(GLFWwindow* window, double tDelta) {
	GameObject2D* player = getObject("Player1");
	playerControls(player, tDelta);
	windowcontrols(window, tDelta);

	GameObjectCollection enemies = getObjectCollection("Enemy");
	for (int i = 0; i < (enemies.objectCount); i++) {
		enemies.objectArray[i]->position.y = sinf(enemyPhase[i]);
		enemyPhase[i] += enemyPhaseVelocity[i] * (float)tDelta * 0.5f;
	}*/

void windowcontrols(GLFWwindow* window, double tDelta) {
	if (escapeKeyPressed) {
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}

void myKeyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods) {
	// check if the key is pressed 
	if (action == GLFW_PRESS) {
		switch (key) {
		case GLFW_KEY_ESCAPE:
			escapeKeyPressed = true;
			glfwSetWindowShouldClose(window, true);
			break;
		
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
			break;
		case GLFW_KEY_A:
			aKeyPressed = false;
			break;
		case GLFW_KEY_S:
			sKeyPressed = false;
			break;
		case GLFW_KEY_D:
			dKeyPressed = false;
			break;
		case GLFW_KEY_ESCAPE:
			escapeKeyPressed = false;
			break;
		}
	}

}