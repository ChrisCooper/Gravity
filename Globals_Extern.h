#include "Definitions.h" //All structure definitions, #defines, #includes, and ENUMs


extern volatile long speedCounter;
extern volatile long speedCounterCheck;
extern volatile long moveCounter;
extern volatile long moveCounterCheck;



/*BITMAPs and BUTTONs*/
extern BITMAP *screenBuffer;                     //Bitmap for double buffering
extern BITMAP *rock50;


/*Gameplay variables*/
extern int inGame;                           //Whether the actual SPQR game is in progress
extern int landscapeHeight[MAPWIDTH];
extern float lLegX, lLegY, rLegX, rLegY;
extern float currentTime;
extern float highTime;
extern float currentDistance;
extern float highDistance;


/*mouse variables*/
extern int mouseX;                               //Pixel X locations of the mouse
extern int mouseY;                               //Pixel Y locations of the mouse
extern int mouseClick[2];                        //True or false if each mouse button has been clicked once
extern int mouseDown[2];                         //True or false if each button is down

extern PALETTE palette;

extern OBJECT theShip;
extern OBJECT *rockHeader;

extern POINT *pointHeader;
