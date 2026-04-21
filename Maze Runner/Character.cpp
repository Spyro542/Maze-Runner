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
		Set_Position(Return_Position[0], Return_Position[1], " ");	//update last pos
	}
}

void Character::Update_Max_Health(float Addition_Value)
{
	Max_Health += Addition_Value;
}

void Character::Set_Position(int Y, int X, std::string Last_Tile)
{
	Screen.Goto_XY(Position[0], Position[1]);
	std::cout << Last_Tile;
	Position[0] = Y;
	Position[1] = X;
	Screen.Goto_XY(Position[0], Position[1]);
	Screen.SetColour(Character_Colors.forground, Character_Colors.background);
	std::cout << Icon;
}

void Character::Update_Position(int Y, int X, std::string Last_Tile)
{
	Screen.Goto_XY(Position[0], Position[1]);
	std::cout << Last_Tile;
	Position[0] += Y;
	Position[1] += X;
	Screen.Goto_XY(Position[0], Position[1]);
	Screen.SetColour(Character_Colors.forground, Character_Colors.background);
	std::cout << Icon;
}

std::vector<int> Character::Get_Position()
{
	return Position;
}
