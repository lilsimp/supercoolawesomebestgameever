#ifndef RENDER_H
#define RENDER_H

#include "Objects.h"
#include "ObjectManager.h"


void RenderInit(void);
void RenderShutdown(void);

void RenderLoad();
void RenderUnload(void);

void RenderGameObjects(ObjectManager *pObjManager);

#endif // !RENDER_H
