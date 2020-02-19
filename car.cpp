#include<graphics.h>

void CreateNMoveEnemyCar(int x,int y,int moveFactor,colors body,colors head)
{
    setcolor(BLACK);
    rectangle(x,y+moveFactor,x+20,-30+y+moveFactor);
    setfillstyle(1,body);
    floodfill(x+1,-20+y+moveFactor-1,BLACK);

    setcolor(BLACK);
    rectangle(x+5,y+moveFactor,x+15,5+y+moveFactor);
    setfillstyle(1,head);
    floodfill(x+6,5+y+moveFactor-1,BLACK);

}
void RecurseEnemy(int enemyFast,int enemyNormal,int enemySlow,int enemysuperFAST)
{
    CreateNMoveEnemyCar(305,-50,enemyFast,RED,GREEN);
    CreateNMoveEnemyCar(300,-100,enemyNormal,BLUE,BROWN);
    CreateNMoveEnemyCar(250,-30,enemySlow,YELLOW,CYAN);
    CreateNMoveEnemyCar(270,-50,enemysuperFAST,BLACK,BLACK);

}
int main()
{
	int gd=DETECT,gm,i;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	int page=0,t_y=-300;
	//car variable
	int C_x=0,C_y=0,M_Speed=5;
	int enemyNormal=0,enemyFast=0,enemySlow=0,enemysuperFAST=0;
	int levelup=0;

	while(1)
	{
		setactivepage(page);
		setvisualpage(1-page);
		cleardevice();
	//for background
	setcolor(GREEN);
	rectangle(100,100,100,100);
	setfillstyle(1,GREEN);
	floodfill(1,1,GREEN);
	//creating track
	setcolor(WHITE);
	rectangle(177,-1,420,590);
	setfillstyle(1,8);
	floodfill(201,0,WHITE);
	//line in roads
	for(int i=0;i<450;i+=65)
	{
		rectangle(290,3+i+t_y,295,40+i+t_y);
		setfillstyle(1,WHITE);
		floodfill(291,11+i+t_y,WHITE);
	}
t_y+=15;
if(t_y>500)
	t_y=-500;
	//for life and points
	settextstyle(10,0,2);
	outtextxy(10,10,"LIFE:");
	outtextxy(10,40,"POINTS:");
	//Drawing circles for life
	setfillstyle(1,WHITE);
	circle(90,20,6);
	floodfill(91,21,WHITE);
	circle(110,20,6);
	floodfill(111,21,WHITE);
	circle(130,20,6);
	floodfill(131,21,WHITE);
	outtextxy(100,40,"0");
	//Car shape
	setcolor(BLACK);
	setfillstyle(1,LIGHTRED);
	rectangle(300+C_x,400+C_y,340+C_x,460+C_y);
	floodfill(301+C_x,401+C_y,BLACK);
	//front
	setfillstyle(1,LIGHTCYAN);
	rectangle(305+C_x,385+C_y,335+C_x,400+C_y);
	floodfill(306+C_x,386+C_y,BLACK);
	//hood
	setfillstyle(1,LIGHTGRAY);
	rectangle(305+C_x,405+C_y,335+C_x,450+C_y);
	floodfill(306+C_x,406+C_y,BLACK);
	//Tyre
	setfillstyle(1,BLACK);
	pieslice(305+C_x,392+C_y,90,270,5);
	pieslice(337+C_x,392+C_y,270,90,5);

	//enemyCar

	RecurseEnemy(enemyFast,enemyNormal,enemySlow,enemysuperFAST);


    enemyNormal+=5;
    enemyFast+=8;
    enemySlow+=3;
    enemysuperFAST+=10;

	//movement
	if(GetAsyncKeyState(VK_LEFT))
		C_x-=M_Speed;
	else if(GetAsyncKeyState(VK_RIGHT))
		C_x+=M_Speed;
    else if (GetAsyncKeyState(VK_UP))
        C_y-=M_Speed;
    else if (GetAsyncKeyState(VK_DOWN))
        C_y+=M_Speed;

	page=1-page;
	delay(35);


    }
	getch();









































}
