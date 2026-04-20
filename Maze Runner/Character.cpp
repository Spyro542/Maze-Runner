#include "Character.h"

void Character::Update_Health(float Damage_Value)
{
	Health -= Damage_Value;
	if ((Health <= 0) and (Handle_Death))
	{
		Set_Position(-1, -1);
	}
	else if ((Health <= 0) and (!Handle_Death))
	{
		Set_Position(Return_Position[0], Return_Position[1]);
	}
}

void Character::Update_Max_Health(float Addition_Value)
{
	Max_Health += Addition_Value;
}

void Character::Set_Position(int Y, int X)
{
	Position[0] = Y;
	Position[1] = X;
}

void Character::Update_Position(int Y, int X)
{
	Position[0] += Y;
	Position[1] += X;
}

std::vector<int> Character::Get_Position()
{
	return Position;
}
