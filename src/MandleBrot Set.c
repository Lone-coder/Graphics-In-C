#include "Headers/2DGC.h"

float map(int x,float in_min,float in_max,float out_min,float out_max);

const float r_min = -1;
const float r_max = 1;

const int max_iteration = 100;

int main(int argc, char* argv[])
{
	CreateConsole("Mandlebrot Set",600,300,1,1);

	int i = 0;
	int j = 0;

	//Computing elements in Mandlebrot set
	for(i = 0; i < screenwidth(); i++)
	{
		for(j = 0; j < screenheight(); j++)
		{
			float a = map(i, 0, screenwidth(), r_min, r_max);
			float b = map(j, 0, screenheight(), r_min, r_max);

			int n = 0;

			float ca = a;
			float cb = b;

			while(n < max_iteration)
			{
				float aa = a * a - b * b;
				float bb = 2*a*b;

				a = aa + ca;
				b = bb + cb;

				if(abs(a+b) > 16)
					break;
				n++;
			}

			if(n == max_iteration)
			{
				putpixel(i, j, BLACK, 'O');
			}
			else
				putpixel(i, j, WHITE, 'P');
		}
	}

	OnUpdate()
	{
		DrawFrame(FALSE);
	}

	return 0;
}

float map(int x,float in_min,float in_max,float out_min,float out_max)
{
	return (x-in_min)*(out_max-out_min)/(in_max-in_min)+ out_min;
}
