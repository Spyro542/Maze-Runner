#include "Map.h"
#include <Windows.h>
#include <vector>
#include <iostream>
#include "Cat.h"

Map::Map(std::vector<std::vector<int>> Level)
{
	Walls = Level;
}

Map::~Map()
{
	while (Cats.size() > 0)
	{
		Destroy_Cat(0);
	}
}

void Map::Draw_Maze()
{
	Maze_Algorithm Maze_variables;


	//go through and print the current state of the maze
	for (size_t Y = 0; Y < Walls[1].size(); Y++)
	{
		for (size_t X = 0; X < Walls.size(); X++)
		{	//░▒▓█♥❤☼
			//https://www.lucasfonts.com/fonts/package_details/consolas
			Screen.Goto_XY(Y, X);
			switch (Walls[X][Y])
			{
			case Maze_variables.air:
			case Maze_variables.Loot_Room:	//fallthrough deliberate to reuse code instead of unnecesarry duplication
				Screen.SetColour(Screen.Black, Screen.Black);
				std::cout << " ";
				break;
			case Maze_variables.wall:
				Screen.SetColour(Screen.White, Screen.Bright_White);
				std::cout << "▓";
				break;
			case Maze_variables.cracked:
				Screen.SetColour(Screen.White, Screen.Gray);
				std::cout << "░";
				break;
			case Maze_variables.Coin:
				Screen.SetColour(Screen.Yellow, Screen.Black);
				std::cout << "©";
				break;
			case Maze_variables.Spawn_Room:
				Screen.SetColour(Screen.White, Screen.Black);
				std::cout << "⌂";
				break;
			case Maze_variables.Exit_Room:
				Screen.SetColour(Screen.Green, Screen.Black);
				std::cout << "⌂";
				break;
			case Maze_variables.Heart:
				Screen.SetColour(Screen.Red, Screen.Black);
				std::cout << "♥";
				break;
			case Maze_variables.Cat:
				Screen.SetColour(Screen.Green, Screen.Black);
				std::cout << " ";
				enable_cats(X, Y);
				break;
			default:
				break;
			}
		}
	}
	Screen.SetColour(Screen.Green, Screen.Black);
}

int Map::Get_Walls(int X, int Y)
{
	return Walls[Y][X];
}

std::string Map::Get_Walls_String(int X, int Y)
{
	Maze_Algorithm Maze_variables;
	switch (Walls[Y][X])
	{
	case Maze_variables.air:
		Screen.SetColour(Screen.Black, Screen.Black);
		return " ";
		break;
	case Maze_variables.wall:
		Screen.SetColour(Screen.White, Screen.Bright_White);
		return "▓";
		break;
	case Maze_variables.cracked:
		Screen.SetColour(Screen.White, Screen.Gray);
		return "░";
		break;
	case Maze_variables.Coin:
		Screen.SetColour(Screen.Yellow, Screen.Black);
		return "©";
		break;
	case Maze_variables.Spawn_Room:
		Screen.SetColour(Screen.White, Screen.Black);
		return "⌂";
		break;
	case Maze_variables.Exit_Room:
		Screen.SetColour(Screen.Green, Screen.Black);
		return "⌂";
		break;
	case Maze_variables.Heart:
		Screen.SetColour(Screen.Red, Screen.Black);
		return "♥";
		break;
	default:
		return " ";
		break;
	}
}
std::string Map::Get_Walls_String(int Tile)
{
	Maze_Algorithm Maze_variables;
	switch (Tile)
	{
	case Maze_variables.air:
		Screen.SetColour(Screen.Black, Screen.Black);
		return " ";
		break;
	case Maze_variables.wall:
		Screen.SetColour(Screen.White, Screen.Bright_White);
		return "▓";
		break;
	case Maze_variables.cracked:
		Screen.SetColour(Screen.White, Screen.Gray);
		return "░";
		break;
	case Maze_variables.Coin:
		Screen.SetColour(Screen.Yellow, Screen.Black);
		return "©";
		break;
	case Maze_variables.Spawn_Room:
		Screen.SetColour(Screen.White, Screen.Black);
		return "⌂";
		break;
	case Maze_variables.Exit_Room:
		Screen.SetColour(Screen.Green, Screen.Black);
		return "⌂";
		break;
	case Maze_variables.Heart:
		Screen.SetColour(Screen.Red, Screen.Black);
		return "♥";
		break;
	default:
		return " ";
		break;
	}
}

void Map::Update_Maze(int X, int Y, int tile)
{
	Screen.Goto_XY(X, Y);
	std::cout << Get_Walls_String(tile);
	Walls[Y][X] = tile;
}

void Map::New_Maze(std::vector<std::vector<int>> Level)
{
	while (Cats.size() > 0)
	{
		Destroy_Cat(0);
	}
	Walls = Level;
	Draw_Maze();
}

std::vector<Cat*> Map::Get_Cats()
{
	return Cats;
}

void Map::Destroy_Cat(int num)
{
	Cats.erase(Cats.begin() + num);
	Cats.shrink_to_fit();
}

void Map::enable_cats(int x, int y)
{
	Cat* meowie = new Cat(this, "¤", x, y);
	Cats.push_back(meowie);
}

