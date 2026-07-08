#include "Cat.h"

Cat::Cat(Map* level, std::string icon, int x, int y)
{
	ptr_level = level;
	Icon = icon;
	Set_Position(y, x, " ");
}

Cat::~Cat()
{
}

bool Cat::Update(Player* mouse)
{
	ptr_player = mouse;
	if (rand() % 100 <= move_chance)
	{
		int Direction = rand() % 4;

		switch (Direction) {
		case 0:
			Update_Position(0, 1, ptr_level->Get_Walls_String(Get_Position()[0], Get_Position()[1]), ptr_level->Get_Walls(Get_Position()[0], Get_Position()[1] + 1));
			break;
		case 1:
			Update_Position(0, -1, ptr_level->Get_Walls_String(Get_Position()[0], Get_Position()[1]), ptr_level->Get_Walls(Get_Position()[0], Get_Position()[1] + -1));
			break;
		case 2:
			Update_Position(1, 0, ptr_level->Get_Walls_String(Get_Position()[0], Get_Position()[1]), ptr_level->Get_Walls(Get_Position()[0] + 1, Get_Position()[1]));
			break;
		case 3:
			Update_Position(-1, 0, ptr_level->Get_Walls_String(Get_Position()[0], Get_Position()[1]), ptr_level->Get_Walls(Get_Position()[0] + -1, Get_Position()[1]));
			break;
		default:
			break;
		}
	}

	if (rand() % 100 < move_chance_towards_player)
	{

		if ((ptr_player->Get_Position()[0] > Get_Position()[0]))
		{
			Update_Position(1, 0, ptr_level->Get_Walls_String(Get_Position()[0], Get_Position()[1]), ptr_level->Get_Walls(Get_Position()[0] + 1, Get_Position()[1]));
		}
		if ((ptr_player->Get_Position()[0] < Get_Position()[0]))
		{
			Update_Position(-1, 0, ptr_level->Get_Walls_String(Get_Position()[0], Get_Position()[1]), ptr_level->Get_Walls(Get_Position()[0] + -1, Get_Position()[1]));
		}
		//side to side
		if ((ptr_player->Get_Position()[1] > Get_Position()[1]))
		{
			Update_Position(0, 1, ptr_level->Get_Walls_String(Get_Position()[0], Get_Position()[1]), ptr_level->Get_Walls(Get_Position()[0], Get_Position()[1] + 1));
		}
		if ((ptr_player->Get_Position()[1] < Get_Position()[1]))
		{
			Update_Position(0, -1, ptr_level->Get_Walls_String(Get_Position()[0], Get_Position()[1]), ptr_level->Get_Walls(Get_Position()[0], Get_Position()[1] + -1));
		}
		//up and down
	}
	
	if (Get_Position() == ptr_player->Get_Position())
	{
		ptr_player->Update_Health(1);
		ptr_player->Set_Position(ptr_player->Get_Position()[0], ptr_player->Get_Position()[1], " ");
		return true;
	}
	return false;
}
