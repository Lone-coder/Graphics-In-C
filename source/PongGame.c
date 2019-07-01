#include "Headers/2DGC.h"

typedef struct VECTOR2
{
	int x;
	int y;
}Vector2;

Vector2 NewVector2(int x,int y)
{
	Vector2 v;
	
	v.x = x;
	v.y = y;
	
	return v;
}

typedef struct BALL
{
	Vector2 position;
	Vector2 movDir;
	
}Ball;

typedef struct BLOCK
{
	Vector2 position;
	
}Block;

void main()
{
	CreateConsole("Pong",90,60,12,12);
	
	Ball pong;
	Block player;
	Block computer;
	
	player.position = NewVector2(88,30);
	computer.position = NewVector2(2,30);
	
	pong.position = NewVector2(45,30);
	
	OnUpdate()
	{
		computer.position.y = pong.position.y;
		
		if(GetAsyncKeyState(VK_INSERT))
			pong.position.y+=1;

		if(GetAsyncKeyState(VK_DELETE))
			pong.position.y-=1;
		
		DrawBall(pong);
		DrawBlock(player);
		DrawBlock(computer);
		DrawFrame(true);
	}
}

void DrawBlock(Block b)
{
	Fillrect2(b.position.x,b.position.y,1,10,WHITE);
}

void DrawBall(Ball bl)
{
	PutPixel(bl.position.x,bl.position.y,WHITE);
}
