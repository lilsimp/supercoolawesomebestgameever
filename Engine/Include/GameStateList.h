#ifndef GAME_STATE_LIST_H
#define GAME_STATE_LIST_H

enum GameStates {
	GS_PLAYGROUND,
	  /* Keep this one last. Used to keep track of the number of levels */
	LEVEL_NUM,

	GS_INVALID,
	GS_RESTART,
	GS_QUIT,

	GS_INIT = GS_PLAYGROUND
};

#endif
