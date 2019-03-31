#include "ConsoleGUI.h"

int m,o;
char c='A';

void main()
{
	OnStart()
	{
		CreateConsole("Test",200,200,2,2);
		SetBGcolor(BLACK);
		
		printString("TEST FOR CHARACTER OUTPUT",3,4,WHITE);
		
		c='1';
		for(m=10;m<80;m+=7)
		{
			putchara(c,m,100,randcolor());
			c++;	
		}
		c='A';
		
		for(m=20;m<121;m+=10)
		{
			for(o=10;o<39;o+=7)
			{
				putchara(c,o,m,randcolor());
				c++;
			}
		}
	}
	
	DrawFrame(FALSE);
	
	OnUpdate()
	{		
		
	}
}
