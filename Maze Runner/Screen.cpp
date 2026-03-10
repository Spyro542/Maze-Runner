#define _CRT_SECURE_NO_WARNINGS 1
#include "Screen.h"
#include <iostream>
#include <Windows.h>

char Current_Screen[129][33];
int Current_Screen_Colour[129][33][2];
int Screen_Size_X = 128;
int Screen_Size_Y = 32;
//char New_Screen[129][33];			sent into flip from caller
//int New_Screen_Colour[129][33];	sent into flip from caller

//Look at singleton pattern & binary partition search

void Intialize()	//setup of screen
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
	PCONSOLE_FONT_INFOEX fontData;
	fontData->cbSize = sizeof(fontData);


	SetCurrentConsoleFontEx(hwnd, false, fontData);

	system("cls");
}

void SetColour(int textColor, int bgColor)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,
		(bgColor << 4) | textColor);
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

void flip(char New_Screen[129][33], int New_Screen_Colour[129][33][2])
{
	std::string Print_Line_Content;

	for (size_t Y = 0; Y < Screen_Size_Y; Y++)
	{
		bool Print_Line = false;
		int Print_Colour[2];

		for (size_t X = 0; X < Screen_Size_X; X++)	//check every pixel for changes
		{
			//update current screen colour
			if ((New_Screen_Colour[X][Y][Text] != Current_Screen_Colour[X][Y][Text]) || (New_Screen_Colour[X][Y][Background] != Current_Screen_Colour[X][Y][Background]))
			{
				//update current screen
				Current_Screen_Colour[X][Y][Text] = New_Screen_Colour[X][Y][Text];
				Current_Screen_Colour[X][Y][Background] = New_Screen_Colour[X][Y][Background];
				Print_Line = true;
			}
			//update current screen colour
			//else check if screen has changed
			else if (Current_Screen[X][Y] != New_Screen[X][Y])
			{
				Print_Line = true;
			}
			//check if screen has changed

			//check if the colour we're printing is diffrent from the colour we're checking
			if ((New_Screen_Colour[X][Y][Text] != New_Screen_Colour[X-1][Y][Text] || (New_Screen_Colour[X][Y][Background] != New_Screen_Colour[X][Y][Background]-1)) && Print_Line)
			{
				if (X == 0)
				{
					SetColour(New_Screen_Colour[X][Y][Text], New_Screen_Colour[X][Y][Background]);
				}
				else
				{
					SetColour(New_Screen_Colour[X - 1][Y][Text], New_Screen_Colour[X - 1][Y][Background]);
				}
				

				std::cout << Print_Line_Content;	//print the line so far
				Goto_XY(X, Y);	//go to where we are in the counting and place cursor for the next segment
				Print_Line_Content = "";	//reset segment to print
				Print_Line = false;
				Print_Colour[Text] = New_Screen_Colour[X][Y][Text];
				Print_Colour[Background] = New_Screen_Colour[X][Y][Background];
			}
			//check if the colour we're printing is diffrent from the colour we're checking

			Print_Line_Content += New_Screen[X][Y];	//update what to print
			Current_Screen[X][Y] = New_Screen[X][Y];	//update current screen text

			//if on last x coordinate print snippet
			if ((X == Screen_Size_X - 1) && Print_Line)
			{
				SetColour(New_Screen_Colour[X][Y][Text], New_Screen_Colour[X][Y][Background]);
				std::cout << Print_Line_Content;	//print the line so far
				Goto_XY(X, Y + 1);	//go to where we are in the counting and place cursor for the next segment
				Print_Line_Content = "";	//reset segment to print
				Print_Line = false;
			}
			//if on last x coordinate print snippet
		}
	}
	
}

void flip_map(char New_Screen[129][33])
{
	bool Print_Line = false;
	std::string Print_Line_Content;

	//Compare the old screen to the new one and if any changes on a line reprint that line in place
	for (size_t Y = 0; Y < Screen_Size_Y; Y++)
	{
		for (size_t X = 0; X < Screen_Size_X; X++)
		{
			Print_Line_Content += New_Screen[X][Y];
			if (Current_Screen[X][Y] != New_Screen[X][Y])
			{
				Print_Line = true;

				Current_Screen[X][Y] = New_Screen[X][Y];
			}
		}
		if (Print_Line)
		{
			Goto_XY(0, Y);
			std::cout << Print_Line_Content;
			Print_Line_Content = "";
			Print_Line = false;
		}
	}
	
	/*for (size_t X = 0; X < Screen_Size_X; X++)
	{
		for (size_t Y = 0; Y < Screen_Size_Y; Y++)
		{
			if (Current_Screen[X][Y] != New_Screen[X][Y])
			{
				Goto_XY(X, Y);
				std::cout << New_Screen[X][Y];
				Current_Screen[X][Y] = New_Screen[X][Y];
			}
		}
	}*/
}

void Goto_XY(int X, int Y)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { X, Y };

	SetConsoleCursorPosition(hStdout, position);
}