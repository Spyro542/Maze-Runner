#include "Time_Manager.h"
#include <iostream>

Time_Manager::Time_Manager()
{
	Start_Time = std::chrono::system_clock::now();
}

void Time_Manager::Start()
{
	Start_Time = std::chrono::system_clock::now();
}

double Time_Manager::Delta_Time()
{
	std::chrono::duration<double> Delta_Time = std::chrono::system_clock::now() - Start_Time;

	return Delta_Time.count();
}
