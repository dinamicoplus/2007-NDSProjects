#include <PA9.h> 
int main()
{
PA_Init3D();//init
while(1) 
{ 
PA_Init3DDrawing(0.0,0.0,1.0,0.0,0.0,0.0);
glPushMatrix(); 
PA_3DBox(0.0,0.0,0.0,0.5,0.1,1.0,0.0,0.0,0.0,255,0,0);//box
glPopMatrix(1);
glFlush();//show
}

return 0;
}//

