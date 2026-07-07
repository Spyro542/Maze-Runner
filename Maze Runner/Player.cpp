#include "Player.h"

Player::Player(Map *level, Menus *menu)
{
	UI = true;
	Icon = menu->get_player_icon();
	ptr_level = level;
	ptr_menu = menu;
	Handle_Death = false;
	Set_Position(Return_Position[0], Return_Position[1], " ");
	Max_Health = 5;
	Health = Max_Health;
	Update_UI();
}

void Player::Update()
{
	
}
