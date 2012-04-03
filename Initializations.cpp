#include "Definitions.h"
#include "Globals_Extern.h"

void initializeShip();
BITMAP *makeBitmap(char *aFilename);
extern void incrementMoveTimer();
extern void incrementTimer();
extern OBJECT *createRock();


void allegInitializations()
{
	int error = 0;
	srand(time(0));
   error |= allegro_init ();
	algif_init ();

   	set_color_depth (32);
   	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1024,768,0,0);
   	//set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, 1024,768,0,0);
   	install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
   	error |= install_keyboard ();
   	install_mouse();
   	error |= install_timer();
   	error |= install_int_ex(incrementTimer, BPS_TO_TIMER(130));
   	error |= install_int_ex(incrementMoveTimer, BPS_TO_TIMER(30));
	if (error)
	{
		set_gfx_mode(GFX_TEXT, 1024,768,0,0);
		allegro_message("Allegro Failed to Initialize!");
		exit(1);
	}
	screenBuffer = create_bitmap(1024, 768);

}

void initializeShip()
{
	theShip.picture = makeBitmap("Images/Lander.gif");
	theShip.x = 462;
	theShip.y = 359;
	theShip.rotation = 0;
	theShip.velRotation = 0;
	theShip.velX = 0;
	theShip.velY = 0;
	theShip.rocketPower = 0;
	theShip.width = 20;
	theShip.height = 25;
	theShip.maxHealth = 100;
	theShip.health = 100;
	theShip.fuel = 1000;
	theShip.maxFuel = 1000;
	theShip.mass = 1000;
	theShip.next = NULL;
	theShip.previous = NULL;

   rock50 = makeBitmap("Images/Block50.gif");
	for (int i = 0; i < NUMBLOCKS; i ++)
	{
   	createRock();
	}
	
}


BITMAP *makeBitmap(char *aFilename)
{
	BITMAP *bitmapPointer;
	if (!(bitmapPointer = load_bitmap(aFilename, NULL)))
	{
      set_gfx_mode(GFX_TEXT, 1024,768,0,0);
		allegro_message("Error! Could not find the file \"%s\"!", aFilename);
		exit(1);
	}
	return(bitmapPointer);
}
