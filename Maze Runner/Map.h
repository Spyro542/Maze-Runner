#pragma once
#include <string>
#include "Maze_Algorithm.h"
#include "Terminal.h"
class Map
{
public:
	Map(std::vector<std::vector<int>> Level);
	~Map();

	void Draw_Maze();
	int Get_Walls(int X, int Y);
	std::string Get_Walls_String(int X, int Y);
	void Update_Maze(int X, int Y, int tile);
	void New_Maze(std::vector<std::vector<int>> Level);

private:
	Terminal Screen;
	std::vector <std::vector<int>> Walls;

};

