
// Includes
#include <PA9.h>       // Include for PA_Lib
#include "gfx/all_gfx.c"
#include "gfx/all_gfx.h"
#include "cumple.h"

u8 MicData[100000]; // Array we will use to save the microphone...


// Function: main()
int main(int argc, char ** argv)
{
	PA_Init();    // Initializes PA_Lib
	PA_InitVBL(); // Initializes a standard VBL
	PA_InitText(1, 0);

	PA_InitSound();  // Init the sound system
	
	
	PA_LoadSpritePal(0,0,(void*)tarta_Pal);
	PA_CreateSprite(0,0,(void*)tarta_Sprite, OBJ_SIZE_64X64,1, 0, 100, 64);	


	PA_StartSpriteAnim(0,0,0,1,2);

	// Infinite loop to keep the program running
	while (1)
	{
		PA_MicReplay(0, MicData, 100000);
		if (PA_MicGetVol() > 200) 
		{
		   PA_StartSpriteAnim(0,0,2,2,2);
			PA_PlaySimpleSound(1,cumple);
			PA_OutputSimpleText(1,7,12,"Felicidades, Papa!");
		}			

		PA_WaitForVBL();	
	}
	
	return 0;
} // End of main()
