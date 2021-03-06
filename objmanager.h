/* object manager to hold game objects so they can be easily looped through
 * for drawing, updating, etc. */
#ifndef __ENG_OBJMANAGER_H
#define __ENG_OBJMANAGER_H

#include "object.h"

#define OBJMANAGER_INITIAL_CAPACITY	2
#define OBJMANAGER_CAPUP_RATE		2

/* tell the compile that sprite is a struct */
struct sprite;

/* struct for the object manager */
struct objm {
	unsigned long objcnt;	/* the number of objects in the manager */
	struct object		*objs;	/* array of objects */
	unsigned long cap;	/* capacity of manager */
};

/* initialize the object manager */
void objminit(struct objm **mgr);

/* add an object to the manager, returns index of object added */
int objmadd(struct objm *mgr, struct object obj, struct sprite spr,
		float x, float y, float z, int flags);

/* get an object from the manager */
struct object *objmget(struct objm *mgr, unsigned int idx);

/* set object at index */
void objmset(struct objm *mgr, unsigned int idx, struct object obj);

/* search manager for object with given type */
int objmfind(struct objm *mgr, int type);

/* free memory allocated by object manager */
void objmfree(struct objm *mgr);

/* returns count of objects in the manager */
unsigned long objmcnt(struct objm *mgr);

/* sort objects by y value for drawing */
void objmsort(struct objm *mgr);

/* print object info for objects in manager */
void objmprint(struct objm *mgr);

#endif
