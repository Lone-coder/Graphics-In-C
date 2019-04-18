#include "ConsoleGUI.h"

void main()
{
	CreateConsole("Calculator",150,200,2,2);
	SetBGcolor(GREY);
	
	OnUpdate()
	{
		DrawRect(75,25,140,40,DARK_GREY);
		DrawRect(75,125,140,140,DARK_GREY);
		
		DrawFrame(TRUE);
	}
}
