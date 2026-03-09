#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <chrono>



#include "Input.h"
#include "Screen.h"




int main()
{
	SetColour(Green, Black);

	while (true)
	{
		auto Start_Time = std::chrono::system_clock::now();
		Clear_Inputs();
		//while (Get_Input() > 0){}	//Stop Repeated keystrokes
		//while (!(Get_Input() > 0))
		
		switch (Get_Input()) {
		case Up:
			std::cout << "Up\n";
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
		for (size_t i = 0; i < 16; i++)
		{
			for (size_t i = 0; i < 16; i++)
			{
				std::cout << "#";
			}
			std::cout << "\n";
		}
		auto Current_Time = std::chrono::system_clock::now();
		std::chrono::duration<double> Delta_Time = Current_Time - Start_Time;
		

		std::cout << "elapsed time: " << Delta_Time.count() << "s"
			<< std::endl;
		system("cls");
	}

}

