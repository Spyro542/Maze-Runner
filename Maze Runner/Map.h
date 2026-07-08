#pragma once
#include <string>
#include "Maze_Algorithm.h"
#include "Terminal.h"
//#include "Cat.h"
class Map
{
public:
	Map(std::vector<std::vector<int>> Level);
	~Map();

	void Draw_Maze();
	int Get_Walls(int X, int Y);
	std::string Get_Walls_String(int X, int Y);
	std::string Get_Walls_String(int Tile);
	void Update_Maze(int X, int Y, int tile);
	void New_Maze(std::vector<std::vector<int>> Level);
	
	//std::vector<Cat*> Get_Cats();
	//void Destroy_Cat(int num);

private:
	Terminal Screen;
	std::vector <std::vector<int>> Walls;
	//std::vector<Cat*> Cats;

	//void enable_cats(int x, int y);
};

