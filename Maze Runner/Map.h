#pragma once
#include "Maze_Algorithm.h"
#include "Terminal.h"
class Map
{
public:
	Map(std::vector<std::vector<int>> Level);
	~Map();

	void Draw_Maze();
	bool Get_Walls(int X, int Y);
	void Update_Maze(int X, int Y, int tile);
	void New_Maze(std::vector<std::vector<int>> Level);

private:
	std::vector <std::vector<int>> Walls;

};

