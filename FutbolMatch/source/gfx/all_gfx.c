//Gfx converted using Mollusk's PAGfx Converter

//This file contains all the .c, for easier inclusion in a project

#ifdef __cplusplus
extern "C" {
#endif

#include "all_gfx.h"


// Sprite files : 
#include "Ball1.c"
#include "monster1.c"
#include "monster2.c"
#include "porteria.c"

// Background files : 
#include "back.c"

// Palette files : 
#include "Ball1.pal.c"
#include "monster1.pal.c"
#include "monster2.pal.c"
#include "porteria.pal.c"
#include "back.pal.c"

// Background Pointers :
PAGfx_struct back = {(void*)back_Map, 1024, (void*)back_Tiles, 128, (void*)back_Pal, (int*)back_Info };


#ifdef __cplusplus
}
#endif

