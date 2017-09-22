#include "main.h"
#include "FrameTime.h"

#define MAX_FRAME_RATE 200

static double gClockStart = 1.0;
static double gClockEnd = 1.0;
static double FrameTime = 0.0f;

void FrameTimeStart() {
  gClockStart = glfwGetTime();
}

void FrameTimeEnd() {
  gClockEnd = glfwGetTime();
  FrameTime = ((double)gClockEnd - (double)gClockStart);

  while (FrameTime < (1.0f / MAX_FRAME_RATE)) {
	  gClockEnd = glfwGetTime();
	  FrameTime = float(gClockEnd - gClockStart);
  }
}

double FrameTimeGetElapsed() {
  return FrameTime;
}
