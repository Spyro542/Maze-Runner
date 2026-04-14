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


