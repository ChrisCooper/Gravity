#include <stdio.h>              
#include <string.h>              
#include <math.h>
#include <allegro.h>             
#include <algif.h>              

#define MAPWIDTH 1024
#define NUMBLOCKS 10

#define OBJECT struct object   
#define POINT struct point

/*
SELECTIVE DECLARATIONS
The following two lines of code are used to prevent multiple definitions and ENUMS
*/
#ifndef MARS_DEF                 
#define MARS_DEF                 

enum anEnum{
	SUMENUM,
	SUMOTHERENUM
};

OBJECT{
       float x;
		 float y;
		 float rotation;
		 float velRotation;
		 float velX;
		 float velY;
		 float rocketPower;
		 int width;
		 int height;
       int maxHealth;
       int health;
		 int fuel;
		 int maxFuel;
		 int mass;
       BITMAP *picture;
		 OBJECT *next;
		 OBJECT *previous;
};
POINT{
       float x;
		 float y;
		 int colour;
		 POINT *next;
		 POINT *previous;
};

#endif
