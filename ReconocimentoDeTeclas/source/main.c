// Includes
#include <PA9.h>       // Include for PA_Lib

// Function: main()
int main(int argc, char ** argv)
{
	PA_Init();    // Initializes PA_Lib
	PA_InitVBL(); // Initializes a standard VBL
	
PA_InitText(1, 0);  // Inicia el sistema de textos en la pantalla superior
PA_Init8bitBg(0, 0); // Dibujaremos los caracteres en este background...
	
u16 *pal = (u16*)PAL_BG0;
pal[1] = PA_RGB(31, 31, 31);
char letter = 0; // Siguiente letra a escribir.
char text[200];  // Este ha de ser nuestro texto.
	
PA_WaitForVBL();
 
u8 nletter = 0;
	
// Loop infinito para mantener el programa en marcha
while (1)
{
	   
	if(Stylus.Newpress) PA_Clear8bitBg(0); // Resetea la pantaña cuando empezamos un nuevo caracter
	   
	PA_8bitDraw(0, 1);
	   	   
	char letter = PA_CheckLetter(); // ¡¡¡ Devuelve la letra!!!
		
	if (letter > 31) { // Esta es una letra nueva
		text[nletter] = letter;
		nletter++;
	}
	else if ((letter == PA_BACKSPACE)&&nletter) { // Espacio pulsado
		nletter--;
		text[nletter] = ' '; // Borra la ultima letra
	}
	else if (letter == '\n'){ // Intro pulsado
		text[nletter] = letter;
		nletter++;
	}
		
	PA_OutputText(1, 2, 2, text); // Escribe el texto
		
	PA_OutputSimpleText(1, 0, 10, "Draw a PAGraffiti letter to have it recognized by the system...");
		
	PA_WaitForVBL();
}
	
	return 0;
} // End of main()
