#pragma once
#include "Character.h"
#include "Movement.h"
#include <iostream>
#include "Terminal.h"
#include <thread>

class Projectile : public Character
{
public:
	Projectile(float Damage, double Speed, int direction, std::string Icon, int Colour, int X, int Y, Time_Manager* Running_Delta_Time, Map* Level);
	void update();
	void Update_Position(int Y, int X, std::string Last_Tile, int next_tile);

	enum Direction
	{
		D_Up,
		D_Down,
		D_Left,
		D_Right,
	};

private:
	int Direction = 0;
	float damage = 0;
	double speed = 0;

	int colour = 0;
	
	Time_Manager* ptr_Delta_Time = nullptr;
	Map* ptr_level = nullptr;
	Movement move;
};

