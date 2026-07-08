#pragma once
#include "Character.h"
#include "Input.h"


class Player : public Character
{
public:
	Player();
	Player(Map *level, Menus *menu, Maze_Algorithm* algorithm);
	void Update();


protected:
	

private:

};

