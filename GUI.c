#include "ConsoleGUI.h"

void main()
{
	CreateConsole("GUI in console",300,200,1,1);
	SetBGcolor(BG_DARK_GREY);

	
	Button b1={screenwidth()/2,screenheight()/2-7,30,5};
	b1.color=FG_RED;
	b1.textColor=FG_WHITE;
	b1.label="PLAY";
	
	Button b2={screenwidth()/2,screenheight()/2,30,5};
	b2.color=FG_RED;
	b2.textColor=FG_WHITE;
	b2.label="SETTINGS";
	
	Button b3={screenwidth()/2,screenheight()/2+7,30,5};
	b3.color=FG_RED;
	b3.textColor=FG_WHITE;
	b3.label="QUIT";
	
	Panel p1={screenwidth()/2,screenheight()/2,50,25};
	p1.color=FG_WHITE;
	
	Panel p2={screenwidth()/2,screenheight()/2+17,100,3};
	p2.color=FG_WHITE;
	
	Panel p3={screenwidth()/2,0,screenWidth,2};
	p3.color=FG_WHITE;
	
	OnUpdate()
	{
		MakePanel(p1);
		MakePanel(p2);
		MakePanel(p3);
		printString("CREATED BY: ABHIJITH_C_V",screenWidth/2-10,screenHeight/2+17,FG_MAGENTA,BG_WHITE);
		printString("FILE",2,1,FG_MAGENTA,BG_WHITE);
		printString("EDIT",9,1,FG_MAGENTA,BG_WHITE);
		printString("SETTINGS",16,1,FG_MAGENTA,BG_WHITE);
		MakeButton(b1,TRUE,FG_DARK_RED);
		MakeButton(b2,TRUE,FG_DARK_RED);
		MakeButton(b3,TRUE,FG_DARK_RED);
		
		//printStr("HELLO");
		
		DrawFrame();			
	}

}
