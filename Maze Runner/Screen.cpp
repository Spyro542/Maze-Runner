#include "Screen.h"
#include <iostream>
#include <Windows.h>

char Current_Screen[129][33];
//char New_Screen[129][33];			sent into flip from caller

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

void flip(char New_Screen[129][33])
{
	bool Print_Line = false;
	std::string Print_Line_Content;

	//Compare the old screen to the new one and if any changes on a line reprint that line in place
	for (size_t Y = 0; Y < 32; Y++)
	{
		for (size_t X = 0; X < 128; X++)
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
	/*
	for (size_t X = 0; X < 128; X++)
		{
			for (size_t Y = 0; Y < 32; Y++)
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