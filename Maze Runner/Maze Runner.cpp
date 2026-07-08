//#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <chrono>
#include <Windows.h>
#include <string>



#include "Input.h"
#include "Map.h"

#include "Terminal.h"
#include "Maze_Algorithm.h"
#include "Time_Manager.h"
#include "Player.h"
#include "Player_Controller.h"
#include "Menus.h"
#include "Cat.h"


char New_Screen[129][33];
int New_Screen_Colour[129][33][2];
std::vector<double> pos = { 1,1 };
float movespeed = 150;
float Timer = 0.0;
bool quit = false;
bool restart = false;
bool Return_to_Menu = false;

struct Vector_2D
{
	float X = 0;
	float Y = 0;
};
struct Position_2D
{
	int X = 0;
	int Y = 0;
};

int main()
{
	{
		Terminal Screen;
		// initialize the terminal
		Screen.Intialize();
		Screen.SetColour(Screen.Green, Screen.Black);
		// initialize the terminal
	}
	Menus Menu(&quit, &restart, &Return_to_Menu);
	while (!quit)
	{

		Menu.Main_Menu();

		while (!Return_to_Menu)
		{

			//Generate Random Maze
			Maze_Algorithm Maze_Generator;
			Maze_Generator.Recursive();
			//Generate Random Maze

			//Initialize delta time
			Time_Manager Time;
			//Initialize delta time

			Map Level_1_Map(Maze_Generator.Get_Level());	//Make the map with level 1
			Level_1_Map.Draw_Maze();	//Draw Level 1

			//Place player
			Player Active_Player(&Level_1_Map, &Menu, &Maze_Generator);
			Player_Controller Active_Player_controller(&Time, &Menu);

			/*for (size_t i = 0; i < Level_1_Map.Get_Cats().size() - 1; i++)
			{

			}*/
			restart = false;
		}
		Return_to_Menu = false;
	}
	quit = false;
}

