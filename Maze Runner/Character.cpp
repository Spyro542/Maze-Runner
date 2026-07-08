#include "Character.h"

void Character::Update_Health(float Damage_Value)
{
	Health -= Damage_Value;
	if ((Health <= 0) and (Handle_Death))
	{
		Set_Position(-1, -1, " ");	//update last pos
	}
	else if ((Health <= 0) and (!Handle_Death))
	{
		if (ptr_menu != nullptr)
		{
			ptr_menu->Game_Over(Score, Level);
		}
		else
		{
			Set_Position(Return_Position[0], Return_Position[1], " ");	//update last pos
		}
	}
	if (Health > Max_Health)
	{
		Health = Max_Health;
	}
	if (UI)
	{
		Update_UI();
	}
	}

void Character::Update_UI()
{
	Screen.SetColour(Screen.Bright_Green, Screen.Black);

	Screen.Goto_XY(130, 0);
	std::cout << "Score:";
	Screen.Goto_XY(130, 1);
	std::cout << Score;
	
	Screen.Goto_XY(130, 3);
	std::cout << "Health:";
	Screen.Goto_XY(130, 4);
	Print_Healthbar();
	
	Screen.Goto_XY(130, 6);
	std::cout << "Level:";
	Screen.Goto_XY(130, 7);
	std::cout << Level;
}

void Character::Print_Healthbar()
{
	if (Health / Max_Health * 100 >= 95) { std::cout << "[▓▓▓▓▓]"; }
	else if (Health / Max_Health * 100 >= 90) { std::cout << "[▓▓▓▓▒]"; }
	else if (Health / Max_Health * 100 >= 85) { std::cout << "[▓▓▓▓░]"; }
	else if (Health / Max_Health * 100 >= 80) { std::cout << "[▓▓▓▓ ]"; }
	
	else if (Health / Max_Health * 100 >= 75) { std::cout << "[▓▓▓▓ ]"; }
	else if (Health / Max_Health * 100 >= 70) { std::cout << "[▓▓▓▒ ]"; }
	else if (Health / Max_Health * 100 >= 65) { std::cout << "[▓▓▓░ ]"; }
	else if (Health / Max_Health * 100 >= 60) { std::cout << "[▓▓▓  ]"; }
	
	else if (Health / Max_Health * 100 >= 55) { std::cout << "[▓▓▓  ]"; }
	else if (Health / Max_Health * 100 >= 50) { std::cout << "[▓▓▒  ]"; }
	else if (Health / Max_Health * 100 >= 45) { std::cout << "[▓▓░  ]"; }
	else if (Health / Max_Health * 100 >= 40) { std::cout << "[▓▓   ]"; }
	
	else if (Health / Max_Health * 100 >= 35) { std::cout << "[▓▓   ]"; }
	else if (Health / Max_Health * 100 >= 30) { std::cout << "[▓▒   ]"; }
	else if (Health / Max_Health * 100 >= 25) { std::cout << "[▓░   ]"; }
	else if (Health / Max_Health * 100 >= 20) { std::cout << "[▓    ]"; }
	
	else if (Health / Max_Health * 100 >= 15) { std::cout << "[▓    ]"; }
	else if (Health / Max_Health * 100 >= 10) { std::cout << "[▒    ]"; }
	else if (Health / Max_Health * 100 >= 5) { std::cout << "[░    ]"; }
	else if (Health / Max_Health * 100 >= 1) { std::cout << "[     ]"; }
}

void Character::Update_Max_Health(float Addition_Value)
{
	Max_Health += Addition_Value;
}

void Character::Set_Position(int Y, int X, std::string Last_Tile)
{
	if (Y != 0 or X != 0)
	{
		Screen.Goto_XY(Position[0], Position[1]);
		std::cout << Last_Tile;
		Position[0] = Y;
		Position[1] = X;
		Screen.Goto_XY(Position[0], Position[1]);
		Screen.SetColour(Character_Colors.forground, Character_Colors.background);
		std::cout << Icon;
	}
}

void Character::Update_Position(int Y, int X, std::string Last_Tile, int next_tile)
{
	if (Y != 0 or X != 0)
	{
		bool walkable = true;
		for (size_t i = 0; i < non_passable.size(); i++)
		{
			if (next_tile == non_passable[i])
			{
				walkable = false;
			}
		}
		if (walkable)
		{
			Screen.Goto_XY(Position[0], Position[1]);
			/*if (Last_Tile == "©") { Screen.SetColour(Screen.Yellow, Screen.Black); }
			else if (Last_Tile == "⌂") { Screen.SetColour(Screen.Green, Screen.Black); }
			else if (Last_Tile == "♥") { Screen.SetColour(Screen.Red, Screen.Black); }*/
			std::cout << Last_Tile;
			Position[0] += Y;
			Position[1] += X;
			Screen.Goto_XY(Position[0], Position[1]);
			Screen.SetColour(Character_Colors.forground, Character_Colors.background);
			std::cout << Icon;
			if (ptr_level != nullptr && ptr_menu != nullptr)
			{
				switch (next_tile) {
				case Coin:

					Score += 10;
					ptr_level->Update_Maze(Position[0], Position[1], 0);
					if (UI)
					{
						Update_UI();
					}
					break;
				case Heart:
					Max_Health++;
					Update_Health(-2);
					ptr_level->Update_Maze(Position[0], Position[1], 0);
					break;
				case Exit:
					Score += 100;
					Level++;
					ptr_algorithm->Recursive();
					ptr_level->New_Maze(ptr_algorithm->Get_Level());
					Update_UI();
					Set_Position(Return_Position[0], Return_Position[1], ptr_level->Get_Walls_String(Position[0], Position[1]));
					break;
				default:
					break;
				}
			}
		}
	}
}

std::vector<int> Character::Get_Position()
{
	return Position;
}
