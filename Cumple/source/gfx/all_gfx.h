//Gfx converted using Mollusk's PAGfx Converter

//This file contains all the .h, for easier inclusion in a project

#ifndef ALL_GFX_H
#define ALL_GFX_H

#ifndef PAGfx_struct
    typedef struct{
    void *Map;
    int MapSize;
    void *Tiles;
    int TileSize;
    void *Palette;
    int *Info;
} PAGfx_struct;
#endif


// Sprite files : 
extern const unsigned char tarta_Sprite[12288] __attribute__ ((aligned (4))) ;  // Pal : tarta_Pal

// Palette files : 
extern const unsigned short tarta_Pal[75] __attribute__ ((aligned (4))) ;


#endif

