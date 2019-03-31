#ifndef _CONSOLEGUI_H_
#define _CONSOLEGUI_H_

#include "2DGC.h"
#include "PixelText.h"

VOID ErrorExit(LPSTR);
VOID KeyEventProc(KEY_EVENT_RECORD); 
VOID MouseEventProc(MOUSE_EVENT_RECORD); 
VOID ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD);

DWORD cNumRead, fdwMode, n; 
INPUT_RECORD irInBuf[128]; 
int offsetx, offsety;


char *toString(int num);

typedef struct panel
{
	int ox,oy;
	int width,height;
	int color;
	
}Panel;

typedef void (*OnClickFunction)(void);
typedef struct button
{
	int ox,oy;
	int width,height;
	int color;
	int textColor;
	const char *label;
	OnClickFunction Onclick;
}Button;

typedef struct loadingbar
{
	int ox,oy;
	int width,height;
	int bordercolor;
	int fillcolor;
	int loadvalue;
	int endvalue;
		
}LoadingBar;

void MakeButton(Button,int,int);
void MakePanel(Panel);
void MakeLoadingBar(LoadingBar *);
void printString(const char *,int,int,int);
void GetInput();

void MakeButton(Button B,int border,int bdcol)
{
	int x1,x2,y1,y2;
	
	x1=B.ox-(B.width/2);
	x2=B.ox+(B.width/2);
	y1=B.oy-(B.height/2);
	y2=B.oy+(B.height/2);
	
	Fillrect(x1,y1,x2,y2,B.color);
	
	if(border)
	{
		for(i=x1;i<=x2;i++)
		{
			for(j=y1;j<=y2;j++)
			{
				if(i==x1 || i==x2 || j==y1 || j==y2)
					putpixel(i,j,bdcol);
			}
		}
	}
	
	if(B.label!=NULL)
	{
		printString(B.label,x1+10,B.oy,B.textColor);
	}
}

void MakePanel(Panel P)
{
	int x1,x2,y1,y2;
	
	x1=P.ox-(P.width/2);
	x2=P.ox+(P.width/2);
	y1=P.oy-(P.height/2);
	y2=P.oy+(P.height/2);
	
	Fillrect(x1,y1,x2,y2,P.color);
}

void MakeLoadingBar(LoadingBar *Lb)
{
	int x1,x2,y1,y2;
	
	x1=Lb->ox-(Lb->width/2);
	x2=Lb->ox+(Lb->width/2);
	y1=Lb->oy-(Lb->height/2);
	y2=Lb->oy+(Lb->height/2);
	
	Lb->endvalue=x2-2;
	
	DrawRect(Lb->ox,Lb->oy,Lb->width,Lb->height,Lb->bordercolor);
	Fillrect(x1+2,y1+2,Lb->loadvalue,y2-2,Lb->fillcolor);
	
}

void printString(const char *s,int x,int y,int color)
{
	int i=0;
	int space=0;
	
	while(*(s+i)!=0)
	{
		putchara(*(s+i),x+space,y,color);
		space+=6;
		i++;
	}
}

int stringsize(char *s)
{
	int n=0;
	while(*(s+n)!=0)
		n++;
	return n;
}

char *toString(int num)
{
	int n=num;
	int numdigits;
	char *number;
		
	while(n!=0)
	{
		n=n/10;
		numdigits++;
	}
	
	number=(char*)malloc(sizeof(char)*numdigits);
	
	itoa(num,number,10);
	
	return number;	
}

//---------------Input handling--------------------//


Button *Buttons;
int buttonNum;

void NumOfButtons(int num)
{
	buttonNum=num;
	Buttons=(Button*)malloc(num*sizeof(Button));
}

void GetInput()
{
        ReadConsoleInput(rHnd,      // input buffer handle 
                		irInBuf,     // buffer to read into 
                		128,         // size of read buffer 
                		&cNumRead); // number of records read  
 
        // Dispatch the events to the appropriate handler. 
        for (n = 0; n< cNumRead; n++) 
        {
            switch(irInBuf[n].EventType) 
            { 
                case KEY_EVENT: // keyboard input 
                    KeyEventProc(irInBuf[n].Event.KeyEvent);
                    break; 
 
                case MOUSE_EVENT: // mouse input 
                
                        offsetx = irInBuf[n].Event.MouseEvent.dwMousePosition.X;
        				offsety = irInBuf[n].Event.MouseEvent.dwMousePosition.Y;
        				//DrawRect(offsetx,offsety,10,10,BLACK);
        				for(i=0;i<buttonNum;i++)
        				{
        					if( offsetx>Buttons[i].ox-(Buttons[i].width/2) && offsetx<Buttons[i].ox+(Buttons[i].width/2) 
							&& offsety>Buttons[i].oy-(Buttons[i].height/2) &&offsety<Buttons[i].oy+(Buttons[i].height/2))
							{
                				DrawRect(Buttons[i].ox,Buttons[i].oy,Buttons[i].width+6,Buttons[i].height+5,randcolor());							
							}
	
						}
                    MouseEventProc(irInBuf[n].Event.MouseEvent);
                    break; 
 
                case WINDOW_BUFFER_SIZE_EVENT: // scrn buf. resizing 
                    //ResizeEventProc( irInBuf[i].Event.WindowBufferSizeEvent ); 
                    break; 
 
                case FOCUS_EVENT:  // disregard focus events 
 
                case MENU_EVENT:   // disregard menu events 
                    break; 
 
                default: 
                    //ErrorExit("Unknown event type"); 
                    break; 
            } 
        }
}

VOID KeyEventProc(KEY_EVENT_RECORD ker)
{
//    printf("Key event: ");
//
//        printf("key pressed\n");
//    else printf("key released\n");
}

VOID MouseEventProc(MOUSE_EVENT_RECORD mer)
{
#ifndef MOUSE_HWHEELED
#define MOUSE_HWHEELED 0x0008
#endif
    
    switch(mer.dwEventFlags)
    {
        case 0:

            if(mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
            {           	
				for(i=0;i<buttonNum;i++)
				{
					if( offsetx>Buttons[i].ox-(Buttons[i].width/2) && offsetx<Buttons[i].ox+(Buttons[i].width/2) 
					&& offsety>Buttons[i].oy-(Buttons[i].height/2) &&offsety<Buttons[i].oy+(Buttons[i].height/2))
					{
						Buttons[i].Onclick();					
					}

				}
            }
            else if(mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
            {
                //printf("right button press \n");
            }
            else
            {
                //printf("button press\n");
            }
            break;
            
        case DOUBLE_CLICK:
            //printf("double click\n");
            break;
        case MOUSE_HWHEELED:
            //printf("horizontal mouse wheel\n");
            break;
        case MOUSE_MOVED:
            //printf("mouse moved\n");
            break;
        case MOUSE_WHEELED:
            //printf("vertical mouse wheel\n");
            break;
        default:
            //printf("unknown\n");
            break;
    }
}

VOID ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD wbsr)
{
    //printf("Resize event\n");
    //printf("Console screen buffer is %d columns by %d rows.\n", wbsr.dwSize.X, wbsr.dwSize.Y);
} 

#endif
