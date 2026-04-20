//#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <chrono>
#include <Windows.h>
#include <string>



#include "Input.h"
#include "Map.h"
//#include "Levels.h"
#include "Terminal.h"
#include "Maze_Algorithm.h"
#include "Time_Manager.h"


char New_Screen[129][33];
int New_Screen_Colour[129][33][2];
std::vector<double> pos = { 1,1 };
float movespeed = 150;

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
	Input Key;
	Terminal Screen;
	// initialize the terminal
	Screen.Intialize();
	Screen.SetColour(Screen.Green, Screen.Black);
	// initialize the terminal

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
	Screen.Goto_XY(pos[0], pos[1]);
	Screen.SetColour(Screen.Yellow, Screen.Black);
	std::cout << "v";

	while (true)
	{
		auto Frame_Start = clock();
		Time.Start();


		Screen.SetColour(Screen.Yellow, Screen.Black);
		switch (Key.Get_Input()) {
		case Key.Up:
		{
			Screen.Goto_XY(std::round(pos[0]), std::round(pos[1]));
			std::cout << " ";
			pos[1] -= (movespeed * Time.Delta_Time());
			if (!Level_1_Map.Get_Walls(std::round(pos[0]), std::round(pos[1])))
			{
				Screen.Goto_XY(std::round(pos[0]), std::round(pos[1]));
				std::cout << "˄";
				pos[0] = std::round(pos[0]);
			}
			else
			{
				pos[1] += 1;
			}
		}
			break;
		case Key.Down:
		{
			Screen.Goto_XY(std::round(pos[0]), std::round(pos[1]));
			std::cout << " ";
			pos[1] += (movespeed * Time.Delta_Time());
			if (!Level_1_Map.Get_Walls(std::round(pos[0]), std::round(pos[1])))
			{
				Screen.Goto_XY(std::round(pos[0]), std::round(pos[1]));
				std::cout << "˅";
				pos[0] = std::round(pos[0]);
			}
			else
			{
				pos[1] -= 1;
			}
		}
			break;
		case Key.Left:
		{
			Screen.Goto_XY(std::round(pos[0]), std::round(pos[1]));
			std::cout << " ";
			pos[0] -= (movespeed * Time.Delta_Time());
			if (!Level_1_Map.Get_Walls(std::round(pos[0]), std::round(pos[1])))
			{
				Screen.Goto_XY(std::round(pos[0]), std::round(pos[1]));
				std::cout << "˂";
				pos[1] = std::round(pos[1]);
			}
			else
			{
				pos[0] += 1;
			}
		}
			break;
		case Key.Right:
		{
			Screen.Goto_XY(std::round(pos[0]), std::round(pos[1]));
			std::cout << " ";
			pos[0] += (movespeed * Time.Delta_Time());
			if (!Level_1_Map.Get_Walls(std::round(pos[0]), std::round(pos[1])))
			{
				Screen.Goto_XY(std::round(pos[0]), std::round(pos[1]));
				std::cout << "˃";
				pos[1] = std::round(pos[1]);
			}
			else
			{
				pos[0] -= 1;
			}
		}
			break;
		case Key.Enter:
			break;
		case Key.Esc:
			return 0;
			break;
		case Key.Return:
			break;
		case Key.Interact:
			//system("cls");
			Screen.Goto_XY(0, 34);
			Maze_Generator.Recursive();
			//Generate Random Maze

			Level_1_Map.New_Maze(Maze_Generator.Get_Level());
			Level_1_Map.Draw_Maze();	//Draw Level 1
			break;
		
		}
		//std::cout << std::endl;
		Screen.SetColour(Screen.Green, Screen.Black);
		
		

		auto Frame_Time = clock() - Frame_Start;
				
		Screen.Goto_XY(0, 32);
		std::cout << "Elapsed time: " << Time.Delta_Time() << "s        " << std::endl;

		if (Frame_Time > 0)
		{
			Screen.Goto_XY(0, 33);
			std::cout << "FPS: " << CLOCKS_PER_SEC / Frame_Time << "Fps" << std::endl;
		}
	}

}

