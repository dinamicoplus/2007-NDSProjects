#include <PA9.h> 
void main(void)
{
	PA_Init();
	PA_InitVBL();
	PA_InitText(1,1);
	PA_OutputSimpleText(1,1,1,"Hola Mundo.");
	PA_OutputSimpleText(1,1,2,"Hecho por Marcos Brito.");
	while(1)
	{
	   if (Stylus.Held) PA_OutputSimpleText(1,1,3,"El Stylus esta presionado      ");
	   if (Stylus.Held==0) PA_OutputSimpleText(1,1,3,"El Stylus no esta presionado");
	}
	
	return 0;
} // End of main()
