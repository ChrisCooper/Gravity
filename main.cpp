#include "Definitions.h"
#include "Globals.h"

extern void allegInitializations();
extern void initializeGame();
extern void initializeShip();
extern void getInput();
extern void gameVisuals();
extern void evaluatePhysics();


int main()
{

   allegInitializations();
   initializeShip();

   inGame = 1;
	//The main game loop
	while (inGame && (!key[KEY_ESC]))
    {
			/*Input vs. Visuals loop                      130 BPS*/
			if (speedCounterCheck == speedCounter)
			{
			}
			else if (speedCounter > 1)
			{
              currentTime += 0.1;
              speedCounter = 0;
              gameVisuals();
			}
         else
         {
              getInput();
              speedCounterCheck = speedCounter;
         }

			/*Input vs. Visuals loop                      30 BPS*/
			if (moveCounterCheck == moveCounter)
			{
			}
         else
         {
               evaluatePhysics();
              moveCounterCheck = moveCounter;
         }

    }
	return 0;
}END_OF_MAIN();

/*
* Current fuel flow rate as a fraction of the maximum fuel flow (default zero)
* Vertical velocity of the lander (default zero meters/sec)
* Altitude of the lander (default 1000 meters)
* Amount of fuel (default 1700 kg)
* Mass of the lander when it has no fuel (default 900 kg)
* Maximum fuel flow rate (default 10 kg/sec)
* Maximum thrust of the lander's engines (default 5000 newtons)
*/
