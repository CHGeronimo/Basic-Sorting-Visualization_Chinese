#include <stdio.h>
#include <graphics.h>
#include <time.h>                
#include <conio.h>
#include <stdlib.h>
void draw(int* s, int xzn, double dt, float max, COLORREF string, int panduan)//xzn现在的位数 单位长度 为每两位的之间的距离 maxy最大的y值 并不刷屏,该函数为画数组函数
{
	BeginBatchDraw();
	int i;
	float yx, ym;
	yx = float(s[xzn]) / float(max) * 550;
	//ym = float(s[mbn])/float(max)  * 550;
	settextcolor(WHITE);
	char* ptrxzn = (char*)malloc(10 * sizeof(char));
	itoa(s[xzn], ptrxzn, 10);
	//char* ptrmbn=(char *)malloc(10 * sizeof(char));
	//itoa(s[mbn],ptrmbn,10);
	setfillcolor(string);
	solidrectangle(50 + dt * xzn, 600 - yx, 50 - dt / 5 + (dt) * (xzn + 1), 600);
	FlushBatchDraw();
	if (panduan)
		settextstyle(20, 0, "Elephant");
	outtextxy(45 + dt / 5 + dt * xzn, 600 - yx - 30, ptrxzn);
	FlushBatchDraw();
} 
void swap(int* s, int xzn, int mbn, double dt, float max, int n) //xzn为现在需要替换的数组的下标，mbn为目标替换的下标。该函数用于可视化数组的移动。
{
	settextstyle(20, 0, "Elephant");
	BeginBatchDraw();
	int i;
	float yx, ym;
	yx = float(s[xzn]) / float(max) * 550;
	ym = float(s[mbn]) / float(max) * 550;
	setbkmode(TRANSPARENT);
	settextcolor(WHITE);
	char* ptrxzn = (char*)malloc(10 * sizeof(char));
	itoa(s[xzn], ptrxzn, 10);
	char* ptrmbn = (char*)malloc(10 * sizeof(char));
	itoa(s[mbn], ptrmbn, 10);
	cleardevice();
	int k = mbn - xzn;
	double  step = k > 0 ? (double)dt / 10 : (double)-dt / 10;
	k = k > 0 ? k : -k;
	for (int j = 0; j <= k * 10; ++j) {
		Sleep(65);
		for (int i = 0; i < n; ++i) {
			if (i != xzn && i != mbn)
				draw(s, i, dt, max, LIGHTGRAY, 1);
		}
		setfillcolor(LIGHTGRAY);
		clearrectangle(50 + dt * mbn - (j - 1) * step, 600 - ym, 50 - dt / 5 + (dt) * (mbn + 1) - (j - 1) * step, 600);
		clearrectangle(50 + dt * xzn + (j - 1) * step, 600 - yx, 50 - dt / 5 + (dt) * (xzn + 1) + (j - 1) * step, 600);
		settextcolor(BLACK);
		outtextxy(45 + dt / 5 + dt * xzn + (j - 1) * step, 600 - yx - 30, ptrxzn);
		outtextxy(45 + dt / 5 + dt * mbn - (j - 1) * step, 600 - ym - 30, ptrmbn);
		settextcolor(WHITE);
		solidrectangle(50 + dt * xzn + j * step, 600 - yx, 50 - dt / 5 + (dt) * (xzn + 1) + j * step, 600);
		outtextxy(45 + dt / 5 + dt * xzn + j * step, 600 - yx - 30, ptrxzn);
		solidrectangle(50 + dt * mbn - j * step, 600 - ym, 50 - dt / 5 + (dt) * (mbn + 1) - j * step, 600);
		outtextxy(45 + dt / 5 + dt * mbn - j * step, 600 - ym - 30, ptrmbn);
		FlushBatchDraw();

	}
	clearrectangle(50 + dt * mbn - (k * 10) * step, 600 - ym, 50 - dt / 5 + (dt) * (mbn + 1) - (k * 10) * step, 600);
	clearrectangle(50 + dt * xzn + (k + 10) * step, 600 - yx, 50 - dt / 5 + (dt) * (xzn + 1) + (k * 10) * step, 600);
	settextcolor(BLACK);
	outtextxy(45 + dt / 5 + dt * xzn + (k * 10) * step, 600 - yx - 30, ptrxzn);
	outtextxy(45 + dt / 5 + dt * mbn - (k * 10) * step, 600 - ym - 30, ptrmbn);
	int t = s[mbn];
	s[mbn] = s[xzn];
	s[xzn] = t;
	draw(s, xzn, dt, max, LIGHTGRAY, 1);
	draw(s, mbn, dt, max, LIGHTGRAY, 1);
	FlushBatchDraw();
}
void selection_sort(int* s, int n, double dt, float max)//该函数为选择排序
{
	int i, j, temp;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (s[i] > s[j])
			{

				for (int i = 0; i < n; i++) {
					draw(s, i, dt, max, LIGHTGRAY, 1);
				}
				for (int k = 0; k < 4; k++)
				{
					draw(s, j, dt, max, RGB(85, 155, 10), 0);
					draw(s, i, dt, max, RGB(85, 155, 10), 0);
					Sleep(200);
					draw(s, j, dt, max, LIGHTGRAY, 0);
					draw(s, i, dt, max, LIGHTGRAY, 0);
					Sleep(200);
				}
				swap(s, j, i, dt, max, n);
				clearrectangle(0, 0, 600, 700);
				for (int i = 0; i < n; i++) {
					draw(s, i, dt, max, LIGHTGRAY, 1);
				}
				FlushBatchDraw();

			}
			else {
				for (int i = 0; i < n; i++) {
					draw(s, i, dt, max, LIGHTGRAY, 1);
				}
				for (int k = 0; k < 4; k++)
				{
					draw(s, j, dt, max, RGB(15, 158, 199), 0);
					draw(s, i, dt, max, RGB(15, 158, 199), 0);
					Sleep(200);
					draw(s, j, dt, max, LIGHTGRAY, 0);
					draw(s, i, dt, max, LIGHTGRAY, 0);
					Sleep(200);
				}

			}
		}
	}
}
void bubble_sort(int* s, int n, double dt, float max)//该函数为冒泡排序函数
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j <= n - i - 1; ++j)
		{
			if (s[j] > s[j + 1])//交换的时候有闪动特效
			{

				for (int i = 0; i < n; i++) {
					draw(s, i, dt, max, LIGHTGRAY, 1);
				}
				for (int k = 0; k < 4; k++)
				{
					draw(s, j, dt, max, RGB(85, 155, 10), 0);
					draw(s, j + 1, dt, max, RGB(85, 155, 10), 0);
					Sleep(200);
					draw(s, j, dt, max, LIGHTGRAY, 0);
					draw(s, j + 1, dt, max, LIGHTGRAY, 0);
					Sleep(200);
				}
				swap(s, j, j + 1, dt, max, n);
				clearrectangle(0, 0, 600, 700);
				for (int i = 0; i < n; i++) {
					draw(s, i, dt, max, LIGHTGRAY, 1);
				}
				FlushBatchDraw();
			}
			else {
				for (int i = 0; i < n; i++) {
					draw(s, i, dt, max, LIGHTGRAY, 1);
				}
				for (int k = 0; k < 4; k++)
				{
					draw(s, j, dt, max, RGB(15, 158, 199), 0);
					draw(s, j + 1, dt, max, RGB(15, 158, 199), 0);
					Sleep(200);
					draw(s, j, dt, max, LIGHTGRAY, 0);
					draw(s, j + 1, dt, max, LIGHTGRAY, 0);
					Sleep(200);
				}

			}
		}
		Sleep(300);
	}
}
void insertion_sort(int* s, int n, double dt, float max) {

	for (int i = 1; i < n; i++)
	{
		int j = i - 1;

		int temp = s[i];//需要插入的数据 

		while (temp < s[j] && j >= 0)//当插入的数据小于前面的数据时 
		{

			for (int k = 0; k < 4; k++) {

				FlushBatchDraw();
				draw(s, j, dt, max, RGB(85, 155, 10), 0);
				draw(s, j + 1, dt, max, RGB(85, 155, 10), 0);
				Sleep(200);
				draw(s, j, dt, max, LIGHTGRAY, 0);
				draw(s, j + 1, dt, max, LIGHTGRAY, 0);
				Sleep(200);
			}
			swap(s, j + 1, j, dt, max, n);
			clearrectangle(0, 0, 600, 700);
			for (int i = 0; i < n; i++) {
				draw(s, i, dt, max, LIGHTGRAY, 1);
			}
			FlushBatchDraw();
			j--;
		}
		if (j >= 0)
		{
			for (int k = 0; k < 4; k++) {
				draw(s, j, dt, max, RGB(15, 158, 199), 0);
				draw(s, j + 1, dt, max, RGB(15, 158, 199), 0);
				Sleep(200);
				draw(s, j, dt, max, LIGHTGRAY, 0);
				draw(s, j + 1, dt, max, LIGHTGRAY, 0);
				Sleep(200);
			}
		}

		s[++j] = temp;//插入数据 

	}
}
int find_n(char const* name)//输入同地址下的文件名字，找到该数组有几个数字。
{
	FILE* fp;
	int i = 0;
	fp = fopen(name, "r");
	char k = 0;
	int  j = 0;
	while ((k = fgetc(fp)) != EOF)
	{
		if (k == ' ')
			i++;
	}
	fclose(fp);
	return i;
}