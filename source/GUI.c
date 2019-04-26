#include "ConsoleGUI.h"

void click();

void main()
{
	CreateConsole("GUI in console",300,200,2,2);
	SetBgColor(DARK_GREY);

	Button b1={midX(),screenheight()/2-35,100,25};
	b1.color=RED;
	b1.textColor=WHITE;
	b1.label="BUTTON 1";
	b1.Onclick=click;
	
	Button b2={ midX(),midY(),100,25};
	b2.color=GREEN;
	b2.textColor=WHITE;
	b2.label="BUTTON 2";
	b2.Onclick=click;
	
	Button b3={ midX(),screenheight()/2+35,100,25};
	b3.color=BLUE;
	b3.textColor=WHITE;
	b3.label="BUTTON 3";
	b3.Onclick=click;
	
	NumOfButtons(3);	
	Buttons[0]=b1;
	Buttons[1]=b2;
	Buttons[2]=b3;
	
	Panel p1={midX(),midY(),150,120};
	p1.color=WHITE;
	
	Panel p2={ midX(),screenheight()-13,300,25};
	p2.color=DARK_CYAN;
	
	Panel p3={ midX(),7,screenwidth(),15};
	p3.color= DARK_CYAN;
	
	LoadingBar lb;
	lb.bordercolor=WHITE;
	lb.fillcolor=WHITE;
	lb.ox=midX();
	lb.oy=midY();
	lb.width=screenwidth()/2;
	lb.height=15;
	lb.loadvalue=0;

	OnUpdate()
	{
		MakeLoadingBar(&lb);
	
		PrintString("LOADING", midX(), 85, WHITE);
		
		if(lb.loadvalue<lb.endvalue){
			lb.loadvalue+=3;
		}
		else
		{
			goto Menu;
		}
		
		DrawFrame(TRUE);
	}
	
	Menu:
		
	OnUpdate()
	{
		MakePanel(p1);
		MakePanel(p2);
		MakePanel(p3);
		
		PrintString("CREATED BY ABHIJITH C V",midX(),screenheight()-13,WHITE);
		PrintString("FILE",20,7, WHITE);
		PrintString("EDIT",60,7, WHITE);
		PrintString("SETTINGS",110,7, WHITE);
		
		MakeButton(b1);
		MakeButton(b2);
		MakeButton(b3);
		
		GetInput();
		DrawFrame(TRUE);					
	}

}
	
void click()
{
	PrintString("YOU CLICKED A BUTTON",midX(),30,WHITE);
}


