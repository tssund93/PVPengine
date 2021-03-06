/* this file is code for creating and animating sprites */
#ifndef __ENG_SPRITE_H
#define __ENG_SPRITE_H

#include <SDL2/SDL.h>
#include "basic.h"

struct object;

/* struct to hold details about the sprite. */
struct sprite {
	int		type;
	char		*fname;
	SDL_Texture	*texture;
	float		speed;
	SDL_Rect	base_rect;
	SDL_Rect	source_rect;
	SDL_Rect	dest_rect;
	SDL_Rect	hb_base_rect;
	SDL_Rect	hb_rect;	/* hitbox rectangle */
	int		frames;
	float		curr_frame;
	int		standframe;
	int		flags;
};

/* this holds the default info for a new sprite. */
extern const struct sprite SPRITE_DEFAULT;

/* start the sprite's animation from the current frame */
void anistart(struct sprite *spr, int loop);

/* set the animation speed */
void anispeed(struct sprite *spr, float speed);

/* whether to play the animation in reverse */
void anireverse(struct sprite *spr, int reverse);

/* pause the animation, keeping the current frame */
void anipause(struct sprite *spr);

/* stop the animation, setting the current frame
 * back to the beginning of the animation */
void anistop(struct sprite *spr);

/* set the current frame of the animation */
void aniset(struct sprite *spr, int frame);

/* this should be run every time the SCREEN is redrawn
 * to animate and draw the sprite */
void animate(struct sprite *spr);

/* initialize al sprites in the game */
void initsprites(void);

/* unload (free) all sprites */
void unloadsprites(void);

/* draws all sprites */
void drawall(void);

/* change the sprite of an object */
void sprchange(struct object *obj, struct sprite spr);

#endif
