#include "ConsoleGUI.h"

void main()
{
	CreateConsole("GUI in console",300,200,2,2);
	SetBGcolor(BG_DARK_GREY);

	
	Button b1={screenwidth()/2,screenheight()/2-30,100,25};
	b1.color=FG_RED;
	b1.textColor=FG_WHITE;
	b1.label="PLAY";
	
	Button b2={screenwidth()/2,screenheight()/2,100,25};
	b2.color=FG_RED;
	b2.textColor=FG_WHITE;
	b2.label="SETTINGS";
	
	Button b3={screenwidth()/2,screenheight()/2+30,100,25};
	b3.color=FG_RED;
	b3.textColor=FG_WHITE;
	b3.label="QUIT";
	
	Panel p1={screenwidth()/2,screenheight()/2,150,120};
	p1.color=FG_WHITE;
	
	Panel p2={screenwidth()/2,screenheight()/2+10,300,25};
	p2.color=FG_WHITE;
	
	Panel p3={screenwidth()/2,7,screenwidth(),15};
	p3.color=FG_WHITE;
	
	OnUpdate()
	{
		MakePanel(p1);
//		MakePanel(p2);
		MakePanel(p3);
		//printString("CREATED BY: ABHIJITH_C_V",screenWidth/2-10,screenHeight/2+15,FG_MAGENTA);
//		printString("FILE",2,1,FG_MAGENTA);
//		printString("EDIT",9,1,FG_MAGENTA);
//		printString("SETTINGS",16,1,FG_MAGENTA);
		MakeButton(b1,TRUE,FG_DARK_RED);
		MakeButton(b2,TRUE,FG_DARK_RED);
		MakeButton(b3,TRUE,FG_DARK_RED);

		//printString("HELLO WORLD",3,4,FG_BLUE);
		
		
		
		DrawFrame(TRUE);			
	}

}
