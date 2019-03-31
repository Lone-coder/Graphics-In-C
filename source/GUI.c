#include "ConsoleGUI.h"

void click();

void main()
{
	CreateConsole("GUI in console",300,200,2,2);
	SetBGcolor(DARK_GREY);
	
	Button b1={screenwidth()/2,screenheight()/2-35,100,25};
	b1.color=RED;
	b1.textColor=WHITE;
	b1.label="BUTTON1";
	b1.Onclick=click;
	
	Button b2={screenwidth()/2,screenheight()/2,100,25};
	b2.color=RED;
	b2.textColor=WHITE;
	b2.label="CLICK ME";
	b2.Onclick=click;
	
	Button b3={screenwidth()/2,screenheight()/2+35,100,25};
	b3.color=RED;
	b3.textColor=WHITE;
	b3.label="BUTTON2";
	b3.Onclick=click;
	
	NumOfButtons(3);	
	Buttons[0]=b1;
	Buttons[1]=b2;
	Buttons[2]=b3;
	
	Panel p1={screenwidth()/2,screenheight()/2,150,120};
	p1.color=WHITE;
	
	Panel p2={screenwidth()/2,screenheight()-13,300,25};
	p2.color=WHITE;
	
	Panel p3={screenwidth()/2,7,screenwidth(),15};
	p3.color=WHITE;
	
	LoadingBar lb;
	lb.bordercolor=WHITE;
	lb.fillcolor=WHITE;
	lb.ox=screenwidth()/2;
	lb.oy=screenheight()/2;
	lb.width=screenwidth()/2;
	lb.height=15;
	lb.loadvalue=0;

	OnUpdate()
	{
		MakeLoadingBar(&lb);
	
		DrawFrame(TRUE);
			
		if(lb.loadvalue<=lb.endvalue){
			lb.loadvalue+=2;
		}
		else
		{
			goto Menu;
		}
	}
	
	Menu:
		
	OnUpdate()
	{
		MakePanel(p1);
		MakePanel(p2);
		MakePanel(p3);
		
		printString("CREATED BY ABHIJITH_C_V",screenwidth()/2-80,screenheight()-13,MAGENTA);
		printString("FILE",10,7,MAGENTA);
		printString("EDIT",50,7,MAGENTA);
		printString("SETTINGS",90,7,MAGENTA);
		
		MakeButton(b1,TRUE,DARK_RED);
		MakeButton(b2,TRUE,DARK_RED);
		MakeButton(b3,TRUE,DARK_RED);
		
		GetInput();
		DrawFrame(TRUE);					
	}

}
	
void click()
{
	printString("YOU CLICKED A BUTTON",screenwidth()/2-60,screenheight()-45,BLACK);
}	

