#include "Function.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <thread>
#include <stdio.h>
#include <conio.h>
#include<fstream>
#include <vector>
using namespace std;
#pragma execution_character_set( "utf-8" )
vector<DATA> player;
int nData;
int INDEX_DATA = -1;
POINT snake[10], food[5];
int CHAR_LOCK;
POINT GATE[4];
POINT GATE_INTO;
int MOVING;
int SPEED;
int HEIGH_CONSOLE, WIDTH_CONSOLE;
int FOOD_INDEX;
int SIZE_SNAKE;
int STATE;
int SCORE = 0;
char MSSV[11] = { "|50|68|18|" };
vector <char> MOVING_MAP3;
vector<POINT> MAP;
HANDLE handle_t0;
HANDLE handle_t1;
void Nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void FixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void GotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void textColor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void Loading()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	//Loading game
	srand(NULL);
	GotoXY(56, 20);
	cout << "LOADING";

	
	int i = 3;
	GotoXY(25, i);
	cout << "     ---_ ......._-_--."; i++;
	GotoXY(25, i);
	cout << "    (|\\ /      / /| \\  \\ "; i++;
	GotoXY(25, i);
	cout << "    /  /     .'  -=-'   `."; i++;
	GotoXY(25, i);
	cout << "   /  /    .'             )"; i++;
	GotoXY(25, i);
	cout << " _/  /   .'        _.)   /"; i++;
	GotoXY(25, i);
	cout << "/ o   o        _.-' /  .'  "; i++;
	GotoXY(25, i);
	cout << "\\          _.-'    / .'*|  "; i++;
	GotoXY(25, i);
	cout << " \\______.-'//    .'.' \\*|  "; i++;
	GotoXY(25, i);
	cout << "  \\|  \\ | //   .'.' _ |*|                        _"; i++;
	GotoXY(25, i);
	cout << "   `   \\|//  .'.'_ _ _|*|                       | |"; i++;
	GotoXY(25, i);
	cout << "    .  .// .'.' | _ _ \\*|        ___ _ __   __ _| | _____"; i++;
	GotoXY(25, i);
	cout << "    \\`-|\\_/ /    \\ _ _ \\*\\      / __| '_ \\ / _` | |/ / _ \\"; i++;
	GotoXY(25, i);
	cout << "     `/'\\__/      \\ _ _ \\*\\     \\__ \\ | | | (_| |    < __/"; i++;
	GotoXY(25, i);
	cout << "    /^|            \\ _ _ \\*     |___/_| |_|\\__,_|_|\\_\\___| "; i++;
	GotoXY(25, i);
	cout << "   '  `             \\ _ _ \\     "; i++;
	GotoXY(25, i);
	cout << "                     \\_  "; i++;


	GotoXY(28, 25);
	cout << "│";
	GotoXY(92, 25);
	cout << "│";
	GotoXY(29, 25);
	for (int i = 29; i < 92; i++) {
		int a = rand() % 50;
		Sleep(a);
		cout << "█";
	}
}
int Menu() {
	//nền menu
	system("cls");
	for (int i = 0; i < 20; i++) {
		textColor(1);
		cout << "█";
	}
	cout << endl;
	for (int i = 0; i < 18; i++) {
		textColor(2);
		cout << "█";
	}
	cout << endl;
	for (int i = 0; i < 18; i++) {
		cout << "█";
	}
	cout << endl;
	for (int i = 0; i < 16; i++) {
		cout << "█";
	}
	cout << endl;
	for (int i = 0; i < 12; i++) {
		cout << "█";
	}
	cout << endl;
	for (int i = 0; i < 11; i++) {
		cout << "█";
	}
	cout << endl;
	for (int i = 0; i < 6; i++) {
		cout << "█";
	}
	cout << endl;
	for (int i = 0; i < 22; i++) {
		cout << "■";
	}

	textColor(228);
	int i = 4;
	GotoXY(36, i);
	cout << " ██████\\  ██\\   ██\\  ██████\\  ██\\   ██\\ ████████\\  "; i++;
	GotoXY(36, i);
	cout << "██  __██\\ ███\\  ██ |██  __██\\ ██ | ██  |██  _____| "; i++;
	GotoXY(36, i);
	cout << "██ /  \\__|████\\ ██ |██ /  ██ |██ |██  / ██ |       "; i++;
	GotoXY(36, i);
	cout << "\\██████\\  ██ ██\\██ |████████ |█████  /  █████\\     "; i++;
	GotoXY(36, i);
	cout << " \\____██\\ ██ \\████ |██  __██ |██  ██<   ██  __|    "; i++;
	GotoXY(36, i);
	cout << "██\\   ██ |██ |\\███ |██ |  ██ |██ |\\██\\  ██ |       "; i++;
	GotoXY(36, i);
	cout << "\\██████  |██ | \\██ |██ |  ██ |██ | \\██\\ █████████\\ "; i++;
	GotoXY(36, i);
	cout << " \\______/ \\__|  \\__|\\__|  \\__|\\__|  \\__|\\_________|"; i++;
	GotoXY(1, 30);
	cout << "█" << "▄" << "▄" << "▄";

	GotoXY(34, i);
	//menu
	int Choose = 1;
	char press;
	do {
		switch (Choose)
		{
		case 1:
		{
			GotoXY(48, 15); textColor(228);
			cout << ">>    N_E_W   G_A_M_E    <<";
			GotoXY(48, 17); textColor(232);
			cout << "     L_O_A_D   G_A_M_E     ";
			GotoXY(48, 19); textColor(232);
			cout << "    R_A_N_K   B_O_A_R_D    ";
			GotoXY(48, 21); textColor(232);
			cout << "     I_N_T_R_O_D_U_C_E     ";
			GotoXY(48, 23); textColor(232);
			cout << "     E_X_I_T   G_A_M_E     ";
			break;
		}
		case 2:
		{
			GotoXY(48, 15); textColor(232);
			cout << "      N_E_W   G_A_M_E      ";
			GotoXY(48, 17); textColor(228);
			cout << ">>   L_O_A_D   G_A_M_E   <<";
			GotoXY(48, 19); textColor(232);
			cout << "    R_A_N_K   B_O_A_R_D    ";
			GotoXY(48, 21); textColor(232);
			cout << "     I_N_T_R_O_D_U_C_E     ";
			GotoXY(48, 23); textColor(232);
			cout << "     E_X_I_T   G_A_M_E     ";
			break;
		}
		case 3:
		{
			GotoXY(48, 15); textColor(232);
			cout << "      N_E_W   G_A_M_E      ";
			GotoXY(48, 17); textColor(232);
			cout << "     L_O_A_D   G_A_M_E     ";
			GotoXY(48, 19); textColor(228);
			cout << ">>  R_A_N_K   B_O_A_R_D  <<";
			GotoXY(48, 21); textColor(232);
			cout << "     I_N_T_R_O_D_U_C_E     ";
			GotoXY(48, 23); textColor(232);
			cout << "     E_X_I_T   G_A_M_E     ";
			break;
		}
		case 4:
		{
			GotoXY(48, 15); textColor(232);
			cout << "      N_E_W   G_A_M_E      ";
			GotoXY(48, 17); textColor(232);
			cout << "     L_O_A_D   G_A_M_E     ";
			GotoXY(48, 19); textColor(232);
			cout << "    R_A_N_K   B_O_A_R_D    ";
			GotoXY(48, 21); textColor(228);
			cout << ">>   I_N_T_R_O_D_U_C_E   <<";
			GotoXY(48, 23); textColor(232);
			cout << "     E_X_I_T   G_A_M_E     ";
			break;
		}
		case 5:
		{
			GotoXY(48, 15); textColor(232);
			cout << "      N_E_W   G_A_M_E      ";
			GotoXY(48, 17); textColor(232);
			cout << "     L_O_A_D   G_A_M_E     ";
			GotoXY(48, 19); textColor(232);
			cout << "    R_A_N_K   B_O_A_R_D    ";
			GotoXY(48, 21); textColor(232);
			cout << "     I_N_T_R_O_D_U_C_E     ";
			GotoXY(48, 23); textColor(228);
			cout << ">>   E_X_I_T   G_A_M_E   <<";
			break;
		}
		}
		press = toupper(_getch());
		if (press == 'W')
		{
			if (Choose != 1) Choose--;
		}
		if (press == 'S')
		{
			if (Choose != 5) Choose++;
		}
	} while (press != 13);
	return Choose;
}
void Get_Data()
{
	// tao file ghi
	ifstream data;
	data.open("C:/Users/DELL/source/repos/Data4.txt");
	//lay du lieu
	data >> nData; data.ignore();
	INDEX_DATA = -1;
	for (int i = 0; i < nData; i++)
	{
		player.push_back(DATA());
		data.getline(player[i].name, 50);
		data >> player[i].SCORE;
		data >> player[i].MAX_SCORE;
		data >> player[i].SPEED;
		data >> player[i].FODD_INDEX;
		data >> player[i].SIZE_SNAKE;
		for (int j = 0; j < player[i].SIZE_SNAKE; j++)
		{
			data >> player[i].snake[j].x >> player[i].snake[j].y;
		}
		data.ignore();
		data >> player[i].CHAR_LOCK >> player[i].MOVING;
		data.ignore();
	}
	data.close();
}
void Get_Index_Data()
{
	//nhap thu tu nguoi choi
	system("cls");
	LoadGame();
	textColor(228);
	GotoXY(19, 15);
	cout << "Choose Index : ";
	cin >> INDEX_DATA; cin.ignore();
	//lấy index_data
	if (INDEX_DATA <= player.size() && INDEX_DATA >= 1)
	{
		INDEX_DATA = INDEX_DATA - 1;
	}
	else INDEX_DATA = -1;
}
void Change_Data()
{
	if (STATE == 1)
	{
		player[INDEX_DATA].SCORE = SCORE;
		if (SCORE > player[INDEX_DATA].MAX_SCORE)
		{
			player[INDEX_DATA].MAX_SCORE = SCORE;
		}
		player[INDEX_DATA].SPEED = SPEED;
		player[INDEX_DATA].CHAR_LOCK = CHAR_LOCK;
		player[INDEX_DATA].MOVING = MOVING;
		player[INDEX_DATA].SIZE_SNAKE = SIZE_SNAKE;
		for (int i = 0; i < SIZE_SNAKE; i++)
		{
			player[INDEX_DATA].snake[i] = snake[i];
		}
		player[INDEX_DATA].FODD_INDEX = FOOD_INDEX;
	}
	else
	{
		//khoi tao lại giá trị mặc định
		if (SCORE > player[INDEX_DATA].MAX_SCORE)
		{
			player[INDEX_DATA].MAX_SCORE = SCORE;
		}
		player[INDEX_DATA].SCORE = 0;
		player[INDEX_DATA].SPEED = 1;
		player[INDEX_DATA].CHAR_LOCK = 'A';
		player[INDEX_DATA].MOVING = 'D';
		player[INDEX_DATA].SIZE_SNAKE = 6;
		player[INDEX_DATA].FODD_INDEX = 0;
		player[INDEX_DATA].snake[0] = { 10, 4 };
		player[INDEX_DATA].snake[1] = { 11, 4 };
		player[INDEX_DATA].snake[2] = { 12, 4 };
		player[INDEX_DATA].snake[3] = { 13, 4 };
		player[INDEX_DATA].snake[4] = { 14, 4 };
		player[INDEX_DATA].snake[5] = { 15, 4 };
	}
	SCORE = 0;
}
void add_Player()
{
	INDEX_DATA = nData;
	player.push_back(DATA());
	//  Nhap ten de luu
	for (int i = 6; i <= 110; i++) {
		GotoXY(i, 5);  cout << "▄";
		GotoXY(i, 25); cout << "▀";
	}

	for (int i = 6; i < 25; i++)
	{
		GotoXY(6, i); cout << "█";
		GotoXY(110, i); cout << "█";
	}
	//
	textColor(234);
	for (int i = 7; i <= 109; i++) {
		GotoXY(i, 6);  cout << "█";
		GotoXY(i, 24); cout << "█";
	}

	for (int i = 7; i < 24; i++)
	{
		GotoXY(7, i); cout << "█";
		GotoXY(109, i); cout << "█";
	}

	int i = 8;
	textColor(228);
	GotoXY(24, i);
	cout << "██╗░░░██╗░█████╗░██╗░░░██╗██████╗░  ███╗░░██╗░█████╗░███╗░░░███╗███████╗"; i++;
	GotoXY(24, i);
	cout << "╚██╗░██╔╝██╔══██╗██║░░░██║██╔══██╗  ████╗░██║██╔══██╗████╗░████║██╔════╝"; i++;
	GotoXY(24, i);
	cout << "░╚████╔╝░██║░░██║██║░░░██║██████╔╝  ██╔██╗██║███████║██╔████╔██║█████╗░░"; i++;
	GotoXY(24, i);
	cout << "░░╚██╔╝░░██║░░██║██║░░░██║██╔══██╗  ██║╚████║██╔══██║██║╚██╔╝██║██╔══╝░░"; i++;
	GotoXY(24, i);
	cout << "░░░██║░░░╚█████╔╝╚██████╔╝██║░░██║  ██║░╚███║██║░░██║██║░╚═╝░██║███████╗"; i++;
	GotoXY(24, i);
	cout << "░░░╚═╝░░░░╚════╝░░╚═════╝░╚═╝░░╚═╝  ╚═╝░░╚══╝╚═╝░░╚═╝╚═╝░░░░░╚═╝╚══════╝"; i++;


	for (int i = 36; i <= 86; i++) {
		GotoXY(i, 14);  cout << "▄";
		GotoXY(i, 23); cout << "▀";
	}

	for (int i = 15; i < 23; i++)
	{
		GotoXY(36, i); cout << "█";
		GotoXY(86, i); cout << "█";
	}

	//
	textColor(234);
	for (int i = 37; i <= 85; i++) {
		GotoXY(i, 15);  cout << "█";
		GotoXY(i, 22); cout << "█";
	}

	for (int i = 16; i < 22; i++)
	{
		GotoXY(37, i); cout << "█";
		GotoXY(85, i); cout << "█";
	}

	//
	textColor(232);
	for (int i = 38; i <= 84; i++) {
		GotoXY(i, 16);  cout << "█";
		GotoXY(i, 21); cout << "█";
	}

	for (int i = 17; i < 21; i++)
	{
		GotoXY(38, i); cout << "█";
		GotoXY(84, i); cout << "█";
	}

	textColor(228);
	GotoXY(42, 18);
	cout << "ENTER YOUR NAME: ";
	cin.getline(player[INDEX_DATA].name, 50);
	player[INDEX_DATA].SCORE = player[INDEX_DATA].MAX_SCORE = SCORE;
	player[INDEX_DATA].SPEED = SPEED;
	player[INDEX_DATA].CHAR_LOCK = CHAR_LOCK;
	player[INDEX_DATA].MOVING = MOVING;
	player[INDEX_DATA].SIZE_SNAKE = SIZE_SNAKE;
	for (int i = 0; i < SIZE_SNAKE; i++)
	{
		player[INDEX_DATA].snake[i] = snake[i];
	}
	player[INDEX_DATA].FODD_INDEX = FOOD_INDEX;
	nData++;
}
void Save_File_Data()
{
	// tao file luu
	ofstream data;
	data.open("C:/Users/DELL/source/repos/Data4.txt");
	//lay du lieu
	data << nData << endl;
	for (int i = 0; i < nData; i++)
	{
		data << player[i].name << endl;
		data << player[i].SCORE << endl;
		data << player[i].MAX_SCORE << endl;
		data << player[i].SPEED << endl;
		data << player[i].FODD_INDEX << endl;
		data << player[i].SIZE_SNAKE << endl;
		for (int j = 0; j < player[i].SIZE_SNAKE; j++)
		{
			data << player[i].snake[j].x << " " << player[i].snake[j].y << endl;
		}
		data << player[i].CHAR_LOCK << " " << player[i].MOVING << endl;
	}
	data.close();
}
bool IsValid(int x, int y)
{
	//khung 
	if (x == 1) return false;
	/////
	for (int i = 0; i < SIZE_SNAKE; i++)
	{
		if (snake[i].x == x && snake[i].y == y)
		{
			return false;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (x == GATE[i].x && y == GATE[i].y)
			return false;
	}
	//map 
	for (int i = 0; i < MAP.size(); i++)
	{
		if (x == MAP[i].x && y == MAP[i].y)
			return false;
	}
	if (SPEED == 3)
	{
		if ((x >= 8 && x <= 19) || (x >= 22 && x <= 33) || (x >= 36 && x <= 47) || (x >= 50 && x <= 61) || (x > WIDTH_CONSOLE - 11))
			return false;
	}
	return true;
}
void GenerateFood()
{
	int x, y;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX_SIZE_FOOD; i++)
	{
		do {
			x = rand() % (WIDTH_CONSOLE)+1;
			y = rand() % (HEIGH_CONSOLE - 1) + 1;
		} while (IsValid(x, y) == false);
		food[i] = { x,y };
	}
	int k = 0;
}
void Count_Down()
{
	// In số 3
	GotoXY(33, 11); cout << "■" << "■" << "■" << "■";
	GotoXY(37, 11); cout << "▄";
	GotoXY(37, 12); cout << "█";
	GotoXY(33, 13); cout << "■" << "■" << "■" << "■";
	GotoXY(37, 13); cout << "█";
	GotoXY(37, 14); cout << "█";
	GotoXY(33, 15); cout << "■" << "■" << "■" << "■";
	GotoXY(37, 15); cout << "▀";
	// Xóa 
	Sleep(1000);
	GotoXY(33, 11); cout << "       ";
	GotoXY(33, 12); cout << "       ";
	GotoXY(33, 13); cout << "       ";
	GotoXY(33, 14); cout << "       ";
	GotoXY(33, 15); cout << "       ";
	// In số 2 
	GotoXY(33, 11); cout << "■" << "■" << "■" << "■";
	GotoXY(37, 11); cout << "▄";
	GotoXY(37, 12); cout << "█";
	GotoXY(33, 13); cout << "▄" << "■" << "■" << "■" << "▀";
	GotoXY(33, 14); cout << "█";
	GotoXY(33, 15); cout << "▀" << "■" << "■" << "■" << "■";
	// Xóa 
	Sleep(1000);
	GotoXY(33, 11); cout << "       ";
	GotoXY(33, 12); cout << "       ";
	GotoXY(33, 13); cout << "       ";
	GotoXY(33, 14); cout << "       ";
	GotoXY(33, 15); cout << "       ";
	//in số 1
	GotoXY(37, 11); cout << "█";
	GotoXY(37, 12);  cout << "█";
	GotoXY(37, 13); cout << "█";
	GotoXY(37, 14); cout << "█";
	GotoXY(37, 15); cout << "█";
	//xóa 
	Sleep(1000);
	GotoXY(33, 11); cout << "       ";
	GotoXY(33, 12); cout << "       ";
	GotoXY(33, 13); cout << "       ";
	GotoXY(33, 14); cout << "       ";
	GotoXY(33, 15); cout << "       ";

}
void ResetData()
{
	if (INDEX_DATA != -1)
	{
		SCORE = player[INDEX_DATA].SCORE;
		SPEED = player[INDEX_DATA].SPEED;
		CHAR_LOCK = player[INDEX_DATA].CHAR_LOCK;
		MOVING = player[INDEX_DATA].MOVING;
		SIZE_SNAKE = player[INDEX_DATA].SIZE_SNAKE;
		for (int i = 0; i < SIZE_SNAKE; i++)
		{
			snake[i] = player[INDEX_DATA].snake[i];
		}
		FOOD_INDEX = player[INDEX_DATA].FODD_INDEX;
	}
	else
	{
		//Khởi tạo các giá trị toàn cục
		CHAR_LOCK = 'A', MOVING = 'D', SPEED = 1;
		FOOD_INDEX = 0, SIZE_SNAKE = 6; SCORE = 0;

		//Khởi tạo giá trị mặc định cho snake
		snake[0] = { 10, 4 }; snake[1] = { 11, 4 };
		snake[2] = { 12, 4 }; snake[3] = { 13, 4 };
		snake[4] = { 14, 4 }; snake[5] = { 15, 4 };
	}
	WIDTH_CONSOLE = 74, HEIGH_CONSOLE = 29;
	GATE[0] = { WIDTH_CONSOLE - 4,HEIGH_CONSOLE / 2 - 1 };
	GATE[1] = { WIDTH_CONSOLE - 4 + 1,HEIGH_CONSOLE / 2 - 1 };
	GATE[2] = { WIDTH_CONSOLE - 4,HEIGH_CONSOLE / 2 + 1 };
	GATE[3] = { WIDTH_CONSOLE - 4 + 1,HEIGH_CONSOLE / 2 + 1 };
	GATE_INTO = { WIDTH_CONSOLE - 3,HEIGH_CONSOLE / 2 };
	GenerateFood();//Tạo mảng thức ăn food
}
void StartGame() {
	system("cls");
	ResetData(); // Khởi tạo dữ liệu 
	DrawBoard(1, 0, WIDTH_CONSOLE, HEIGH_CONSOLE); // Vẽ màn hình game
	//Count_Down();
	Draw_Map();
	STATE = 1;//Bắt đầu cho Thread chạy

}
void DrawGate_In()
{
	GotoXY(GATE[0].x, GATE[0].y);
	cout << "▄";
	GotoXY(GATE[1].x, GATE[1].y);
	cout << "▄";
	GotoXY(GATE_INTO.x, GATE_INTO.y);
	cout << "▐";
	GotoXY(GATE[2].x, GATE[2].y);
	cout << "▀";
	GotoXY(GATE[3].x, GATE[3].y);
	cout << "▀";
}
void DrawGate_Out()
{
	GotoXY(GATE[0].x - 64, GATE[0].y);
	cout << "▄";
	GotoXY(GATE[1].x - 64, GATE[1].y);
	cout << "▄";
	GotoXY(GATE_INTO.x - 65, GATE_INTO.y);
	cout << "▌";
	GotoXY(GATE[2].x - 64, GATE[2].y);
	cout << "▀";
	GotoXY(GATE[3].x - 64, GATE[3].y);
	cout << "▀";
}
void EraseGate()
{

	GotoXY(WIDTH_CONSOLE - 4, HEIGH_CONSOLE / 2 - 1);
	cout << "  ";
	GotoXY(WIDTH_CONSOLE - 3, HEIGH_CONSOLE / 2);
	cout << " ";
	GotoXY(WIDTH_CONSOLE - 4, HEIGH_CONSOLE / 2 + 1);
	cout << "  ";

	GotoXY(WIDTH_CONSOLE - 4 - 64, HEIGH_CONSOLE / 2 - 1);
	cout << "  ";
	GotoXY(WIDTH_CONSOLE - 3 - 65, HEIGH_CONSOLE / 2);
	cout << " ";
	GotoXY(WIDTH_CONSOLE - 4 - 64, HEIGH_CONSOLE / 2 + 1);
	cout << "  ";
}
void EraseMap()
{
	for (int i = 0; i < MAP.size(); i++)
	{
		GotoXY(MAP[i].x, MAP[i].y);
		cout << " ";
	}
}
void Draw_Map()
{
	// ve map 
	MAP.clear();
	MOVING_MAP3.clear();
	if (SPEED == 1)
	{
		int x, y;
		x = 35; y = 4;
		GotoXY(x, y);       cout << "__";
		GotoXY(x - 1, y + 1); cout << "/'{>";
		GotoXY(x - 5, y + 2); cout << "____) (____";
		GotoXY(x - 7, y + 3); cout << "//'--;   ;--'" << "\\" << "\\";
		GotoXY(x - 8, y + 4); cout << "///////" << "\\" << "_/" << "\\" << "\\" << "\\" << "\\" << "\\" << "\\" << "\\";
		GotoXY(x - 1, y + 5); cout << "m m";
		for (int i = x; i < x + 2; i++)
		{
			MAP.push_back(POINT());
			MAP[MAP.size() - 1].x = i; MAP[MAP.size() - 1].y = y;
		}
		for (int i = x - 1; i < x + 3; i++)
		{
			MAP.push_back(POINT());
			MAP[MAP.size() - 1].x = i; MAP[MAP.size() - 1].y = y + 1;
		}
		for (int i = x - 5; i < x + 6; i++)
		{
			MAP.push_back(POINT());
			MAP[MAP.size() - 1].x = i; MAP[MAP.size() - 1].y = y + 2;
		}
		for (int i = x - 7; i < x + 8; i++)
		{
			MAP.push_back(POINT());
			MAP[MAP.size() - 1].x = i; MAP[MAP.size() - 1].y = y + 3;
		}
		for (int i = x - 8; i < x + 9; i++)
		{
			MAP.push_back(POINT());
			MAP[MAP.size() - 1].x = i; MAP[MAP.size() - 1].y = y + 4;
		}
		for (int i = x - 1; i < x + 2; i++)
		{
			MAP.push_back(POINT());
			MAP[MAP.size() - 1].x = i; MAP[MAP.size() - 1].y = y + 5;
		}

		x = 18; y = 16;
		GotoXY(x, y);       cout << "__";
		GotoXY(x - 1, y + 1); cout << "/'{>";
		GotoXY(x - 5, y + 2); cout << "____) (____";
		GotoXY(x - 7, y + 3); cout << "//'--;   ;--'" << "\\" << "\\";
		GotoXY(x - 8, y + 4); cout << "///////" << "\\" << "_/" << "\\" << "\\" << "\\" << "\\" << "\\" << "\\" << "\\";
		GotoXY(x - 1, y + 5); cout << "m m";
		for (int i = x; i < x + 2; i++)
		{
			MAP.push_back(POINT());
			MAP[MAP.size() - 1].x = i; MAP[MAP.size() - 1].y = y;
		}
		for (int i = x - 1; i < x + 3; i++)
		{
			MAP.push_back(POINT());
			MAP[MAP.size() - 1].x = i; MAP[MAP.size() - 1].y = y + 1;
		}
		for (int i = x - 5; i < x + 6; i++)
		{
			MAP.push_back(POINT());
			MAP[MAP.size() - 1].x = i; MAP[MAP.size() - 1].y = y + 2;
		}
		for (int i = x - 7; i < x + 8; i++)
		{
			MAP.push_back(POINT());
			MAP[MAP.size() - 1].x = i; MAP[MAP.size() - 1].y = y + 3;
		}
		for (int i = x - 8; i < x + 9; i++)
		{
			MAP.push_back(POINT());
			MAP[MAP.size() - 1].x = i; MAP[MAP.size() - 1].y = y + 4;
		}
		for (int i = x - 1; i < x + 2; i++)
		{
			MAP.push_back(POINT());
			MAP[MAP.size() - 1].x = i; MAP[MAP.size() - 1].y = y + 5;
		}


		x = 52; y = 16;
		GotoXY(x, y);       cout << "__";
		GotoXY(x - 1, y + 1); cout << "/'{>";
		GotoXY(x - 5, y + 2); cout << "____) (____";
		GotoXY(x - 7, y + 3); cout << "//'--;   ;--'" << "\\" << "\\";
		GotoXY(x - 8, y + 4); cout << "///////" << "\\" << "_/" << "\\" << "\\" << "\\" << "\\" << "\\" << "\\" << "\\";
		GotoXY(x - 1, y + 5); cout << "m m";
		for (int i = x; i < x + 2; i++)
		{
			MAP.push_back(POINT());
			MAP[MAP.size() - 1].x = i; MAP[MAP.size() - 1].y = y;
		}
		for (int i = x - 1; i < x + 3; i++)
		{
			MAP.push_back(POINT());
			MAP[MAP.size() - 1].x = i; MAP[MAP.size() - 1].y = y + 1;
		}
		for (int i = x - 5; i < x + 6; i++)
		{
			MAP.push_back(POINT());
			MAP[MAP.size() - 1].x = i; MAP[MAP.size() - 1].y = y + 2;
		}
		for (int i = x - 7; i < x + 8; i++)
		{
			MAP.push_back(POINT());
			MAP[MAP.size() - 1].x = i; MAP[MAP.size() - 1].y = y + 3;
		}
		for (int i = x - 8; i < x + 9; i++)
		{
			MAP.push_back(POINT());
			MAP[MAP.size() - 1].x = i; MAP[MAP.size() - 1].y = y + 4;
		}
		for (int i = x - 1; i < x + 2; i++)
		{
			MAP.push_back(POINT());
			MAP[MAP.size() - 1].x = i; MAP[MAP.size() - 1].y = y + 5;
		}
	}
	else if (SPEED == 2) // tao du lieu map va ve
	{
		//ngnag
		for (int j = 11; j <= 65; j++)
		{
			if (j == 33) j = 43;
			MAP.push_back(POINT());
			MAP[MAP.size() - 1].x = j; MAP[MAP.size() - 1].y = 6;
			GotoXY(MAP[MAP.size() - 1].x, MAP[MAP.size() - 1].y); cout << "▄";
			MAP.push_back(POINT());
			MAP[MAP.size() - 1].x = j; MAP[MAP.size() - 1].y = 22;
			GotoXY(MAP[MAP.size() - 1].x, MAP[MAP.size() - 1].y); cout << "▀";
		}
		for (int j = 16; j <= 60; j++)
		{
			MAP.push_back(POINT());
			MAP[MAP.size() - 1].x = j; MAP[MAP.size() - 1].y = 11;
			GotoXY(MAP[MAP.size() - 1].x, MAP[MAP.size() - 1].y); cout << "■";
			MAP.push_back(POINT());
			MAP[MAP.size() - 1].x = j; MAP[MAP.size() - 1].y = 17;
			GotoXY(MAP[MAP.size() - 1].x, MAP[MAP.size() - 1].y); cout << "■";
		}
		//docj
		for (int j = 7; j <= 12; j++)
		{
			MAP.push_back(POINT());
			MAP[MAP.size() - 1].x = 65; MAP[MAP.size() - 1].y = j;
			GotoXY(MAP[MAP.size() - 1].x, MAP[MAP.size() - 1].y); cout << "█";

			MAP.push_back(POINT());
			MAP[MAP.size() - 1].x = 11; MAP[MAP.size() - 1].y = j;
			GotoXY(MAP[MAP.size() - 1].x, MAP[MAP.size() - 1].y); cout << "█";

		}
		for (int j = 16; j <= 21; j++)
		{
			MAP.push_back(POINT());
			MAP[MAP.size() - 1].x = 65; MAP[MAP.size() - 1].y = j;
			GotoXY(MAP[MAP.size() - 1].x, MAP[MAP.size() - 1].y); cout << "█";

			MAP.push_back(POINT());
			MAP[MAP.size() - 1].x = 11; MAP[MAP.size() - 1].y = j;
			GotoXY(MAP[MAP.size() - 1].x, MAP[MAP.size() - 1].y); cout << "█";

		}
	}
	else if (SPEED == 3)
	{
		MOVING_MAP3.push_back('S');
		for (int i = 8; i < 20; i++)
		{
			MAP.push_back(POINT());
			MAP[MAP.size() - 1].x = i; MAP[MAP.size() - 1].y = 1;
			MAP.push_back(POINT());
			MAP[MAP.size() - 1].x = i; MAP[MAP.size() - 1].y = 2;
			MAP.push_back(POINT());
			MAP[MAP.size() - 1].x = i; MAP[MAP.size() - 1].y = 3;
		}
		GotoXY(8, MAP[0].y);
		cout << "▐"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▌";
		GotoXY(8, MAP[1].y);
		cout << "▐ DEADLINE ▌";
		GotoXY(8, MAP[2].y);
		cout << "▐"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▌";


		MOVING_MAP3.push_back('W');
		for (int i = 22; i < 34; i++)
		{
			MAP.push_back(POINT());
			MAP[MAP.size() - 1].x = i; MAP[MAP.size() - 1].y = 18;
			MAP.push_back(POINT());
			MAP[MAP.size() - 1].x = i; MAP[MAP.size() - 1].y = 19;
			MAP.push_back(POINT());
			MAP[MAP.size() - 1].x = i; MAP[MAP.size() - 1].y = 20;
		}
		GotoXY(22, MAP[36].y);
		cout << "▐"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▌";
		GotoXY(22, MAP[37].y);
		cout << "▐   MONEY  ▌";
		GotoXY(22, MAP[38].y);
		cout << "▐"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▌";


		MOVING_MAP3.push_back('S');
		for (int i = 36; i < 48; i++)
		{
			MAP.push_back(POINT());
			MAP[MAP.size() - 1].x = i; MAP[MAP.size() - 1].y = 5;
			MAP.push_back(POINT());
			MAP[MAP.size() - 1].x = i; MAP[MAP.size() - 1].y = 6;
			MAP.push_back(POINT());
			MAP[MAP.size() - 1].x = i; MAP[MAP.size() - 1].y = 7;
		}
		GotoXY(36, MAP[72].y);
		cout << "▐"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▌";
		GotoXY(36, MAP[73].y);
		cout << "▐   VICES  ▌";
		GotoXY(36, MAP[74].y);
		cout << "▐"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▌";


		MOVING_MAP3.push_back('W');
		for (int i = 50; i < 62; i++)
		{
			MAP.push_back(POINT());
			MAP[MAP.size() - 1].x = i; MAP[MAP.size() - 1].y = 26;
			MAP.push_back(POINT());
			MAP[MAP.size() - 1].x = i; MAP[MAP.size() - 1].y = 27;
			MAP.push_back(POINT());
			MAP[MAP.size() - 1].x = i; MAP[MAP.size() - 1].y = 28;
		}
		GotoXY(50, MAP[108].y);
		cout << "▐"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▌";
		GotoXY(50, MAP[109].y);
		cout << "▐ THE_LOVE ▌";
		GotoXY(50, MAP[110].y);
		cout << "▐"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▌";


		int i = 1;
		while (i < HEIGH_CONSOLE)
		{
			MAP.push_back(POINT());
			MAP[MAP.size() - 1].x = 64; MAP[MAP.size() - 1].y = i;
			GotoXY(MAP[MAP.size() - 1].x, MAP[MAP.size() - 1].y); cout << "■";
			MAP.push_back(POINT());
			MAP[MAP.size() - 1].x = 65; MAP[MAP.size() - 1].y = i;
			GotoXY(MAP[MAP.size() - 1].x, MAP[MAP.size() - 1].y); cout << "▌";
			i++;
			if (i == 11)
			{
				MAP.push_back(POINT());
				MAP[MAP.size() - 1].x = 64; MAP[MAP.size() - 1].y = i;
				GotoXY(MAP[MAP.size() - 1].x, MAP[MAP.size() - 1].y); cout << "▄";
				MAP.push_back(POINT());
				MAP[MAP.size() - 1].x = 65; MAP[MAP.size() - 1].y = i;
				GotoXY(MAP[MAP.size() - 1].x, MAP[MAP.size() - 1].y); cout << "▌";
				i = 17;
				MAP.push_back(POINT());
				MAP[MAP.size() - 1].x = 64; MAP[MAP.size() - 1].y = i;
				GotoXY(MAP[MAP.size() - 1].x, MAP[MAP.size() - 1].y); cout << "▀";
				MAP.push_back(POINT());
				MAP[MAP.size() - 1].x = 65; MAP[MAP.size() - 1].y = i;
				GotoXY(MAP[MAP.size() - 1].x, MAP[MAP.size() - 1].y); cout << "▌";
				i++;
			}
		}

	}
}
void DrawBoard(int x, int y, int width, int height)
{
	system("color e4");

	int i = x;
	int j = y + 1;
	while (i <= width + x || j < height + y)
	{
		//ngang
		if (i <= width + x)
		{
			GotoXY(i, y);  cout << "▄";
			GotoXY(width - i + x + 1, y + height); cout << "▀";
			i++;
		}
		Sleep(5);
		if (i <= width + x)
		{
			GotoXY(i, y);  cout << "▄";
			GotoXY(width - i + x + 1, y + height); cout << "▀";
			i++;
		}
		Sleep(5);
		if (i <= width + x)
		{
			GotoXY(i, y);  cout << "▄";
			GotoXY(width - i + x + 1, y + height); cout << "▀";
			i++;
		}
		Sleep(5);
		//doc
		if (j < height + y)
		{
			GotoXY(x, j); cout << "█";
			GotoXY(x + width, height - j); cout << "█";
			j++;
		}
		Sleep(20);
	}

	//Infomation
	for (int i = width + 6; i <= 110; i++) {
		GotoXY(i, y);  cout << "▄";
		GotoXY(i, y + height / 2 - 3); cout << "▀";
	}

	for (int i = y + 1; i < height / 2 - 3 + y; i++)
	{
		int j = 0;
		GotoXY(width + 6, i); cout << "█";
		GotoXY(110, i); cout << "█";
		j++;
	}

	textColor(187);
	for (int i = width + 7; i <= 109; i++) {
		for (int j = 1; j < height / 2 - 3; j++) {
			GotoXY(i, j);
			cout << " ";
		}
	}
	//Something
	textColor(228);
	for (int i = width + 6; i <= 110; i++) {
		GotoXY(i, height / 2 - 2 + y);  cout << "▄";
		GotoXY(i, height); cout << "▀";
	}

	for (int i = height / 2 - 1 + y; i < 29; i++)
	{
		GotoXY(width + 6, i); cout << "█";
		GotoXY(110, i); cout << "█";
	}

	textColor(187);
	for (int i = width + 7; i <= 109; i++) {
		for (int j = height / 2 - 2 + 1; j < height; j++) {
			GotoXY(i, j);
			cout << " ";
		}
	}

	textColor(199);
	GotoXY(width + 7, height / 2 - 1);
	cout << "      KEYS USED IN GAME      ";
	GotoXY(width + 7, 1);
	cout << "         INFORMATION         ";
	GotoXY(width + 19, height / 2 + 1);
	cout << " UP ";
	textColor(224);
	GotoXY(width + 20, height / 2 + 3);
	cout << "[W]";
	textColor(199);
	GotoXY(width + 8, height / 2 + 5);
	cout << "LEFT";
	textColor(224);
	GotoXY(width + 14, height / 2 + 5);
	cout << "[A]";
	GotoXY(width + 20, height / 2 + 5);
	cout << "[+]";
	GotoXY(width + 25, height / 2 + 5);
	cout << "[D]";
	textColor(199);
	GotoXY(width + 30, height / 2 + 5);
	cout << "RIGHT";

	textColor(224);
	GotoXY(width + 20, height / 2 + 7);
	cout << "[S]";
	textColor(199);
	GotoXY(width + 19, height / 2 + 9);
	cout << " DOWN ";

	textColor(224);
	GotoXY(width + 8, height / 2 + 11);
	cout << "[L]";
	GotoXY(width + 8, height / 2 + 13);
	cout << "[P]";

	textColor(199);
	GotoXY(width + 12, height / 2 + 11);
	cout << "SAVE GAME";
	GotoXY(width + 12, height / 2 + 13);
	cout << "PAUSE GAME";
	textColor(228);
}
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void Sort() {
	for (int i = 0; i < player.size() - 1; i++) {
		for (int j = i + 1; j < player.size(); j++)
		{
			if (player[i].MAX_SCORE < player[j].MAX_SCORE) {
				swap(player[i].MAX_SCORE, player[j].MAX_SCORE);
				swap(player[i].CHAR_LOCK, player[j].CHAR_LOCK);
				swap(player[i].FODD_INDEX, player[j].FODD_INDEX);
				swap(player[i].MOVING, player[j].MOVING);
				swap(player[i].name, player[j].name);
				swap(player[i].SCORE, player[j].SCORE);
				swap(player[i].SIZE_SNAKE, player[j].SIZE_SNAKE);
				swap(player[i].snake, player[j].snake);
				swap(player[i].SPEED, player[j].SPEED);
			}
		}
	}
}
void RankBoard()
{
	GotoXY(15, 0);
	for (int i = 20; i < 110; i++) {
		cout << "▀";
	}

	textColor(228);
	int i = 2;
	GotoXY(45, i);
	cout << "██████   █████  ███    ██ ██   ██ "; i++;
	GotoXY(45, i);
	cout << "██   ██ ██   ██ ████   ██ ██  ██  "; i++;
	GotoXY(45, i);
	cout << "██████  ███████ ██ ██  ██ █████  "; i++;
	GotoXY(45, i);
	cout << "██   ██ ██   ██ ██  ██ ██ ██  ██ "; i++;
	GotoXY(45, i);
	cout << "██   ██ ██   ██ ██   ████ ██   ██ ";

	textColor(232);
	GotoXY(15, 8);
	for (int i = 20; i < 110; i++) {
		cout << "▄";
	}

	//Output Player

	textColor(192);
	GotoXY(8, 10);
	cout << "     Rank    ";
	GotoXY(22, 10);
	cout << "     Player name     ";
	Sleep(5);
	GotoXY(44, 10);
	cout << "     Score           ";
	Sleep(5);
	GotoXY(66, 10);
	cout << "     Speed           ";
	Sleep(5);
	GotoXY(88, 10);
	cout << "     Size snake      ";

	Sleep(5);
	textColor(236);
	GotoXY(7, 10);
	cout << "│";
	Sleep(5);
	GotoXY(21, 10);
	cout << "│";
	Sleep(5);
	GotoXY(43, 10);
	cout << "│";
	Sleep(5);
	GotoXY(65, 10);
	cout << "│";
	Sleep(5);
	GotoXY(87, 10);
	cout << "│";
	Sleep(5);
	GotoXY(109, 10);
	cout << "│";

	if (player.size() == 0) {
		textColor(232);
		GotoXY(92, player.size() * 2 + 10 + i);
		cout << "Press <ESC> to return menu";
		textColor(228);
	}
	else {
		for (int i = 0; i < player.size(); i++) {
			textColor(228);
			GotoXY(9, 11 + i);
			cout << i + 1;
			GotoXY(23, 11 + i);
			cout << player[i].name;
			Sleep(5);
			GotoXY(45, 11 + i);
			cout << player[i].MAX_SCORE;
			GotoXY(67, 11 + i);
			cout << player[i].SPEED;
			GotoXY(89, 11 + i);
			cout << player[i].SIZE_SNAKE;

			//1
			textColor(236);
			GotoXY(7, 11 + i);
			cout << "│";
			textColor(236);
			GotoXY(21, 11 + i);
			cout << "│";
			//2
			textColor(236);
			GotoXY(43, 11 + i);
			cout << "│";
			//3
			Sleep(5);
			textColor(236);
			GotoXY(65, 11 + i);
			cout << "│";
			//4
			textColor(236);
			GotoXY(87, 11 + i);
			cout << "│";
			//5
			textColor(236);
			GotoXY(109, 11 + i);
			cout << "│";

		}
		textColor(232);
		GotoXY(92, player.size() * 2 + 10 + i);
		cout << "Press <ESC> to return menu";
		textColor(228);
	}
}
void Introduce() {
	textColor(228);
	int i = 3;
	GotoXY(25, i);
	cout << "██ ███    ██ ████████ ██████   ██████  ██████  ██    ██  ██████ ███████"; i++;
	GotoXY(25, i);
	cout << "██ ████   ██    ██    ██   ██ ██    ██ ██   ██ ██    ██ ██      ██     "; i++;
	GotoXY(25, i);
	cout << "██ ██ ██  ██    ██    ██████  ██    ██ ██   ██ ██    ██ ██      █████ "; i++;
	GotoXY(25, i);
	cout << "██ ██  ██ ██    ██    ██   ██ ██    ██ ██   ██ ██    ██ ██      ██    "; i++;
	GotoXY(25, i);
	cout << "██ ██   ████    ██    ██   ██  ██████  ██████   ██████   ██████ ███████ ";

	for (int i = 0; i < 19; i++) {
		GotoXY(58, i + 11);
		cout << "│";
	}

	textColor(180);
	GotoXY(15, 12);
	cout << "TEAM 1's COURSE PROJECT";
	//
	textColor(199);
	GotoXY(15, 14);
	cout << "Establish";
	textColor(232);
	GotoXY(25, 14);
	cout << "27/03/2021";
	//
	textColor(199);
	GotoXY(15, 16);
	cout << "Members";
	textColor(232);
	GotoXY(25, 16);
	cout << "3";
	//
	textColor(199);
	GotoXY(15, 18);
	cout << "Name";
	GotoXY(40, 18);
	cout << "Student's ID";
	//
	textColor(232);
	GotoXY(15, 20);
	cout << "Duong Quang Binh";
	GotoXY(15, 22);
	cout << "Vuong Huynh Tan Tai";
	GotoXY(15, 24);
	cout << "Ha Dang Nhuan";
	//
	GotoXY(40, 20);
	cout << "20127450";
	GotoXY(40, 22);
	cout << "20127618";
	GotoXY(40, 24);
	cout << "20127268";

	//Course
	textColor(180);
	GotoXY(70, 12);
	cout << "VNUHCM - UNIVERSITY OF SCIENCE - HCMUS";
	textColor(199);
	GotoXY(70, 14);
	cout << "Majors";
	textColor(232);
	GotoXY(80, 14);
	cout << "Information Technology";
	//
	textColor(199);
	GotoXY(70, 16);
	cout << "Lecturer";
	textColor(232);
	GotoXY(80, 16);
	cout << "Truong Toan Thinh";
	//
	textColor(199);
	GotoXY(70, 18);
	cout << "Class";
	textColor(232);
	GotoXY(80, 18);
	cout << "20CLC07";
	//
	textColor(180);
	GotoXY(70, 20);
	cout << "PROJECT \"HUNTER SNAKE\"";
	textColor(199);
	GotoXY(70, 22);
	cout << "Name game";
	textColor(232);
	GotoXY(89, 22);
	cout << "\"HUNTER SNAKE\"";
	//
	textColor(199);
	GotoXY(70, 24);
	cout << "Project started on";
	textColor(232);
	GotoXY(89, 24);
	cout << "20/03/2021";
	//
	textColor(199);
	GotoXY(70, 26);
	cout << "Complete time";
	textColor(232);
	GotoXY(89, 26);
	cout << "6 weeks";

	GotoXY(92, 29);
	cout << "Press <Esc> to return menu";
	textColor(228);
}
void LoadGame() {
	GotoXY(15, 0);
	for (int i = 20; i < 110; i++) {
		cout << "▀";
	}
	textColor(228);
	int i = 2;
	GotoXY(20, i);
	cout << "██      ██ ███████ ████████     ██████  ██       █████  ██    ██ ███████ ██████ "; i++;
	GotoXY(20, i);
	cout << "██      ██ ██         ██        ██   ██ ██      ██   ██  ██  ██  ██      ██   ██ "; i++;
	GotoXY(20, i);
	cout << "██      ██ ███████    ██        ██████  ██      ███████   ████   █████   ██████  "; i++;
	GotoXY(20, i);
	cout << "██      ██      ██    ██        ██      ██      ██   ██    ██    ██      ██   ██ "; i++;
	GotoXY(20, i);
	cout << "███████ ██ ███████    ██        ██      ███████ ██   ██    ██    ███████ ██   ██ ";

	textColor(232);
	GotoXY(15, 9);
	for (int i = 20; i < 110; i++) {
		cout << "▀";
	}

	//Board Choose Name
	for (int i = 17; i <= 46; i++) {
		GotoXY(i, 12);  cout << "▄";
		GotoXY(i, 18); cout << "▀";
	}

	for (int i = 13; i < 18; i++)
	{
		GotoXY(17, i); cout << "█";
		Sleep(10);
		GotoXY(46, i); cout << "█";
		Sleep(10);
	}
	textColor(228);
	for (int i = 18; i <= 45; i++) {
		GotoXY(i, 13);  cout << "█";
		GotoXY(i, 17); cout << "█";
	}

	for (int i = 14; i < 17; i++)
	{
		GotoXY(18, i); cout << "█";
		Sleep(10);
		GotoXY(45, i); cout << "█";
		Sleep(10);
	}

	//ListName
	textColor(228);
	for (int i = 51; i <= 101; i++) {
		GotoXY(i, 11);  cout << "▄";
		GotoXY(i, 20 + player.size() * 2 + 1); cout << "▀";
	}

	for (int i = 12; i < 20 + player.size() * 2 + 1; i++)
	{
		GotoXY(51, i); cout << "█";
		GotoXY(101, i); cout << "█";
	}

	//
	textColor(234);
	for (int i = 52; i <= 100; i++) {
		GotoXY(i, 12);  cout << "█";
		GotoXY(i, 19 + player.size() * 2 + 1); cout << "█";
	}

	for (int i = 13; i < 19 + player.size() * 2 + 1; i++)
	{
		GotoXY(52, i); cout << "█";
		GotoXY(100, i); cout << "█";
	}

	//
	textColor(232);
	for (int i = 53; i <= 99; i++) {
		GotoXY(i, 13);  cout << "█";
		GotoXY(i, 18 + player.size() * 2 + 1); cout << "█";
	}

	for (int i = 14; i < 18 + player.size() * 2 + 1; i++)
	{
		GotoXY(53, i); cout << "█";
		GotoXY(99, i); cout << "█";
	}

	textColor(187);
	for (int i = 54; i <= 98; i++)
	{
		for (int j = 14; j <= 17 + player.size() * 2 + 1; j++) {
			GotoXY(i, j);
			cout << " ";
		}
	}

	textColor(176);
	i = 15;
	for (int j = 0; j < player.size(); j++) {
		GotoXY(56, i);
		cout << j + 1 << ". " << player[j].name;
		i = i + 2;
	}
}
void ExitGame(HANDLE t)
{
	TerminateThread(t, 0);
	return;
}
void PauseGame(HANDLE t)
{
	SuspendThread(t);
}
void Eat()
{
	snake[SIZE_SNAKE] = food[FOOD_INDEX];
	if (FOOD_INDEX == MAX_SIZE_FOOD - 1)
	{
		DrawGate_In();
		SCORE += 5;
		FOOD_INDEX = MAX_SIZE_FOOD;
		food[FOOD_INDEX] = GATE_INTO;
		SIZE_SNAKE = MAX_SIZE_SNAKE;
	}
	else if (FOOD_INDEX == MAX_SIZE_FOOD)
	{
		if (SPEED == MAX_SPEED)
		{
			SPEED = 1;
			SIZE_SNAKE = 6;
		}
		else SPEED++;
		EraseMap();
		Draw_Map();
		DrawGate_Out();
		FOOD_INDEX = 0;
		snake[SIZE_SNAKE - 1] = { GATE_INTO.x - 64, GATE_INTO.y };
		GenerateFood();
	}
	else
	{
		SCORE += 5;
		FOOD_INDEX++;
		if (SIZE_SNAKE != MAX_SIZE_SNAKE)  SIZE_SNAKE++;
	}
}
void EraseSnakeAndFood()
{
	if (snake[0].x == GATE_INTO.x - 64 && snake[0].y == GATE_INTO.y)
	{
		EraseGate();
	}
	if (FOOD_INDEX != MAX_SIZE_FOOD)
	{
		GotoXY(food[FOOD_INDEX].x, food[FOOD_INDEX].y);
		cout << " ";
	}
	for (int i = 0; i < SIZE_SNAKE; i++)
	{
		GotoXY(snake[i].x, snake[i].y);
		cout << " ";
	}
}
void DrawSnakeAndFood()
{
	if (FOOD_INDEX != MAX_SIZE_FOOD)
	{
		GotoXY(food[FOOD_INDEX].x, food[FOOD_INDEX].y);
		cout << "■";
	}
	//xet truong hop loading khi dang qua cong
	else
	{
		DrawGate_In();
	}
	for (int i = 0; i < SIZE_SNAKE; i++)
	{
		GotoXY(snake[i].x, snake[i].y);
		cout << MSSV[i];
	}
}
void ProcessDead()
{
	STATE = 0;

	//hieeuj ung 
	DrawSnakeAndFood();
	GotoXY(snake[SIZE_SNAKE - 1].x, snake[SIZE_SNAKE - 1].y);
	textColor(187);
	//	cout << MSSV[SIZE_SNAKE - 1];
	cout << "█";
	Sleep(500);
	GotoXY(snake[SIZE_SNAKE - 1].x, snake[SIZE_SNAKE - 1].y);
	textColor(224);
	//	cout << MSSV[SIZE_SNAKE - 1];
	cout << " ";
	Sleep(500);
	GotoXY(snake[SIZE_SNAKE - 1].x, snake[SIZE_SNAKE - 1].y);
	textColor(187);
	//	cout << MSSV[SIZE_SNAKE - 1];
	cout << "█";
	Sleep(500);
	GotoXY(snake[SIZE_SNAKE - 1].x, snake[SIZE_SNAKE - 1].y);
	textColor(224);
	//	cout << MSSV[SIZE_SNAKE - 1];
	cout << " ";
	Sleep(500);
	/// 

	textColor(187);
	for (int i = 74 + 7; i <= 109; i++) {
		for (int j = 29 / 2 - 2 + 1; j < 29; j++) {
			GotoXY(i, j);
			cout << " ";
		}
	}
	textColor(199);
	GotoXY(74 + 7, 29 / 2 + 3);
	cout << "                             ";
	GotoXY(74 + 7, 29 / 2 + 4);
	cout << "                             ";
	GotoXY(74 + 7, 29 / 2 + 5);
	textColor(224);
	cout << "       G_A_M_E O_V_E_R       ";
	textColor(199);
	GotoXY(74 + 7, 29 / 2 + 6);
	cout << "                             ";
	GotoXY(74 + 7, 29 / 2 + 7);
	cout << "   Press   ";
	GotoXY(94, 29 / 2 + 7);
	cout << "  to continue   ";
	textColor(224);
	GotoXY(91, 29 / 2 + 7);
	cout << "[Y]";


	textColor(199);
	GotoXY(74 + 7, 29 / 2 + 8);
	cout << "                             ";
	GotoXY(74 + 7, 29 / 2 + 9);
	cout << "   Press  ";
	GotoXY(94, 29 / 2 + 9);
	cout << "  to exit       ";
	textColor(224);
	GotoXY(90, 29 / 2 + 9);
	cout << "<ESC>";
	textColor(199);
	GotoXY(74 + 7, 29 / 2 + 10);
	cout << "                             ";
	GotoXY(74 + 7, 29 / 2 + 11);
	cout << "                             ";
	textColor(228);
}
bool Head_Touched_Body()
{
	for (int i = 0; i < SIZE_SNAKE - 1; i++)
	{
		if ((snake[SIZE_SNAKE - 1].x == snake[i].x) && (snake[SIZE_SNAKE - 1].y == snake[i].y))
		{
			return true;
		}
	}
	return false;
}
bool Head_Touched_Gate(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		if (x == GATE[i].x && y == GATE[i].y)
			return true;
	}
	return false;
}
bool Head_Map(int x, int y)
{
	for (int i = 0; i < MAP.size(); i++)
	{
		if (MAP[i].x == x && MAP[i].y == y)
			return true;
	}
	return false;
}
void MoveRight()
{
	if (snake[SIZE_SNAKE - 1].x + 1 == WIDTH_CONSOLE + 1 ||
		(FOOD_INDEX == MAX_SIZE_FOOD && Head_Touched_Gate(snake[SIZE_SNAKE - 1].x + 1, snake[SIZE_SNAKE - 1].y)) ||
		Head_Map(snake[SIZE_SNAKE - 1].x + 1, snake[SIZE_SNAKE - 1].y))
	{
		ProcessDead();
	}
	else
	{
		if (snake[SIZE_SNAKE - 1].x + 1 == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y == food[FOOD_INDEX].y)
		{
			Eat();
		}
		for (int i = 0; i < SIZE_SNAKE - 1; i++) {
			snake[i].x = snake[i + 1].x;
			snake[i].y = snake[i + 1].y;
		}
		snake[SIZE_SNAKE - 1].x++;
	}
}
void MoveLeft()
{
	if ((snake[SIZE_SNAKE - 1].x - 1 == 1) ||
		(FOOD_INDEX == MAX_SIZE_FOOD && Head_Touched_Gate(snake[SIZE_SNAKE - 1].x - 1, snake[SIZE_SNAKE - 1].y)) ||
		(snake[SIZE_SNAKE - 1].x - 1 == GATE_INTO.x && snake[SIZE_SNAKE - 1].y == GATE_INTO.y) ||
		Head_Map(snake[SIZE_SNAKE - 1].x - 1, snake[SIZE_SNAKE - 1].y))
	{
		ProcessDead();
	}
	else
	{
		if (snake[SIZE_SNAKE - 1].x - 1 == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y == food[FOOD_INDEX].y)
			Eat();
		for (int i = 0; i < SIZE_SNAKE - 1; i++)
		{
			snake[i].x = snake[i + 1].x;
			snake[i].y = snake[i + 1].y;
		}
		snake[SIZE_SNAKE - 1].x--;
	}
}
void MoveDown() {
	if (snake[SIZE_SNAKE - 1].y + 1 == HEIGH_CONSOLE ||
		(FOOD_INDEX == MAX_SIZE_FOOD && Head_Touched_Gate(snake[SIZE_SNAKE - 1].x, snake[SIZE_SNAKE - 1].y + 1)) ||
		Head_Map(snake[SIZE_SNAKE - 1].x, snake[SIZE_SNAKE - 1].y + 1))
	{
		ProcessDead();
	}
	else
	{
		if (snake[SIZE_SNAKE - 1].x == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y + 1 == food[FOOD_INDEX].y) {
			Eat();
		}
		for (int i = 0; i < SIZE_SNAKE - 1; i++) {
			snake[i].x = snake[i + 1].x;
			snake[i].y = snake[i + 1].y;
		}
		snake[SIZE_SNAKE - 1].y++;
	}
}
void MoveUp() {
	if (snake[SIZE_SNAKE - 1].y - 1 == 0 ||
		(FOOD_INDEX == MAX_SIZE_FOOD && Head_Touched_Gate(snake[SIZE_SNAKE - 1].x, snake[SIZE_SNAKE - 1].y - 1)) ||
		Head_Map(snake[SIZE_SNAKE - 1].x, snake[SIZE_SNAKE - 1].y - 1))
	{
		ProcessDead();
	}
	else
	{
		if (snake[SIZE_SNAKE - 1].x == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y - 1 == food[FOOD_INDEX].y) {
			Eat();
		}
		for (int i = 0; i < SIZE_SNAKE - 1; i++) {
			snake[i].x = snake[i + 1].x;
			snake[i].y = snake[i + 1].y;
		}
		snake[SIZE_SNAKE - 1].y--;
	}
}
void Map3()
{
	while (1)
	{
		if (STATE == 1 && SPEED == 3)
		{
			PauseGame(handle_t1);
			if (MAP[2].y == HEIGH_CONSOLE - 1) MOVING_MAP3[0] = 'W';
			if (MAP[0].y == 1)                 MOVING_MAP3[0] = 'S';
			if (MAP[38].y == HEIGH_CONSOLE - 1) MOVING_MAP3[1] = 'W';
			if (MAP[36].y == 1)                 MOVING_MAP3[1] = 'S';
			if (MAP[74].y == HEIGH_CONSOLE - 1) MOVING_MAP3[2] = 'W';
			if (MAP[72].y == 1)                 MOVING_MAP3[2] = 'S';
			if (MAP[110].y == HEIGH_CONSOLE - 1) MOVING_MAP3[3] = 'W';
			if (MAP[108].y == 1)                 MOVING_MAP3[3] = 'S';


			for (int i = 0; i < 36; i++)
			{
				//xoa hinh cu
				GotoXY(MAP[i].x, MAP[i].y); cout << " ";
				//thay đổi giá trị 
				if (MOVING_MAP3[0] == 'S')
					MAP[i].y++; else MAP[i].y--;
			}
			//draw
			GotoXY(8, MAP[0].y);
			cout << "▐"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▌";
			GotoXY(8, MAP[1].y);
			cout << "▐ DEADLINE ▌";
			GotoXY(8, MAP[2].y);
			cout << "▐"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▌";



			for (int i = 36; i < 72; i++)
			{
				//xoa hinh cu
				GotoXY(MAP[i].x, MAP[i].y); cout << " ";
				//thay đổi giá trị 
				if (MOVING_MAP3[1] == 'S')
					MAP[i].y++; else MAP[i].y--;
			}
			GotoXY(22, MAP[36].y);
			cout << "▐"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▌";
			GotoXY(22, MAP[37].y);
			cout << "▐   MONEY  ▌";
			GotoXY(22, MAP[38].y);
			cout << "▐"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▌";


			for (int i = 72; i < 108; i++)
			{
				//xoa hinh cu
				GotoXY(MAP[i].x, MAP[i].y); cout << " ";
				//thay đổi giá trị 
				if (MOVING_MAP3[2] == 'S')
					MAP[i].y++; else MAP[i].y--;
			}
			GotoXY(36, MAP[72].y);
			cout << "▐"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▌";
			GotoXY(36, MAP[73].y);
			cout << "▐   VICES  ▌";
			GotoXY(36, MAP[74].y);
			cout << "▐"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▌";


			for (int i = 108; i < 144; i++)
			{
				//xoa hinh cu
				GotoXY(MAP[i].x, MAP[i].y); cout << " ";
				//thay đổi giá trị 
				if (MOVING_MAP3[3] == 'S')
					MAP[i].y++; else MAP[i].y--;
			}
			GotoXY(50, MAP[108].y);
			cout << "▐"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▀"; cout << "▌";
			GotoXY(50, MAP[109].y);
			cout << "▐ THE_LOVE ▌";
			GotoXY(50, MAP[110].y);
			cout << "▐"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▄"; cout << "▌";
			ResumeThread(handle_t1);
			Sleep(1000);
		}
	}
}
void ThreadFunc()
{
	while (1)
	{
		if (STATE == 1)
		{
			PauseGame(handle_t0);
			EraseSnakeAndFood();
			switch (MOVING) {
			case 'A':
				MoveLeft();
				break;
			case 'D':
				MoveRight();
				break;
			case 'W':
				MoveUp();
				break;
			case 'S':
				MoveDown();
				break;
			}
			if (Head_Touched_Body())
			{
				ProcessDead();
				GotoXY(0, HEIGH_CONSOLE + 3);
			}
			DrawSnakeAndFood();
			GotoXY(83, 5);
			textColor(199);
			cout << "SCORE";
			GotoXY(94, 5);
			textColor(224);
			cout << SCORE;
			textColor(228);
			if (INDEX_DATA != -1)
			{
				GotoXY(83, 3);
				textColor(199);
				cout << "NAME";
				GotoXY(90, 3);
				textColor(224);
				cout << player[INDEX_DATA].name;
				textColor(228);
				if (SCORE > player[INDEX_DATA].MAX_SCORE) player[INDEX_DATA].MAX_SCORE = SCORE;
				GotoXY(83, 7);
				textColor(199);
				cout << "MAX SCORE";
				GotoXY(94, 7);
				textColor(224);
				cout << player[INDEX_DATA].MAX_SCORE;
				textColor(228);
			}
			ResumeThread(handle_t0);
			if (SPEED == 1) Sleep(300);
			else if (SPEED == 2) Sleep(200);
			else if (SPEED == 3) Sleep(100);
		}
	}
}