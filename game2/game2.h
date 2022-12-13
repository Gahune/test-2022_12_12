#pragma once

#define ROWS 11
#define COLS 11
#define ROW 9
#define COL 9
#define EASY_COUNT 10
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void InitBoard(char board[ROWS][COLS],int rows,int cols,char set);
void ShowBoard(char board[ROWS][COLS],int row,int col);
void SetMine(char board[ROWS][COLS],int row,int col);
void ChooseRC(char board[ROWS][COLS],char show[ROWS][COLS], int row, int col);