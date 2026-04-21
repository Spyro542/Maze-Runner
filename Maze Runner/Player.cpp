#include "Player.h"

Player::Player()
{
	Handle_Death = false;
	Icon = "♀";
	Set_Position(Return_Position[0], Return_Position[1], " ");
}

Player::Player(std::string Player_Character)
{
	Icon = Player_Character;
}

void Player::Update()
{
	
}
