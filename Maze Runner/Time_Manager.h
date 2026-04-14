#pragma once
#include <chrono>

class Time_Manager
{
public:
	Time_Manager();

	void Start();
	double Delta_Time();


private:
	//std::chrono::duration<double> Start_Time;
	std::chrono::time_point<std::chrono::system_clock> Start_Time; //, std::chrono::duration<__int64, std::ratio<1, 10000000>>
};

