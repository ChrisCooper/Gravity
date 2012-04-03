#include "Definitions.h"
#include "Globals_Extern.h"

void getInput();
void evaluatePhysics();
OBJECT *createObject(OBJECT **listHeader);
POINT *createPoint(int colour, float x, float y);
void destroyObject(OBJECT *theObject, OBJECT **listHeader);
void randomizeMap();


void getInput()
{
	if (theShip.fuel > 0)
	{
		if (key[KEY_W])
		{
			theShip.rocketPower = 400;
	      theShip.fuel--;
	 	}
	   else if (key[KEY_S])
		{
			theShip.rocketPower = -150;
	      theShip.fuel--;
		}
		else
		{
	   	theShip.rocketPower = 0;
		}
		if (key[KEY_A])
		{
			theShip.velRotation -= 0.05;
	      theShip.fuel--;
		}
	   if (key[KEY_D])
		{
			theShip.velRotation += 0.05;
	      theShip.fuel--;
		}
	}
	else
	{
      theShip.rocketPower = 0;
	}

	if (theShip.rotation < -255)
	{
      theShip.rotation = 255;
	}
	if (theShip.rotation > 255)
	{
      theShip.rotation = -255;
	}

	if (key[KEY_LCONTROL])
	{
		theShip.velX = 0;
		theShip.velY = 0;
		theShip.velRotation = 0;
	}
	if (key[KEY_C])
	{
		pointHeader = NULL;
	}
	if (key[KEY_R])
	{
		randomizeMap();
	}
	if (key[KEY_P])
	{
		readkey();
	}

   createPoint(makecol(255, 255, 255), theShip.x + 0.5 * theShip.width, theShip.y + 0.5 * theShip.height);
   createPoint(makecol(255, 0, 0), theShip.x + 0.5 * theShip.width + (fixtof(fixcos(ftofix(theShip.rotation))) * 10), theShip.y + 0.5 * theShip.height + (fixtof(fixsin(ftofix(theShip.rotation))) * 10));
}

void evaluatePhysics()
{
   if (theShip.x > MAPWIDTH)
	{
      theShip.x = MAPWIDTH;
      theShip.velX *= -1;
	}
   if (theShip.x < 0)
	{
      theShip.x = 0;
      theShip.velX *= -1;
	}
   if (theShip.y > 768)
	{
      theShip.y = 768;
      theShip.velY *= -1;
	}
   if (theShip.y < 0)
	{
      theShip.y = 0;
      theShip.velY *= -1;
	}
   theShip.rotation += theShip.velRotation;
	theShip.velX += fixtof(fixsin(ftofix(theShip.rotation))) * (theShip.rocketPower/theShip.mass) * 0.99;
	theShip.velY -= fixtof(fixcos(ftofix(theShip.rotation))) * (theShip.rocketPower/theShip.mass) * 0.99;
	theShip.x += theShip.velX;
	theShip.y += theShip.velY;


	OBJECT *theRock = rockHeader;
	static float distance;
	static float diffX;
	static float diffY;
	static float fG;
	static float fGX;
	static float fGY;
	static float rockX;
	static float rockY;
	static float shipX;
	static float shipY;
	shipX = theShip.x + (theShip.width / 2);
	shipY = theShip.y + (theShip.height / 2);
	while (theRock != NULL)
	{
		rockX = theRock->x + (theRock->width) / 2;
	   rockY = theRock->y + (theRock->height) / 2;
		diffX = (shipX - rockX);
		diffY = (shipY - rockY);
		distance = (pow(pow(diffX, 2)+ pow(diffY, 2), 0.5));
		fG = 25 * theShip.mass * theRock->mass / pow(distance, 2);
		fGX = fixtof(fixcos(fixatan(ftofix(diffY/diffX)))) * fG / theShip.mass;
		fGY = fixtof(fixsin(fixatan(ftofix(diffY/diffX)))) * fG / theShip.mass;
		theShip.velX += ((shipX > rockX) ? -fGX : fGX);
		theShip.velY += ((shipX > rockX) ? -fGY : fGY);

	   putpixel(screenBuffer, (int)shipX, (int)shipY, makecol(255, 255, 255));

		if (shipX > theRock->x && shipX < theRock->x + theRock->width)
		{
   		if (shipY > theRock->y && shipY < theRock->y + theRock->height)
			{
				theShip.x = 462;
				theShip.y = 359;
				theShip.rotation = 0;
				theShip.velRotation = 0;
				theShip.velX = 0;
				theShip.velY = 0;
				theShip.fuel = theShip.maxFuel;
				if (currentTime > highTime)
				{
					highTime = currentTime;
				}
				currentTime = 0;
			}
		}

		theRock = theRock->next;
	}

}

OBJECT *createObject(OBJECT **listHeader)
{
	OBJECT *newObject = (OBJECT*)malloc(sizeof(OBJECT));

	newObject->x;
	newObject-> y;
	newObject->rotation;
	newObject->velRotation;
	newObject->velX;
	newObject->velY;
	newObject->rocketPower;
	newObject->width;
	newObject->height;
	newObject->maxHealth;
	newObject->health;
	newObject->fuel;
	newObject->maxFuel;
	newObject->mass;
   newObject->picture;
	newObject->previous = NULL;
	newObject->next = *listHeader;
	if (newObject->next != NULL)
	{
      	newObject->next->previous = newObject;
	}
	*listHeader = newObject;
	return newObject;
}

OBJECT *createRock()
{
	OBJECT *newRock = (OBJECT*)malloc(sizeof(OBJECT));

	newRock->x = (float)(rand()%1024);
	newRock->y = (float)(rand()%768);
	newRock->rotation = 0;
	newRock->velRotation = 0;
	newRock->velX = 0;
	newRock->velY = 0;
	newRock->rocketPower = 0;
	newRock->width = 50;
	newRock->height = 50;
	newRock->maxHealth = 1;
	newRock->health = 1;
	newRock->fuel = 0;
	newRock->maxFuel = 0;
	newRock->mass = 100;
   newRock->picture = rock50;
	newRock->previous = NULL;
	newRock->next = rockHeader;
	if (newRock->next != NULL)
	{
      	newRock->next->previous = newRock;
	}
	rockHeader = newRock;
	return newRock;
}

POINT *createPoint(int colour, float x, float y)
{
	POINT *newPoint = (POINT*)malloc(sizeof(POINT));

	newPoint->x = x;
	newPoint->y = y;
	newPoint->colour = colour;
	newPoint->previous = NULL;
	newPoint->next = pointHeader;
	if (newPoint->next != NULL)
	{
      	newPoint->next->previous = newPoint;
	}
	pointHeader = newPoint;
	return newPoint;
}

void destroyObject(OBJECT *theObject, OBJECT **listHeader)
{
	if (theObject == *listHeader)
	{
		*listHeader = theObject->next;
	}
	else
	{
		theObject->previous->next = theObject->next;
	}

	if (theObject->next != NULL)
	{
		theObject->next->previous = theObject->previous;
	}
	free(theObject);
}

void randomizeMap()
{
	OBJECT *theRock = rockHeader;
	OBJECT *theRockSave = rockHeader;
	while (theRock != NULL)
	{
		theRockSave = theRock->next;
		destroyObject(theRock, &rockHeader);
		theRock = theRockSave;
	}
   pointHeader = NULL;
   for (int i = 0; i < NUMBLOCKS; i ++)
	{
   	createRock();
	}
}
