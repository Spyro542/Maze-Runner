#include "Player_Controller.h"

Player_Controller::Player_Controller(Time_Manager* Running_Delta_Time)
{
	Movement_Speed = Base_Movement_Speed;
	Delta_Time = Running_Delta_Time;
}

void Player_Controller::Update(Player* ptr_Player, Map* ptr_Map)
{
	switch (Key.Get_Input()) {
	case Key.Up:
		//std::vector<int> Last_pos = ptr_Player->Get_Position();
		ptr_Player->Update_Position(0, Up(ptr_Player->Get_Position(), Delta_Time), ptr_Map->Get_Walls_String(ptr_Player->Get_Position()[0], ptr_Player->Get_Position()[1]));
		break;
	case Key.Down:
		ptr_Player->Update_Position(0, Down(ptr_Player->Get_Position(), Delta_Time), ptr_Map->Get_Walls_String(ptr_Player->Get_Position()[0], ptr_Player->Get_Position()[1]));
		break;
	case Key.Left:
		ptr_Player->Update_Position(Left(ptr_Player->Get_Position(), Delta_Time), 0, ptr_Map->Get_Walls_String(ptr_Player->Get_Position()[0], ptr_Player->Get_Position()[1]));
		break;
	case Key.Right:
		ptr_Player->Update_Position(Right(ptr_Player->Get_Position(), Delta_Time), 0, ptr_Map->Get_Walls_String(ptr_Player->Get_Position()[0], ptr_Player->Get_Position()[1]));
		break;
	default:
		//Reset_Float();
		break;
	}
}
