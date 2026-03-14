#include "Maze_Algorithm.h"

Maze_Algorithm::Maze_Algorithm()
{
	srand(time(0));
}

void Maze_Algorithm::Recursive()
{
	Solid_Map(air);		//Get an empty baseplate to work from (empty map)
	Border(solid);
	int Run_Count_Main = 0;
	while (Run_Count_Main < ((Height + Width) * 2))
	{
		int Run_Count_Intersection = 0;
		Run_Count_Main++;
		//getting random position within the borders
		struct
		{
			int x = 0;
			int y = 0;
		}	Startpoint;
		do
		{
			Startpoint.x = (((rand() % (Width / 2 - 2)) + 1) * 2);
			Startpoint.y = (((rand() % (Height / 2 - 2)) + 1) * 2);
			Run_Count_Intersection++;
		} while ((Level[Startpoint.y][Startpoint.x] != air) and !(Run_Count_Intersection >= (Height + Width) * 2));
		if (Run_Count_Intersection >= (Height + Width) * 2)
		{
			break;
		}
		//getting random position within the borders
		//Current Position
		struct
		{
			int x = 0;
			int y = 0;
		}	Pos;
		Pos.x = Startpoint.x;
		Pos.y = Startpoint.y;
		//Current Position
		//Saving start and end of walls
		struct
		{
			int x0 = 0;
			int y0 = 0;
			int x1 = 0;
			int y1 = 0;
		}	Max_Pos;
		//Saving start and end of walls
		

		//make walls
		//up
		while (true)
		{
			if ((Level[Pos.y][Pos.x] != empty) or (Pos.y == Height - 1))
			{
				Max_Pos.y1 = Pos.y - 1;
				break;
			}
			Level[Pos.y][Pos.x] = wall;
			Pos.y++;
		}
		Pos.y = Startpoint.y-1;
		//down
		while (true)
		{
			if ((Level[Pos.y][Pos.x] != empty) or (Pos.y == 0))
			{
				Max_Pos.y0 = Pos.y + 1;
				break;
			}
			Level[Pos.y][Pos.x] = wall;
			Pos.y--;
		}
		Pos.y = Startpoint.y;
		Pos.x = Startpoint.x + 1;
		//left
		while (true)
		{
			if ((Level[Pos.y][Pos.x] != empty) or (Pos.x == Width - 1))
			{
				Max_Pos.x1 = Pos.x - 1;
				break;
			}
			Level[Pos.y][Pos.x] = wall;
			Pos.x++;
		}
		Pos.x = Startpoint.x - 1;
		//right
		while (true)
		{
			if ((Level[Pos.y][Pos.x] != empty) or (Pos.x == 0))
			{
				Max_Pos.x0 = Pos.x + 1;
				break;
			}
			Level[Pos.y][Pos.x] = wall;
			Pos.x--;
		}
		//

		//making the doors
		struct 
		{
			int x = 0;
			int y = 0;
		}Doors;

		if (rand() % 2 == 1)
		{
			Doors.x = 2;
			Doors.y = 1;
		}
		else
		{
			Doors.x = 1;
			Doors.y = 2;
		}
		for (size_t x_doors = 0; x_doors < Doors.x; x_doors++)
		{
			int x_pos = 0;
			//to ensure one door per segment if more than 2
			if ((Doors.x > 1) && (x_doors % 2 == 1) && (Max_Pos.x1 - Startpoint.x != 0))
			{
				x_pos = (rand() % (Max_Pos.x1 - Startpoint.x)) + Startpoint.x + 1;
			}
			else if ((Doors.x > 1) && (x_doors % 2 == 0) && (Startpoint.x - Max_Pos.x0 != 0))
			{
				x_pos = (rand() % (Startpoint.x - Max_Pos.x0)) + Max_Pos.x0;
			}
			//to ensure one door per segment if more than 2
			else if ((Max_Pos.x1 - Max_Pos.x0) != 0)
			{
				x_pos = (rand() % (Max_Pos.x1 - Max_Pos.x0)) + Max_Pos.x0;
				if (x_pos >= Startpoint.x)	//to avoid a door at the intersection of the lines
				{
					x_pos++;
				}
			}
			if ((Max_Pos.x1 - Max_Pos.x0) != 0)
			{
				Level[Startpoint.y][x_pos] = door;
				Level[Startpoint.y + 1][x_pos] = door;
				Level[Startpoint.y - 1][x_pos] = door;
			}
		}
		for (size_t y_doors = 0; y_doors < Doors.y; y_doors++)
		{
			int y_pos = 0;
			//to ensure one door per segment if more than 2
			if ((Doors.y > 1) && (y_doors % 2 == 1) && (Max_Pos.y1 - Startpoint.y != 0))
			{
				y_pos = (rand() % (Max_Pos.y1 - Startpoint.y)) + Startpoint.y + 1;
			}
			else if ((Doors.y > 1) && (y_doors % 2 == 0) && (Startpoint.y - Max_Pos.y0 != 0))
			{
				y_pos = (rand() % (Startpoint.y - Max_Pos.y0)) + Max_Pos.y0;
			}
			//to ensure one door per segment if more than 2
			else if (Max_Pos.y1 - Max_Pos.y0 != 0)
			{
				y_pos = (rand() % (Max_Pos.y1 - Max_Pos.y0)) + Max_Pos.y0;
				if (y_pos >= Startpoint.y)	//to avoid a door at the intersection of the lines
				{
					y_pos++;
				}
			}
			if (Max_Pos.y1 - Max_Pos.y0 != 0)
			{
				Level[y_pos][Startpoint.x] = door;
				Level[y_pos][Startpoint.x + 1] = door;
				Level[y_pos][Startpoint.x - 1] = door;
			}
		}
		//break;
	}

	Generate_Rooms();
	
	Spawn_collectibles();

	Fix_Temporaries(air);	//Replace temporary blocking with air
}

std::vector<std::vector<int>> Maze_Algorithm::Get_Level()
{
	return Level;
}

void Maze_Algorithm::Solid_Map(int Fill)
{
	for (size_t Y = 0; Y < Height; Y++)
	{
		for (size_t X = 0; X < Width; X++)
		{
			Level[Y][X] = Fill;
		}
	}
}

void Maze_Algorithm::Border(int Material)	//make a border around the maze
{
	for (size_t X = 0; X < Width; X++)
	{
		Level[0][X] = Material;
		Level[Height - 1][X] = Material;
	}
	for (size_t Y = 0; Y < Height; Y++)
	{
		Level[Y][0] = Material;
		Level[Y][Width - 1] = Material;
	}
}

void Maze_Algorithm::Fix_Temporaries(int Material)	//remove negatives used for map generation
{
	for (size_t Y = 0; Y < Height; Y++)
	{
		for (size_t X = 0; X < Width; X++)
		{
			if (Level[Y][X] < 0)
			{
				Level[Y][X] = Material;
			}
		}
	}
}

void Maze_Algorithm::Generate_Rooms()
{
	//Spawn Room
	for (size_t Y = 0; Y < Spawn_Room_Size; Y++)
	{
		for (size_t X = 0; X < Spawn_Room_Size; X++)
		{
			Level[Y + 1][X + 1] = air;
		}
	}
	//Exit Room
	for (size_t Y = 0; Y < Exit_Room_Size; Y++)
	{
		for (size_t X = 0; X < Exit_Room_Size; X++)
		{
			Level[Y + Height - (Exit_Room_Size + 1)][X + Width - (Exit_Room_Size + 1)] = air;
		}
	}

	//Loot Room
	for (size_t Attempts = 0; Attempts < Loot_room_spawn_attempts; Attempts++)
	{
		bool Spawnable = true;
		struct
		{
			int x = 0;
			int y = 0;
		}Test_pos;
		Test_pos.x = (((rand() % (Width / 2 - (2 + (int)std::floor((float)Loot_room_size_x / 2)))) + 1) * 2 + 1);
		Test_pos.y = (((rand() % (Height / 2 - (2 + (int)std::floor((float)Loot_room_size_y / 2)))) + 1) * 2 + 1);
		//check if the ajacent corridor is empty
		for (size_t X = 0; X < Loot_room_spawn_check_distance; X++)
		{
			if (((Level[Test_pos.y][Test_pos.x + X] != 0) and (Level[Test_pos.y][Test_pos.x + X] != -1)) or ((Level[Test_pos.y][Test_pos.x - X] != 0) and (Level[Test_pos.y][Test_pos.x - X] != -1)))
			{
				Spawnable = false;
				break;
			}
		}
		if (Spawnable)
		{
			for (size_t Y = 0; Y < Loot_room_size_y; Y++)
			{
				for (size_t X = 0; X < Loot_room_size_x; X++)
				{
					Level[Test_pos.y - std::floor((float)Loot_room_size_y / 2) + Y][Test_pos.x - std::floor((float)Loot_room_size_x / 2) + X] = Loot_Room;
				}
			}
			for (size_t X = 0; X <= Loot_room_size_x; X++)
			{
				Level[Test_pos.y - std::floor((float)Loot_room_size_y / 2)][Test_pos.x + X - std::floor((float)Loot_room_size_x / 2)] = breakable;
				Level[Test_pos.y + Loot_room_size_y - std::floor((float)Loot_room_size_y / 2)][Test_pos.x + X - std::floor((float)Loot_room_size_x / 2)] = breakable;
			}
			for (size_t Y = 0; Y <= Loot_room_size_y; Y++)
			{
				Level[Test_pos.y + Y - std::floor((float)Loot_room_size_y / 2)][Test_pos.x - std::floor((float)Loot_room_size_x / 2)] = breakable;
				Level[Test_pos.y + Y - std::floor((float)Loot_room_size_y / 2)][Test_pos.x + Loot_room_size_x - std::floor((float)Loot_room_size_x / 2)] = breakable;
			}
			break;
		}
		Spawnable = true;
	}
}

void Maze_Algorithm::Spawn_collectibles()
{
	for (size_t Y = 0; Y < Height; Y++)
	{
		for (size_t X = 0; X < Width; X++)
		{
			if (Level[Y][X] == Loot_Room)
			{
				if (rand() % 100 < Loot_room_coin_frequency)
				{
					Level[Y][X] = Coin;
				}
			}
			if (Level[Y][X] == air)
			{
				if (rand() % 1000 < Default_coin_frequency)
				{
					Level[Y][X] = Coin;
				}
			}
		}
	}
}
