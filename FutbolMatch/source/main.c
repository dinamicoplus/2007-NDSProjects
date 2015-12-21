// Includes
#include <PA9.h> 
#include "gfx/all_gfx.h"
#include "gfx/all_gfx.c"
#include "prelude.h"



// Function: main()
int main(int argc, char ** argv)
{
	PA_Init();    // Initializes PA_Lib
	PA_InitVBL(); // Initializes a standard VBL
	
	PA_InitText(1,1);
	
	PA_OutputSimpleText(1,1,1,"Hecho por Marcos Brito");
	PA_OutputSimpleText(1,1,3,"Futbol Match!");
	
	PA_InitSound();
	
	PA_SetDefaultSound(255,11025,0);
	PA_PlaySoundRepeat(0,prelude);
	
	
	PA_EasyBgLoad(0,0,back);
	
	PA_LoadSpritePal(0,0,(void*)monster1_Pal);
	PA_CreateSprite(0,0,(void*)monster1_Sprite,OBJ_SIZE_32X32,1,0,1,1);
	PA_LoadSpritePal(0,1,(void*)monster2_Pal);
	PA_CreateSprite(0,1,(void*)monster2_Sprite,OBJ_SIZE_32X32,1,1,150,1);
	PA_LoadSpritePal(0,2,(void*)Ball1_Pal);
	PA_CreateSprite(0,2,(void*)Ball1_Sprite,OBJ_SIZE_32X32,1,2,127,95);
	PA_LoadSpritePal(0,3,(void*)porteria_Pal);
	PA_CreateSprite(0,3,(void*)porteria_Sprite,OBJ_SIZE_32X64,1,3,1,65);
	PA_CreateSprite(0,4,(void*)porteria_Sprite,OBJ_SIZE_32X64,1,3,240,65);
	
	s32 x1 = 1; s32 y1 = 1;	s32 x2 = 223; s32 y2 = 1; 
	s32 bx = 127; s32 by = 95; s32 vbx=0; s32 vby=2; s32 i =0;
	
	
	s32 marc1 = 0;
	s32 marc2 = 0;
	
	
	while (1)
	{
	   PA_OutputText(1,3,10,"Coco rojo: %d",marc1);
	   PA_OutputText(1,3,13,"Coco verde: %d",marc2);
	   
	   //Coco1
	   if (y1>=0)  y1 += Pad.Held.Down - Pad.Held.Up;
	   else  y1=0;
	   if (y1<=153)  y1 += Pad.Held.Down - Pad.Held.Up;
	   else  y1=153;
	   if (x1>=0)  x1 += Pad.Held.Right - Pad.Held.Left;
	   else  x1=0;
	   if (x1<=223)  x1 += Pad.Held.Right - Pad.Held.Left;
	   else  x1=223;			
		PA_SetSpriteXY(0,0,x1,y1);
		
		//Coco2
		if (y2>=0)  y2 += Pad.Held.B - Pad.Held.X;
	   else  y2=0;
	   if (y2<=153)  y2 += Pad.Held.B - Pad.Held.X;
	   else  y2=153;
	   if (x2>=0)  x2 += Pad.Held.A - Pad.Held.Y;
	   else  x2=0;
	   if (x2<=223)  x2 += Pad.Held.A - Pad.Held.Y;
	   else  x2=223;	
		PA_SetSpriteXY(0,1,x2,y2);
		
		//Bola
		bx += vbx;
		by += vby;
		
		if ((bx <= 0) && (vbx < 0)) vbx = -vbx; 
		else if ((bx+32 >= 256)&&(vbx > 0)) vbx = -vbx;
		
		if ((by <= 0) && (vby < 0)) vby = -vby;
		else if ((by+32>= 192)&& (vby > 0)) vby = -vby;	
		
		PA_SetSpriteXY(0,2,bx,by);	
		
		if (PA_Distance(bx, by, x1, y1) < 32*32)
		{
			vbx = (bx-x1)/8; 
			vby = (by-y1)/8;
		}
		if (PA_Distance(bx, by, x2, y2) < 32*32)
		{
			vbx = (bx-x2)/8;
			vby = (by-y2)/8;
		}
		//Gol
		if (bx<10 && by>35 && by<120)
		{
		   marc1+=1,
		   x1=1; y1=1; x2=223; y2=1; bx=127; by=95;
		   PA_WaitForVBL();
		   i=PA_RandMinMax(-255,255);
		   vbx = PA_Cos(i)*3/255;
		   vby = PA_Sin(i)*3/255;
		}		
					
		if (bx>215 && by>35 && by<120)
		{
		   marc2+=1;
		   x1=1; y1=1; x2=223; y2=1; bx=127; by=95;
		   PA_WaitForVBL();
		   i=PA_RandMinMax(-255,255);
		   vbx = PA_Cos(i)*3/255;
		   vby = PA_Sin(i)*3/255;
		}		

	
		PA_WaitForVBL();
	}
	
	return 0;
} // End of main()
