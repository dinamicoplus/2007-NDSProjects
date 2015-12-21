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
extern const unsigned char Ball1_Sprite[1024] __attribute__ ((aligned (4))) ;  // Pal : Ball1_Pal
extern const unsigned char monster1_Sprite[1024] __attribute__ ((aligned (4))) ;  // Pal : monster1_Pal
extern const unsigned char monster2_Sprite[1024] __attribute__ ((aligned (4))) ;  // Pal : monster2_Pal
extern const unsigned char porteria_Sprite[2048] __attribute__ ((aligned (4))) ;  // Pal : porteria_Pal

// Background files : 
extern const int back_Info[3]; // BgMode, Width, Height
extern const unsigned short back_Map[1024] __attribute__ ((aligned (4))) ;  // Pal : back_Pal
extern const unsigned char back_Tiles[128] __attribute__ ((aligned (4))) ;  // Pal : back_Pal
extern PAGfx_struct back; // background pointer


// Palette files : 
extern const unsigned short Ball1_Pal[5] __attribute__ ((aligned (4))) ;
extern const unsigned short monster1_Pal[20] __attribute__ ((aligned (4))) ;
extern const unsigned short monster2_Pal[16] __attribute__ ((aligned (4))) ;
extern const unsigned short porteria_Pal[3] __attribute__ ((aligned (4))) ;
extern const unsigned short back_Pal[2] __attribute__ ((aligned (4))) ;


#endif

