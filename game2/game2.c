#include"game2.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void ShowBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	srand((unsigned int)time(NULL));
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int get_mine_count(char board[ROWS][COLS], int x, int y)
{
	return board[x - 1][y - 1] +
		board[x - 1][y] +
		board[x - 1][y + 1] +
		board[x][y - 1] +
		board[x][y + 1] +
		board[x + 1][y - 1] +
		board[x + 1][y] +
		board[x + 1][y + 1] -8*'0';
}
void ChooseRC(char board[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x;
	int y;
	int win = 0;
	while (win<row*col - EASY_COUNT)
	{
		printf("请选择排除雷的坐标：");
		scanf_s("%d%d", &x, &y);
		if (x <= 9 && x > 0 && y <= 9 && y > 0)
		{
			if (board[x][y] == '1')
			{
				printf("很遗憾，你被炸死了\n");
				ShowBoard(board, ROW, COL);
				break;
			}
			else
			{
				int count = get_mine_count(board, x, y);
				show[x][y] = '0' + count;
				ShowBoard(show, ROW, COL);
				win++;
			}
		}
		else
		{
			printf("输入坐标非法，请重新输入\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("恭喜你，排雷成功！\n");
	}
}