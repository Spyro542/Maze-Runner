#include "Projectile.h"

Projectile::Projectile(float Damage, double Speed, int direction, std::string icon, int Colour, int X, int Y, Time_Manager* Running_Delta_Time, Map* Level)
{
	Direction = direction;
	damage = Damage;
	speed = Speed;
	Icon = icon;
	colour = Colour;
	Position[0] = Y;
	Position[1] = X;
	ptr_Delta_Time = Running_Delta_Time;
	ptr_level = Level;
	
	switch (Direction) {
	case D_Up:
	{
		Position[0]--;
		break;
	}
	case D_Down:
	{
		Position[0]++;
		break;
	}
	break;
	case D_Left:
	{
		Position[1]--;
		break;
	}
	break;
	case D_Right:
	{
		Position[1]++;
		break;
	}
	break;
	default:
		break;
	}

	Screen.Goto_XY(Position[1], Position[0]);
	Screen.SetColour(colour, Screen.Black);
	std::cout << icon;

	
}

void Projectile::update()
{
	switch (Direction) {
	case D_Up:
	{
		int Movement_Update = move.Up(Position);
		Update_Position(Movement_Update, 0, ptr_level->Get_Walls_String(Position[1], Position[0] + Movement_Update), ptr_level->Get_Walls(Position[1], Position[0] + Movement_Update));
		break;
	}
	case D_Down:
	{
		int Movement_Update = move.Down(Position);
		Update_Position(Movement_Update, 0, ptr_level->Get_Walls_String(Position[1], Position[0] + Movement_Update), ptr_level->Get_Walls(Position[1], Position[0] + Movement_Update));
		break;
	}
		break;
	case D_Left:
	{
		int Movement_Update = move.Left(Position);
		Update_Position(0, Movement_Update, ptr_level->Get_Walls_String(Position[1] + Movement_Update, Position[0]), ptr_level->Get_Walls(Position[1] + Movement_Update, Position[0]));
		break;
	}
		break;
	case D_Right:
	{
		int Movement_Update = move.Right(Position);
		Update_Position(0, Movement_Update, ptr_level->Get_Walls_String(Position[1] + Movement_Update, Position[0]), ptr_level->Get_Walls(Position[1] + Movement_Update, Position[0]));
		break;
	}
		break;
	default:
		break;
	}
}

void Projectile::Update_Position(int Y, int X, std::string Last_Tile, int next_tile)
{
	if (Y != 0 or X != 0)
	{
		bool walkable = true;
		for (size_t i = 0; i < non_passable.size(); i++)
		{
			if (next_tile == non_passable[i])
			{
				walkable = false;
			}
		}
		if (walkable)
		{
			Screen.Goto_XY(Position[0], Position[1]);
			std::cout << Last_Tile;
			Position[0] += Y;
			Position[1] += X;
			Screen.Goto_XY(Position[0], Position[1]);
			Screen.SetColour(Character_Colors.forground, Character_Colors.background);
			std::cout << Icon;

			switch (next_tile) {
			case Coin:

				Score++;
				ptr_level->Update_Maze(Position[0], Position[1], 0);
				Update_UI();
				break;
			case Heart:
				if (Health == Max_Health)
				{
					Max_Health++;
				}
				else
				{
					Update_Health(-1);
				}
				ptr_level->Update_Maze(Position[0], Position[1], 0);
				break;
			default:
				break;
			}
		}
	}
}