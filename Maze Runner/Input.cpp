#include "Input.h"

int Input::Get_Input()
{
	if (GetAsyncKeyState('W') || GetAsyncKeyState(VK_UP))
	{
		//while (GetAsyncKeyState('W') || GetAsyncKeyState(VK_UP)) {}
		return Up;
	}
	else if (GetAsyncKeyState('S') || GetAsyncKeyState(VK_DOWN))
	{
		//while (GetAsyncKeyState('S') || GetAsyncKeyState(VK_DOWN)) {}
		return Down;
	}
	else if (GetAsyncKeyState('A') || GetAsyncKeyState(VK_LEFT))
	{
		//while (GetAsyncKeyState('A') || GetAsyncKeyState(VK_LEFT)) {}
		return Left;
	}
	else if (GetAsyncKeyState('D') || GetAsyncKeyState(VK_RIGHT))
	{
		//while (GetAsyncKeyState('D') || GetAsyncKeyState(VK_RIGHT)) {}
		return Right;
	}
	else if (GetAsyncKeyState(VK_RETURN) || GetAsyncKeyState('Z'))
	{
		//while (GetAsyncKeyState(VK_RETURN) || GetAsyncKeyState('Z')) {}
		return Enter;
	}
	else if (GetAsyncKeyState(VK_ESCAPE))
	{
		//while (GetAsyncKeyState(VK_ESCAPE)) {}
		return Esc;
	}
	else if (GetAsyncKeyState(VK_BACK) || GetAsyncKeyState('X'))
	{
		//while (GetAsyncKeyState(VK_BACK) || GetAsyncKeyState('X')) {}
		return Return;
	}
	else if (GetAsyncKeyState('F'))
	{
		//while (GetAsyncKeyState('F')) {}
		return Interact;
	}
    return 0;
}

void Input::Clear_Inputs()
{
	GetAsyncKeyState('W');
	GetAsyncKeyState('S');
	GetAsyncKeyState('A');
	GetAsyncKeyState('D');
	GetAsyncKeyState(VK_UP);
	GetAsyncKeyState(VK_DOWN);
	GetAsyncKeyState(VK_LEFT);
	GetAsyncKeyState(VK_RIGHT);

	GetAsyncKeyState(VK_RETURN);	//Enter
	GetAsyncKeyState(VK_ESCAPE);	//Esc
	GetAsyncKeyState(VK_BACK);		//Return
	GetAsyncKeyState('Z');
	GetAsyncKeyState('X');

	GetAsyncKeyState('F');
}

//	GetAsyncKeyState('');
//	GetAsyncKeyState(VK_);