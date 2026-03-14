#pragma once
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

class Maze_Algorithm
{
public:

	Maze_Algorithm();
	void Recursive();
	std::vector<std::vector<int>> Get_Level();


private:
	void Solid_Map(int Fill);
	void Border(int Material);
	void Fix_Temporaries(int Material);
	void Generate_Rooms();
	void Spawn_collectibles();

	int Height = 32;
	int Width = 128;
	std::vector<int> Level_X = std::vector<int>(Width);
	std::vector<std::vector<int>> Level = std::vector<std::vector<int>>(Height, Level_X);
	
	enum Spawn_Rooms
	{
		Spawn_Room_Size = 3,
		Exit_Room_Size = Spawn_Room_Size,
	};
	enum Loot_Room
	{
		Loot_Room = 10,
		Loot_room_spawn_attempts = 100,
		Loot_room_size_x = 10,
		Loot_room_size_y = 4,
		Loot_room_spawn_check_distance = Loot_room_size_x / 2 + 1,
		Loot_room_coin_frequency = 30,		//out of 100
	};
	enum Collectibles
	{
		Coin = 100,
		Default_coin_frequency = 5,		//out of 1000
	};
	enum Wall_Material
	{
		air = 0,
		empty = 0,
		solid = 1,
		wall = 1,
		cracked = 2,
		breakable = 2,
	};
	enum Temporary_Wall_Material
	{
		door = -1,
		exclution_zone = -2,
	};
};

