#include "Movement.h"

Movement::Movement(double Current_Movement_Speed)
{
	Movement_Speed = Current_Movement_Speed;
}

void Movement::Up(std::vector<int>* Pos)
{
	(*Pos)[0]--;
}

void Movement::Down(std::vector<int>* Pos)
{
	(*Pos)[0]++;
}

void Movement::Left(std::vector<int>* Pos)
{
	(*Pos)[1]--;
}

void Movement::Right(std::vector<int>* Pos)
{
	(*Pos)[1]++;
}

//Float based movent system for holding keys \/

void Movement::Up(std::vector<int>* Pos, Time_Manager* Delta_Time)
{
	float_Pos[0] -= Delta_Time->Delta_Time() * Movement_Speed;
	if (float_Pos[0] <= -1)
	{
		float_Pos[0]--;
		(*Pos)[0]--;
	}
}

void Movement::Down(std::vector<int>* Pos, Time_Manager* Delta_Time)
{
	float_Pos[0] -= Delta_Time->Delta_Time() * Movement_Speed;
	if (float_Pos[0] <= 1)
	{
		float_Pos[0]++;
		(*Pos)[0]++;
	}
}

void Movement::Left(std::vector<int>* Pos, Time_Manager* Delta_Time)
{
	float_Pos[1] -= Delta_Time->Delta_Time() * Movement_Speed;
	if (float_Pos[1] <= -1)
	{
		float_Pos[1]--;
		(*Pos)[1]--;
	}
}

void Movement::Right(std::vector<int>* Pos, Time_Manager* Delta_Time)
{
	float_Pos[1] -= Delta_Time->Delta_Time() * Movement_Speed;
	if (float_Pos[1] <= 1)
	{
		float_Pos[1]++;
		(*Pos)[1]++;
	}
}

void Movement::Reset_Float()
{
	float_Pos[0] = 0;
	float_Pos[1] = 0;
}


