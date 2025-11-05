#include "Engine.h"

// Function prototypes


int main(void) {
	const float pi = 3.14159265359f;
	// Initialise the engine (create window, setup OpenGL backend)
	int initResult = engineInit("GDV4002 - Applied Maths for Games", 1024, 1024);

	// If the engine initialisation failed report error and exit
	if (initResult != 0) {

		printf("Cannot setup game window!!!\n");
		return initResult; // exit if setup failed
	}
	printf("Connecting to Jumpgate Network... Failed Accessing Local Sensors... Online !Incoming Contacts! \n");

	hideAxisLines();

	//
	// Setup game scene objects here
	//
	addObject("Player1", glm::vec2(0.0f, 0.0f), glm::radians(0.0f), glm::vec2(1.0f, 1.0f));
	addObject("Player2", glm::vec2(0.0f, 0.0f), glm::radians(0.0f), glm::vec2(1.0f, 1.0f));

	GameObject2D* Player1Object =
	getObject("Player1");
	if (Player1Object != nullptr) {
		Player1Object->position = glm::vec2(-1.0f, -1.0f);
		Player1Object->orientation = glm::radians(45.0f);
		Player1Object->size = glm::vec2(0.25f, 0.25f);
		Player1Object->textureID = loadTexture("resources\\textures\\player1_ship.png");
	}
	GameObject2D* Player2Object =
		getObject("Player2");
	if (Player2Object != nullptr) {
		Player2Object->position = glm::vec2(1.0f, 1.0f);
		Player2Object->orientation = glm::radians(225.0f);
		Player2Object->size = glm::vec2(0.25f, 0.25f);
		Player2Object->textureID = loadTexture("resources\\textures\\USS Relaint.png");
	}




	







	// Enter main loop - this handles update and render calls
	engineMainLoop();

	// When we quit (close window for example), clean up engine resources
	engineShutdown();

	// return success :)
	return 0;
}


