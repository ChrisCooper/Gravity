#include "Definitions.h"
#include "Globals_Extern.h"


void gameVisuals();
void drawRotatedSprite(BITMAP *targetBMP, BITMAP  *sprite, int x, int y, float angle);
void showHealthBar(OBJECT *theObject);
void printAll(OBJECT *theObject);
POINT *createPoint(int colour, float x, float y);
void drawPath();

void gameVisuals()
{
	rectfill(screenBuffer, 100, 3, 500, 20, makecol(150, 150, 150));
	if (theShip.health > 750)
		rectfill(screenBuffer, 103, 6, 103 + ((int)(394*((float)theShip.fuel/(float)theShip.maxFuel))), 17, makecol(0, 200, 0));
	else if (theShip.health > 350)
		rectfill(screenBuffer, 103, 6, 103 + ((int)(394*((float)theShip.fuel/(float)theShip.maxFuel))), 17, makecol(255, 255, 0));
	else
		rectfill(screenBuffer, 103, 6, 103 + ((int)(394*((float)theShip.fuel/(float)theShip.maxFuel))), 17, makecol(200, 0, 0));
   textprintf_centre_ex(screenBuffer, font, 250, 8, makecol(0, 0, 0), -1, "Fuel: %d / %d", theShip.fuel, theShip.maxFuel);
   textprintf_centre_ex(screenBuffer, font, 500, 30, makecol(255, 255, 255), -1, "Time: %.0f", currentTime);
   textprintf_centre_ex(screenBuffer, font, 500, 40, makecol(255, 255, 255), -1, "High Score: %.0f", highTime);

 //  drawRotatedSprite(screenBuffer, theShip.picture, (int)(theShip.x + cameraX), (int)(theShip.y + cameraY), theShip.rotation);
	drawPath();
   printAll(&theShip);
   printAll(rockHeader);



//   putpixel(screenBuffer, (int)(lLegX - 3 + cameraX), (int)(lLegY + cameraY), makecol(255, 255, 255));

	blit(screenBuffer, screen, 0,0,0, 0,1024,768);         //Blit the buffer
   clear_to_color(screenBuffer, makecol(0,0,0));
}

void printAll(OBJECT *theObject)
{
	while (theObject != NULL)
	{
   	drawRotatedSprite(screenBuffer, theObject->picture, (int)theObject->x, (int)theObject->y, theObject->rotation);
      theObject = theObject->next;
	}
}

void drawRotatedSprite(BITMAP *targetBMP, BITMAP  *sprite, int x, int y, float angle)
{
   rotate_sprite(targetBMP, sprite, x, y, ftofix(angle));
}

void showHealthBar(OBJECT *theObject)
{
	rectfill(screenBuffer, (int)theObject->x, (int)theObject->y - 15, (int)theObject->x + 50, (int)theObject->y - 5, makecol(150, 150, 150));
	if (theObject->health/theObject->maxHealth > 0.75)
		rectfill(screenBuffer, (int)theObject->x+2, (int)(theObject->y - 13), (int)(theObject->x + (47*((float)theObject->health/(float)theObject->maxHealth))), (int)theObject->y - 7, makecol(0, 200, 0));
	else if (theShip.health > 350)
		rectfill(screenBuffer, (int)theObject->x+2, (int)(theObject->y - 13), (int)(theObject->x + (47*((float)theObject->health/(float)theObject->maxHealth))), (int)theObject->y - 7, makecol(255, 255, 0));
	else
		rectfill(screenBuffer, (int)theObject->x+2, (int)(theObject->y - 13), (int)(theObject->x + (47*((float)theObject->health/(float)theObject->maxHealth))), (int)theObject->y - 7, makecol(200, 0, 0));
}

void drawPath()
{
	POINT *thePoint = pointHeader;
	while (thePoint != NULL)
	{
      putpixel(screenBuffer, (int)thePoint->x, (int)thePoint->y, thePoint->colour);
      thePoint = thePoint->next;
	}
}
