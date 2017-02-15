# include <stdio.h>
# include <windows.h>
# include <conio.h>
# include <stdlib.h>
# include <malloc.h>
# include <string.h>

struct MyStudent//学生类
{
	char ID[15];//学号
	char Name[10];//姓名
	char Object[25];//专业
	char Class[10];//班级
	struct MyStudent * Next;//指针域
							//float Math,English,Computer,JavaP,PE; //成绩

};
typedef struct MyStudent student;

struct MyScore
{
	char ID[15]; //学号
	char Name[10]; //姓名
	float Math, English, Computer, JavaP, PE; //成绩
	struct MyScore *Next; //指针域
};
typedef struct MyScore score;


/****************************************************
声明函数语句
*****************************************************/
void gotoxy(int x, int y);//移动光标;
void HideCursor();//隐藏光标函数;
void Face();//定义信息 成绩管理 和退出系统 选择界面;
void ZFace();//定义选择信息 成绩后 的管理界面;
void OperateAZFace();//操作A时的信息管理界面;
void OperateBZFace();//选择B时的成绩管理界面;
void clean();//清理界面的函数;
void Operate();//总操作函数;
void cleanBIG();//清理大界面的函数；				
boolean add();//新增 或 添加学生信息函数;
boolean addScore();// 新增 或 添加学生信息函数；
boolean check(struct MyStudent *STU);//查找学生信息函数	
boolean checkScore(struct MyScore *SCO);//查找学生成绩函数								
struct MyStudent *ReadData(); //读出文件数据 
struct MyScore *ReadDataScore();//读出成绩文件数据						  
boolean modify(struct MyStudent * STU);//修改学生的信息函数
boolean modifyScore(struct MyScore * SCO);//修改学生的成绩函数									   
boolean deleted(struct MyStudent *STU);//删除学生信息的函数；
boolean deletedScore(struct MyScore *SCO);//删除学生成绩的函数；

int main(void)
{
	system("mode con cols=80 lines=30");//控制台的 宽X高；
	system("color A0");//控制台的颜色，十六进制数字控制；
	HideCursor();
	Operate();
	getchar();

	return 0;
}

/**********************************************
传参：
返回值：
作用：定义修饰界面函数；
***********************************************/
void Interface(int opt)
{

	int i, j;

	for (i = 0; i < 80; i += 2)
	{
		gotoxy(i, 30);
		printf("▆");
	}

	for (j = 0; j < 80; j += 2)
	{
		if (j < 28)
		{
			gotoxy(j, 5);
			printf("▆");
		}

		gotoxy(j, 0);
		printf("▆");
	}

	gotoxy(26, 1);//26列1行
	printf("▆");
	gotoxy(26, 2);
	printf("▆");
	gotoxy(26, 3);
	printf("▆");
	gotoxy(26, 4);
	printf("▆");
	gotoxy(2, 1);
	printf("学生信息与成绩管理系统");
	gotoxy(2, 2);
	printf("制作团队:");
	gotoxy(12, 2);
	printf("刘新华");
	gotoxy(12, 3);
	printf("苏家荣");
	gotoxy(12, 4);
	printf("白鸿华");

	if (opt == 1)
	{
		Face();
	}
	else if (opt == 2)
	{
		ZFace();
	}

	return;
}

/*******************************************
传参：
返回值：
作用：定义信息 成绩管理 和退出系统 选择界面
********************************************/
void Face()
{
	int k, m;

	for (k = 4; k < 28; k += 2)
	{
		gotoxy(k, 8);
		printf("▆");
		gotoxy(k, 16);
		printf("▆");
	}
	for (m = 8; m < 16; m++)
	{
		gotoxy(4, m);
		printf("▆");
		gotoxy(26, m);
		printf("▆");
	}

	gotoxy(8, 10);
	printf("A: 学生信息管理");
	gotoxy(8, 12);
	printf("B: 学生成绩管理");
	gotoxy(8, 14);
	printf("C: 退出系统");

	return;
}
/******************************************
传参：
返回值：
作用：定义特定的显示界面函数；
*******************************************/
void ZFace()
{
	int i, j;

	for (i = 4; i < 76; i += 2)
	{
		gotoxy(i, 8);
		printf("▆");
		gotoxy(i, 27);
		printf("▆");
	}
	for (j = 8; j < 27; j++)
	{
		gotoxy(4, j);
		printf("▆");
		gotoxy(74, j);
		printf("▆");
	}

	return;
}

/******************************************
传参：
返回值：
作用：当选择A选项时调用的界面函数；
*******************************************/
void OperateAZFace()
{
	clean();    //???
	gotoxy(8, 10);
	printf("A:  学生信息管理: ");
	gotoxy(8, 12);
	printf("B: 学生成绩管理");

	gotoxy(26, 10);
	printf("1: 添加信息");
	gotoxy(26, 12);
	printf("2: 查找信息");
	gotoxy(26, 14);
	printf("3: 修改信息");
	gotoxy(26, 16);
	printf("4: 删除信息");
	gotoxy(26, 18);
	printf("5: 返回上层");
	gotoxy(26, 20);
	printf("6: 退出系统");

	return;
}

/******************************************
传参：
返回值：
作用：当选择B选项时调用的界面函数；
*******************************************/
void OperateBZFace()
{
	clean();
	gotoxy(8, 10);
	printf("A: 学生信息管理");
	gotoxy(8, 12);
	printf("B:  学生成绩管理: ");

	gotoxy(26, 12);
	printf("1: 添加成绩");
	gotoxy(26, 14);
	printf("2: 查找成绩");
	gotoxy(26, 16);
	printf("3: 成绩排序");
	gotoxy(26, 18);
	printf("4: 成绩绩点");
	gotoxy(26, 20);
	printf("5: 修改成绩");
	gotoxy(26, 22);
	printf("6: 删除成绩");
	gotoxy(26, 24);
	printf("7: 返回上层");
	gotoxy(26, 26);
	printf("8: 退出系统");

	return;
}

/****************************************
传参：
返回值：
作用：清理为win32控制台规定的区域；
*****************************************/
void clean()
{
	int i, j;//i为X轴，j为Y轴；

	for (i = 6; i < 72; i++)
	{
		for (j = 9; j < 27; j++)
		{
			gotoxy(i, j);
			printf(" ");
		}
	}
	return;
}

/***************************************
传参：
返回值：
作用：清理win32控制台整一个界面；
****************************************/
void cleanBIG()
{
	int i, j;//i为X轴，j为Y轴；

	for (i = 0; i < 78; i++)
	{
		for (j = 7; j < 29; j++)
		{
			gotoxy(i, j);
			printf(" ");
		}
	}
	return;
}

/******************************************
传进的参数：void
返回值：void
作用：总调用函数；
*******************************************/
void Operate()
{
	char AB;

	cleanBIG();
	Interface(1);


	while (1)
	{
		student * STU = NULL;
		score * SCO = NULL;

		AB = _getch();

		if ('A' == AB || 'a' == AB)//选择A时的操作界面
		{
			cleanBIG();
			Interface(2);
			OperateAZFace();

			while (1)
			{
				char optA;
				optA = _getch();

				switch (optA)
				{
				case '1':
					//添加信息
					add();
					break;
				case '2':
					//查找信息
					STU = ReadData();
					check(STU);
					break;
				case '3':
					//修改信息
					STU = ReadData();
					modify(STU);
					break;
				case '4':
					//删除信息
					STU = ReadData();
					deleted(STU);
					break;
				case '5':
					//返回上层
					cleanBIG();
					Operate();
					break;
				case '6':
					//退出系统
					exit(0);
					break;
				default:
					break;
				}
			}
		}
		if ('B' == AB || 'b' == AB)//选择B时的操作界面
		{
			cleanBIG();
			Interface(2);
			OperateBZFace();

			while (1)
			{
				char optB;
				optB = _getch();

				switch (optB)
				{
				case '1':
					//添加成绩
					addScore();
					break;
				case '2':
					//查找成绩
					SCO = ReadDataScore();
					checkScore(SCO);
					break;
				case '3':
					//成绩排序
					break;
				case '4':
					//成绩绩点
					break;
				case '5':
					//修改成绩
					SCO = ReadDataScore();
					modifyScore(SCO);
					break;
				case '6':
					//删除成绩
					SCO = ReadDataScore();
					deletedScore(SCO);
					break;
				case '7':
					//返回上层
					cleanBIG();
					Operate();
					break;
				case '8':
					//退出系统
					exit(0);
					break;
				default:
					break;
				}
			}
		}
		if ('c' == AB || 'C' == AB)//退出系统
		{
			exit(0);
		}
	}
	return;
}

//新增 或 添加学生信息函数
boolean add()
{
	int count;
	int i;
	FILE * fp;
	struct MyStudent * p = NULL;
	clean();
	gotoxy(18, 11);
	printf("请输入需要创建的学生个数：");
	gotoxy(44, 11);
	scanf("%d", &count);


	if ((fp = fopen("学生信息.txt", "ab")) == NULL)
	{//先判断原来是否存在  学生信息.txt，不存在，则关闭文件指针
		fclose(fp);

		if ((fp = fopen("学生信息.txt", "wb")) == NULL)
		{//如果为空，则新建 学生信息.txt  失败
			gotoxy(30, 13);
			printf("文件出错！");
			gotoxy(30, 15);
			printf("请按任意键返回!");
			_getch();
			cleanBIG();
			Operate();

			return 0;
		}
	}

	for (i = 0; i < count; i++)
	{
		clean();
		p = (struct MyStudent *)malloc(sizeof(struct MyStudent));

		if (p == NULL)
		{
			gotoxy(30, 12);
			printf("创建学生失败！");
			gotoxy(30, 15);
			printf("请按任意键返回!");
			_getch();
			cleanBIG();
			Operate();
			return 0;

		}
		gotoxy(26, 11);
		printf("请输入第%d个学生的学号：", i + 1);
		gotoxy(49, 11);
		scanf("%s", &(p->ID));//15表示p->ID的字节数

		clean();
		gotoxy(26, 11);
		printf("请输入第%d个学生的姓名：", i + 1);
		gotoxy(49, 11);
		scanf("%s", &(p->Name));

		clean();
		gotoxy(26, 11);
		printf("请输入第%d个学生的专业：", i + 1);
		gotoxy(49, 11);
		scanf("%s", &(p->Object));

		clean();
		gotoxy(26, 11);
		printf("请输入第%d个学生的班级：", i + 1);
		gotoxy(49, 11);
		scanf("%s", &(p->Class));

		fprintf(fp, "%s %s %s %s", p->ID, p->Name, p->Object, p->Class);
		fputs("\r\n", fp);
	}

	clean();
	gotoxy(30, 13);
	printf("添加成功!");
	fclose(fp);
	gotoxy(30, 15);
	printf("请按任意键返回!");
	_getch();

	cleanBIG();
	Operate();

	return 0;
}

/************************************************
传进的参数：链表的头指针
返回值：0
作者用：通过查找单向链表，找到学生的信息；
*************************************************/
boolean check(struct MyStudent *STU)
{
	int j = 0;
	char id[20];
	struct MyStudent * p1, *p2;
	p1 = STU;
	p2 = STU;

	if (p1 == NULL)
	{
		clean();
		gotoxy(30, 13);
		printf("学生信息为空!");
		gotoxy(30, 15);
		printf("请按任意键返回!");
		_getch();

		cleanBIG();
		Operate();

		return 0;
	}

	clean();
	gotoxy(26, 11);
	printf("请输入需要查找学生的学号：");
	gotoxy(52, 11);
	scanf("%s", &id);

	while (strcmp(p1->ID, id) != 0 && p1->Next != NULL)//依次按链表查找
	{
		p1 = p2->Next;
		p2 = p1;

		gotoxy(60, 2);
		printf("%d", ++j);
	}

	if (strcmp(p1->ID, id) == 0)
	{
		gotoxy(30, 13);
		printf("成功找到该学生！");
		gotoxy(16, 14);
		printf("学号------------姓名------------专业------------班级");
		gotoxy(16, 15);
		printf("%s     %s       %s       %s", p1->ID, p1->Name, p1->Object, p1->Class);
		gotoxy(30, 17);
		printf("请按任意键返回!");
		_getch();

		cleanBIG();
		Operate();
		return 0;
	}

	if (p1->Next == NULL)
	{
		gotoxy(30, 13);
		printf("没有找到该学生!");
		gotoxy(30, 15);
		printf("请按任意键返回!");
		_getch();
		cleanBIG();
		Operate();
		return 0;
	}
	return 0;
}

/********************************************
参数：需要修改的链表的首结点的地址
返回值：0
作用：通过查找单向链表的结点，修改学生信息
*********************************************/
boolean modify(struct MyStudent * STU)
{
	int j = 0;
	char id[20];
	FILE * fp = NULL;
	struct MyStudent * p1 = NULL, *p2 = NULL, *p3 = NULL, *p4 = NULL;
	p1 = STU;
	p2 = STU;
	p3 = STU;
	p4 = STU;


	if ((fp = fopen("学生信息.txt", "wb+")) == NULL)
	{
		gotoxy(30, 12);
		printf("文件操作失败\n");
		fclose(fp);
		gotoxy(30, 15);
		printf("请按任意键返回!");
		_getch();

		cleanBIG();
		Operate();
		return 0;
	}

	if (p1 == NULL)
	{
		clean();
		gotoxy(30, 13);
		printf("学生信息为空!");
		fclose(fp);
		gotoxy(30, 15);
		printf("请按任意键返回!");
		_getch();

		cleanBIG();
		Operate();

		return 0;
	}

	clean();
	gotoxy(26, 11);
	printf("请输入需要修改学生的学号：");
	gotoxy(52, 11);
	scanf("%s", &id);

	while (strcmp(p1->ID, id) != 0 && p1->Next != NULL)//依次按链表查找
	{
		p1 = p2->Next;
		p2 = p1;
	}

	if (strcmp(p1->ID, id) == 0)
	{
		char YN;
		gotoxy(30, 13);
		printf("确定修改该学生的信息吗？(Y/N)");

		while (1)
		{
			YN = _getch();

			if ('n' == YN || 'N' == YN)
			{
				fclose(fp);
				cleanBIG();
				Operate();
				return 0;
			}

			if ('y' == YN || 'Y' == YN)
			{
				clean();
				gotoxy(26, 11);
				printf("修改后的学号：");
				gotoxy(40, 11);
				scanf("%s", &(p1->ID));

				clean();
				gotoxy(26, 11);
				printf("修改后的姓名：");
				gotoxy(40, 11);
				scanf("%s", &(p1->Name));

				clean();
				gotoxy(26, 11);
				printf("修改后的专业：");
				gotoxy(40, 11);
				scanf("%s", &(p1->Object));

				clean();
				gotoxy(26, 11);
				printf("修改后的班级：");
				gotoxy(40, 11);
				scanf("%s", &(p1->Class));

				break;
			}
		}

		if (p1->Next == NULL)
		{
			gotoxy(30, 13);
			printf("没有找到要修改的学生信息!");
			gotoxy(30, 15);
			printf("请按任意键返回!");
			fclose(fp);
			_getch();
			cleanBIG();
			Operate();
			return 0;
		}

		do
		{
			fprintf(fp, "%s %s %s %s", p3->ID, p3->Name, p3->Object, p3->Class);
			fputs("\r\n", fp);

			p4 = p3->Next;
			p3 = p4;

			gotoxy(60, 4);
			printf("修改：%d", ++j);
		} while (p3->Next != NULL);

		clean();
		gotoxy(30, 13);
		printf("修改成功!");
		fclose(fp);
		gotoxy(30, 15);
		printf("请按任意键返回!");
		_getch();

		cleanBIG();
		Operate();
	}
	return 0;
}

/********************************************
参数：需要删除的链表的首结点地址
返回值：0
作用：通过查找链表，删除链表某一个结点，达到删除学生信息的作用；
*********************************************/
boolean deleted(struct MyStudent *STU)
{
	int j = 0;
	char id[20];
	FILE * fp = NULL;
	struct MyStudent * p1 = NULL, *p2 = NULL, *p3 = NULL, *p4 = NULL, *temp = NULL;
	p1 = STU;
	p2 = STU;
	p3 = STU;
	p4 = STU;

	if ((fp = fopen("学生信息.txt", "wb+")) == NULL)
	{
		gotoxy(30, 12);
		printf("文件操作失败\n");
		fclose(fp);
		gotoxy(30, 15);
		printf("请按任意键返回!");
		_getch();

		cleanBIG();
		Operate();
		return 0;
	}


	if (p1 == NULL && p2 == NULL && p3 == NULL && p4 == NULL)
	{
		clean();
		gotoxy(30, 13);
		printf("学生信息为空!");
		fclose(fp);
		gotoxy(30, 15);
		printf("请按任意键返回!");
		_getch();

		cleanBIG();
		Operate();

		return 0;
	}

	clean();
	gotoxy(26, 11);
	printf("请输入需要删除的学生学号：");
	gotoxy(52, 11);
	scanf("%s", &id);

	while (strcmp(p1->ID, id) != 0 && p1->Next != NULL)//依次按链表查找
	{
		p1 = p2->Next;
		temp = p2;
		p2 = p1;
	}

	if (strcmp(p1->ID, id) == 0)
	{
		char YN;
		gotoxy(30, 13);
		printf("成功找到该学生！");
		gotoxy(16, 14);
		printf("学号------------姓名------------专业------------班级");
		gotoxy(16, 15);
		printf("%s     %s       %s       %s", p1->ID, p1->Name, p1->Object, p1->Class);
		gotoxy(30, 17);
		printf("确定删除该学生的信息吗？(Y/N)");

		while (1)
		{
			YN = _getch();

			if ('n' == YN || 'N' == YN)
			{
				fclose(fp);
				cleanBIG();
				Operate();
				return 0;
			}
			if ('y' == YN || 'Y' == YN)
			{
				clean();
				gotoxy(16, 14);
				printf("学号------------姓名------------专业------------班级");
				gotoxy(16, 15);
				printf("%s     %s       %s         %s", p1->ID, p1->Name, p1->Object, p1->Class);
				gotoxy(30, 17);
				printf("请再一次确定删除(Y/N)");

				while (1)
				{
					char yn;
					yn = _getch();

					if ('n' == yn || 'N' == yn)
					{
						fclose(fp);
						cleanBIG();
						Operate();
						return 0;
					}
					if ('y' == yn || 'Y' == yn)
					{
						if (temp == NULL)//如果第一个节点就是要删除的学生信息
						{
							p3 = p1->Next;
							free(p1);
						}
						else//要删除的学生信息不在第一个节点
						{
							temp->Next = p1->Next;
							free(p1);
						}

					if(p3 != NULL)
					{
						do
						{
							gotoxy(60, 4);
							printf("删除+++++========：%d", ++j);
							fprintf(fp, "%s %s %s %s\n", p3->ID, p3->Name, p3->Object, p3->Class);
							fputs("\r\n", fp);
							p4 = p3->Next;
							p3 = p4;
						} while (p3 != NULL);
					}

						clean();
						gotoxy(30, 13);
						printf("成功删除学生信息!");
						fclose(fp);
						gotoxy(30, 15);
						printf("请按任意键返回!");
						_getch();
						cleanBIG();
						Operate();

						return 0;
					}
				}

			}
		}
	}
	if (p1->Next == NULL)
	{
		gotoxy(30, 13);
		printf("没有找到要删除的学生信息!");
		fclose(fp);
		gotoxy(30, 15);
		printf("请按任意键返回!");
		_getch();

		cleanBIG();
		Operate();
		return 0;
	}
	return 0;
}

/***********************************************
参数：void
返回值：链表的首结点的地址
作用：读取D盘下存在的txt文件（学生信息.txt），存进构建的链表中，并返回该
链表的头结点指针；
***********************************************/
struct MyStudent *ReadData()
{
	int i = 0;
	FILE *fp = NULL;
	struct MyStudent *H = NULL, *p = NULL, *p1 = NULL;
	p1 = (struct MyStudent *)malloc(sizeof(struct MyStudent));

	if ((fp = fopen("学生信息.txt", "rb")) == NULL)
	{
		gotoxy(30, 12);
		printf("文件操作失败\n");
		fclose(fp);
		gotoxy(30, 15);
		printf("请按任意键返回!");
		_getch();
		cleanBIG();
		Operate();
		return NULL;
	}
	while (!feof(fp))//如果读取文件没有结束，feof（）返回 0 值；
	{
		p = (struct MyStudent *)malloc(sizeof(struct MyStudent));

		fscanf(fp, "%s", &p->ID);
		fscanf(fp, "%s", &p->Name);
		fscanf(fp, "%s", &p->Object);
		fscanf(fp, "%s", &p->Class);
		fputs("\r\n", fp);

		if (i == 0)
		{
			H = p;
			p1 = p;
		}
		else
		{
			p1->Next = p;
		}
		p1 = p;
		i++;

	}
	p1->Next = p;
	p1 = p;
	p1->Next = p;
	p->Next = NULL;

	gotoxy(60, 3);
	printf("读数据：%d", ++i);

	fclose(fp);
	return H;
}

/****************************************************
参数：win32控制台的纵横坐标X Y
返回值：void
作用：定义光标的位置的函数，坐标为GetStdHandle(STD_OUTPUT_HANDLE)
返回标准的输出句柄，也就是获得输出屏幕缓冲去的句柄，并赋值给positing；
*****************************************************/
void gotoxy(int x, int y)
{
	COORD position = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

/****************************************************
参数：void
返回值：void
作用：隐藏控制台的光标；
*****************************************************/
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}


//新增 或 添加成绩信息函数
boolean addScore()
{
	int count;
	int i;
	FILE * fp;
	struct MyScore * p = NULL;
	clean();
	gotoxy(18, 11);
	printf("请输入需要创建的学生个数：");
	gotoxy(44, 11);
	scanf("%d", &count);

	if ((fp = fopen("学生成绩.txt", "ab")) == NULL)
	{//先判断原来是否存在  学生成绩.txt，不存在，则关闭文件指针
		fclose(fp);

		if ((fp = fopen("学生成绩.txt", "wb")) == NULL)
		{//如果为空，则新建 学生成绩.txt  失败
			gotoxy(30, 13);
			printf("文件出错！");
			gotoxy(30, 15);
			printf("请按任意键返回!");
			_getch();
			cleanBIG();
			Operate();

			return 0;
		}
	}

	for (i = 0; i < count; i++)
	{
		clean();
		p = (struct MyScore *)malloc(sizeof(struct MyScore));

		if (p == NULL)
		{
			gotoxy(30, 12);
			printf("创建学生失败！");
			gotoxy(30, 15);
			printf("请按任意键返回!");
			_getch();
			cleanBIG();
			Operate();
			return 0;

		}
		gotoxy(20, 10);
		printf("请输入第%d个学生的学号：", i + 1);
		gotoxy(43, 10);
		scanf("%s", &(p->ID));//15表示p->ID的字节数

							  //clean();
		gotoxy(20, 11);
		printf("请输入第%d个学生的姓名：", i + 1);
		gotoxy(43, 11);
		scanf("%s", &(p->Name));

		//clean();
		gotoxy(20, 12);
		printf("请输入第%d个学生的高数成绩：", i + 1);
		gotoxy(47, 12);
		scanf("%f", &(p->Math));

		gotoxy(20, 13);
		printf("请输入第%d个学生的英语成绩：", i + 1);
		gotoxy(47, 13);
		scanf("%f", &(p->English));

		gotoxy(20, 14);
		printf("请输入第%d个学生的计算机成绩：", i + 1);
		gotoxy(49, 14);
		scanf("%f", &(p->Computer));

		gotoxy(20, 15);
		printf("请输入第%d个学生的JAVA成绩：", i + 1);
		gotoxy(47, 15);
		scanf("%f", &(p->JavaP));

		gotoxy(20, 16);
		printf("请输入第%d个学生的体育成绩：", i + 1);
		gotoxy(47, 16);
		scanf("%f", &(p->PE));

		//clean();
		//gotoxy(26, 11);
		//printf("请输入第%d个学生的班级：", i + 1);
		//gotoxy(49, 11);
		//scanf("%s", &(p->Class));

		fprintf(fp, "%s %s %f %f %f %f %f ", p->ID, p->Name, p->Math, p->English, p->Computer, p->JavaP, p->PE);
		fputs("\r\n", fp);
	}

	clean();
	gotoxy(30, 13);
	printf("添加成功!");
	fclose(fp);
	gotoxy(30, 15);
	printf("请按任意键返回!");
	_getch();

	cleanBIG();
	Operate();

	return 0;
}
/***********************************************
参数：void
返回值：链表的首结点的地址
作用：读取D盘下存在的txt文件（学生成绩.txt），存进构建的链表中，并返回该
链表的头结点指针；
***********************************************/
struct MyScore *ReadDataScore()
{
	int i = 0;
	FILE *fp = NULL;
	struct MyScore *H = NULL, *p = NULL, *p1 = NULL;
	p1 = (struct MyScore *)malloc(sizeof(struct MyScore));

	if ((fp = fopen("学生成绩.txt", "rb")) == NULL)
	{
		gotoxy(30, 12);
		printf("文件操作失败\n");
		fclose(fp);
		gotoxy(30, 15);
		printf("请按任意键返回!");
		_getch();
		cleanBIG();
		Operate();
		return NULL;
	}
	while (!feof(fp))//如果读取文件没有结束，feof（）返回 0 值；
	{
		p = (struct MyScore *)malloc(sizeof(struct MyScore));

		fscanf(fp, "%s", &p->ID);
		fscanf(fp, "%s", &p->Name);
		fscanf(fp, "%f", &p->Math);
		fscanf(fp, "%f", &p->English);
		fscanf(fp, "%f", &p->Computer);
		fscanf(fp, "%f", &p->JavaP);
		fscanf(fp, "%f", &p->PE);
		fputs("\r\n", fp);

		if (i == 0)
		{
			H = p;
			p1 = p;
		}
		else
		{
			p1->Next = p;
		}
		p1 = p;
		i++;

	}
	p1->Next = p;
	p1 = p;
	p1->Next = p;
	p->Next = NULL;



	fclose(fp);
	return H;
}
/************************************************
传进的参数：链表的头指针
返回值：0
作者用：通过查找单向链表，找到学生的成绩；
*************************************************/
boolean checkScore(struct MyScore *SCO)
{
	int j = 0;
	char id[20];
	struct MyScore * p1, *p2;
	p1 = SCO;
	p2 = SCO;

	if (p1 == NULL)
	{
		clean();
		gotoxy(30, 13);
		printf("学生信息为空!");
		gotoxy(30, 15);
		printf("请按任意键返回!");
		_getch();

		cleanBIG();
		Operate();

		return 0;
	}

	clean();
	gotoxy(26, 11);
	printf("请输入需要查找学生的学号：");
	gotoxy(52, 11);
	scanf("%s", &id);

	while (strcmp(p1->ID, id) != 0 && p1->Next != NULL)//依次按链表查找
	{
		p1 = p2->Next;
		p2 = p1;

		gotoxy(60, 2);
		printf("%d", ++j);
	}

	if (strcmp(p1->ID, id) == 0)
	{
		gotoxy(30, 13);
		printf("成功找到该学生！");
		gotoxy(8, 14);
		printf("学号------姓名------高数------英语------计算机------JAVA------体育");
		gotoxy(8, 15);
		printf("%s   %s    %.1f     %.1f     %.1f      %.1f      %.1f", p1->ID, p1->Name, p1->Math, p1->English, p1->Computer, p1->JavaP, p1->PE);
		gotoxy(16, 17);
		printf("请按任意键返回!");
		_getch();

		cleanBIG();
		Operate();
		return 0;
	}

	if (p1->Next == NULL)
	{
		gotoxy(30, 13);
		printf("没有找到该学生!");
		gotoxy(30, 15);
		printf("请按任意键返回!");
		_getch();
		cleanBIG();
		Operate();
		return 0;
	}
	return 0;
}
/********************************************
参数：需要修改的链表的首结点的地址
返回值：0
作用：通过查找单向链表的结点，修改学生成绩
*********************************************/
boolean modifyScore(struct MyScore * SCO)
{
	int j = 0;
	char id[20];
	FILE * fp = NULL;
	struct MyScore * p1 = NULL, *p2 = NULL, *p3 = NULL, *p4 = NULL;
	p1 = SCO;
	p2 = SCO;
	p3 = SCO;
	p4 = SCO;


	if ((fp = fopen("学生成绩.txt", "wb+")) == NULL)
	{
		gotoxy(30, 12);
		printf("文件操作失败\n");
		fclose(fp);
		gotoxy(30, 15);
		printf("请按任意键返回!");
		_getch();

		cleanBIG();
		Operate();
		return 0;
	}

	if (p1 == NULL)
	{
		clean();
		gotoxy(30, 13);
		printf("学生信息为空!");
		fclose(fp);
		gotoxy(30, 15);
		printf("请按任意键返回!");
		_getch();

		cleanBIG();
		Operate();

		return 0;
	}

	clean();
	gotoxy(26, 11);
	printf("请输入需要修改学生的学号：");
	gotoxy(52, 11);
	scanf("%s", &id);

	while (strcmp(p1->ID, id) != 0 && p1->Next != NULL)//依次按链表查找
	{
		p1 = p2->Next;
		p2 = p1;
	}

	if (strcmp(p1->ID, id) == 0)
	{
		char YN;
		gotoxy(30, 13);
		printf("确定修改该学生的信息吗？(Y/N)");

		while (1)
		{
			YN = _getch();

			if ('n' == YN || 'N' == YN)
			{
				fclose(fp);
				cleanBIG();
				Operate();
				return 0;
			}

			if ('y' == YN || 'Y' == YN)
			{
				clean();
				gotoxy(26, 11);
				printf("修改后的学号：");
				gotoxy(40, 11);
				scanf("%s", &(p1->ID));

				//clean();
				gotoxy(26, 12);
				printf("修改后的姓名：");
				gotoxy(40, 12);
				scanf("%s", &(p1->Name));

				//clean();
				gotoxy(26, 13);
				printf("修改后的高数：");
				gotoxy(40, 13);
				scanf("%f", &(p1->Math));

				//clean();
				gotoxy(26, 14);
				printf("修改后的英语：");
				gotoxy(40, 14);
				scanf("%f", &(p1->English));

				gotoxy(26, 15);
				printf("修改后的计算机：");
				gotoxy(42, 15);
				scanf("%f", &(p1->Computer));

				gotoxy(26, 16);
				printf("修改后的JAVA：");
				gotoxy(42, 16);
				scanf("%f", &(p1->JavaP));

				gotoxy(26, 17);
				printf("修改后的体育：");
				gotoxy(40, 17);
				scanf("%f", &(p1->PE));
				break;
			}
		}

		if (p1->Next == NULL)
		{
			gotoxy(30, 13);
			printf("没有找到要修改的学生信息!");
			gotoxy(30, 15);
			printf("请按任意键返回!");
			fclose(fp);
			_getch();
			cleanBIG();
			Operate();
			return 0;
		}

		do
		{
			fprintf(fp, "%s %s %f %f %f %f %f", p3->ID, p3->Name, p3->Math, p3->English, p3->Computer, p3->JavaP, p3->PE);
			fputs("\r\n", fp);

			p4 = p3->Next;
			p3 = p4;

			gotoxy(60, 4);
			printf("修改：%d", ++j);
		} while (p3->Next != NULL);

		clean();
		gotoxy(30, 13);
		printf("修改成功!");
		fclose(fp);
		gotoxy(30, 15);
		printf("请按任意键返回!");
		_getch();

		cleanBIG();
		Operate();
	}
	return 0;
}
/********************************************
参数：需要删除的链表的首结点地址
返回值：0
作用：通过查找链表，删除链表某一个结点，达到删除学生成绩的作用；
*********************************************/
boolean deletedScore(struct MyScore *SCO)
{
	int j = 0;
	char id[20];
	FILE * fp = NULL;
	struct MyScore * p1 = NULL, *p2 = NULL, *p3 = NULL, *p4 = NULL, *temp = NULL;
	p1 = SCO;
	p2 = SCO;
	p3 = SCO;
	p4 = SCO;

	if ((fp = fopen("学生成绩.txt", "wb+")) == NULL)
	{
		gotoxy(30, 12);
		printf("文件操作失败\n");
		fclose(fp);
		gotoxy(30, 15);
		printf("请按任意键返回!");
		_getch();

		cleanBIG();
		Operate();
		return 0;
	}


	if (p1 == NULL && p2 == NULL && p3 == NULL && p4 == NULL && temp == NULL)
	{
		clean();
		gotoxy(30, 13);
		printf("学生信息为空!");
		fclose(fp);
		gotoxy(30, 15);
		printf("请按任意键返回!");
		_getch();

		cleanBIG();
		Operate();

		return 0;
	}

	clean();
	gotoxy(26, 11);
	printf("请输入需要删除的学生学号：");
	gotoxy(52, 11);
	scanf("%s", &id);

	while (strcmp(p1->ID, id) != 0 && p1->Next != NULL)//依次按链表查找
	{
		p1 = p2->Next;
		temp = p2->Next;
		p2 = p1;


		gotoxy(60, 4);
		printf("删除：%d", ++j);
	}

	if (strcmp(p1->ID, id) == 0)
	{
		char YN;
		gotoxy(30, 13);
		printf("成功找到该学生！");
		gotoxy(8, 14);
		printf("学号------姓名------高数------英语------计算机------JAVA------体育");
		gotoxy(8, 15);
		printf("%s   %s    %.1f     %.1f     %.1f      %.1f      %.1f", p1->ID, p1->Name, p1->Math, p1->English, p1->Computer, p1->JavaP, p1->PE);
		gotoxy(30, 17);
		printf("确定删除该学生的信息吗？(Y/N)");

		while (1)
		{
			YN = _getch();

			if ('n' == YN || 'N' == YN)
			{
				fclose(fp);
				cleanBIG();
				Operate();
				return 0;
			}
			if ('y' == YN || 'Y' == YN)
			{
				clean();
				gotoxy(8, 14);
				printf("学号------姓名------高数------英语------计算机------JAVA------体育");
				gotoxy(8, 15);
				printf("%s   %s    %.1f     %.1f     %.1f      %.1f      %.1f", p1->ID, p1->Name, p1->Math, p1->English, p1->Computer, p1->JavaP, p1->PE);
				gotoxy(30, 17);
				printf("请再一次确定删除(Y/N)");

				while (1)
				{
					char yn;
					yn = _getch();

					if ('n' == yn || 'N' == yn)
					{
						fclose(fp);
						cleanBIG();
						Operate();
						return 0;
					}
					if ('y' == yn || 'Y' == yn)
					{
						if (temp == NULL)//如果第一个节点就是要删除的学生信息
						{
							p3 = p1->Next;
							free(p1);
						}
						else//要删除的学生信息不在第一个节点
						{
							temp->Next = p1->Next;
							free(p1);
						}

						do
						{
							fprintf(fp, "%s %s %f %f %f %f %f\n", p3->ID, p3->Name, p3->Math, p3->English, p3->Computer, p3->JavaP, p3->PE);
							fputs("\r\n", fp);
							p4 = p3->Next;
							p3 = p4;
						} while (p3->Next != NULL);

						clean();
						gotoxy(30, 13);
						printf("成功删除学生信息!");
						fclose(fp);
						gotoxy(30, 15);
						printf("请按任意键返回!");
						_getch();
						cleanBIG();
						Operate();

						return 0;
					}
				}

			}
		}
	}
	if (p1->Next == NULL)
	{
		gotoxy(30, 13);
		printf("没有找到要删除的学生信息!");
		fclose(fp);
		gotoxy(30, 15);
		printf("请按任意键返回!");
		_getch();

		cleanBIG();
		Operate();
		return 0;
	}
	return 0;
}
