#ifndef PLAYGROUND_LEVEL_H
#define PLAYGROUND_LEVEL_H

#include <vector>

#include "GameStateManager.h"
#include "ObjectManager.h"

// ---------------------------------------------------------------------------

class Playground: public Level {
	public:
		void Load(void);
		void Unload(void);

		void Init(void);
		void Shutdown(void);

		void InputHandler(void);
		void Update(void);
		void Draw(void);

		void Pause(void);
		void Resume(void);

		Camera* MainCam;

		ObjectManager* BaseManager;
};

// ---------------------------------------------------------------------------

#endif 


