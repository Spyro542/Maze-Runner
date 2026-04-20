#include "Player.h"

void Player::Update()
{
	switch (Key.Get_Input()) {
	case Key.Up:
	{
		Screen.Goto_XY(std::round(pos[0]), std::round(pos[1]));
		std::cout << " ";
		pos[1] -= (movespeed * Time.Delta_Time());
		if (!Level_1_Map.Get_Walls(std::round(pos[0]), std::round(pos[1])))
		{
			Screen.Goto_XY(std::round(pos[0]), std::round(pos[1]));
			std::cout << "˄";
			pos[0] = std::round(pos[0]);
		}
		else
		{
			pos[1] += 1;
		}
	}
	break;
	case Key.Down:
	{
		Screen.Goto_XY(std::round(pos[0]), std::round(pos[1]));
		std::cout << " ";
		pos[1] += (movespeed * Time.Delta_Time());
		if (!Level_1_Map.Get_Walls(std::round(pos[0]), std::round(pos[1])))
		{
			Screen.Goto_XY(std::round(pos[0]), std::round(pos[1]));
			std::cout << "˅";
			pos[0] = std::round(pos[0]);
		}
		else
		{
			pos[1] -= 1;
		}
	}
	break;
	case Key.Left:
	{
		Screen.Goto_XY(std::round(pos[0]), std::round(pos[1]));
		std::cout << " ";
		pos[0] -= (movespeed * Time.Delta_Time());
		if (!Level_1_Map.Get_Walls(std::round(pos[0]), std::round(pos[1])))
		{
			Screen.Goto_XY(std::round(pos[0]), std::round(pos[1]));
			std::cout << "˂";
			pos[1] = std::round(pos[1]);
		}
		else
		{
			pos[0] += 1;
		}
	}
	break;
	case Key.Right:
	{
		Screen.Goto_XY(std::round(pos[0]), std::round(pos[1]));
		std::cout << " ";
		pos[0] += (movespeed * Time.Delta_Time());
		if (!Level_1_Map.Get_Walls(std::round(pos[0]), std::round(pos[1])))
		{
			Screen.Goto_XY(std::round(pos[0]), std::round(pos[1]));
			std::cout << "˃";
			pos[1] = std::round(pos[1]);
		}
		else
		{
			pos[0] -= 1;
		}
	}
	break;
	case Key.Enter:
		break;
	case Key.Esc:
		return 0;
		break;
	case Key.Return:
		break;
	case Key.Interact:
		//system("cls");
		Screen.Goto_XY(0, 34);
		Maze_Generator.Recursive();
		//Generate Random Maze

		Level_1_Map.New_Maze(Maze_Generator.Get_Level());
		Level_1_Map.Draw_Maze();	//Draw Level 1
		break;

	}
}
