#include "Headers/2DGC.h"
#include "Headers/Vector2D.h"

LARGE_INTEGER t1, t2;

typedef struct BALL
{
	Vector2 position;
	Vector2 movDir;
	int size;
	
}Ball;

typedef struct BLOCK
{
	Vector2 position;
	
}Block;

void DrawBlock(Block blc)
{
	Fillrect2(blc.position.x,blc.position.y,5,40,WHITE);
}

void DrawBall(Ball b)
{
	//PutPixel(b.position.x,b.position.y,WHITE);
	Fillrect2(b.position.x,b.position.y,b.size,b.size,WHITE);
}

Vector2 ReflectDir(Vector2 I,Vector2 N)
{
	DATATYPE dotIN =  2* Vector2Dot(I,N);
	Vector2Scale(&N,dotIN);
	
	return Vector2Subtract(I,N);
}

Vector2 CalculateMovDir(Ball pong,Block computer,Block player)
{
	Vector2 movDir = pong.movDir;
	
	DATATYPE e = 3.0;
	
	if(fabs(pong.position.x - (double)pong.size - 0.0) < e)
			movDir = ReflectDir(pong.movDir,NewVector2(1,0));
			
	else if(fabs(pong.position.x + (double)pong.size - (double)screenwidth()) < e)
			movDir = ReflectDir(pong.movDir,NewVector2(-1,0));
			
	else if(fabs(pong.position.y - (double)pong.size - 0.0) < e)
			movDir = ReflectDir(pong.movDir,NewVector2(0,1));
			
	else if(fabs(pong.position.y + (double)pong.size - (double)screenheight()) < e)
			movDir = ReflectDir(pong.movDir,NewVector2(0,-1));
	
	return movDir;
}

void main()
{
	CreateConsole("Pong",400,300,2,2);
	
	Ball pong;
	Block player;
	Block computer;
	
	player.position = NewVector2(screenwidth()-10,midY());
	computer.position = NewVector2(10,midY());
	
	pong.position = NewVector2(midX(),midY());
	
	pong.movDir = NewVector2(1,1);
	pong.size = 3;
	
	DATATYPE dt = 0.1;
	
	OnUpdate()
	{
		QueryPerformanceCounter(&t1);
		
		computer.position.y = pong.position.y;
		//player.position.y = pong.position.y;
		
		if(GetAsyncKeyState(VK_UP))
			player.position.y -= 3.0 * dt;

		if(GetAsyncKeyState(VK_DOWN))
			player.position.y += 3.0 * dt;
			
		pong.position.x += pong.movDir.x * dt;
		pong.position.y += pong.movDir.y * dt;
		
		pong.movDir = CalculateMovDir(pong,computer,player);
		
		DrawBall(pong);
		DrawBlock(player);
		DrawBlock(computer);
		
		Fillrect2(midX(),midY(),1,screenheight(),WHITE);
		
		DrawFrame(true);
		
		QueryPerformanceCounter(&t2);

		dt = (t2.QuadPart - t1.QuadPart)/20000.0;
	} 
}
