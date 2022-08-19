#include "标头.h"

int main() {
	IMAGE m1, m2,m3,m4;
	initgraph(600, 700);
	cleardevice();
	int n = 0;//数字数量
	double dt = 0;//每次位移
	int* a = 0;//目标数组
	int* tem = 0;//暂存数组
	float max = 0;//找到数组最大值
	MOUSEMSG m;//鼠标参数
kaishi:
	BeginBatchDraw();
	Sleep(10);
	loadimage(&m1, "掩码.png", 100, 100);
	loadimage(&m2, "黑底.png", 100, 100);
	loadimage(&m3, "掩码.png", 200, 200);
	loadimage(&m4, "黑底.png", 200, 200);//载入校徽
	cleardevice();
	FlushBatchDraw();
	setfillcolor(LIGHTGRAY);
	setbkmode(TRANSPARENT);
	solidrectangle(150, 150, 450, 200);
	solidrectangle(150, 250, 450, 300);
	solidrectangle(150, 350, 450, 400);
	solidrectangle(150, 450, 450, 500);
	solidrectangle(150, 550, 450, 600);
	settextcolor(WHITE);
	settextstyle(30, 0, "华文楷体");
	outtextxy(250, 160, "开始排序");
	outtextxy(250, 260, "设置数字");
	outtextxy(280, 360, "帮助");
	outtextxy(280, 460, "关于");
	outtextxy(280, 560, "退出");
	settextstyle(50, 0, "华文楷体");
	outtextxy(100, 50, "基本排序可视化系统");
	settextstyle(15, 0, "等线");
	outtextxy(510, 85, "版本1.00");
	outtextxy(445, 675, "本作品允许自由转载修改");
	putimage(0, 0, &m2, SRCAND);
	putimage(0, 0, &m1, SRCPAINT);//菜单可视化
	FlushBatchDraw();
	while (1) {
		m = GetMouseMsg();
		if (m.x < 450 && m.x>150 && m.y > 150 && m.y < 200)//开始排序
		{
			setlinecolor(RED);
			rectangle(145, 145, 455, 205);
			FlushBatchDraw();
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				cleardevice();
				FlushBatchDraw();
				while (2) {
					solidrectangle(150, 150, 450, 200);
					solidrectangle(150, 250, 450, 300);
					solidrectangle(150, 350, 450, 400);
					solidrectangle(150, 450, 450, 500);
					settextstyle(30, 0, "华文楷体");
					outtextxy(250, 160, "冒泡排序");
					outtextxy(250, 260, "选择排序");
					outtextxy(250, 360, "插入排序");
					outtextxy(280, 460, "返回");
					m = GetMouseMsg();
					if (m.x < 450 && m.x>150 && m.y > 150 && m.y < 200) {//冒泡
						setlinecolor(RED);
						rectangle(145, 145, 455, 205);
						FlushBatchDraw();
						if (m.uMsg == WM_LBUTTONDOWN) {
						bubble_sort:
							cleardevice();
							FlushBatchDraw();
							for (int i = 0; i < n; i++)
							{
								draw(a, i, dt, max, WHITE, 1);
							}
							bubble_sort(a, n, dt, max);
							while (3) {
								settextcolor(BLACK);
								settextstyle(30, 0, "华文楷体");
								setfillcolor(LIGHTGRAY);
								solidrectangle(0, 700, 70, 650);
								outtextxy(6, 655, "返回");
								solidrectangle(530, 700, 600, 650);
								outtextxy(540, 655, "重播");
								FlushBatchDraw();
								m = GetMouseMsg();
								for (int i = 0; i < n; ++i)
									a[i] = tem[i];
								if (m.uMsg == WM_LBUTTONDOWN && m.x < 70 && m.y>650) 
									goto kaishi;
								else if (m.uMsg == WM_LBUTTONDOWN && m.x > 530 && m.y > 650)
									goto bubble_sort;

							}
						}
					}
					else if (m.x < 450 && m.x>150 && m.y > 250 && m.y < 300) {//选择排序
						setlinecolor(RED);
						rectangle(145, 245, 455, 305);
						FlushBatchDraw();
						if (m.uMsg == WM_LBUTTONDOWN) {
						selection_sort:
							cleardevice();
							FlushBatchDraw();
							for (int i = 0; i < n; i++)
							{
								draw(a, i, dt, max, WHITE, 1);
							}
							selection_sort(a, n, dt, max);
							while (3) {
								settextcolor(BLACK);
								settextstyle(30, 0, "华文楷体");
								setfillcolor(LIGHTGRAY);
								solidrectangle(0, 700, 70, 650);
								outtextxy(6, 655, "返回");
								solidrectangle(530, 700, 600, 650);
								outtextxy(540, 655, "重播");
								FlushBatchDraw();
								m = GetMouseMsg();
								for (int i = 0; i < n; ++i)
									a[i] = tem[i];
								if (m.uMsg == WM_LBUTTONDOWN && m.x < 70 && m.y>650) 
									goto kaishi;
								else if (m.uMsg == WM_LBUTTONDOWN && m.x > 530 && m.y > 650)
										goto selection_sort;

							}
						}
					}


					else if (m.x < 450 && m.x>150 && m.y > 350 && m.y < 400)
						//插入
					{
						setlinecolor(RED);
						rectangle(145, 345, 455, 405);
						FlushBatchDraw();
						if (m.uMsg == WM_LBUTTONDOWN) {
						insertion_sort:
							cleardevice();

							FlushBatchDraw();
							for (int i = 0; i < n; i++)
							{
								draw(a, i, dt, max, LIGHTGRAY, 1);
							}
							insertion_sort(a, n, dt, max);
							while (3) {
								settextcolor(BLACK);
								settextstyle(30, 0, "华文楷体");
								setfillcolor(LIGHTGRAY);
								solidrectangle(0, 700, 70, 650);
								outtextxy(6, 655, "返回");
								solidrectangle(530, 700, 600, 650);
								outtextxy(540, 655, "重播");
								FlushBatchDraw();
								m = GetMouseMsg();
								for (int i = 0; i < n; ++i)
									a[i] = tem[i];
								if (m.uMsg == WM_LBUTTONDOWN && m.x < 70 && m.y>650) 
									goto kaishi;
								else if (m.uMsg == WM_LBUTTONDOWN && m.x > 530 && m.y > 650)
									goto insertion_sort;
								FlushBatchDraw();
							}
						}
					}
					else if (m.x < 450 && m.x>150 && m.y > 450 && m.y < 500)//返回
					{
						setlinecolor(RED);
						rectangle(145, 445, 455, 505);
						FlushBatchDraw();
						if (m.uMsg == WM_LBUTTONDOWN) {
							goto kaishi;
						}
					}
					else {
						clearrectangle(145, 145, 455, 205);
						clearrectangle(145, 245, 455, 305);
						clearrectangle(145, 345, 455, 405);
						clearrectangle(145, 445, 455, 505);
						solidrectangle(150, 150, 450, 200);
						solidrectangle(150, 250, 450, 300);
						solidrectangle(150, 350, 450, 400);
						solidrectangle(150, 450, 450, 500);
						settextstyle(30, 0, "华文楷体");
						outtextxy(250, 160, "冒泡排序");
						outtextxy(250, 260, "选择排序");
						outtextxy(250, 360, "插入排序");
						outtextxy(280, 460, "返回");
						FlushBatchDraw();
					}

				}

			}
		}
		else if (m.x < 450 && m.x>150 && m.y > 250 && m.y < 300)//设置数字
		{
			setlinecolor(RED);
			rectangle(145, 245, 455, 305);
			FlushBatchDraw();
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				cleardevice();
				settextcolor(WHITE);
				putimage(0, 0, &m2, SRCAND);
				putimage(0, 0, &m1, SRCPAINT);
				settextstyle(20, 0, "华文楷体");
				outtextxy(100, 150, "请输入数字数量(建议在15个以内),文件读取请输入0");
				FlushBatchDraw();				
				scanf("%d", &n);	
				free(a);
				free(tem);
				if (n == 0)//文件读取操作 
				{
					outtextxy(230, 200, "读取出以下数字");
					int c = 0;
					char k;
					n=find_n("数组放入这个文件.txt");
					tem = (int*)malloc((n + 1) * sizeof(int) );
					char *temp = (char*)malloc(10*sizeof(char));
					a = (int*)malloc((n+1)*sizeof(int) );
					FILE* fp;
					fp = fopen("数组放入这个文件.txt", "r");
					int l = 0, j = 0;
					while ((k = fgetc(fp)) != EOF)
					{
						if (k != ' ')
						{
							temp[l] = k;
							l++;
						}
						else {
							a[j] = atoi(temp);
							//free(temp);
							l = 0;
							char* temp = (char*)malloc(10 * sizeof(char));
							j++;
						}
					}
					
					fclose(fp);
					for (int i = 0; i < n; i++) {
						settextstyle(25, 0, "Elephant");
						char* p = (char*)malloc(10 * sizeof(char));
						itoa(a[i], p, 10);
						outtextxy(100 + i % 8 * 50, 250 + i / 8 * 30, p);
						outtextxy(142 + i % 8 * 50, 250 + i / 8 * 30, ",");
						FlushBatchDraw();
						free(p); 
						tem = (int*)malloc((n + 1) * sizeof(int));
						tem[i] = a[i];
						if (a[i] > max)
						{
							max = a[i];
						}
						Sleep(400);
					}
					Sleep(600);
				}
				else //手动输入操作
				{
					tem = (int*)malloc((n + 1) * sizeof(int));
					a = (int*)malloc((n + 1) * sizeof(int));
					outtextxy(230, 200, "请输入      个数字");
					char* np = (char*)malloc(10*sizeof(char) );
					itoa(n, np, 10);
					outtextxy(290, 200, np);
					free(np);
					FlushBatchDraw();
					for (int i = 0; i < n; i++) {
						settextstyle(25, 0, "Elephant");
						scanf("%d", &a[i]);
						char* p = (char*)malloc(10 * sizeof(char));
						itoa(a[i], p, 10);
						outtextxy(100 + i % 8 * 50, 250 + i / 8 * 30, p);
						outtextxy(142 + i % 8 * 50, 250 + i / 8 * 30, ",");
						FlushBatchDraw();
						free(p);
						tem[i] = a[i];
						if (a[i] > max)
						{
							max = a[i];
						}
					}
					Sleep(500);
				}
				setbkcolor(BLACK);
				dt = 500 / n;
				goto kaishi;
			}
		}
		else if (m.x < 450 && m.x>150 && m.y > 350 && m.y < 400)//帮助
		{

			setlinecolor(RED);
			rectangle(145, 345, 455, 405);
			FlushBatchDraw();
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				cleardevice();

				while (1) {
					m = GetMouseMsg();
					if (m.x < 450 && m.x>150 && m.y > 550 && m.y < 600)
					{
						setlinecolor(RED);
						rectangle(145, 545, 455, 605);
						FlushBatchDraw();
						if (m.uMsg == WM_LBUTTONDOWN) {
							goto kaishi;
						}
					}
					clearrectangle(145, 545, 455, 605);
					solidrectangle(150, 550, 450, 600);
					settextstyle(30, 0, "华文楷体");
					outtextxy(280, 560, "返回");
					settextstyle(22, 0, "华文楷体");
					outtextxy(100, 250, " 通过设置数组，可以录入需要排序的数组");
					outtextxy(100, 290, " 设置后即可点击开始排序，选择一种排序");
					outtextxy(70, 330, "排序后，可以选择重播，或者返回菜单重新设置数组");
					outtextxy(0, 370, "若想读取文件，请将数字输入同目录下的 “数组放入这个文件.txt” 中");
					outtextxy(70, 410, "文件中每输入一个整型请输入一个空格确保正确运行");
					outtextxy(140, 450, "若想手动输入请输入数量n并用回车键入");
					outtextxy(70, 490, "手动每输入一个整型请输入键入回车确保正确运行");
					putimage(200, 0, &m4, SRCAND);
					putimage(200, 0, &m3, SRCPAINT);
					FlushBatchDraw();
				}

			}
		}
		else if (m.x < 450 && m.x>150 && m.y > 450 && m.y < 500)//关于
		{
		
			setlinecolor(RED);
			rectangle(145, 445, 455, 505);
			FlushBatchDraw();
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				cleardevice();
			
				while (1) {
					m = GetMouseMsg();
					if (m.x < 450 && m.x>150 && m.y > 550 && m.y < 600)
					{
						setlinecolor(RED);
						rectangle(145, 545, 455, 605);
						FlushBatchDraw();
						if (m.uMsg == WM_LBUTTONDOWN) {
							goto kaishi;
						}
					}
					clearrectangle(145, 545, 455, 605);
					solidrectangle(150, 550, 450, 600);
					settextstyle(30, 0, "华文楷体");
					outtextxy(280, 560, "返回");
					settextstyle(22, 0, "华文楷体");
					outtextxy(50, 250, " 名称:基本排序可视化系统     版本1.00,开发时间2021.12.7");
					outtextxy(50, 290, " 本项目旨在利用可视化程序帮助同学们更好理解排序算法。");
					outtextxy(50, 330, "开发者：软件学院计算机Ⅱ类  2105班  崔昊  学号：8008121143");
					putimage(200, 0, &m4, SRCAND);
					putimage(200, 0, &m3, SRCPAINT);
					FlushBatchDraw();
				}
			}

		}
		else if (m.x < 450 && m.x>150 && m.y > 550 && m.y < 600) //退出
{
			setlinecolor(RED);
			rectangle(145, 545, 455, 605);
			FlushBatchDraw();
			if (m.uMsg == WM_LBUTTONDOWN) {
				free(a);
				free(tem);
				closegraph();
				exit(1);
			}
		}
		else//重新恢复 
		{
		clearrectangle(145, 145, 455, 205);
		clearrectangle(145, 245, 455, 305);
		clearrectangle(145, 345, 455, 405);
		clearrectangle(145, 445, 455, 505);
		clearrectangle(145, 545, 455, 605);
		solidrectangle(150, 150, 450, 200);
		solidrectangle(150, 250, 450, 300);
		solidrectangle(150, 350, 450, 400);
		solidrectangle(150, 450, 450, 500);
		solidrectangle(150, 550, 450, 600);
		settextstyle(30, 0, "华文楷体");
		outtextxy(250, 160, "开始排序");
		outtextxy(250, 260, "设置数字");
		outtextxy(280, 360, "帮助");
		outtextxy(280, 460, "关于");
		outtextxy(280, 560, "退出");
		settextstyle(50, 0, "华文楷体");
		outtextxy(100, 50, "基本排序可视化系统");
		settextstyle(15, 0, "等线");
		outtextxy(510, 85, "版本1.00");
		outtextxy(445, 675, "本作品允许自由转载修改");
		FlushBatchDraw();

		}

		
	}
	

}
		
	