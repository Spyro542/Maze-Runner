#pragma once
#include "Movement.h"
#include "Input.h"
#include "Player.h"

class Player_Controller : public Movement
{
public:
	Player_Controller(Time_Manager* Running_Delta_Time);
	void Update(Player *ptr_Player, Map* ptr_Map);

protected:
	Input Key;
	double Base_Movement_Speed = 5;
	Time_Manager* Delta_Time;
private:

};

