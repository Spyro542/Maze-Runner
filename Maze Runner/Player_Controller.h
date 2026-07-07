#pragma once
#include "Movement.h"
#include "Input.h"
#include "Player.h"
#include "Projectile.h"
#include "Menus.h"

class Player_Controller : public Movement
{
public:
	Player_Controller(Time_Manager* Running_Delta_Time, Menus* Menu);
	void Update(Player *ptr_Player, Map* ptr_Map);

protected:
	Input Key;
	double Base_Movement_Speed = 100;
	double Running_Multiplier = 2.0;
	Time_Manager* Delta_Time;
	Menus* ptr_menu = nullptr;
private:

};

