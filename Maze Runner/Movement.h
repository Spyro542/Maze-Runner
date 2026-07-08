#pragma once
#include <vector>
#include "Time_Manager.h"
#include "Map.h"


class Movement
{
public:

	int Up(std::vector<int> Pos);
	int Down(std::vector<int> Pos);
	int Left(std::vector<int> Pos);
	int Right(std::vector<int> Pos);
	
	
	int Up(std::vector<int> Pos, Time_Manager* Delta_Time);
	int Down(std::vector<int> Pos, Time_Manager* Delta_Time);
	int Left(std::vector<int> Pos, Time_Manager* Delta_Time);
	int Right(std::vector<int> Pos, Time_Manager* Delta_Time);

	void Reset_Float();

protected:
	double Movement_Speed = 0;

private:

	
	std::vector<double> float_Pos{ 0,0 };
};

