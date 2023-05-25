#ifndef _RanSanMoi_
#define _RanSanMoi_
#include <iostream>
#include <string>
#include <Windows.h>
#include <thread>
#include <stdio.h>
#include <conio.h>
#include<vector>
struct DATA
{
	char name[51];
	int SCORE;
	int MAX_SCORE;
	int SPEED;
	int FODD_INDEX;
	int SIZE_SNAKE;
	POINT snake[10];
	char CHAR_LOCK, MOVING;
};
using namespace std;
#pragma execution_character_set( "utf-8" )
#define MAX_SIZE_FOOD 4
#define MAX_SIZE_SNAKE 10
#define MAX_SPEED 3
extern int nData;
extern int INDEX_DATA;
extern vector<DATA> player;
extern POINT snake[10], food[5];
extern int CHAR_LOCK;
extern POINT GATE[4];
extern POINT GATE_INTO;
extern int MOVING;
extern int SPEED;
extern int HEIGH_CONSOLE, WIDTH_CONSOLE;
extern int FOOD_INDEX;
extern int SIZE_SNAKE;
extern int STATE;
extern char MSSV[11];
extern int SCORE;
extern vector <char> MOVING_MAP3;
extern vector<POINT> MAP;
extern HANDLE handle_t0;
extern HANDLE handle_t1;
void Nocursortype();
void FixConsoleWindow();
void GotoXY(int x, int y);
void textColor(int x);
void Loading();
int Menu();
void Get_Data();
void Get_Index_Data();
void Change_Data();
void add_Player();
void Save_File_Data();
void Count_Down();
void Draw_Map();
void DrawBoard(int x, int y, int width, int height);
void StartGame();
void ExitGame(HANDLE t);
void PauseGame(HANDLE t);
void Map3();
void ThreadFunc();
void RankBoard();
void Sort();
void LoadGame();
void Introduce();
#endif // !_RanSanMoi_










