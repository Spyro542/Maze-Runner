#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Terminal.h"
#include "Map.h"
#include "Menus.h"

class Character
{
public:
	Character() = default;
	void Update_Health(float Damage_Value);
	void Update_UI();
	void Print_Healthbar();
	void Update_Max_Health(float Addition_Value);
	void Set_Position(int Y, int X, std::string Last_Tile);
	void Update_Position(int Y, int X, std::string Last_Tile, int next_tile);
	std::vector<int> Get_Position();
	//write current pos as wall type then write space moved to as player

	std::vector<int> non_passable = { 1, 2 };
	std::vector<int> collectibles = { 100, 101 };

protected:
	float Max_Health = 1;
	float Health = Max_Health;
	int Score = 0;
	int Level = 1;
	Menus* ptr_menu = nullptr;

	Map *ptr_level = nullptr;
	Maze_Algorithm* ptr_algorithm = nullptr;
	bool Handle_Death = true;
	bool UI = false;
	std::vector<int> Position{ 1,1 };
	std::vector<int> Return_Position{ 2,2 };
	std::string Icon = "☺";
	Terminal Screen;
	enum Walkable_tiles
	{
		Coin = 100,
		Heart = 101,
		Exit = 11,
	};
	struct
	{
		int forground = 12;
		int background = 0;
	} Character_Colors;
private:

};

