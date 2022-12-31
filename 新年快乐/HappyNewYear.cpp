#include<graphics.h>
#include<Windows.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<easyx.h>
#include"resource.h"

const int colour[5][3] = { 199,91,19,
						128,181,25,
						171,57,94 ,
						203,184,40 ,
						72,162,210 };
struct fire
{
	int x, y;
	double r;
	int color;
};
fire f[12];
void firework(int w)
{
	f[w].x = rand() % 540 + 50;
	f[w].y = rand() % 200;
	f[w].r = (double)(rand() % 30 + 10);
	f[w].color = rand() % 4;
}

int main()
{
	srand(time(0));
	initgraph(640, 360);
	IMAGE baozhu;
	
	int height = 120;
	int lenth = (int)(height * 0.6);

	//loadimage(&baozhu, "yanhua", lenth, height);
	loadimage(&baozhu, "PNG", "yanhua", lenth, height, true);
	int x = (640 - lenth) / 2;
	int y = (360 - height+180) / 2;
	putimage(x, y, &baozhu);

	char a[] = "Press any keys";
	int text_width = textwidth(a);
	outtextxy((640 - text_width) / 2, 330, a);

	system("pause");

	for (int i = 1; i <= 11;i++)
	{
		height += 5;
		lenth = (int)height * 0.6;
		loadimage(&baozhu, "PNG", "yanhua",lenth, height, true);
		int x = (640 - lenth) / 2 ;
		int y = (360 - height+180) / 2 ;
		putimage(x, y, &baozhu);
		Sleep(pow(1.3,(double)i)*20);
		cleardevice();
		firework(i);
	}

	char wish[] = "新年快乐！";
	settextstyle(50, 0, "楷体");
	setbkmode(TRANSPARENT);
	text_width = textwidth(wish);

	for (int i = 1; i <= 11; i++)
	{
		for (int j = 10; j <= f[i].r; j += 5)
		{
			setfillcolor(RGB(colour[f[i].color][0], colour[f[i].color][1], colour[f[i].color][2]));
			setlinecolor(RGB(rand(), rand(), rand()));
			setlinestyle(PS_DASHDOT,(int)(j*0.1));
			fillcircle(f[i].x, f[i].y, j);
		
			outtextxy((640 - text_width) / 2, 200, wish);
			Sleep(100);
			cleardevice();
		}
	}
	outtextxy((640 - text_width) / 2, 200, wish);
	system("pause");
}