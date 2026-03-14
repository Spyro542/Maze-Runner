#include "Terminal.h"
#include <Windows.h>
#include <iostream>

void Terminal::Intialize()
{
	//Dealing with Window size and posistion
	RECT rcClip;
	HWND hwnd = GetForegroundWindow();

	if (hwnd != NULL) MoveWindow(hwnd, -15, -50, 0, 0, TRUE); //moving window to top left
	if (hwnd != NULL) { SetWindowPos(hwnd, 0, 0, 0, 1500, 900, SWP_SHOWWINDOW | SWP_NOMOVE); } //setting window size

	if (hwnd != NULL) GetWindowRect(hwnd, &rcClip); //get window borders
	if (hwnd != NULL) ClipCursor(&rcClip); //keep cursor inside the window
	//Dealing with Window size and posistion

	//Hide the console cursor
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
	//Hide the console cursor

	/*PCONSOLE_FONT_INFOEX fontData;
	fontData->cbSize = sizeof(fontData);


	SetCurrentConsoleFontEx(hwnd, false, fontData);*/


	system("cls");
}

void Terminal::SetColour(int Text_Colour, int Background_Colour)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,
		(Background_Colour << 4) | Text_Colour);
	/*
	0 Black			11 Even Lighter Blue (Pale Blue)
	1 Blue			12 Pale/Light Red
	2 Green			13 Bright Purple
	3 Light Blue	14 Light Yellow/ Beige
	4 Red			15 Bright White
	5 Purple
	6 Yellow
	7 White
	8 Gray			27+ Full line background color
	9 Bright Blue
	10 bright Green
	*/
}

void Terminal::Goto_XY(int X, int Y)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { X, Y };

	SetConsoleCursorPosition(hStdout, position);
}


