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

	//
	// Setup game scene objects here
	//
	addObject("Player", glm::vec2(0.0f, 0.0f), glm::radians(0.0f),glm::vec2(0.25f, 0.25f), "resources\\textures\\player1_ship.png");
	addObject("Player2", glm::vec2(0.0f, 0.0f), glm::radians(0.0f), glm::vec2(0.25f, 0.25f), "resources\\textures\\player1_ship.png");

	






	// Enter main loop - this handles update and render calls
	engineMainLoop();

	// When we quit (close window for example), clean up engine resources
	engineShutdown();

	// return success :)
	return 0;
}


