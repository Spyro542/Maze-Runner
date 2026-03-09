#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <chrono>
#include <Windows.h>
#include <string>


#include "Input.h"
#include "Screen.h"


char New_Screen[129][33];
int New_Screen_Colour[129][33][2];



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

	


	while (true)
	{
		auto Frame_Start = clock();
		auto Start_Time = std::chrono::system_clock::now();	//Delta time
		flip(New_Screen, New_Screen_Colour);	//print screen changes


		Clear_Inputs();
		//while (Get_Input() > 0){}	//Stop Repeated keystrokes
		//while (!(Get_Input() > 0))
		
		for (size_t i1 = 0; i1 < 32; i1++)
		{
			for (size_t i = 0; i < 128; i++)
			{
				New_Screen[i][i1] = '#';
				if (i < 64)
				{
					New_Screen_Colour[i][i1][Text] = Blue;
					New_Screen_Colour[i][i1][Background] = Black;
				}
				else
				{
					New_Screen_Colour[i][i1][Text] = Bright_White;
					New_Screen_Colour[i][i1][Background] = Black;
				}
			}
			
		}

		switch (Get_Input()) {
		case Up:
			//std::cout << "Up\n";
			for (size_t i1 = 0; i1 < 32; i1++)
			{
				for (size_t i = 0; i < 128; i++)
				{
					New_Screen[i][i1] = 'W';
					New_Screen_Colour[i][i1][Text] = Green;
					New_Screen_Colour[i][i1][Background] = Black;
				}
			}
			break;
		case Down:
			std::cout << "Down\n";
			break;
		case Left:
			std::cout << "Left\n";
			break;
		case Right:
			std::cout << "Right\n";
			break;
		case Enter:
			std::cout << "Enter\n";
			break;
		case Esc:
			std::cout << "Esc\n";
			break;
		case Return:
			std::cout << "Return\n";
			break;
		case Interact:
			std::cout << "Interact\n";
			break;
		
		}
		//std::cout << std::endl;
		
		
		

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

