// Includes
#include <PA9.h>     
#include "gfx/all_gfx.c"
#include "gfx/all_gfx.h"


#define MONSTERS 30 
#define SCREENHOLE 48
#define BALASS 10

void MoveMonsters(void);
void NaveActs(void);
void Disparo(s16 x, s16 y);
void Bala (void);
void deletesprite(u8 spritenumber);
u8 getsprite();
u8 sprite[128];
u8 nave;

typedef struct{
	s16 x, y; 
	s16 vx, vy; 
	s16 sprite;
}monsinfo;

monsinfo monster[MONSTERS];

	s32 count = 0;
	s32 pos = 0;
	s32 dir = 1;
	s32 naveX = 127;

typedef struct{
   s16 x, y;
   s16 sprite;
   s16 v;
}balainfo;
balainfo bala[100000];
s32 numbalas =0;

int main(int argc, char ** argv)
{
	PA_Init();    // Initializes PA_Lib
	PA_InitVBL(); // Initializes a standard VBL
	
	PA_InitText(0, 0);
	
	PA_DualLoadSpritePal(0, (void*)monster_Pal);
	
	nave=getsprite();
	PA_DualCreateSprite(nave, (void*)nave_Sprite, OBJ_SIZE_16X16, 1, 0, naveX,385);
	
	
	s32 i;
	
	for (i = 0; i < MONSTERS; i++)
	{
		monster[i].x = (i%10)*16;
		monster[i].y = ((i/10)+1)*16;
		monster[i].sprite =getsprite();
		PA_DualCreateSprite(monster[i].sprite, (void*)monster_Sprite, OBJ_SIZE_16X16, 1, 0, monster[i].x,monster[i].y-16);
		PA_DualStartSpriteAnim(monster[i].sprite,0,1,2);
	}
	
	while (1)
	{
  		MoveMonsters();
  		NaveActs();
  		Bala();
  		for(i=0; i<MONSTERS; i++)	PA_OutputText(0,i*2,0,"%d",monster[i].sprite);
  		for(i=0; i<numbalas; i++)	PA_OutputText(0,i*2,3,"%d",bala[i].sprite);
  		PA_OutputText(0,0,4,"%d",nave);
		PA_WaitForVBL();
	}
	
	return 0;
} // End of main()

void MoveMonsters(void)
{
   count++;
   s32 i;
	if (count%100 == 99) 
	{
	   for(i=0; i < MONSTERS; i++)
	   {
	      monster[i].x += 16*dir;
	   }
		pos+=dir;
		if (pos==0)
		{
		   dir=1;
			for(i=0; i < MONSTERS; i++)
			{
			   monster[i].y +=  16;
			}
		}
		if(pos==6)
		{
		   dir=-1;
		   for(i=0; i <MONSTERS; i++)
		   {
		      monster[i].y += 16;
			}
		}			
	}
	for(i=0; i < MONSTERS; i++)
	{					   
	  	PA_DualSetSpriteXY(monster[i].sprite, monster[i].x, monster[i].y-16);
	}
} 	
void NaveActs(void)
{
		if (naveX>=0)  naveX += Pad.Held.Right - Pad.Held.Left;
	   else  naveX=0;
	   if (naveX<=223)  naveX += Pad.Held.Right - Pad.Held.Left;
	   else  naveX=223;
	   PA_DualSetSpriteXY(nave,naveX,385);
	   if (Pad.Newpress.A) Disparo(naveX+3,382);
}
void Disparo(s16 x, s16 y)
{
   bala[numbalas].x=x;
   bala[numbalas].y=y;
   bala[numbalas].sprite = getsprite();
   bala[numbalas].v=6;
   PA_DualCreateSprite(bala[numbalas].sprite,(void*)bala_Sprite,OBJ_SIZE_8X8, 1, 0,bala[numbalas].x,bala[numbalas].y);
   numbalas++;
}
u8 getsprite(){
   int i;
   for(i=0;i<128;i++)
	{
      if(sprite[i]==0)
		{
         sprite[i]=1;
			return i;
		}			
   }
	return -1;
}
void deletesprite(u8 spritenumber){
	sprite[spritenumber]=0;
		PA_DeleteSprite(1,spritenumber);
}
void Bala(void)
{
   s32 i;
   for(i=0; i<numbalas; i++)
   {
      bala[i].y-=bala[i].v;
      PA_DualSetSpriteXY(bala[i].sprite,bala[i].x,bala[i].y);
      s32 j;
      if (bala[i].y<0)
		{
		   deletesprite(bala[i].sprite);
		   bala[i].v=0;
		}   
      for(j=0; j<MONSTERS; j++)
      {
	   	if((bala[i].y < monster[j].y) && (bala[i].y > monster[j].y-16) && bala[i].x<monster[j].x+16 && bala[i].x>monster[j].x)
			{
		     	if(sprite[bala[i].sprite]!=0)
				{
				   deletesprite(monster[j].sprite);
		     		deletesprite(bala[i].sprite);
		    		bala[i].v=0;
		   	} 		
			}
		}		
	}
}	   
