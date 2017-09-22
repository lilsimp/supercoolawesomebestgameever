#include <iostream>

#include "main.h"
#include "Engine.h"
#include "FrameTime.h"
#include "GameStateManager.h"
#include "Render.h"

// Initialize the game engine.
GameEngine::GameEngine() {
	//--------------------------------------------------------------------------
	// NOTE: Certain modules need to be initialized first.
	//--------------------------------------------------------------------------

	FrameTimeStart();

	// Initialize the game state manager.
	GSM.Init();

	RenderInit();

	FrameTimeEnd();
}

// Update the game engine.
// Params:
//	 dt = Change in time (in seconds) since the last game loop.
void GameEngine::Update() {
	FrameTimeStart();

	// Update the game state manager.
	GSM.Update();

	FrameTimeEnd();

	std::cout << FrameTimeGetElapsed() << std::endl;
}

// Shutdown the game engine.
GameEngine::~GameEngine() {
	// Shutdown the game state manager.
	GSM.Shutdown();

	RenderShutdown();
}

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------

