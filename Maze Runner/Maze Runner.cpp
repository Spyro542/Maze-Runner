#include <iostream>

#include "Input.h"
#include "Screen.h"




int main()
{
	SetColour(Green, Black);

	while (true)
	{
		Clear_Inputs();
		//while (Get_Input() > 0){}	//Stop Repeated keystrokes
		//while (!(Get_Input() > 0))
		{
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
		}
	}

}

