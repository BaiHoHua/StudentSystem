# include <stdio.h>
# include <windows.h>
# include <conio.h>
# include <stdlib.h>
# include <malloc.h>
# include <string.h>

struct MyStudent//ѧ����
{
	char ID[15];//ѧ��
	char Name[10];//����
	char Object[25];//רҵ
	char Class[10];//�༶
	struct MyStudent * Next;//ָ����
							//float Math,English,Computer,JavaP,PE; //�ɼ�

};
typedef struct MyStudent student;

struct MyScore
{
	char ID[15]; //ѧ��
	char Name[10]; //����
	float Math, English, Computer, JavaP, PE; //�ɼ�
	struct MyScore *Next; //ָ����
};
typedef struct MyScore score;


/****************************************************
�����������
*****************************************************/
void gotoxy(int x, int y);//�ƶ����;
void HideCursor();//���ع�꺯��;
void Face();//������Ϣ �ɼ����� ���˳�ϵͳ ѡ�����;
void ZFace();//����ѡ����Ϣ �ɼ��� �Ĺ������;
void OperateAZFace();//����Aʱ����Ϣ�������;
void OperateBZFace();//ѡ��Bʱ�ĳɼ��������;
void clean();//�������ĺ���;
void Operate();//�ܲ�������;
void cleanBIG();//��������ĺ�����				
boolean add();//���� �� ���ѧ����Ϣ����;
boolean addScore();// ���� �� ���ѧ����Ϣ������
boolean check(struct MyStudent *STU);//����ѧ����Ϣ����	
boolean checkScore(struct MyScore *SCO);//����ѧ���ɼ�����								
struct MyStudent *ReadData(); //�����ļ����� 
struct MyScore *ReadDataScore();//�����ɼ��ļ�����						  
boolean modify(struct MyStudent * STU);//�޸�ѧ������Ϣ����
boolean modifyScore(struct MyScore * SCO);//�޸�ѧ���ĳɼ�����									   
boolean deleted(struct MyStudent *STU);//ɾ��ѧ����Ϣ�ĺ�����
boolean deletedScore(struct MyScore *SCO);//ɾ��ѧ���ɼ��ĺ�����

int main(void)
{
	system("mode con cols=80 lines=30");//����̨�� ��X�ߣ�
	system("color A0");//����̨����ɫ��ʮ���������ֿ��ƣ�
	HideCursor();
	Operate();
	getchar();

	return 0;
}

/**********************************************
���Σ�
����ֵ��
���ã��������ν��溯����
***********************************************/
void Interface(int opt)
{

	int i, j;

	for (i = 0; i < 80; i += 2)
	{
		gotoxy(i, 30);
		printf("�}");
	}

	for (j = 0; j < 80; j += 2)
	{
		if (j < 28)
		{
			gotoxy(j, 5);
			printf("�}");
		}

		gotoxy(j, 0);
		printf("�}");
	}

	gotoxy(26, 1);//26��1��
	printf("�}");
	gotoxy(26, 2);
	printf("�}");
	gotoxy(26, 3);
	printf("�}");
	gotoxy(26, 4);
	printf("�}");
	gotoxy(2, 1);
	printf("ѧ����Ϣ��ɼ�����ϵͳ");
	gotoxy(2, 2);
	printf("�����Ŷ�:");
	gotoxy(12, 2);
	printf("���»�");
	gotoxy(12, 3);
	printf("�ռ���");
	gotoxy(12, 4);
	printf("�׺軪");

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
���Σ�
����ֵ��
���ã�������Ϣ �ɼ����� ���˳�ϵͳ ѡ�����
********************************************/
void Face()
{
	int k, m;

	for (k = 4; k < 28; k += 2)
	{
		gotoxy(k, 8);
		printf("�}");
		gotoxy(k, 16);
		printf("�}");
	}
	for (m = 8; m < 16; m++)
	{
		gotoxy(4, m);
		printf("�}");
		gotoxy(26, m);
		printf("�}");
	}

	gotoxy(8, 10);
	printf("A: ѧ����Ϣ����");
	gotoxy(8, 12);
	printf("B: ѧ���ɼ�����");
	gotoxy(8, 14);
	printf("C: �˳�ϵͳ");

	return;
}
/******************************************
���Σ�
����ֵ��
���ã������ض�����ʾ���溯����
*******************************************/
void ZFace()
{
	int i, j;

	for (i = 4; i < 76; i += 2)
	{
		gotoxy(i, 8);
		printf("�}");
		gotoxy(i, 27);
		printf("�}");
	}
	for (j = 8; j < 27; j++)
	{
		gotoxy(4, j);
		printf("�}");
		gotoxy(74, j);
		printf("�}");
	}

	return;
}

/******************************************
���Σ�
����ֵ��
���ã���ѡ��Aѡ��ʱ���õĽ��溯����
*******************************************/
void OperateAZFace()
{
	clean();    //???
	gotoxy(8, 10);
	printf("A:  ѧ����Ϣ����: ");
	gotoxy(8, 12);
	printf("B: ѧ���ɼ�����");

	gotoxy(26, 10);
	printf("1: �����Ϣ");
	gotoxy(26, 12);
	printf("2: ������Ϣ");
	gotoxy(26, 14);
	printf("3: �޸���Ϣ");
	gotoxy(26, 16);
	printf("4: ɾ����Ϣ");
	gotoxy(26, 18);
	printf("5: �����ϲ�");
	gotoxy(26, 20);
	printf("6: �˳�ϵͳ");

	return;
}

/******************************************
���Σ�
����ֵ��
���ã���ѡ��Bѡ��ʱ���õĽ��溯����
*******************************************/
void OperateBZFace()
{
	clean();
	gotoxy(8, 10);
	printf("A: ѧ����Ϣ����");
	gotoxy(8, 12);
	printf("B:  ѧ���ɼ�����: ");

	gotoxy(26, 12);
	printf("1: ��ӳɼ�");
	gotoxy(26, 14);
	printf("2: ���ҳɼ�");
	gotoxy(26, 16);
	printf("3: �ɼ�����");
	gotoxy(26, 18);
	printf("4: �ɼ�����");
	gotoxy(26, 20);
	printf("5: �޸ĳɼ�");
	gotoxy(26, 22);
	printf("6: ɾ���ɼ�");
	gotoxy(26, 24);
	printf("7: �����ϲ�");
	gotoxy(26, 26);
	printf("8: �˳�ϵͳ");

	return;
}

/****************************************
���Σ�
����ֵ��
���ã�����Ϊwin32����̨�涨������
*****************************************/
void clean()
{
	int i, j;//iΪX�ᣬjΪY�᣻

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
���Σ�
����ֵ��
���ã�����win32����̨��һ�����棻
****************************************/
void cleanBIG()
{
	int i, j;//iΪX�ᣬjΪY�᣻

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
�����Ĳ�����void
����ֵ��void
���ã��ܵ��ú�����
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

		if ('A' == AB || 'a' == AB)//ѡ��Aʱ�Ĳ�������
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
					//�����Ϣ
					add();
					break;
				case '2':
					//������Ϣ
					STU = ReadData();
					check(STU);
					break;
				case '3':
					//�޸���Ϣ
					STU = ReadData();
					modify(STU);
					break;
				case '4':
					//ɾ����Ϣ
					STU = ReadData();
					deleted(STU);
					break;
				case '5':
					//�����ϲ�
					cleanBIG();
					Operate();
					break;
				case '6':
					//�˳�ϵͳ
					exit(0);
					break;
				default:
					break;
				}
			}
		}
		if ('B' == AB || 'b' == AB)//ѡ��Bʱ�Ĳ�������
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
					//��ӳɼ�
					addScore();
					break;
				case '2':
					//���ҳɼ�
					SCO = ReadDataScore();
					checkScore(SCO);
					break;
				case '3':
					//�ɼ�����
					break;
				case '4':
					//�ɼ�����
					break;
				case '5':
					//�޸ĳɼ�
					SCO = ReadDataScore();
					modifyScore(SCO);
					break;
				case '6':
					//ɾ���ɼ�
					SCO = ReadDataScore();
					deletedScore(SCO);
					break;
				case '7':
					//�����ϲ�
					cleanBIG();
					Operate();
					break;
				case '8':
					//�˳�ϵͳ
					exit(0);
					break;
				default:
					break;
				}
			}
		}
		if ('c' == AB || 'C' == AB)//�˳�ϵͳ
		{
			exit(0);
		}
	}
	return;
}

//���� �� ���ѧ����Ϣ����
boolean add()
{
	int count;
	int i;
	FILE * fp;
	struct MyStudent * p = NULL;
	clean();
	gotoxy(18, 11);
	printf("��������Ҫ������ѧ��������");
	gotoxy(44, 11);
	scanf("%d", &count);


	if ((fp = fopen("ѧ����Ϣ.txt", "ab")) == NULL)
	{//���ж�ԭ���Ƿ����  ѧ����Ϣ.txt�������ڣ���ر��ļ�ָ��
		fclose(fp);

		if ((fp = fopen("ѧ����Ϣ.txt", "wb")) == NULL)
		{//���Ϊ�գ����½� ѧ����Ϣ.txt  ʧ��
			gotoxy(30, 13);
			printf("�ļ�����");
			gotoxy(30, 15);
			printf("�밴���������!");
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
			printf("����ѧ��ʧ�ܣ�");
			gotoxy(30, 15);
			printf("�밴���������!");
			_getch();
			cleanBIG();
			Operate();
			return 0;

		}
		gotoxy(26, 11);
		printf("�������%d��ѧ����ѧ�ţ�", i + 1);
		gotoxy(49, 11);
		scanf("%s", &(p->ID));//15��ʾp->ID���ֽ���

		clean();
		gotoxy(26, 11);
		printf("�������%d��ѧ����������", i + 1);
		gotoxy(49, 11);
		scanf("%s", &(p->Name));

		clean();
		gotoxy(26, 11);
		printf("�������%d��ѧ����רҵ��", i + 1);
		gotoxy(49, 11);
		scanf("%s", &(p->Object));

		clean();
		gotoxy(26, 11);
		printf("�������%d��ѧ���İ༶��", i + 1);
		gotoxy(49, 11);
		scanf("%s", &(p->Class));

		fprintf(fp, "%s %s %s %s", p->ID, p->Name, p->Object, p->Class);
		fputs("\r\n", fp);
	}

	clean();
	gotoxy(30, 13);
	printf("��ӳɹ�!");
	fclose(fp);
	gotoxy(30, 15);
	printf("�밴���������!");
	_getch();

	cleanBIG();
	Operate();

	return 0;
}

/************************************************
�����Ĳ����������ͷָ��
����ֵ��0
�����ã�ͨ�����ҵ��������ҵ�ѧ������Ϣ��
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
		printf("ѧ����ϢΪ��!");
		gotoxy(30, 15);
		printf("�밴���������!");
		_getch();

		cleanBIG();
		Operate();

		return 0;
	}

	clean();
	gotoxy(26, 11);
	printf("��������Ҫ����ѧ����ѧ�ţ�");
	gotoxy(52, 11);
	scanf("%s", &id);

	while (strcmp(p1->ID, id) != 0 && p1->Next != NULL)//���ΰ��������
	{
		p1 = p2->Next;
		p2 = p1;

		gotoxy(60, 2);
		printf("%d", ++j);
	}

	if (strcmp(p1->ID, id) == 0)
	{
		gotoxy(30, 13);
		printf("�ɹ��ҵ���ѧ����");
		gotoxy(16, 14);
		printf("ѧ��------------����------------רҵ------------�༶");
		gotoxy(16, 15);
		printf("%s     %s       %s       %s", p1->ID, p1->Name, p1->Object, p1->Class);
		gotoxy(30, 17);
		printf("�밴���������!");
		_getch();

		cleanBIG();
		Operate();
		return 0;
	}

	if (p1->Next == NULL)
	{
		gotoxy(30, 13);
		printf("û���ҵ���ѧ��!");
		gotoxy(30, 15);
		printf("�밴���������!");
		_getch();
		cleanBIG();
		Operate();
		return 0;
	}
	return 0;
}

/********************************************
��������Ҫ�޸ĵ�������׽��ĵ�ַ
����ֵ��0
���ã�ͨ�����ҵ�������Ľ�㣬�޸�ѧ����Ϣ
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


	if ((fp = fopen("ѧ����Ϣ.txt", "wb+")) == NULL)
	{
		gotoxy(30, 12);
		printf("�ļ�����ʧ��\n");
		fclose(fp);
		gotoxy(30, 15);
		printf("�밴���������!");
		_getch();

		cleanBIG();
		Operate();
		return 0;
	}

	if (p1 == NULL)
	{
		clean();
		gotoxy(30, 13);
		printf("ѧ����ϢΪ��!");
		fclose(fp);
		gotoxy(30, 15);
		printf("�밴���������!");
		_getch();

		cleanBIG();
		Operate();

		return 0;
	}

	clean();
	gotoxy(26, 11);
	printf("��������Ҫ�޸�ѧ����ѧ�ţ�");
	gotoxy(52, 11);
	scanf("%s", &id);

	while (strcmp(p1->ID, id) != 0 && p1->Next != NULL)//���ΰ��������
	{
		p1 = p2->Next;
		p2 = p1;
	}

	if (strcmp(p1->ID, id) == 0)
	{
		char YN;
		gotoxy(30, 13);
		printf("ȷ���޸ĸ�ѧ������Ϣ��(Y/N)");

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
				printf("�޸ĺ��ѧ�ţ�");
				gotoxy(40, 11);
				scanf("%s", &(p1->ID));

				clean();
				gotoxy(26, 11);
				printf("�޸ĺ��������");
				gotoxy(40, 11);
				scanf("%s", &(p1->Name));

				clean();
				gotoxy(26, 11);
				printf("�޸ĺ��רҵ��");
				gotoxy(40, 11);
				scanf("%s", &(p1->Object));

				clean();
				gotoxy(26, 11);
				printf("�޸ĺ�İ༶��");
				gotoxy(40, 11);
				scanf("%s", &(p1->Class));

				break;
			}
		}

		if (p1->Next == NULL)
		{
			gotoxy(30, 13);
			printf("û���ҵ�Ҫ�޸ĵ�ѧ����Ϣ!");
			gotoxy(30, 15);
			printf("�밴���������!");
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
			printf("�޸ģ�%d", ++j);
		} while (p3->Next != NULL);

		clean();
		gotoxy(30, 13);
		printf("�޸ĳɹ�!");
		fclose(fp);
		gotoxy(30, 15);
		printf("�밴���������!");
		_getch();

		cleanBIG();
		Operate();
	}
	return 0;
}

/********************************************
��������Ҫɾ����������׽���ַ
����ֵ��0
���ã�ͨ����������ɾ������ĳһ����㣬�ﵽɾ��ѧ����Ϣ�����ã�
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

	if ((fp = fopen("ѧ����Ϣ.txt", "wb+")) == NULL)
	{
		gotoxy(30, 12);
		printf("�ļ�����ʧ��\n");
		fclose(fp);
		gotoxy(30, 15);
		printf("�밴���������!");
		_getch();

		cleanBIG();
		Operate();
		return 0;
	}


	if (p1 == NULL && p2 == NULL && p3 == NULL && p4 == NULL)
	{
		clean();
		gotoxy(30, 13);
		printf("ѧ����ϢΪ��!");
		fclose(fp);
		gotoxy(30, 15);
		printf("�밴���������!");
		_getch();

		cleanBIG();
		Operate();

		return 0;
	}

	clean();
	gotoxy(26, 11);
	printf("��������Ҫɾ����ѧ��ѧ�ţ�");
	gotoxy(52, 11);
	scanf("%s", &id);

	while (strcmp(p1->ID, id) != 0 && p1->Next != NULL)//���ΰ��������
	{
		p1 = p2->Next;
		temp = p2;
		p2 = p1;
	}

	if (strcmp(p1->ID, id) == 0)
	{
		char YN;
		gotoxy(30, 13);
		printf("�ɹ��ҵ���ѧ����");
		gotoxy(16, 14);
		printf("ѧ��------------����------------רҵ------------�༶");
		gotoxy(16, 15);
		printf("%s     %s       %s       %s", p1->ID, p1->Name, p1->Object, p1->Class);
		gotoxy(30, 17);
		printf("ȷ��ɾ����ѧ������Ϣ��(Y/N)");

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
				printf("ѧ��------------����------------רҵ------------�༶");
				gotoxy(16, 15);
				printf("%s     %s       %s         %s", p1->ID, p1->Name, p1->Object, p1->Class);
				gotoxy(30, 17);
				printf("����һ��ȷ��ɾ��(Y/N)");

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
						if (temp == NULL)//�����һ���ڵ����Ҫɾ����ѧ����Ϣ
						{
							p3 = p1->Next;
							free(p1);
						}
						else//Ҫɾ����ѧ����Ϣ���ڵ�һ���ڵ�
						{
							temp->Next = p1->Next;
							free(p1);
						}

					if(p3 != NULL)
					{
						do
						{
							gotoxy(60, 4);
							printf("ɾ��+++++========��%d", ++j);
							fprintf(fp, "%s %s %s %s\n", p3->ID, p3->Name, p3->Object, p3->Class);
							fputs("\r\n", fp);
							p4 = p3->Next;
							p3 = p4;
						} while (p3 != NULL);
					}

						clean();
						gotoxy(30, 13);
						printf("�ɹ�ɾ��ѧ����Ϣ!");
						fclose(fp);
						gotoxy(30, 15);
						printf("�밴���������!");
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
		printf("û���ҵ�Ҫɾ����ѧ����Ϣ!");
		fclose(fp);
		gotoxy(30, 15);
		printf("�밴���������!");
		_getch();

		cleanBIG();
		Operate();
		return 0;
	}
	return 0;
}

/***********************************************
������void
����ֵ��������׽��ĵ�ַ
���ã���ȡD���´��ڵ�txt�ļ���ѧ����Ϣ.txt������������������У������ظ�
�����ͷ���ָ�룻
***********************************************/
struct MyStudent *ReadData()
{
	int i = 0;
	FILE *fp = NULL;
	struct MyStudent *H = NULL, *p = NULL, *p1 = NULL;
	p1 = (struct MyStudent *)malloc(sizeof(struct MyStudent));

	if ((fp = fopen("ѧ����Ϣ.txt", "rb")) == NULL)
	{
		gotoxy(30, 12);
		printf("�ļ�����ʧ��\n");
		fclose(fp);
		gotoxy(30, 15);
		printf("�밴���������!");
		_getch();
		cleanBIG();
		Operate();
		return NULL;
	}
	while (!feof(fp))//�����ȡ�ļ�û�н�����feof�������� 0 ֵ��
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
	printf("�����ݣ�%d", ++i);

	fclose(fp);
	return H;
}

/****************************************************
������win32����̨���ݺ�����X Y
����ֵ��void
���ã��������λ�õĺ���������ΪGetStdHandle(STD_OUTPUT_HANDLE)
���ر�׼����������Ҳ���ǻ�������Ļ����ȥ�ľ��������ֵ��positing��
*****************************************************/
void gotoxy(int x, int y)
{
	COORD position = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

/****************************************************
������void
����ֵ��void
���ã����ؿ���̨�Ĺ�ꣻ
*****************************************************/
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}


//���� �� ��ӳɼ���Ϣ����
boolean addScore()
{
	int count;
	int i;
	FILE * fp;
	struct MyScore * p = NULL;
	clean();
	gotoxy(18, 11);
	printf("��������Ҫ������ѧ��������");
	gotoxy(44, 11);
	scanf("%d", &count);

	if ((fp = fopen("ѧ���ɼ�.txt", "ab")) == NULL)
	{//���ж�ԭ���Ƿ����  ѧ���ɼ�.txt�������ڣ���ر��ļ�ָ��
		fclose(fp);

		if ((fp = fopen("ѧ���ɼ�.txt", "wb")) == NULL)
		{//���Ϊ�գ����½� ѧ���ɼ�.txt  ʧ��
			gotoxy(30, 13);
			printf("�ļ�����");
			gotoxy(30, 15);
			printf("�밴���������!");
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
			printf("����ѧ��ʧ�ܣ�");
			gotoxy(30, 15);
			printf("�밴���������!");
			_getch();
			cleanBIG();
			Operate();
			return 0;

		}
		gotoxy(20, 10);
		printf("�������%d��ѧ����ѧ�ţ�", i + 1);
		gotoxy(43, 10);
		scanf("%s", &(p->ID));//15��ʾp->ID���ֽ���

							  //clean();
		gotoxy(20, 11);
		printf("�������%d��ѧ����������", i + 1);
		gotoxy(43, 11);
		scanf("%s", &(p->Name));

		//clean();
		gotoxy(20, 12);
		printf("�������%d��ѧ���ĸ����ɼ���", i + 1);
		gotoxy(47, 12);
		scanf("%f", &(p->Math));

		gotoxy(20, 13);
		printf("�������%d��ѧ����Ӣ��ɼ���", i + 1);
		gotoxy(47, 13);
		scanf("%f", &(p->English));

		gotoxy(20, 14);
		printf("�������%d��ѧ���ļ�����ɼ���", i + 1);
		gotoxy(49, 14);
		scanf("%f", &(p->Computer));

		gotoxy(20, 15);
		printf("�������%d��ѧ����JAVA�ɼ���", i + 1);
		gotoxy(47, 15);
		scanf("%f", &(p->JavaP));

		gotoxy(20, 16);
		printf("�������%d��ѧ���������ɼ���", i + 1);
		gotoxy(47, 16);
		scanf("%f", &(p->PE));

		//clean();
		//gotoxy(26, 11);
		//printf("�������%d��ѧ���İ༶��", i + 1);
		//gotoxy(49, 11);
		//scanf("%s", &(p->Class));

		fprintf(fp, "%s %s %f %f %f %f %f ", p->ID, p->Name, p->Math, p->English, p->Computer, p->JavaP, p->PE);
		fputs("\r\n", fp);
	}

	clean();
	gotoxy(30, 13);
	printf("��ӳɹ�!");
	fclose(fp);
	gotoxy(30, 15);
	printf("�밴���������!");
	_getch();

	cleanBIG();
	Operate();

	return 0;
}
/***********************************************
������void
����ֵ��������׽��ĵ�ַ
���ã���ȡD���´��ڵ�txt�ļ���ѧ���ɼ�.txt������������������У������ظ�
�����ͷ���ָ�룻
***********************************************/
struct MyScore *ReadDataScore()
{
	int i = 0;
	FILE *fp = NULL;
	struct MyScore *H = NULL, *p = NULL, *p1 = NULL;
	p1 = (struct MyScore *)malloc(sizeof(struct MyScore));

	if ((fp = fopen("ѧ���ɼ�.txt", "rb")) == NULL)
	{
		gotoxy(30, 12);
		printf("�ļ�����ʧ��\n");
		fclose(fp);
		gotoxy(30, 15);
		printf("�밴���������!");
		_getch();
		cleanBIG();
		Operate();
		return NULL;
	}
	while (!feof(fp))//�����ȡ�ļ�û�н�����feof�������� 0 ֵ��
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
�����Ĳ����������ͷָ��
����ֵ��0
�����ã�ͨ�����ҵ��������ҵ�ѧ���ĳɼ���
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
		printf("ѧ����ϢΪ��!");
		gotoxy(30, 15);
		printf("�밴���������!");
		_getch();

		cleanBIG();
		Operate();

		return 0;
	}

	clean();
	gotoxy(26, 11);
	printf("��������Ҫ����ѧ����ѧ�ţ�");
	gotoxy(52, 11);
	scanf("%s", &id);

	while (strcmp(p1->ID, id) != 0 && p1->Next != NULL)//���ΰ��������
	{
		p1 = p2->Next;
		p2 = p1;

		gotoxy(60, 2);
		printf("%d", ++j);
	}

	if (strcmp(p1->ID, id) == 0)
	{
		gotoxy(30, 13);
		printf("�ɹ��ҵ���ѧ����");
		gotoxy(8, 14);
		printf("ѧ��------����------����------Ӣ��------�����------JAVA------����");
		gotoxy(8, 15);
		printf("%s   %s    %.1f     %.1f     %.1f      %.1f      %.1f", p1->ID, p1->Name, p1->Math, p1->English, p1->Computer, p1->JavaP, p1->PE);
		gotoxy(16, 17);
		printf("�밴���������!");
		_getch();

		cleanBIG();
		Operate();
		return 0;
	}

	if (p1->Next == NULL)
	{
		gotoxy(30, 13);
		printf("û���ҵ���ѧ��!");
		gotoxy(30, 15);
		printf("�밴���������!");
		_getch();
		cleanBIG();
		Operate();
		return 0;
	}
	return 0;
}
/********************************************
��������Ҫ�޸ĵ�������׽��ĵ�ַ
����ֵ��0
���ã�ͨ�����ҵ�������Ľ�㣬�޸�ѧ���ɼ�
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


	if ((fp = fopen("ѧ���ɼ�.txt", "wb+")) == NULL)
	{
		gotoxy(30, 12);
		printf("�ļ�����ʧ��\n");
		fclose(fp);
		gotoxy(30, 15);
		printf("�밴���������!");
		_getch();

		cleanBIG();
		Operate();
		return 0;
	}

	if (p1 == NULL)
	{
		clean();
		gotoxy(30, 13);
		printf("ѧ����ϢΪ��!");
		fclose(fp);
		gotoxy(30, 15);
		printf("�밴���������!");
		_getch();

		cleanBIG();
		Operate();

		return 0;
	}

	clean();
	gotoxy(26, 11);
	printf("��������Ҫ�޸�ѧ����ѧ�ţ�");
	gotoxy(52, 11);
	scanf("%s", &id);

	while (strcmp(p1->ID, id) != 0 && p1->Next != NULL)//���ΰ��������
	{
		p1 = p2->Next;
		p2 = p1;
	}

	if (strcmp(p1->ID, id) == 0)
	{
		char YN;
		gotoxy(30, 13);
		printf("ȷ���޸ĸ�ѧ������Ϣ��(Y/N)");

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
				printf("�޸ĺ��ѧ�ţ�");
				gotoxy(40, 11);
				scanf("%s", &(p1->ID));

				//clean();
				gotoxy(26, 12);
				printf("�޸ĺ��������");
				gotoxy(40, 12);
				scanf("%s", &(p1->Name));

				//clean();
				gotoxy(26, 13);
				printf("�޸ĺ�ĸ�����");
				gotoxy(40, 13);
				scanf("%f", &(p1->Math));

				//clean();
				gotoxy(26, 14);
				printf("�޸ĺ��Ӣ�");
				gotoxy(40, 14);
				scanf("%f", &(p1->English));

				gotoxy(26, 15);
				printf("�޸ĺ�ļ������");
				gotoxy(42, 15);
				scanf("%f", &(p1->Computer));

				gotoxy(26, 16);
				printf("�޸ĺ��JAVA��");
				gotoxy(42, 16);
				scanf("%f", &(p1->JavaP));

				gotoxy(26, 17);
				printf("�޸ĺ��������");
				gotoxy(40, 17);
				scanf("%f", &(p1->PE));
				break;
			}
		}

		if (p1->Next == NULL)
		{
			gotoxy(30, 13);
			printf("û���ҵ�Ҫ�޸ĵ�ѧ����Ϣ!");
			gotoxy(30, 15);
			printf("�밴���������!");
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
			printf("�޸ģ�%d", ++j);
		} while (p3->Next != NULL);

		clean();
		gotoxy(30, 13);
		printf("�޸ĳɹ�!");
		fclose(fp);
		gotoxy(30, 15);
		printf("�밴���������!");
		_getch();

		cleanBIG();
		Operate();
	}
	return 0;
}
/********************************************
��������Ҫɾ����������׽���ַ
����ֵ��0
���ã�ͨ����������ɾ������ĳһ����㣬�ﵽɾ��ѧ���ɼ������ã�
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

	if ((fp = fopen("ѧ���ɼ�.txt", "wb+")) == NULL)
	{
		gotoxy(30, 12);
		printf("�ļ�����ʧ��\n");
		fclose(fp);
		gotoxy(30, 15);
		printf("�밴���������!");
		_getch();

		cleanBIG();
		Operate();
		return 0;
	}


	if (p1 == NULL && p2 == NULL && p3 == NULL && p4 == NULL && temp == NULL)
	{
		clean();
		gotoxy(30, 13);
		printf("ѧ����ϢΪ��!");
		fclose(fp);
		gotoxy(30, 15);
		printf("�밴���������!");
		_getch();

		cleanBIG();
		Operate();

		return 0;
	}

	clean();
	gotoxy(26, 11);
	printf("��������Ҫɾ����ѧ��ѧ�ţ�");
	gotoxy(52, 11);
	scanf("%s", &id);

	while (strcmp(p1->ID, id) != 0 && p1->Next != NULL)//���ΰ��������
	{
		p1 = p2->Next;
		temp = p2->Next;
		p2 = p1;


		gotoxy(60, 4);
		printf("ɾ����%d", ++j);
	}

	if (strcmp(p1->ID, id) == 0)
	{
		char YN;
		gotoxy(30, 13);
		printf("�ɹ��ҵ���ѧ����");
		gotoxy(8, 14);
		printf("ѧ��------����------����------Ӣ��------�����------JAVA------����");
		gotoxy(8, 15);
		printf("%s   %s    %.1f     %.1f     %.1f      %.1f      %.1f", p1->ID, p1->Name, p1->Math, p1->English, p1->Computer, p1->JavaP, p1->PE);
		gotoxy(30, 17);
		printf("ȷ��ɾ����ѧ������Ϣ��(Y/N)");

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
				printf("ѧ��------����------����------Ӣ��------�����------JAVA------����");
				gotoxy(8, 15);
				printf("%s   %s    %.1f     %.1f     %.1f      %.1f      %.1f", p1->ID, p1->Name, p1->Math, p1->English, p1->Computer, p1->JavaP, p1->PE);
				gotoxy(30, 17);
				printf("����һ��ȷ��ɾ��(Y/N)");

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
						if (temp == NULL)//�����һ���ڵ����Ҫɾ����ѧ����Ϣ
						{
							p3 = p1->Next;
							free(p1);
						}
						else//Ҫɾ����ѧ����Ϣ���ڵ�һ���ڵ�
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
						printf("�ɹ�ɾ��ѧ����Ϣ!");
						fclose(fp);
						gotoxy(30, 15);
						printf("�밴���������!");
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
		printf("û���ҵ�Ҫɾ����ѧ����Ϣ!");
		fclose(fp);
		gotoxy(30, 15);
		printf("�밴���������!");
		_getch();

		cleanBIG();
		Operate();
		return 0;
	}
	return 0;
}
