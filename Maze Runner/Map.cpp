#include "Map.h"
#include <Windows.h>
#include <vector>
#include <iostream>

Map::Map(std::vector<std::vector<bool>> Level)
{
	Walls = Level;
}

Map::~Map()
{
}

void Map::Draw_Maze()
{
	for (size_t Y = 0; Y < Walls[1].size(); Y++)
	{
		for (size_t X = 0; X < Walls.size(); X++)
		{
			if (Walls[X][Y])
			{
				Goto_XY(Y, X);
				SetColour(Bright_White, Bright_White);
				std::cout << "#";
				SetColour(Black, Black);
			}
		}
	}
}

bool Map::Get_Walls(int X, int Y)
{
	if (Walls[Y][X])
	{
		return true;
	}
	else
	{
		return false;
	}
}



void Map::Goto_XY(int X, int Y)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { X, Y };

	SetConsoleCursorPosition(hStdout, position);
}

void Map::SetColour(int textColor, int bgColor)
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
