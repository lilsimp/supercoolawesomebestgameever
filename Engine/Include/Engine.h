#ifndef ENGINE_H
#define ENGINE_H

#include "GameStateManager.h"

class GameEngine {
	public:
		GameEngine();
		~GameEngine();

		// Update the game engine.
		void Update(void);

		bool IsRunning() { return GSM.IsRunning(); };

	private:
		GameStateManager GSM;
};

#endif
