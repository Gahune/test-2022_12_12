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
	//初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//打印棋盘
	ShowBoard(mine, ROW, COL);
	ShowBoard(show, ROW, COL);
	//布置棋盘
	SetMine(mine, ROW, COL);
	ShowBoard(mine, ROW, COL);
	//排雷
	ChooseRC(mine,show, ROW, COL);
}

void test()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择：");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
		default:
			printf("选择错误，请重新选择！");
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}