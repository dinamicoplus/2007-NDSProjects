// Includes
#include <PA9.h>      
#include "gfx/all_gfx.c"
#include "gfx/all_gfx.h"
#include "minuano.h"

int main(void){
   s32 x = 0;
   s32 y = 0;
   s32 x1= 150;
   s32 y1= 0;
 
	PA_Init(); //PAlib inits
	PA_InitVBL();
	PA_InitSound();
	PA_PlaySimpleSound(0, minuano);
	PA_InitText(1,1);
	PA_OutputSimpleText(1,1,1,"Hecho por Marcos Brito");
	PA_OutputSimpleText(1,1,23,"Futbol Match!");
	
	PA_LoadSpritePal(0,0,(void*)monster1_Pal);						
	PA_CreateSprite(0,0,(void*)monster1_Sprite,OBJ_SIZE_32X32,1,0,50, 50);
	PA_LoadSpritePal(0,1,(void*)monster2_Pal); 
	PA_CreateSprite(0,1,(void*)monster2_Sprite,OBJ_SIZE_32X32,1,1,50, 50); 
	while(1) // Infinite loops
	{
	   if (y>=0)  y += Pad.Held.Down - Pad.Held.Up;
	   else  y=0;
	   if (y<=153)  y += Pad.Held.Down - Pad.Held.Up;
	   else  y=153;
	   if (x>=0)  x += Pad.Held.Right - Pad.Held.Left;
	   else  x=0;
	   if (x<=223)  x += Pad.Held.Right - Pad.Held.Left;
	   else  x=223;			
		PA_SetSpriteXY(0,0,x,y);
		
		if (y1>=0)  y1 += Pad.Held.B - Pad.Held.X;
	   else  y1=0;
	   if (y1<=153)  y1 += Pad.Held.B - Pad.Held.X;
	   else  y1=153;
	   if (x1>=0)  x1 += Pad.Held.A - Pad.Held.Y;
	   else  x1=0;
	   if (x1<=223)  x1 += Pad.Held.A - Pad.Held.Y;
	   else  x1=223;	
		PA_SetSpriteXY(0,1,x1,y1);		
	   
   	if (PA_Distance(x, y, x1, y1) < 1024) PA_OutputText(1, 2, 10, "Collision !!");
   	else PA_OutputSimpleText(1,2,10,"                 ");
		
		PA_WaitForVBL();    
	}
return 0;
}
