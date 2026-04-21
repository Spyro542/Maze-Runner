#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Terminal.h"

class Character
{
public:
	Character() = default;
	void Update_Health(float Damage_Value);
	void Update_Max_Health(float Addition_Value);
	void Set_Position(int Y, int X, std::string Last_Tile);
	void Update_Position(int Y, int X, std::string Last_Tile);
	std::vector<int> Get_Position();
	//write current pos as wall type then write space moved to as player

protected:
	float Max_Health = 0;
	float Health = 0;
	bool Handle_Death = true;
	std::vector<int> Position{ 1,1 };
	std::vector<int> Return_Position{ 2,2 };
	std::string Icon = "☺";
	Terminal Screen;
	struct
	{
		int forground = 12;
		int background = 0;
	} Character_Colors;
private:

};

