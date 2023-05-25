#include "Function.h"
#include <string>
#include<fstream>
using namespace std;
void main()
{
	int temp;
	system("color e4");
	FixConsoleWindow();
	Nocursortype();
	// lấy dữ liệu người chơi 
	Get_Data();
	//Bắt đầu chạy chương trình 
	Loading();
	int Choose = Menu();
	thread t0(Map3); //Tao thread cho map3
	handle_t0 = t0.native_handle(); //Lay handle cua thread
	thread t1(ThreadFunc); //Tao thread cho snake
	handle_t1 = t1.native_handle(); //Lay handle cua thread
	while (1)
	{
		switch (Choose)
		{
		case 1:
		{
			StartGame();
			while (1)
			{
				temp = toupper(_getch());
				if (STATE == 1)
				{
					if (temp == 'P')
					{
						PauseGame(handle_t1);
					}
					else if (temp == 27)
					{
						if (INDEX_DATA != -1)
						{
							Change_Data();
							INDEX_DATA = -1;
						}
						STATE = 0;
						Choose = Menu();
						break;
					}
					else if (temp == 'L')
					{
						if (INDEX_DATA == -1)
						{
							STATE = 0;
							system("cls");
							add_Player();
							StartGame();
						}
					}
					else
					{
						ResumeThread(handle_t1);
						if ((temp != CHAR_LOCK) && (temp == 'D' || temp == 'A' || temp == 'W' || temp == 'S'))
						{
							if (temp == 'D') CHAR_LOCK = 'A';
							else if (temp == 'W') CHAR_LOCK = 'S';
							else if (temp == 'S') CHAR_LOCK = 'W';
							else CHAR_LOCK = 'D';
							MOVING = temp;
						}
					}
				}
				else
				{
					if (INDEX_DATA != -1)
					{
						Change_Data();
					}
					if (temp == 'Y')
					{
						StartGame();
					}
					else if (temp == 27)
					{
						system("cls");
						INDEX_DATA = -1;
						Choose = Menu();
						break;
					}
				}
			}
			break;
		}
		case 2:
		{
			system("cls");
			//Lay vi tri nguoi dung
			if (player.size() == 0) {
				textColor(232);
				int i = 2;
				GotoXY(25, i);
				cout << "███    ██  ██████      ██████  ██       █████  ██    ██ ███████ ██████"; i++;
				GotoXY(25, i);
				cout << "████   ██ ██    ██     ██   ██ ██      ██   ██  ██  ██  ██      ██   ██ "; i++;
				GotoXY(25, i);
				cout << "██ ██  ██ ██    ██     ██████  ██      ███████   ████   █████   ██████  "; i++;
				GotoXY(25, i);
				cout << "██  ██ ██ ██    ██     ██      ██      ██   ██    ██    ██      ██   ██ "; i++;
				GotoXY(25, i);
				cout << "██   ████  ██████      ██      ███████ ██   ██    ██    ███████ ██   ██ "; i++;



				GotoXY(92, 28);
				cout << "Press <ESC> to return menu";
				textColor(228);
				temp = toupper(_getch());
				if (temp == 27) {
					Choose = Menu();
				}
			}
			else {
				Get_Index_Data();
				if (INDEX_DATA == -1) Choose = Menu();
				else Choose = 1;
				break;
				return;
			}
			break;

		}
		case 3:
		{
			system("cls");
			if (player.size() == 0) {
				RankBoard();
				temp = toupper(_getch());
				if (temp == 27) {
					Choose = Menu();
				}
			}
			else {
				Sort();
				RankBoard();
				temp = toupper(_getch());
				if (temp == 27) {
					Choose = Menu();
				}
			}
			break;

		}
		case 4:
		{
			system("cls");
			Introduce();
			temp = toupper(_getch());
			if (temp == 27) {
				Choose = Menu();
			}
			break;

		}
		case 5:
		{
			Save_File_Data();
			return;
		}
		}
	}
}











