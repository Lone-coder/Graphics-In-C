#include "2DGC.h"

void main()
{
	FILE* file;
	char c;
	char alpha='W';
	char cho[35];


	CreateConsole("Text",120,40,7,14);
	SetBGcolor(BLACK);

	file = fopen("\CharInfo\CGtext.cif","r");

	if(file == NULL)
		return;

	while(c!=EOF)
	{
		c=fgetc(file);

		if(c==alpha)
		{
			c=fgetc(file);

			while(i<35)
			{
				cho[i]=fgetc(file);
				i++;
			}

			break;
		}
	}

	fclose(file);

	OnUpdate()
	{
		for(i=0;i<7;i++)
		{
			for(j=0;j<5;j++)
			{
				if(cho[j+i*5]=='.')
					putpixel(j,i,BLACK);

				if(cho[j+i*5]=='o')
					putpixel(j,i,BLUE);
			}
		}

		DrawFrame(TRUE);
	}

}
