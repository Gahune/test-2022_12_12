#include"game2.h"

void menu()
{
	printf("**********************\n");
	printf("******  1.play  ******\n");
	printf("******  0.exit  ******\n");
	printf("**********************\n");
}
void game()
{
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	//��ʼ������
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//��ӡ����
	ShowBoard(mine, ROW, COL);
	ShowBoard(show, ROW, COL);
	//��������
	SetMine(mine, ROW, COL);
	ShowBoard(mine, ROW, COL);
	//����
	ChooseRC(mine,show, ROW, COL);
}

void test()
{
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
		default:
			printf("ѡ�����������ѡ��");
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}