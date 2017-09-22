#ifndef GAME_STATE_MANAGER_H
#define GAME_STATE_MANAGER_H

#include <vector>

#include "GameStateList.h"
#include "Level.h"

class GameStateManager {
	public:
		void Init(void);
		void Shutdown(void);

		void Update(void);

		void SetNextState(GameStates nextState);
		bool IsRunning(void);
		void ChangeLevel(unsigned short change);

	private:
		GameStates _current;
		GameStates _previous;
		GameStates _next;

		Level* _level;
		std::vector<Level*> all_levels;
};

#endif
