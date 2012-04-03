#include "Definitions.h" //All structure definitions, #defines, #includes, and ENUMs


volatile long speedCounter = 0;
volatile long speedCounterCheck = 0;
volatile long moveCounter = 0;
volatile long moveCounterCheck = 0;



/*BITMAPs and BUTTONs*/
BITMAP *screenBuffer;
BITMAP *rock50;


/*Gameplay variables*/
int inGame = 0;                           //Whether the actual SPQR game is in progress
int landscapeHeight[MAPWIDTH];
float lLegX, lLegY, rLegX, rLegY;
float currentTime = 0;
float highTime = 0;
float currentDistance = 0;
float highDistance = 0;


/*mouse variables*/
int mouseX;                               //Pixel X locations of the mouse
int mouseY;                               //Pixel Y locations of the mouse
int mouseClick[2];                        //True or false if each mouse button has been clicked once
int mouseDown[2];                         //True or false if each button is down

PALETTE palette;

OBJECT theShip;
OBJECT *rockHeader = NULL;

POINT *pointHeader = NULL;
