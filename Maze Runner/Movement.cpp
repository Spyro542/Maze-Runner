#include "Movement.h"



int Movement::Up(std::vector<int> Pos)
{
	return -1;
}

int Movement::Down(std::vector<int> Pos)
{
	return 1;
}

int Movement::Left(std::vector<int> Pos)
{
	return -1;
}

int Movement::Right(std::vector<int> Pos)
{
	return 1;
}

//Float based movent system for holding keys \/

int Movement::Up(std::vector<int> Pos, Time_Manager* Delta_Time)
{
	float_Pos[0] -= Delta_Time->Delta_Time() * Movement_Speed;
	if (float_Pos[0] <= -1)
	{
		float_Pos[0]++;
		return -1;
	}
	return 0;
}

int Movement::Down(std::vector<int> Pos, Time_Manager* Delta_Time)
{
	float_Pos[0] += Delta_Time->Delta_Time() * Movement_Speed/100;
	if (float_Pos[0] <= 1)
	{
		float_Pos[0]--;
		return 1;
	}
	return 0;
}

int Movement::Left(std::vector<int> Pos, Time_Manager* Delta_Time)
{
	float_Pos[1] -= Delta_Time->Delta_Time() * Movement_Speed;
	if (float_Pos[1] <= -1)
	{
		float_Pos[1]++;
		return -1;
	}
	return 0;
}

int Movement::Right(std::vector<int> Pos, Time_Manager* Delta_Time)
{
	float_Pos[1] += Delta_Time->Delta_Time() * Movement_Speed;
	if (float_Pos[1] <= 1)
	{
		float_Pos[1]--;
		return 1;
	}
	return 0;
}

void Movement::Reset_Float()
{
	float_Pos[0] = 0;
	float_Pos[1] = 0;
}


