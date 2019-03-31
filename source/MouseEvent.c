#include "ConsoleGUI.h"

void ChangeColor();

int squarecolor=BLACK;

void main()
{
	CreateConsole("Mouse Event testing",200,200,2,2);
	SetBGcolor(WHITE);
	
	Button left={screenwidth()/2,screenheight()-30,100,25};
	left.color=GREEN;
	left.label="CHANGE COLOR";
	left.textColor=WHITE;
	left.Onclick=ChangeColor;
	
//	Button right={screenwidth()/2+20,screenheight()-30,25,25};
//	right.color=GREEN;
//	right.label="R";
//	right.textColor=WHITE;
//	right.Onclick=ChangeColor;
	
	NumOfButtons(1);
	Buttons[0]=left;
//	Buttons[1]=right;
	
	Panel ColorSquare;
	ColorSquare.ox=screenwidth()/2;
	ColorSquare.oy=80;
	ColorSquare.width=130;
	ColorSquare.height=130;
	ColorSquare.color=squarecolor;
	
	OnUpdate()
	{
		MakePanel(ColorSquare);
		ColorSquare.color=squarecolor;
		MakeButton(left,TRUE,DARK_GREEN);
		//MakeButton(right,TRUE,DARK_GREEN);
		
		
		GetInput();
		DrawFrame(TRUE);
	}
}

void ChangeColor()
{
	squarecolor=randcolor();
}
