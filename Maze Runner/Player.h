#pragma once
#include "Character.h"
#include "Input.h"


class Player : public Character
{
public:
	Player();
	Player(Map *level, Menus *menu);
	void Update();


protected:
	

private:

};

