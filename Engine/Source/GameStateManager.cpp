#include "main.h"
#include "GameStateManager.h"
#include "Playground_Level.h"
#include "Input.h"

extern GLFWwindow* window;

void GameStateManager::Init() {
	_current  = GS_INVALID;
	_previous = GS_INVALID;
	_next     = GS_INIT;
	
	///////////////////////////////////////////////
	// YO THIS SHIT ASS CODE NEEDS TO CHANGE
	///////////////////////////////////////////////
	all_levels.push_back(new Playground);
}

void GameStateManager::Shutdown() {
	all_levels.clear();
}

void GameStateManager::SetNextState(GameStates nextState) {
	_next = nextState;
}

bool GameStateManager::IsRunning(void) {
	return _current != GS_QUIT;
}

void GameStateManager::ChangeLevel(unsigned short change) {
	_level = all_levels[change];

}

void GameStateManager::Update(void) {
	// Check for a game state change.
	if (_current != _next)
	{
		// Shutdown the current game state.
		if(_level)
			_level->Shutdown();


		if (_level && (_next != GS_RESTART))
			_level->Unload();

		// Update the recorded states.
		_previous = _current;
		_current =  _next;


		if (_next == GS_RESTART) {
			_current = _previous;
			_next =    _current;
		}
		else if (_current != GS_QUIT) {
			ChangeLevel(_next);
			_level->Load();
		}

		if (_current != GS_QUIT) {
			// Initialize the new game state.
			_level->Init();
		}
	}

	if (_current != GS_QUIT) {
		// Initialize the new game state.
		//FrameStart();

		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

		//InputUpdate();

		// Update the current game state.
		_level->Update();

		// Draw the current game state.
		_level->Draw();

		// check if forcing the application to quit
		if ((glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) || glfwWindowShouldClose(window))
			_next = GS_QUIT;
	}
}
