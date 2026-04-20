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
	};
	enum Screen_Colour_Target
	{
		Text,
		Background
	};


private:

	
};

