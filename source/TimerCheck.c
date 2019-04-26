#include <windows.h> // for Windows APIs
#include<stdio.h>                

void main()
{
    LARGE_INTEGER frequency;        // ticks per second
    LARGE_INTEGER t1, t2;           // ticks
    double elapsedTime;

    // get ticks per second
    QueryPerformanceFrequency(&frequency);

    // start timer
    QueryPerformanceCounter(&t1);

	Sleep(3);
    // do somethings
    // stop timer
    QueryPerformanceCounter(&t2);

    // compute and print the elapsed time in millisec
    elapsedTime = (t2.QuadPart - t1.QuadPart)*1000.0/ frequency.QuadPart;
    printf("%lf milliseconds",elapsedTime);

}
