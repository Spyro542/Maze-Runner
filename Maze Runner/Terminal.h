#pragma once
class Terminal
{
public:
	Terminal() = default;


	void SetColour(int Text_Colour, int Background_Colour);
	void Goto_XY(int X, int Y);
	void Intialize();


	enum Colour
	{
		Black,
		Blue,
		Green,
		Light_Blue,
		Red,
		Purple,
		Yellow,
		White,
		Gray,
		Bright_Blue,
		Bright_Green,
		Pale_Blue,
		Light_Red,
		Bright_Purple,
		Light_Yellow,
		Bright_White,

		Full_Black = 0 + 27,
		Full_Blue = 1 + 27,
		Full_Green = 2 + 27,
		Full_Light_Blue = 3 + 27,
		Full_Red = 4 + 27,
		Full_Purple = 5 + 27,
		Full_Yellow = 6 + 27,
		Full_White = 7 + 27,
		Full_Gray = 8 + 27,
		Full_Bright_Blue = 9 + 27,
		Full_Bright_Green = 10 + 27,
		Full_Pale_Blue = 11 + 27,
		Full_Light_Red = 12 + 27,
		Full_Bright_Purple = 13 + 27,
		Full_Light_Yellow = 14 + 27,
		Full_Bright_White = 15 + 27,
	};
	enum Screen_Colour_Target
	{
		Text,
		Background
	};


private:

	
};

