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
extern const unsigned char monster1_Sprite[1024] __attribute__ ((aligned (4))) ;  // Pal : monster1_Pal
extern const unsigned char monster2_Sprite[1024] __attribute__ ((aligned (4))) ;  // Pal : monster2_Pal

// Palette files : 
extern const unsigned short monster1_Pal[20] __attribute__ ((aligned (4))) ;
extern const unsigned short monster2_Pal[16] __attribute__ ((aligned (4))) ;


#endif

