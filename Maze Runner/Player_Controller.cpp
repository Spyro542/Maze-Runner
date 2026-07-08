#include "Player_Controller.h"

Player_Controller::Player_Controller(Time_Manager* Running_Delta_Time, Menus* menu)
{
	Movement_Speed = Base_Movement_Speed;
	Delta_Time = Running_Delta_Time;
	ptr_menu = menu;
}

void Player_Controller::Update(Player* ptr_Player, Map* ptr_Map)
{
	if (Key.Get_Shift())	//Running
	{
		Movement_Speed = Base_Movement_Speed * Running_Multiplier;
	}
	else
	{
		Movement_Speed = Base_Movement_Speed;
	}

	switch (Key.Get_Input()) {
	case Key.Up:
	{
		int Added_Pos = Up(ptr_Player->Get_Position(), Delta_Time);
		ptr_Player->Update_Position(0, Added_Pos, ptr_Map->Get_Walls_String(ptr_Player->Get_Position()[0], ptr_Player->Get_Position()[1]), ptr_Map->Get_Walls(ptr_Player->Get_Position()[0], ptr_Player->Get_Position()[1] + Added_Pos));
		break;
	}
	case Key.Down:
	{
		int Added_Pos = Down(ptr_Player->Get_Position(), Delta_Time);
		ptr_Player->Update_Position(0, Added_Pos, ptr_Map->Get_Walls_String(ptr_Player->Get_Position()[0], ptr_Player->Get_Position()[1]), ptr_Map->Get_Walls(ptr_Player->Get_Position()[0], ptr_Player->Get_Position()[1] + Added_Pos));
		break;
	}
	case Key.Left:
	{
		int Added_Pos = Left(ptr_Player->Get_Position(), Delta_Time);
		ptr_Player->Update_Position(Added_Pos, 0, ptr_Map->Get_Walls_String(ptr_Player->Get_Position()[0], ptr_Player->Get_Position()[1]), ptr_Map->Get_Walls(ptr_Player->Get_Position()[0] + Added_Pos, ptr_Player->Get_Position()[1]));
		break;
	}
	case Key.Right:
	{
		int Added_Pos = Right(ptr_Player->Get_Position(), Delta_Time);
		ptr_Player->Update_Position(Added_Pos, 0, ptr_Map->Get_Walls_String(ptr_Player->Get_Position()[0], ptr_Player->Get_Position()[1]), ptr_Map->Get_Walls(ptr_Player->Get_Position()[0] + Added_Pos, ptr_Player->Get_Position()[1]));
		break;
	}
	case Key.Esc:
		ptr_menu->Options();
		break;
	default:
		//Reset_Float();
		break;
	}

	/*if (Key.Get_Space())
	{
		while (Key.Get_Space()){}
		ptr_Player->Update_Health(1);
	}*/
	
}
