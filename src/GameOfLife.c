#include "Headers/ConsoleGUI.h"

int main(int argc, char *argv[])
{
    CreateConsole("Game of Life : Cellular Automata",150,100,6,6);
    SetBgColor(BLACK);

    int i,j;


    int *cells=(int*)malloc(screenwidth()*screenheight()*sizeof(int));
    int *cells1=(int*)malloc(screenwidth()*screenheight()*sizeof(int));

    for(i=0; i<screenwidth()*screenheight(); i++)
    {
        cells[i]=random(0,2);
        cells1[i]=cells[i];
    }

    int numofneighbour=0;
    int generation;

    OnUpdate()
    {
        PrintString("GENERATION: ",40,screenheight()-10,WHITE);
        PrintString(ToString(generation),80,screenheight()-10,WHITE);

        for(i=1; i<screenwidth()-1; i++)
        {
            for(j=1; j<screenheight()-20; j++)
            {
                numofneighbour = cells1[(i-1)+((j-1)*screenwidth())] + cells1[(i-0)+((j-1)*screenwidth())] + cells1[(i+1)+((j-1)*screenwidth())]+
                                 cells1[(i-1)+((j-0)*screenwidth())] + 0 + cells1[(i+1)+((j-0)*screenwidth())]+
                                 cells1[(i-1)+((j+1)*screenwidth())] + cells1[(i-0)+((j+1)*screenwidth())] + cells1[(i+1)+((j+1)*screenwidth())] ;

                if(cells1[i+j*screenwidth()]==0 && numofneighbour==3)
                {
                    cells[i+j*screenwidth()]=1;
                }

                else if(cells1[i+j*screenwidth()]==1 && (numofneighbour<2 || numofneighbour>3) )
                {
                    cells[i+j*screenwidth()]=0;
                }

                if(cells[i+j*screenwidth()]==1)
                    PutPixel(i,j,YELLOW);
                else
                    PutPixel(i,j,BLACK);
            }
        }

        DrawFrame(TRUE);


        for(i=0; i<screenwidth()*screenheight(); i++)
        {
            cells1[i]=cells[i];
        }
        //Sleep(100);
        generation++;
    }
}
