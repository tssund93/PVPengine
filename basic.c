#include "basic.h"

int DEBUG;
double DT = 1;

SDL_Window *WINDOW = NULL;
SDL_Renderer *RENDERER = NULL;
SDL_Texture *TEXTURE = NULL;

SDL_Event *EVENT = NULL;

struct objm *OBJ_MGR = NULL;
