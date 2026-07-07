#pragma once
#include <Windows.h>
class Input
{
public:
	Input() = default;

	int Get_Input();
	bool Get_Shift();
	bool Get_Space();
	void Clear_Inputs();


	enum Keys
	{
		Up = 1,		//W & Up arrow
		Down,		//S & Down arrow
		Left,		//A & Left arrow
		Right,		//D & Right arrow

		Enter,		//Enter & X & E
		Esc,		//Escape / Esc
		Return,		//Backspace & Z
		Shift,		//left shift
		Space,

		Interact,	//F

	};

private:

};

