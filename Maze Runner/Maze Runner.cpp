#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <chrono>
#include <Windows.h>
#include <string>



#include "Input.h"
#include "Map.h"
#include "Levels.h"
#include "Terminal.h"
#include "Maze_Algorithm.h"


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
	Terminal Screen;
	// initialize the terminal
	Screen.Intialize();
	Screen.SetColour(Screen.Green, Screen.Black);
	// initialize the terminal

	//Generate Random Maze
	Maze_Algorithm Maze_Generator;
	Maze_Generator.Recursive();
	//Generate Random Maze

	
	Map Level_1_Map(Maze_Generator.Get_Level());	//Make the map with level 1
	Level_1_Map.Draw_Maze();	//Draw Level 1

	//Place player
	Screen.Goto_XY(pos[0], pos[1]);
	Screen.SetColour(Screen.Yellow, Screen.Black);
	std::cout << "v";

	while (true)
	{
		auto Frame_Start = clock();
		auto Start_Time = std::chrono::system_clock::now();	//Delta time


		Screen.SetColour(Screen.Yellow, Screen.Black);
		switch (Get_Input()) {
		case Up:
		{
			auto Current_Time = std::chrono::system_clock::now();
			std::chrono::duration<double> Delta_Time = Current_Time - Start_Time;
			Screen.Goto_XY(std::round(pos[0]), std::round(pos[1]));
			std::cout << " ";
			pos[1] -= (movespeed * Delta_Time.count());
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
		case Down:
		{
			auto Current_Time = std::chrono::system_clock::now();
			std::chrono::duration<double> Delta_Time = Current_Time - Start_Time;
			Screen.Goto_XY(std::round(pos[0]), std::round(pos[1]));
			std::cout << " ";
			pos[1] += (movespeed * Delta_Time.count());
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
		case Left:
		{
			auto Current_Time = std::chrono::system_clock::now();
			std::chrono::duration<double> Delta_Time = Current_Time - Start_Time;
			Screen.Goto_XY(std::round(pos[0]), std::round(pos[1]));
			std::cout << " ";
			pos[0] -= (movespeed * Delta_Time.count());
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
		case Right:
		{
			auto Current_Time = std::chrono::system_clock::now();
			std::chrono::duration<double> Delta_Time = Current_Time - Start_Time;
			Screen.Goto_XY(std::round(pos[0]), std::round(pos[1]));
			std::cout << " ";
			pos[0] += (movespeed * Delta_Time.count());
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
		case Enter:
			break;
		case Esc:
			return 0;
			break;
		case Return:
			break;
		case Interact:
			system("cls");
			Maze_Generator.Recursive();
			//Generate Random Maze


			Level_1_Map.New_Maze(Maze_Generator.Get_Level());
			Level_1_Map.Draw_Maze();	//Draw Level 1
			break;
		
		}
		//std::cout << std::endl;
		Screen.SetColour(Screen.Green, Screen.Black);
		
		

		auto Current_Time = std::chrono::system_clock::now();
		std::chrono::duration<double> Delta_Time = Current_Time - Start_Time;
		auto Frame_Time = clock() - Frame_Start;
				
		Screen.Goto_XY(0, 32);
		std::cout << "Elapsed time: " << Delta_Time.count() << "s" << std::endl;

		if (Frame_Time > 0)
		{
			Screen.Goto_XY(0, 33);
			std::cout << "FPS: " << CLOCKS_PER_SEC / Frame_Time << "Fps" << std::endl;
		}
	}

}

