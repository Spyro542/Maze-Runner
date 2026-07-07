#include "Menus.h"

Menus::Menus(bool* quit, bool* restart, bool* Return_to_Menu)
{
	ptr_quit = quit;
	ptr_restart = restart;
	ptr_Return_to_Menu = Return_to_Menu;
}

void Menus::Main_Menu()
{
	//setup
	Terminal Screen;
	Input Key;
	Screen.Clear_Screen();
	Curr_Selection = 60000;
	selected = false;
	
	//Logo/title 
	int Logo_alignment[2] = {35,4};
	Screen.SetColour(Screen.Yellow, Screen.Black);

	Screen.Goto_XY(Logo_alignment[0], Logo_alignment[1]++);
	std::cout << "   _____                               __________                                  ";
	Screen.Goto_XY(Logo_alignment[0], Logo_alignment[1]++);
	std::cout << "  /     \\   ____  __ __  ______ ____   \\______   \\__ __  ____   ____   ___________ ";
	Screen.Goto_XY(Logo_alignment[0], Logo_alignment[1]++);
	std::cout << " /  \\ /  \\ /  _ \\|  |  \\/  ___// __ \\   |       _/  |  \\/    \\ /    \\_/ __ \\_  __ \\";
	Screen.Goto_XY(Logo_alignment[0], Logo_alignment[1]++);
	std::cout << "/    Y    (  <_> )  |  /\\___ \\\\  ___/   |    |   \\  |  /   |  \\   |  \\  ___/|  | \\/";
	Screen.Goto_XY(Logo_alignment[0], Logo_alignment[1]++);
	std::cout << "\\____|__  /\\____/|____//____  >\\___  >  |____|_  /____/|___|  /___|  /\\___  >__|   ";
	Screen.Goto_XY(Logo_alignment[0], Logo_alignment[1]++);
	std::cout << "        \\/                  \\/     \\/          \\/           \\/     \\/     \\/       ";
	//Logo/title 

	
	while (true)
	{
		int Selection_alignment[2] = { 40, 12 };
		//Selection
		
		Screen.Goto_XY(Selection_alignment[0], Selection_alignment[1] += 2);
		if (Curr_Selection % 3 == 0) { Screen.SetColour(Screen.Green, Screen.White); }
		else						 { Screen.SetColour(Screen.Green, Screen.Black); }
		std::cout << "New Game";

		Screen.Goto_XY(Selection_alignment[0], Selection_alignment[1] += 2);
		if (Curr_Selection % 3 == 1) { Screen.SetColour(Screen.Green, Screen.White); }
		else						 { Screen.SetColour(Screen.Green, Screen.Black); }
		std::cout << "Options";

		Screen.Goto_XY(Selection_alignment[0], Selection_alignment[1] += 2);
		if (Curr_Selection % 3 == 2) { Screen.SetColour(Screen.Green, Screen.White); }
		else						 { Screen.SetColour(Screen.Green, Screen.Black); }
		std::cout << "Quit";
		
		if (Curr_Selection % 3 == 0 && Key.Get_Input() == Key.Enter)
		{
			while (Key.Get_Input() == Key.Enter) {}
			break;
		}
		else if (Curr_Selection % 3 == 1 && Key.Get_Input() == Key.Enter)
		{
			while (Key.Get_Input() == Key.Enter) {}
			Options();
			break;
		}
		else if (Curr_Selection % 3 == 2 && Key.Get_Input() == Key.Enter)
		{
			while (Key.Get_Input() == Key.Enter) {}
			Quit();
			break;
		}
		Selection();
	}
	
	
}

void Menus::Game_Over(int score)
{
	//setup
	Terminal Screen;
	Input Key;
	Screen.Clear_Screen();
	Curr_Selection = 60000;
	selected = false;
	
	//Logo/title 
	Screen.SetColour(Screen.Red, Screen.Black);
	int Logo_alignment[2] = { 42,4 };

	Screen.Goto_XY(Logo_alignment[0], Logo_alignment[1]++);
	std::cout << "  ▄████  ▄▄▄       ███▄ ▄███▓▓█████     ▒█████   ██▒   █▓▓█████  ██▀███  ";
	Screen.Goto_XY(Logo_alignment[0], Logo_alignment[1]++);
	std::cout << " ██▒ ▀█▒▒████▄    ▓██▒▀█▀ ██▒▓█   ▀    ▒██▒  ██▒▓██░   █▒▓█   ▀ ▓██ ▒ ██▒";
	Screen.Goto_XY(Logo_alignment[0], Logo_alignment[1]++);
	std::cout << "▒██░▄▄▄░▒██  ▀█▄  ▓██    ▓██░▒███      ▒██░  ██▒ ▓██  █▒░▒███   ▓██ ░▄█ ▒";
	Screen.Goto_XY(Logo_alignment[0], Logo_alignment[1]++);
	std::cout << "░▓█  ██▓░██▄▄▄▄██ ▒██    ▒██ ▒▓█  ▄    ▒██   ██░  ▒██ █░░▒▓█  ▄ ▒██▀▀█▄  ";
	Screen.Goto_XY(Logo_alignment[0], Logo_alignment[1]++);
	std::cout << "░▒▓███▀▒ ▓█   ▓██▒▒██▒   ░██▒░▒████▒   ░ ████▓▒░   ▒▀█░  ░▒████▒░██▓ ▒██▒";
	Screen.Goto_XY(Logo_alignment[0], Logo_alignment[1]++);
	std::cout << " ░▒   ▒  ▒▒   ▓▒█░░ ▒░   ░  ░░░ ▒░ ░   ░ ▒░▒░▒░    ░ ▐░  ░░ ▒░ ░░ ▒▓ ░▒▓░";
	Screen.Goto_XY(Logo_alignment[0], Logo_alignment[1]++);
	std::cout << "  ░   ░   ▒   ▒▒ ░░  ░      ░ ░ ░  ░     ░ ▒ ▒░    ░ ░░   ░ ░  ░  ░▒ ░ ▒░";
	Screen.Goto_XY(Logo_alignment[0], Logo_alignment[1]++);
	std::cout << "░ ░   ░   ░   ▒   ░      ░      ░      ░ ░ ░ ▒       ░░     ░     ░░   ░ ";
	Screen.Goto_XY(Logo_alignment[0], Logo_alignment[1]++);
	std::cout << "      ░       ░  ░       ░      ░  ░       ░ ░        ░     ░  ░   ░     ";
	Screen.Goto_XY(Logo_alignment[0], Logo_alignment[1]++);
	std::cout << "                                                     ░                   ";
	//Logo/title 

	
	while (true)
	{
		int Selection_alignment[2] = { 47, 16 };
		//Selection

		Screen.Goto_XY(Selection_alignment[0], Selection_alignment[1] += 2);
		if (Curr_Selection % 3 == 0) { Screen.SetColour(Screen.Red, Screen.White); }
		else { Screen.SetColour(Screen.Red, Screen.Black); }
		std::cout << "New Game";

		Screen.Goto_XY(Selection_alignment[0], Selection_alignment[1] += 2);
		if (Curr_Selection % 3 == 1) { Screen.SetColour(Screen.Red, Screen.White); }
		else { Screen.SetColour(Screen.Red, Screen.Black); }
		std::cout << "Main Menu";

		Screen.Goto_XY(Selection_alignment[0], Selection_alignment[1] += 2);
		if (Curr_Selection % 3 == 2) { Screen.SetColour(Screen.Red, Screen.White); }
		else { Screen.SetColour(Screen.Red, Screen.Black); }
		std::cout << "Quit";
		
		Screen.SetColour(Screen.Yellow, Screen.Black);
		Screen.Goto_XY(75, 16);
		std::cout << "Score: " << score;


		if (Curr_Selection % 3 == 0 && Key.Get_Input() == Key.Enter)
		{
			while (Key.Get_Input() == Key.Enter){}
			Restart();
			break;
		}
		else if (Curr_Selection % 3 == 1 && Key.Get_Input() == Key.Enter)
		{
			while (Key.Get_Input() == Key.Enter) {}
			Menu_Return();
			break;
		}
		else if (Curr_Selection % 3 == 2 && Key.Get_Input() == Key.Enter)
		{
			while (Key.Get_Input() == Key.Enter) {}
			Quit();
			break;
		}

		Selection();
	}
}

void Menus::Options()
{
	//setup
	Terminal Screen;
	Input Key;
	Screen.Clear_Screen();
	Curr_Selection = 60000;
	selected = false;

	//Logo/title 
	int Logo_alignment[2] = { 35,4 };
	Screen.SetColour(Screen.Green, Screen.Black);

	Screen.Goto_XY(Logo_alignment[0], Logo_alignment[1]++);
	std::cout << "╔═╗┌─┐┌┬┐┬┌─┐┌┐┌┌─┐";
	Screen.Goto_XY(Logo_alignment[0], Logo_alignment[1]++);
	std::cout << "║ ║├─┘ │ ││ ││││└─┐";
	Screen.Goto_XY(Logo_alignment[0], Logo_alignment[1]++);
	std::cout << "╚═╝┴   ┴ ┴└─┘┘└┘└─┘";
	Screen.Goto_XY(Logo_alignment[0], Logo_alignment[1]++);
	//Logo/title 

	const int choices = 3;
	while (true)
	{
		int Selection_alignment[2] = { 40, 8 };
		int choice_num = 0;


		Screen.Goto_XY(Selection_alignment[0], Selection_alignment[1] += 2);
		if (Curr_Selection % choices == choice_num++) 
		{ 
			Screen.SetColour(Screen.Green, Screen.White); 
			switch (Key.Get_Input()) {
			case Key.Left:
				while (Key.Get_Input() != 0) {}
				if (!(player_icon <= 0))
				{
					player_icon--;
				}
				break;
			case Key.Right:
				while (Key.Get_Input() != 0) {}
				if (!(player_icon >= Alphanumeric_characters.size()-1))
				{
					player_icon++;
				}
				break;
			default:
				break;
			}
		}
		else { Screen.SetColour(Screen.Green, Screen.Black); }
		std::cout << "Mouse Icon: " << get_player_icon();

		Screen.Goto_XY(Selection_alignment[0], Selection_alignment[1] += 2);
		if (Curr_Selection % choices == choice_num++) 
		{ 
			Screen.SetColour(Screen.Green, Screen.White); 
			if (Key.Get_Input() == Key.Enter)
			{
				while (Key.Get_Input()) {}
				Menu_Return();
				break;
			}
		}
		else { Screen.SetColour(Screen.Green, Screen.Black); }
		std::cout << "Main Menu";

		Screen.Goto_XY(Selection_alignment[0], Selection_alignment[1] += 2);
		if (Curr_Selection % choices == choice_num++) 
		{ 
			Screen.SetColour(Screen.Green, Screen.White); 
			if (Key.Get_Input() == Key.Enter)
			{
				while (Key.Get_Input()) {}
				Quit();
				break;
			}
		}
		else { Screen.SetColour(Screen.Green, Screen.Black); }
		std::cout << "Quit";

		
		Selection();

	}
}

void Menus::Restart()
{
	*ptr_restart = true;
}

void Menus::Menu_Return()
{
	Restart();
	*ptr_Return_to_Menu = true;
}

std::string Menus::get_player_icon()
{
	return Alphanumeric_characters[player_icon];
}

void Menus::Quit()
{
	*ptr_quit = true;
	Menu_Return();
}

void Menus::Selection()
{
	Input Key;
	
	switch (Key.Get_Input()) {
	case Key.Up:
		Curr_Selection--;
		break;
	case Key.Down:
		Curr_Selection++;
		break;
	default:
		break;
	}


	while (Key.Get_Input() != 0) 
	{
		if (Key.Get_Input() == Key.Enter || Key.Get_Input() == Key.Left || Key.Get_Input() == Key.Right)
		{
			break;
		}
	}
}
