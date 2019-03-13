#include "ConsoleGUI.h"

char a[1]="A";
void main()
{
	OnStart()
	{
		CreateConsole("Test",200,200,2,2);
		SetBGcolor(BG_WHITE);		
	}
	
	OnUpdate()
	{		
		putchara('A',100,20,FG_GREEN);
		putchara('B',107,20,FG_GREEN);
		putchara('C',114,20,FG_GREEN);
		putchara('D',100,30,FG_GREEN);
		putchara('E',107,30,FG_GREEN);
		putchara('F',114,30,FG_GREEN);
		putchara('G',100,40,FG_GREEN);
		putchara('H',107,40,FG_GREEN);
		putchara('I',114,40,FG_GREEN);
		putchara('J',100,50,FG_GREEN);
		putchara('K',107,50,FG_GREEN);
		putchara('L',114,50,FG_GREEN);
		putchara('M',100,60,FG_GREEN);
		putchara('N',107,60,FG_GREEN);
		putchara('O',114,60,FG_GREEN);
		putchara('P',100,70,FG_GREEN);
		putchara('Q',107,70,FG_GREEN);
		putchara('R',114,70,FG_GREEN);
		putchara('S',100,80,FG_GREEN);
		putchara('T',107,80,FG_GREEN);
		putchara('U',114,80,FG_GREEN);
		putchara('V',100,90,FG_GREEN);
		putchara('W',107,90,FG_GREEN);
		putchara('X',114,90,FG_GREEN);
		putchara('Y',100,100,FG_GREEN);
		putchara('Z',107,100,FG_GREEN);
		
		printString("HELLO WORLD",3,4,FG_BLUE);
		
		
		DrawFrame(TRUE);
	}
}
