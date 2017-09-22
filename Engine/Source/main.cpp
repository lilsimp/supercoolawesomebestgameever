#include "main.h"
#include "Engine.h"
#include "GameStateManager.h"
#include "System.h"

GLFWwindow* window;

int main(void) {
	System_Initialize();

	GameEngine game;

	while (game.IsRunning()) {
		game.Update();
	}

	System_Exit();

}