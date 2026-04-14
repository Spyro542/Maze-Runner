#pragma once
#include <vector>
#include "Time_Manager.h"

class Movement
{
public:
	Movement(double Current_Movement_Speed);

	void Up(std::vector<int> *Pos);
	void Down(std::vector<int> *Pos);
	void Left(std::vector<int> *Pos);
	void Right(std::vector<int> *Pos);
	
	
	void Up(std::vector<int> *Pos, Time_Manager* Delta_Time);
	void Down(std::vector<int> *Pos, Time_Manager* Delta_Time);
	void Left(std::vector<int> *Pos, Time_Manager* Delta_Time);
	void Right(std::vector<int> *Pos, Time_Manager* Delta_Time);


private:

	double Movement_Speed = 0;
	std::vector<double> float_Pos{ 0,0 };
};

