#include "��ͷ.h"

int main() {
	IMAGE m1, m2,m3,m4;
	initgraph(600, 700);
	cleardevice();
	int n = 0;//��������
	double dt = 0;//ÿ��λ��
	int* a = 0;//Ŀ������
	int* tem = 0;//�ݴ�����
	float max = 0;//�ҵ��������ֵ
	MOUSEMSG m;//������
kaishi:
	BeginBatchDraw();
	Sleep(10);
	loadimage(&m1, "����.png", 100, 100);
	loadimage(&m2, "�ڵ�.png", 100, 100);
	loadimage(&m3, "����.png", 200, 200);
	loadimage(&m4, "�ڵ�.png", 200, 200);//����У��
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
	settextstyle(30, 0, "���Ŀ���");
	outtextxy(250, 160, "��ʼ����");
	outtextxy(250, 260, "��������");
	outtextxy(280, 360, "����");
	outtextxy(280, 460, "����");
	outtextxy(280, 560, "�˳�");
	settextstyle(50, 0, "���Ŀ���");
	outtextxy(100, 50, "����������ӻ�ϵͳ");
	settextstyle(15, 0, "����");
	outtextxy(510, 85, "�汾1.00");
	outtextxy(445, 675, "����Ʒ��������ת���޸�");
	putimage(0, 0, &m2, SRCAND);
	putimage(0, 0, &m1, SRCPAINT);//�˵����ӻ�
	FlushBatchDraw();
	while (1) {
		m = GetMouseMsg();
		if (m.x < 450 && m.x>150 && m.y > 150 && m.y < 200)//��ʼ����
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
					settextstyle(30, 0, "���Ŀ���");
					outtextxy(250, 160, "ð������");
					outtextxy(250, 260, "ѡ������");
					outtextxy(250, 360, "��������");
					outtextxy(280, 460, "����");
					m = GetMouseMsg();
					if (m.x < 450 && m.x>150 && m.y > 150 && m.y < 200) {//ð��
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
								settextstyle(30, 0, "���Ŀ���");
								setfillcolor(LIGHTGRAY);
								solidrectangle(0, 700, 70, 650);
								outtextxy(6, 655, "����");
								solidrectangle(530, 700, 600, 650);
								outtextxy(540, 655, "�ز�");
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
					else if (m.x < 450 && m.x>150 && m.y > 250 && m.y < 300) {//ѡ������
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
								settextstyle(30, 0, "���Ŀ���");
								setfillcolor(LIGHTGRAY);
								solidrectangle(0, 700, 70, 650);
								outtextxy(6, 655, "����");
								solidrectangle(530, 700, 600, 650);
								outtextxy(540, 655, "�ز�");
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
						//����
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
								settextstyle(30, 0, "���Ŀ���");
								setfillcolor(LIGHTGRAY);
								solidrectangle(0, 700, 70, 650);
								outtextxy(6, 655, "����");
								solidrectangle(530, 700, 600, 650);
								outtextxy(540, 655, "�ز�");
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
					else if (m.x < 450 && m.x>150 && m.y > 450 && m.y < 500)//����
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
						settextstyle(30, 0, "���Ŀ���");
						outtextxy(250, 160, "ð������");
						outtextxy(250, 260, "ѡ������");
						outtextxy(250, 360, "��������");
						outtextxy(280, 460, "����");
						FlushBatchDraw();
					}

				}

			}
		}
		else if (m.x < 450 && m.x>150 && m.y > 250 && m.y < 300)//��������
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
				settextstyle(20, 0, "���Ŀ���");
				outtextxy(100, 150, "��������������(������15������),�ļ���ȡ������0");
				FlushBatchDraw();				
				scanf("%d", &n);	
				free(a);
				free(tem);
				if (n == 0)//�ļ���ȡ���� 
				{
					outtextxy(230, 200, "��ȡ����������");
					int c = 0;
					char k;
					n=find_n("�����������ļ�.txt");
					tem = (int*)malloc((n + 1) * sizeof(int) );
					char *temp = (char*)malloc(10*sizeof(char));
					a = (int*)malloc((n+1)*sizeof(int) );
					FILE* fp;
					fp = fopen("�����������ļ�.txt", "r");
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
				else //�ֶ��������
				{
					tem = (int*)malloc((n + 1) * sizeof(int));
					a = (int*)malloc((n + 1) * sizeof(int));
					outtextxy(230, 200, "������      ������");
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
		else if (m.x < 450 && m.x>150 && m.y > 350 && m.y < 400)//����
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
					settextstyle(30, 0, "���Ŀ���");
					outtextxy(280, 560, "����");
					settextstyle(22, 0, "���Ŀ���");
					outtextxy(100, 250, " ͨ���������飬����¼����Ҫ���������");
					outtextxy(100, 290, " ���ú󼴿ɵ����ʼ����ѡ��һ������");
					outtextxy(70, 330, "����󣬿���ѡ���ز������߷��ز˵�������������");
					outtextxy(0, 370, "�����ȡ�ļ����뽫��������ͬĿ¼�µ� �������������ļ�.txt�� ��");
					outtextxy(70, 410, "�ļ���ÿ����һ������������һ���ո�ȷ����ȷ����");
					outtextxy(140, 450, "�����ֶ���������������n���ûس�����");
					outtextxy(70, 490, "�ֶ�ÿ����һ���������������س�ȷ����ȷ����");
					putimage(200, 0, &m4, SRCAND);
					putimage(200, 0, &m3, SRCPAINT);
					FlushBatchDraw();
				}

			}
		}
		else if (m.x < 450 && m.x>150 && m.y > 450 && m.y < 500)//����
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
					settextstyle(30, 0, "���Ŀ���");
					outtextxy(280, 560, "����");
					settextstyle(22, 0, "���Ŀ���");
					outtextxy(50, 250, " ����:����������ӻ�ϵͳ     �汾1.00,����ʱ��2021.12.7");
					outtextxy(50, 290, " ����Ŀּ�����ÿ��ӻ��������ͬѧ�Ǹ�����������㷨��");
					outtextxy(50, 330, "�����ߣ����ѧԺ���������  2105��  ���  ѧ�ţ�8008121143");
					putimage(200, 0, &m4, SRCAND);
					putimage(200, 0, &m3, SRCPAINT);
					FlushBatchDraw();
				}
			}

		}
		else if (m.x < 450 && m.x>150 && m.y > 550 && m.y < 600) //�˳�
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
		else//���»ָ� 
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
		settextstyle(30, 0, "���Ŀ���");
		outtextxy(250, 160, "��ʼ����");
		outtextxy(250, 260, "��������");
		outtextxy(280, 360, "����");
		outtextxy(280, 460, "����");
		outtextxy(280, 560, "�˳�");
		settextstyle(50, 0, "���Ŀ���");
		outtextxy(100, 50, "����������ӻ�ϵͳ");
		settextstyle(15, 0, "����");
		outtextxy(510, 85, "�汾1.00");
		outtextxy(445, 675, "����Ʒ��������ת���޸�");
		FlushBatchDraw();

		}

		
	}
	

}
		
	