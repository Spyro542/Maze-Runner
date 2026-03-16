#pragma once
#include <vector>

class Character
{
public:
	Character() = default;
	void Update_Health(float Damage_Value);
	void Update_Max_Health(float Addition_Value);
	void Set_Position(int Y, int X);
	void Update_Position(int Y, int X);
	std::vector<int> Get_Position();


protected:
	float Max_Health = 0;
	float Health = 0;
	bool Handle_Death = true;
	std::vector<int> Position{ 0,0 };
	std::vector<int> Return_Position{ 2,2 };
private:

};

