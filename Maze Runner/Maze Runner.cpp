#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <chrono>
#include <Windows.h>
#include <string>
#include <vector>


#include "Input.h"
#include "Screen.h"
#include "Map.h"
#include "Levels.h"


char New_Screen[129][33];
int New_Screen_Colour[129][33][2];
std::vector<double> pos = { 1,1 };
float movespeed = 150;


int main()
{
	Intialize();
	SetColour(Green, Black);
	for (size_t Y = 0; Y < 33; Y++)
	{
		for (size_t X = 0; X < 128; X++)
		{
			New_Screen_Colour[X][Y][Text] = Bright_White;
			New_Screen_Colour[X][Y][Background] = Black;
		}
	}
	system("cls");

	Map Level_1_Map(Level_1);
	Level_1_Map.Draw_Maze();
	Goto_XY(pos[0], pos[1]);
	SetColour(Yellow, Black);
	std::cout << "v";

	while (true)
	{
		auto Frame_Start = clock();
		auto Start_Time = std::chrono::system_clock::now();	//Delta time
		//flip(New_Screen, New_Screen_Colour);	//print screen changes


		Clear_Inputs();
		//while (Get_Input() > 0){}	//Stop Repeated keystrokes
		//while (!(Get_Input() > 0))
		SetColour(Yellow, Black);
		switch (Get_Input()) {
		case Up:
		{
			auto Current_Time = std::chrono::system_clock::now();
			std::chrono::duration<double> Delta_Time = Current_Time - Start_Time;
			Goto_XY(std::round(pos[0]), std::round(pos[1]));
			std::cout << " ";
			pos[1] -= (movespeed * Delta_Time.count());
			if (!Level_1_Map.Get_Walls(std::round(pos[0]), std::round(pos[1])))
			{
				Goto_XY(std::round(pos[0]), std::round(pos[1]));
				std::cout << "^";
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
			Goto_XY(std::round(pos[0]), std::round(pos[1]));
			std::cout << " ";
			pos[1] += (movespeed * Delta_Time.count());
			if (!Level_1_Map.Get_Walls(std::round(pos[0]), std::round(pos[1])))
			{
				Goto_XY(std::round(pos[0]), std::round(pos[1]));
				std::cout << "v";
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
			Goto_XY(std::round(pos[0]), std::round(pos[1]));
			std::cout << " ";
			pos[0] -= (movespeed * Delta_Time.count());
			if (!Level_1_Map.Get_Walls(std::round(pos[0]), std::round(pos[1])))
			{
				Goto_XY(std::round(pos[0]), std::round(pos[1]));
				std::cout << "<";
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
			Goto_XY(std::round(pos[0]), std::round(pos[1]));
			std::cout << " ";
			pos[0] += (movespeed * Delta_Time.count());
			if (!Level_1_Map.Get_Walls(std::round(pos[0]), std::round(pos[1])))
			{
				Goto_XY(std::round(pos[0]), std::round(pos[1]));
				std::cout << ">";
				pos[1] = std::round(pos[1]);
			}
			else
			{
				pos[0] -= 1;
			}
		}
			break;
		case Enter:
			return 0;
			break;
		case Esc:
			break;
		case Return:
			break;
		case Interact:
			break;
		
		}
		//std::cout << std::endl;
		SetColour(Green, Black);
		
		

		auto Current_Time = std::chrono::system_clock::now();
		std::chrono::duration<double> Delta_Time = Current_Time - Start_Time;
		auto Frame_Time = clock() - Frame_Start;
				
		Goto_XY(0, 32);
		std::cout << "Elapsed time: " << Delta_Time.count() << "s" << std::endl;

		if (Frame_Time > 0)
		{
			Goto_XY(0, 33);
			std::cout << "FPS: " << CLOCKS_PER_SEC / Frame_Time << "Fps" << std::endl;
		}
	}

}

