#ifndef LEVEL_H
#define LEVEL_H

class Level {
public:
	virtual void Load()   = 0;
	virtual void Unload() = 0;

	virtual void Init() = 0;
	virtual void Shutdown() = 0;

	virtual void InputHandler() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	virtual void Pause() = 0;
	virtual void Resume() = 0;
};

#endif
